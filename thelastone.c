#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
// La entrada va a ser la vista de las cajas (núm de cajas que se ven) desde cada punto de vista.
// El mapa será de nxn, en los ejemplos trabajaremos con n=4.
// Las entradas serán por tanto col1up para la vista desde arriba desde la primera columna, col2up para la vista desde arriba desde la segunda columna, etc. Igual para los otros puntos de vista.
// Tenemos que tomar un args[], de manera que la entrada del programa sea ./pograma col1up col2up col3up col4up col1down col2down col3down col4down row1left row2left row3left row4left row1right row2right row3right row4right
// El programa comprobará que se han pasado un número de argumentos correcto, y que todos son números enteros entre 1 y n. Cuando se determina el tamaño del mapa, se guardan en las variables correspondientes las entradas.
// Tendremos un array para las colup, otro para las coldown, otro para las rowleft y otro para las rowright. El tamaño de todos ellos será n.
// El programa comprobará que no hay números repetidos en cada array y que no hay números repetidos entre arrays dado un índice. 
// Las cajas pueden repetirse en distintos puntos de vista, pero no en el mismo punto de vista.

// La entrada va ser un string con los tamaños de caja, ejemplo para tamaño 2: ./rush01 "1 2 2 1"


#define DEBUG 1

void printDebug(int flag, char * format, ...) {
    if (flag == 1) {
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
    }
}

int globaldeltotal = 0;

int charToInt(char c) {
    char * temp = malloc(2 * sizeof(char));
    temp[0] = c; 
    temp[1] = '\0';
    return atoi(temp);
}
// Comprueba que todos los valores del array son números entre 1 y n
int checkValuesAreInRange(int n, int * inputAsArray) {
    int i = 0;
    int inputArrayLength = n*4;
    for (i; i < inputArrayLength; i++) {
        if (inputAsArray[i] < 1 || inputAsArray[i] > n) {
            printDebug(DEBUG, "El valor %d no está en el rango permitido\n", inputAsArray[i]);
            return 0;
        }
    }
    return 1;
}

// Comprueba de manera eficiente que no hay números repetidos en la misma columna o fila
int checkValuesAreNotRepeated(int n, int * inputAsArray) {
    int i = 0;
    for (i; i < n; i++) {
        int j = i+1;
        for (j; j < n; j++) {
            if (inputAsArray[i] == inputAsArray[j]) {
                return 0;
            }
        }
    }
    return 1;
}


//toma como entrada input y como salida, n, colup, coldown, rowleft, rowright
int checkInput(char* input, size_t inputSize, int *n, int ** colup, int ** coldown, int ** rowleft, int ** rowright) {
    // Comprobar que el número de argumentos es correcto
    // Comprobar que todos los argumentos son números enteros
    // Comprobar que todos los argumentos son números entre 1 y n
    // Comprobar que no hay números repetidos en cada array

    printDebug(DEBUG, "Entrada: %s\n", input);
    printDebug(DEBUG, "Tamaño de la entrada: %d\n", inputSize);
    // loop que irá de 0 a inputSize-1, de dos en dos y que comprobará a partir de i = 2, que el valor de input[i-1] es un espacio y que el valor de input[i] es un número entre 1 y n
    if (inputSize < 4) {
        return 0;
    }
    printDebug(DEBUG, "Reservando memoria para inputAsInt (debemos tener %d números)...\n", (inputSize+1)/2);
    int * inputAsInt = malloc(((inputSize+1)/2) * sizeof(int)); //reservo el tamaño para array de ints suponiendo que la entrada es correcta, número de argumentos, más número de espacios igual a número de argumentos - 1, dividido entre 2
    int i = 2;
    printDebug(DEBUG, "Comprobando que la entrada es correcta...\n");
    inputAsInt[0] = charToInt(input[0]);
    for (i; i < inputSize; i+=2) {
        if (input[i-1] != ' ') {
            return 0;
        }
        // si no se ha podido leer un número, lo veremos al comprobar si los valores están entre 1 y n, ya que charToInt devuelve 0 si no se ha podido leer un número
        inputAsInt[i/2] = charToInt(    input[i]);
    }
    *n = ((inputSize+1)/2)/4;
    printDebug(DEBUG, "Ahora que conocemos el valor de n (%d), vamos a comprobar que los números de la entrada están dentro del rango...\n", *n);

    if (checkValuesAreInRange(*n, inputAsInt) == 0) {
        return 0;
    }
    printDebug(DEBUG, "Los números están dentro del rango. Reservamos memoria para los puntos de vista e inicializamos los arrays...\n");
    //separamos en 4 arrays, uno para cada punto de vista
    *colup = (int *)malloc((*n) * sizeof(int));
    *coldown = (int *)malloc((*n) * sizeof(int));
    *rowleft = (int *)malloc((*n) * sizeof(int));
    *rowright = (int *)malloc((*n) * sizeof(int));

    printDebug(DEBUG, "Inicializando...\n");
    i = 0;
    for (i; i < *n; i++) {
        (*colup)[i] = inputAsInt[i];
        (*coldown)[i] = inputAsInt[i+(*n)];
        (*rowleft)[i] = inputAsInt[i+2*(*n)];
        (*rowright)[i] = inputAsInt[i+3*(*n)];
    }

    printDebug(DEBUG, "Comprobando si se cumplen las restricciones...\n");
    /*checkValuesAreNotRepeated(n, colup);
    checkValuesAreNotRepeated(n, coldown);
    checkValuesAreNotRepeated(n, rowleft);
    checkValuesAreNotRepeated(n, rowright);*/

    //la entrada es correcta, ya tenemos los puntos de vista separados en 4 arrays, uno para cada punto de vista
    //ahora intentamos generar el mapa que cumpla las condiciones de todos los puntos de vista a la vez
    //si no se puede, devolvemos 0
    //si se puede, devolvemos 1
    return 1;
}





