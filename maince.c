#include <stdio.h>
#include <stdlib.h>

// La entrada va a ser la vista de las cajas (núm de cajas que se ven) desde cada punto de vista.
// El mapa será de nxn, en los ejemplos trabajaremos con n=4.
// Las entradas serán por tanto col1up para la vista desde arriba desde la primera columna, col2up para la vista desde arriba desde la segunda columna, etc. Igual para los otros puntos de vista.
// Tenemos que tomar un args[], de manera que la entrada del programa sea ./pograma col1up col2up col3up col4up col1down col2down col3down col4down row1left row2left row3left row4left row1right row2right row3right row4right
// El programa comprobará que se han pasado un número de argumentos correcto, y que todos son números enteros entre 1 y n. Cuando se determina el tamaño del mapa, se guardan en las variables correspondientes las entradas.
// Tendremos un array para las colup, otro para las coldown, otro para las rowleft y otro para las rowright. El tamaño de todos ellos será n.
// El programa comprobará que no hay números repetidos en cada array y que no hay números repetidos entre arrays dado un índice. 
// Las cajas pueden repetirse en distintos puntos de vista, pero no en el mismo punto de vista.

// La entrada va ser un string con los tamaños de caja, ejemplo para tamaño 2: ./rush01 "1 2 2 1"


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
            printf("El valor %d no está en el rango permitido\n", inputAsArray[i]);
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

    printf("Entrada: %s\n", input);
    printf("Tamaño de la entrada: %d\n", inputSize);
    // loop que irá de 0 a inputSize-1, de dos en dos y que comprobará a partir de i = 2, que el valor de input[i-1] es un espacio y que el valor de input[i] es un número entre 1 y n
    if (inputSize < 4) {
        return 0;
    }
    printf("Reservando memoria para inputAsInt (debemos tener %d números)...\n", (inputSize+1)/2);
    int * inputAsInt = malloc(((inputSize+1)/2) * sizeof(int)); //reservo el tamaño para array de ints suponiendo que la entrada es correcta, número de argumentos, más número de espacios igual a número de argumentos - 1, dividido entre 2
    int i = 2;
    printf("Comprobando que la entrada es correcta...\n");
    inputAsInt[0] = charToInt(input[0]);
    for (i; i < inputSize; i+=2) {
        if (input[i-1] != ' ') {
            return 0;
        }
        // si no se ha podido leer un número, lo veremos al comprobar si los valores están entre 1 y n, ya que charToInt devuelve 0 si no se ha podido leer un número
        inputAsInt[i/2] = charToInt(    input[i]);
    }
    *n = ((inputSize+1)/2)/4;
    printf("Ahora que conocemos el valor de n (%d), vamos a comprobar que los números de la entrada están dentro del rango...\n", *n);

    if (checkValuesAreInRange(*n, inputAsInt) == 0) {
        return 0;
    }
    printf("Los números están dentro del rango. Reservamos memoria para los puntos de vista e inicializamos los arrays...\n");
    //separamos en 4 arrays, uno para cada punto de vista
    *colup = (int *)malloc((*n) * sizeof(int));
    *coldown = (int *)malloc((*n) * sizeof(int));
    *rowleft = (int *)malloc((*n) * sizeof(int));
    *rowright = (int *)malloc((*n) * sizeof(int));

    printf("Inicializando...\n");
    i = 0;
    for (i; i < *n; i++) {
        (*colup)[i] = inputAsInt[i];
        (*coldown)[i] = inputAsInt[i+(*n)];
        (*rowleft)[i] = inputAsInt[i+2*(*n)];
        (*rowright)[i] = inputAsInt[i+3*(*n)];
    }

    printf("Comprobando si se cumplen las restricciones...\n");
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
        printf("%d ", array[i]);
    }
    printf("\n");

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
        printf("%d ", colup[i]);
    }
    printf("\n");
    // pintamos el punto de vista de la izquierda
    i = 0;
    for (i; i < n; i++) {
        printf("%d\n", rowleft[i]);
    }
    // pintamos el mapa de valores
    i = 0;
    for (i; i < n; i++) {
        int j = 0;
        for (j; j < n; j++) {
            printf("%d ", /*map[i][j]*/ 0);
        }
        printf("\n");
    }
    // pintamos el punto de vista de la derecha
    i = 0;
    for (i; i < n; i++) {
        printf("%d\n", rowright[i]);
    }
    // pintamos el punto de vista de abajo
    i = 0;
    for (i; i < n; i++) {
        printf("%d ", coldown[i]);
    }
    printf("\n");
}

