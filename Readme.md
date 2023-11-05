
Nuestro algoritmo completa el juego por filas.


# Estructuras


## Estructura de datos


### Tablero (`board`)

Será un array `int[4][4]` de `int` con valores del 0 al 4, donde el primer índice indica la fila, y el segundo la columna. Si el valor es 0, significa que la casilla está vacía. Si es 1, significa que hay una caja de altura 1. Si es 2, significa que hay una caja de altura 2. Si es 3, significa que hay una caja de altura 3. Si es 4, significa que hay una caja de altura 4.


### Lista de posibles alturas por colocar en fila (`remaining_heights_col`)

Será un array `int[5]` de 5 elementos, los 4 primeros indican si esa altura (+1) está disponible o no, y el último indica el número de fila.


### Lista de posibles alturas por colocar en casilla (`remaining_heights`)


Consistirá en un array `int[4][4][4]` de 0s y 1s, donde el primer índice indica la fila, el segundo la columna, y el tercero la altura. Si el valor es 1 en la lista del último índice, significa que esa altura está disponible para colocar en esa casilla. Si es 0, significa que no está disponible



### Contadores (`col_counter` y `row_counter`)

Vamos a tener dos variables para los contadores, que se llamarán `col_counter` y `row_counter`, serán de tipo `int[4][2]`, y el primer índice indicará el númerod e fila o columna, respectivamente, y el segundo índice indicará el contador, que puede ir de 1 (al menos cada sujeto del borde verá una caja) a 4. El primero es el de arriba (resp. izda.), y el segundo el de abajo (resp. dcha.).


### Input (`col_input` y `row_input`)

Vamos a tener dos variables para los inputs, que se llamarán `col_input` y `row_input`, serán de tipo `int[4][2]`, y el primer índice indicará el número de fila o columna, respectivamente, y el segundo índice indicará el contador, que puede ir de 1 (al menos cada sujeto del borde verá una caja) a 4. El primero es el de arriba (resp. izda.), y el segundo el de abajo (resp. dcha.).




# Variables iniciales

Tendremos varias variables al comienzo del juego, que inicializaremos de acuerdo a lo siguiente:

- `board`: tablero del juego, de tipo `int[4][4]`, con valores posibles: 0, 1, 2, 3, 4. 0 indica que la casilla está vacía, y 1, 2, 3, 4 indican que hay una caja de altura 1, 2, 3, 4 respectivamente. Inicialmente, todas las casillas estarán vacías.
- `remaining_heights`: lista de alturas restantes, de tipo `int[4][4][4]`, con posibles valores 0 y 1. 0 indica que esa altura no está disponible, y 1 indica que sí lo está. Inicialmente, todas las alturas estarán disponibles.
- `remaining_heights_row`: lista de alturas restantes por colocar en fila, de tipo `int[5]`, con posibles valores 0 y 1, salvo para la última entrada, que puede tener valores 1, 2, 3 o 4. 0 indica que esa altura no está disponible, y 1 indica que sí lo está. Inicialmente, todas las alturas estarán disponibles.
- `col_counter`: contador de alturas por columna, de tipo `int[4][2]`, con posibles valores 0, 1, 2, 3, 4. 0 indica que no hay ninguna caja en esa columna, 1, 2, 3, 4 indican que hay una caja de altura 1, 2, 3, 4 respectivamente. Inicialmente, todas las columnas estarán vacías.
- `row_counter`: contador de alturas por fila, de tipo `int[4][2]`, con posibles valores 0, 1, 2, 3, 4. 0 indica que no hay ninguna caja en esa fila, 1, 2, 3, 4 indican que hay una caja de altura 1, 2, 3, 4 respectivamente. Inicialmente, todas las filas estarán vacías.
- `col_input`: input de alturas por columna, de tipo `int[4][2]`, con posibles valores 0, 1, 2, 3, 4. 0 indica que no hay ninguna caja en esa columna, 1, 2, 3, 4 indican que hay una caja de altura 1, 2, 3, 4 respectivamente. Inicialmente, todas las columnas estarán vacías.
- `row_input`: input de alturas por fila, de tipo `int[4][2]`, con posibles valores 0, 1, 2, 3, 4. 0 indica que no hay ninguna caja en esa fila, 1, 2, 3, 4 indican que hay una caja de altura 1, 2, 3, 4 respectivamente. Inicialmente, todas las filas estarán vacías.


# Funciones

## Funciones auxiliares