void printVector(int n, int *array) {
    int i = 0;
    for (i; i < n; i++) {
        printDebug(DEBUG, "%d ", array[i]);
    }
    printDebug(DEBUG, "\n");

}

void printMap(int n, int map[n][n]) {
    int i = 0;
    for (i; i < n; i++) {
        printVector(n, map[i]);
    }
}


// Función auxiliar que pinta el mapa del juego en consola. colup es el array de la vista desde arriba, coldown es el array de la vista desde abajo, rowleft es el array de la vista desde la izquierda y rowright es el array de la vista desde la derecha.
// el punto de vista de arriba se pinta como una fila en la parte superior. el de la izquierda se pinta como columna en el lado izquierdo del mapa de valores. el de la derecha se pinta como columna en el lado derecho del mapa de valores. el de abajo se pinta como fila en la parte inferior.
// el mapa de valores se pinta con los valores de las cajas, si no se ha determinado el valor de una caja, se pinta con un 0.
// la función recibe el tamaño del problema, los puntos de vista y el mapa de valores.

void printGame(int n, int * colup, int * coldown, int * rowleft, int * rowright, int map[n][n]) {
    // pintamos el punto de vista de arriba
    int i = 0;
    for (i; i < n; i++) {
        printDebug(DEBUG, "%d ", colup[i]);
    }
    printDebug(DEBUG, "\n");
    // pintamos el punto de vista de la izquierda
    i = 0;
    for (i; i < n; i++) {
        printDebug(DEBUG, "%d\n", rowleft[i]);
    }
    // pintamos el mapa de valores
    i = 0;
    for (i; i < n; i++) {
        int j = 0;
        for (j; j < n; j++) {
            printDebug(DEBUG, "%d ", /*map[i][j]*/ 0);
        }
        printDebug(DEBUG, "\n");
    }
    // pintamos el punto de vista de la derecha
    i = 0;
    for (i; i < n; i++) {
        printDebug(DEBUG, "%d\n", rowright[i]);
    }
    // pintamos el punto de vista de abajo
    i = 0;
    for (i; i < n; i++) {
        printDebug(DEBUG, "%d ", coldown[i]);
    }
    printDebug(DEBUG, "\n");
}