// Lo mismo que printGame, pero separando celdas con espacios y con líneas horizontales y verticales para separar las cajas 
void printGamePro(int n, int * colup, int * coldown, int * rowleft, int * rowright, int map[n][n]) {
    // pintamos el punto de vista de arriba
    int i = 0;
        printf("Arriba e izquierda\n");

    for (i; i < n; i++) {
        printf("%d ", colup[i]);
    }
    printf("\n\n");
    // pintamos el punto de vista de la izquierda
    i = 0;
    for (i; i < n; i++) {
        printf("%d\n", rowleft[i]);
    }
    // pintamos el mapa de valores
    printf("\n");
    i = 0;
    for (i; i < n; i++) {
        int j = 0;
        for (j; j < n; j++) {
            printf("%d ", map[i][j]);
            if (j < n-1) {
                printf("| ");
            }
        }
        printf("\n");
        if (i < n-1) {
            j = 0;
            for (j; j < n; j++) {
                printf("--");
                if (j < n) {
                    printf("+");
                } 
            }
            printf("--\n");
        }
    }
    printf("\nDerecha y abajo\n");
    // pintamos el punto de vista de la derecha
    i = 0;
    for (i; i < n; i++) {
        printf("%d\n", rowright[i]);
    }
    // pintamos el punto de vista de abajo
    i = 0;
    for (i; i < n; i++) {
        printf("%d ", coldown[i]);
    }
    printf("\n");
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

// la anterior función devuelve un mapa de valores que forma un cuadrado latino, pero no cumple las condiciones de los puntos de vista
// ahora tenemos que intentar modificar el mapa de valores para que cumpla las condiciones de los puntos de vista mientras sigue siendo un cuadrado latino

int generateMapComplainingConditions(int n, int * colup, int * coldown, int * rowleft, int * rowright) {
    int cuadrado[n][n];
    
    //generamos cuadrados latinos aleatorios hasta que uno cumpla las condiciones de los puntos de vista
    //si no se puede, devolvemos 0

    //si se puede, devolvemos el cuadrado
    int startPoint = rand() % n + 1;
    int complains = 0;
        int i = 0;
        for (i; i < n; i++) {
            cuadrado[i][0] = (startPoint + i) % n + 1;
        }

        for (i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                cuadrado[i][j] = (cuadrado[i][j - 1] % n) + 1;
            }
        }
        //check conditions
        //check colup
        i = 0;
        for (i; i < n; i++) {
            int j = 0;
            int max = 0;
            int count = 0;
            for (j; j < n; j++) {
                if (cuadrado[j][i] > max) {
                    max = cuadrado[j][i];
                    count++;
                }
            }
            if (count != colup[i]) {
                break;
            }
        }

        //check coldown
        i = 0;
        for (i; i < n; i++) {
            int j = n-1;
            int max = 0;
            int count = 0;
            for (j; j >= 0; j--) {
                if (cuadrado[j][i] > max) {
                    max = cuadrado[j][i];
                    count++;
                }
            }
            if (count != coldown[i]) {
                break;
            }
        }

        //check rowleft
        i = 0;
        for (i; i < n; i++) {
            int j = 0;
            int max = 0;
            int count = 0;
            for (j; j < n; j++) {
                if (cuadrado[i][j] > max) {
                    max = cuadrado[i][j];
                    count++;
                }
            }
            if (count != rowleft[i]) {
                break;
            }
        }

        //check rowright
        i = 0;
        for (i; i < n; i++) {
            int j = n-1;
            int max = 0;
            int count = 0;
            for (j; j >= 0; j--) {
                if (cuadrado[i][j] > max) {
                    max = cuadrado[i][j];
                    count++;
                }
            }
            if (count != rowright[i]) {
                break;
            }
        }
        if (i == n) {
            complains = 1;
        } else {
            startPoint = rand() % n + 1;
        }
    
    printGamePro(n, colup, coldown, rowleft, rowright, cuadrado);

    return cuadrado;
}

int tryToSolve(int n, int * colup, int * coldown, int * rowleft, int * rowright) {
    //generamos un mapa de nxn
    generateMapComplainingConditions(n, colup, coldown, rowleft, rowright);
}

int main(int argc, char *argv[]) {
    // si no se pasa 1 argumento, devolver error
    if (argc != 2) {
        printf("Error: wrong number of arguments\n");
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
        printf("Error: wrong input\n");
        return 0;
    }

    printf("Input correcto!\n");
    

    /*printVector(n, colup);
    printVector(n, coldown);
    printVector(n, rowleft);
    printVector(n, rowright);*/
    printf("Pintamos el mapa de valores:\n");
    //printGamePro(n, colup, coldown, rowleft, rowright, NULL);
    tryToSolve(n, colup, coldown, rowleft, rowright);
    free(colup);
    free(coldown);
    free(rowleft);
    free(rowright);
    return 0;
}