- Traducción de la entrada, `ft_input`, a las variables `col_input` y `row_input`: Esta función traduce la entrada, que es de la forma _`"col1up col2up col3up col4up col1down col2down col3down col4down row1left row2left row3left row4left row1right row2right row3right row4right"`_, a las variables `col_input` y `row_input`, que son de la forma `int[4][2]`, con cada valor variando entre 1 y 4 (si no, lanzamos un mensaje de "Error" y paramos todo). Tendrá como argumento la entrada, y devolverá las variables `col_input` y `row_input`, posiblemente en un array de dos elementos, a saber, `col_input` y `row_input`.

- Pintar el tablero, `ft_write_results`: Esta función pinta el tablero, de la forma `int[4][4]`, con cada valor variando entre 0 y 4, en la consola. Tendrá como argumento el _tablero_, y no devolverá nada. Debe pintarlo como un cuadrado de tamaño 4x4 de manera que después de cada número haya un espacio, salvo para el último, para el cual solo habrá un salto de línea.

- Eliminar alturas de la lista de alturas posibles por casilla, `ft_remove_rem_heights`: Esta función elimina una altura de la lista de alturas posibles para una casilla dada, `remaining_heights`. Los parámetros son la _fila_, la _columna_ y la _altura a eliminar_, y no devuelve nada. Simplemente pone un 0 en la posición correspondiente de la lista de alturas posibles que se le pasa como argumento.

- Eliminar alturas de la lista de alturas posibles por fila `ft_remove_rem_heights_from_row`: Esta función elimina una altura de la lista de alturas posibles para una fila dada, `remaining_heights_row`. Los parámetros son la _fila_ y la _altura a eliminar_, y no devuelve nada. Simplemente pone un 0 en la posición correspondiente de la lista de alturas posibles.

- Añadir alturas a la lista de alturas posibles por casilla, `ft_add_height`: Esta función añade una altura a la lista de alturas posibles para una casilla dada. Los parámetros son la _fila_, la _columna_ y la _altura a añadir_, y no devuelve nada. Simplemente pone un 1 en la posición correspondiente de la lista de alturas posibles.

- Añadir alturas a la lista de alturas posibles por fila, `ft_add_height_row`: Esta función añade una altura a la lista de alturas posibles para una fila dada. Los parámetros son la _fila_ y la _altura a añadir_, y no devuelve nada. Simplemente pone un 1 en la posición correspondiente de la lista de alturas posibles.

- Actualizar contador de alturas por columna, `ft_update_col_counter`:  Esta función suma una unidad al contador de alturas por columna. Los parámetros son la _columna_ y la _altura a añadir_, y no devuelve nada. Simplemente suma 1 a la posición correspondiente del contador de alturas por columna si el individuo que corresponde ve una nueva caja. Si ve menos cajas, resta 1. Si ve el mismo número de cajas, no hace nada.

- Actualizar contador de alturas por fila `ft_update_row_counter`:  Esta función suma una unidad al contador de alturas por fila. Los parámetros son la _fila_ y la _altura a añadir_, y no devuelve nada. Simplemente suma 1 a la posición correspondiente del contador de alturas por fila si el individuo que corresponde ve una nueva caja. Si ve menos cajas, resta 1. Si ve el mismo número de cajas, no hace nada.

- Función de visualización, `ft_how_many`: Está función indica cuántas cajas ven los sujetos de una fila y columna dadas. Los parámetros son la _fila_ o la _columna_ y el _contador_ (1, 2, 3 o 4), y devuelve el número de cajas que ven los sujetos de esa fila o columna.

## Funciones de restricción

RELLENAR (realmente es necesario?)



# Procedimiento

1. Inicializamos las variables `board`, `remaining_heights`, `remaining_heights_row`, `col_counter`, `row_counter`, `col_input` y `row_input` de acuerdo a lo especificado en la sección de _Variables iniciales_.
2. Traducimos la entrada a las variables `col_input` y `row_input` con la función `ft_input`.
3. Aplicamos las funciones de restricción (a definir aún), que ayudarán a resolver el problema más rápido. Entre ellas, están las restricciones para las listas de casillas disponibles.
4. Aplicamos el algoritmo que se describe a continuación:
	1. Nos colocamos en la primera casilla (casilla (0,0)).
	2. Si la casilla está vacía, probamos a colocar una caja de altura 1, 2, 3 o 4, de entre las disponibles en la lista de alturas posibles para esa casilla y si no se viola ninguna restricción (comprobamos esto con las funciones `ft_how_many` y `ft_update_col_counter` o `ft_update_row_counter`), la colocamos y pasamos a la siguiente casilla. Si se viola alguna restricción, probamos con la siguiente altura. Si no hay más alturas disponibles, volvemos a la casilla anterior y probamos con la siguiente altura de la lista disponible de alturas para esa casilla.
	3. Si la casilla no está vacía, pasamos a la siguiente casilla.
	4. Si no hay más casillas, hemos terminado.