// Lo mismo que printGame, pero separando celdas con espacios y con líneas horizontales y verticales para separar las cajas 
void printGamePro(int n, int * colup, int * coldown, int * rowleft, int * rowright, int map[n][n]) {
    // pintamos el punto de vista de arriba
    const int DEBUG_PRINT_GAME = 1;
    int i = 0;
        printDebug(DEBUG_PRINT_GAME, "Arriba e izquierda\n");

    for (i; i < n; i++) {
        printDebug(DEBUG_PRINT_GAME, "%d ", colup[i]);
    }
    printDebug(DEBUG_PRINT_GAME, "\n\n");
    // pintamos el punto de vista de la izquierda
    i = 0;
    for (i; i < n; i++) {
        printDebug(DEBUG_PRINT_GAME, "%d\n", rowleft[i]);
    }
    // pintamos el mapa de valores
    printDebug(DEBUG_PRINT_GAME, "\n");
    i = 0;
    for (i; i < n; i++) {
        int j = 0;
        for (j; j < n; j++) {
            printDebug(DEBUG_PRINT_GAME, "%d ", map[i][j]);
            if (j < n-1) {
                printDebug(DEBUG_PRINT_GAME, "| ");
            }
        }
        printDebug(DEBUG_PRINT_GAME, "\n");
        if (i < n-1) {
            j = 0;
            for (j; j < n; j++) {
                printDebug(DEBUG_PRINT_GAME, "--");
                if (j < n) {
                    printDebug(DEBUG_PRINT_GAME, "+");
                } 
            }
            printDebug(DEBUG_PRINT_GAME, "--\n");
        }
    }
    printDebug(DEBUG_PRINT_GAME, "\nDerecha y abajo\n");
    // pintamos el punto de vista de la derecha
    i = 0;
    for (i; i < n; i++) {
        printDebug(DEBUG_PRINT_GAME, "%d\n", rowright[i]);
    }
    printDebug(DEBUG_PRINT_GAME, "\n");
    // pintamos el punto de vista de abajo
    i = 0;
    for (i; i < n; i++) {
        printDebug(DEBUG_PRINT_GAME, "%d ", coldown[i]);
    }
    printDebug(DEBUG_PRINT_GAME, "\n");
} 


int generateMap(int n, int * colup, int * coldown, int * rowleft, int * rowright) {

    int cuadrado[n][n];

    for (int i = 0; i < n; i++) {
        cuadrado[i][0] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            cuadrado[i][j] = (cuadrado[i][j - 1] % n) + 1;
        }
    }
    printGamePro(n, colup, coldown, rowleft, rowright, cuadrado);
    return cuadrado;
}

// comprueba para la celda (i, j) que se cumplen las condiciones de los puntos de vista (que la caja que ponemos en la celda haga que desde arriba se vean tantas cajas 
// como indica colup[i], que desde abajo se vean tantas cajas como indica coldown[i], que desde la izquierda se vean tantas cajas como indica rowleft[j] y que desde la derecha se vean tantas cajas como indica rowright[j])
int checkConditions(int n, int * colup, int * coldown, int * rowleft, int * rowright, int map[n][n], int i, int j) {

    //no se repite en file ni en columna
    int k = 0;
    for (k; k < n; k++) {
        if (map[i][k] == map[i][j] && k != j) {
            printDebug(DEBUG, "No se cumple la condición de que no se repite en la fila\n");
            return 0;
        }
        if (map[k][j] == map[i][j] && k != i) {
            //printDebug(DEBUG, "No se cumple la condición de que no se repite en la columna\n");
            return 0;
        }
    }

    // comprobamos que se cumple la condición de la vista desde arriba
    k = 0;
    int count = 0;
    int max = -1;
    int startsInZero = map[k][j];
    for (k; k < n; k++) {
        //printDebug(DEBUG, "RECORRO de arriba a abajo: %d. Cont ahora es %d\n", map[k][j], count);
        if (startsInZero != 0 && (map[k][j] >= max || map[k][j] == 0) ) {
            max = map[k][j];
            count++;
        }
    }
    if (count > colup[j] && colup[j] < max) {
        //printDebug(DEBUG, "No se cumple la condición de la vista desde arriba porque %d != %d\n", count, colup[j]);
        return 0;
    }
    printDebug(DEBUG, "Se cumple la condición de la vista desde arriba\n");
    // comprobamos que se cumple la condición de la vista desde abajo
    k = n-1;
    count = 0;
    max = -1;
    startsInZero = map[k][j];
    for (k; k >= 0; k--) {
        //printDebug(DEBUG, "RECORRO de abajo a arriba: %d Cont ahora es %d\n", map[k][j], count);
        if (startsInZero != 0 && (map[k][j] >= max || map[k][j] == 0) ) {
            max = map[k][j];
            count++;
        }
    }
    if (count > coldown[j] && coldown[j] < max) {
        //printDebug(DEBUG, "No se cumple la condición de la vista desde abajo porque %d != %d\n", count, coldown[j]);
        return 0;
    }
    printDebug(DEBUG, "Se cumple la condición de la vista desde abajo\n");
    // comprobamos que se cumple la condición de la vista desde la izquierda
    k = 0;
    count = 0;
    max = -1;
    startsInZero = map[i][k];
    for (k; k < n; k++) {
        if (startsInZero != 0 && (map[i][k] >= max || map[i][k] == 0)) {
            max = map[i][k];
            count++;
        }
    }
    if (count > rowleft[i] && rowleft[i] < max) {
        //printDebug(DEBUG, "No se cumple la condición de la vista desde la izquierda porque %d != %d\n", count, rowleft[i]);
        return 0;
    }
    printDebug(DEBUG, "Se cumple la condición de la vista desde la izquierda\n");
    // comprobamos que se cumple la condición de la vista desde la derecha
    k = n-1;
    count = 0;
    max = -1;
    startsInZero = map[i][k];
    for (k; k >= 0; k--) {
        if (startsInZero != 0 && (map[i][k] >= max || map[i][k] == 0) ) {
            max = map[i][k];
            count++;
        }
    }
    if (count > rowright[i] && rowright[i] < max) {
        //printDebug(DEBUG, "No se cumple la condición de la vista desde la derecha porque %d != %d\n", count, rowright[i]);
        return 0;
    }
    printDebug(DEBUG, "Se cumple la condición de la vista desde la derecha\n");

    return 1;
}


int backtrack(int n, int * colup, int * coldown, int * rowleft, int * rowright, int map[n][n], int i, int j) {
    printDebug(DEBUG, "backtrack(%d, %d, %d)\n", i, j, map[i][j]);
    // si i == n, hemos terminado
    if (i == n) {
        return 1;
    }
    // si j == n, hemos terminado con la fila i, pasamos a la siguiente fila
    if (j == n) {
        return backtrack(n, colup, coldown, rowleft, rowright, map, i+1, 0);
    }
    // si map[i][j] != 0, pasamos a la siguiente celda
    if (map[i][j] != 0) {
        return backtrack(n, colup, coldown, rowleft, rowright, map, i, j+1);
    }
    // si map[i][j] == 0, probamos a poner un número en la celda
    int k = 1;
    for (k; k <= n; k++) {
        map[i][j] = k;
        printDebug(DEBUG, "Pruebo con %d\n", k);
        // si el número que hemos puesto en la celda es válido, pasamos a la siguiente celda
        if (checkConditions(n, colup, coldown, rowleft, rowright, map, i, j) == 1) {
            printDebug(DEBUG, "CELDA %d %d: %d\n", i, j, map[i][j]);
            if (backtrack(n, colup, coldown, rowleft, rowright, map, i, j+1) == 1) {
                return 1;
            }
        }
    }
    // si no hemos podido poner ningún número en la celda, devolvemos 0
    map[i][j] = 0;
    return 0;
}



int tryToSolve(int n, int * colup, int * coldown, int * rowleft, int * rowright) {
    //generamos un mapa de nxn usando backtracking
    int map[n][n];
    int i = 0;
    for (i; i < n; i++) {
        int j = 0;
        for (j; j < n; j++) {
            map[i][j] = 0;
        }
    }
    if (backtrack(n, colup, coldown, rowleft, rowright, map, 0, 0) == 1) {
        printDebug(DEBUG, "Hemos encontrado una solución!\n");
        printGamePro(n, colup, coldown, rowleft, rowright, map);
        return 1;
    }
    printDebug(DEBUG, "No hemos encontrado ninguna solución\n");
    return 0;
}

int main(int argc, char *argv[]) {
    // si no se pasa 1 argumento, devolver error
    if (argc != 2) {
        printDebug(DEBUG, "Error: wrong number of arguments\n");
        return 0;
    }
    int n = 0;
    int * colup;
    int * coldown;
    int * rowleft;
    int * rowright;

    const char *userInput = argv[1];

    size_t inputSize = 0;
    while (userInput[inputSize] != NULL) {
        inputSize++;
    }

    if (checkInput(userInput, inputSize, &n, &colup, &coldown, &rowleft, &rowright) == 0) {
        printDebug(DEBUG, "Error: wrong input\n");
        return 0;
    }

    printDebug(DEBUG, "Input correcto!\n");
    printDebug(DEBUG, "n = %d\n%d", n, n);
    tryToSolve(n, colup, coldown, rowleft, rowright);
    free(colup);
    free(coldown);
    free(rowleft);
    free(rowright);
    return 0;
}



