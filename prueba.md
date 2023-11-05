Nuestro algoritmo completa el juego por filas.


# Estructuras


## Estructura de datos


### Tablero (`board`)

Será un array `int[4][4]` de enteros  , donde el primer índice indica la fila, y el segundo la columna. Si el valor es 0, significa que la casilla está vacía. Si es 1, significa que hay una caja de altura 1. Si es 2, significa que hay una caja de altura 2. Si es 3, significa que hay una caja de altura 3. Si es 4, significa que hay una caja de altura 4.

<!-- ### Coordenadas (`coord`)

Vamos a tener una estructura para las coordenadas, que se llamará `coord`, y cuyos elementos serán: `row` y `column`.

- `row`: fila de la casilla, valores posibles: 1, 2, 3, 4. Tipo: `int`.
- `column`: columna de la casilla, valores posibles: 1, 2, 3, 4. Tipo: `int`. -->



<!-- ### Casillas (`box`)

Vamos a tener una estructura para las casillas, que se llamará `box`, y cuyos elementos serán: `pos`, `height` y `filled`. 

- `pos`: coordenadas de la casilla, valores posibles: (1, 1), (1, 2), (1, 3), (1, 4), (2, 1), (2, 2), (2, 3), (2, 4), (3, 1), (3, 2), (3, 3), (3, 4), (4, 1), (4, 2), (4, 3), (4, 4). Tipo: `coord`.
- `height`: altura de la caja que se encuentra en la casilla, valores posibles: 1, 2, 3, 4. Tipo: `int`.
- `filled`: booleano que indica si la casilla está rellena o no, valores posibles: 0 o 1. Tipo: `int`. -->

### Lista de posibles alturas por colocar en fila (`remaining_heights_col`)

Será un array `int[5]` de 5 elementos, los 4 primeros indican si esa altura (+1) está disponible o no, y el último indica el número de fila.
<!-- 
Vamos a tener una estructura para las alturas que quedan por colocar para la fila, que se llamará `remaining_heights_row`, y cuyos elementos serán: `h1`, `h2`, `h3`, `h4`, `col`.

- `h1`: indica que queda por colocar una caja de altura 1. Valores posibles: 0 o 1. Tipo: `int`.
- `h2`: indica que queda por colocar una caja de altura 2. Valores posibles: 0 o 1. Tipo: `int`.
- `h3`: indica que queda por colocar una caja de altura 3. Valores posibles: 0 o 1. Tipo: `int`.
- `h4`: indica que queda por colocar una caja de altura 4. Valores posibles: 0 o 1. Tipo: `int`.
- `row`: indica el número de fila, valores posibles: 1, 2, 3, 4. Tipo: `int`. -->

### Lista de posibles alturas por colocar en casilla (`remaining_heights`)


Consistirá en un array `int[4][4][4]` de 0s y 1s, donde el primer índice indica la fila, el segundo la columna, y el tercero la altura. Si el valor es 1 en la lista del último índice, significa que esa altura está disponible para colocar en esa casilla. Si es 0, significa que no está disponible

<!-- Vamos a tener una estructura para las alturas que quedan por colocar aceptables y disponibles para la casilla, que se llamará `remaining_heights`, y cuyos elementos serán: `h1`, `h2`, `h3`, `h4`, `pos`.

- `h1`: indica que queda por colocar una caja de altura 1. Valores posibles: 0 o 1. Tipo: `int`.
- `h2`: indica que queda por colocar una caja de altura 2. Valores posibles: 0 o 1. Tipo: `int`.
- `h3`: indica que queda por colocar una caja de altura 3. Valores posibles: 0 o 1.	Tipo: `int`.
- `h4`: indica que queda por colocar una caja de altura 4. Valores posibles: 0 o 1.	Tipo: `int`.
- `pos`: coordenadas de la casilla, valores posibles: (1, 1), (1, 2), (1, 3), (1, 4), (2, 1), (2, 2), (2, 3), (2, 4), (3, 1), (3, 2), (3, 3), (3, 4), (4, 1), (4, 2), (4, 3), (4, 4). Tipo: `coord`. -->



### Contadores (`col_counter` y `row_counter`)

Vamos a tener dos variables para los contadores, que se llamarán `col_counter` y `row_counter`, serán de tipo `int[4][2]`, y el primer índice indicará el númerod e fila o columna, respectivamente, y el segundo índice indicará el contador, que puede ir de 1 (al menos cada sujeto del borde verá una caja) a 4. El primero es el de arriba (resp. izda.), y el segundo el de abajo (resp. dcha.).

<!-- Vamos a tener dos estructuras para los contadores, que se llamarán `col_counter` y `row_counter`, y cuyos elementos serán `up`, `down` y `left`, `right`, respectivamente. Habrá uno de estos contadores por cada fila y columna del tablero, de manera adecuada, en total, 8.

#### `col_counter`

- `up`: indica el número de cajas que se ve desde arriba. Valores posibles: 1, 2, 3, 4 (siempre se ve al menos una). 
- `down`: indica el número de cajas que se ve desde abajo. Valores posibles: 1, 2, 3, 4 (siempre se ve al menos una).

#### `row_counter`

- `left`: indica el número de cajas que se ve desde la izquierda. Valores posibles: 1, 2, 3, 4 (siempre se ve al menos una).
- `right`: indica el número de cajas que se ve desde la derecha. Valores posibles: 1, 2, 3, 4 (siempre se ve al menos una).

Usaremos esta estructura para controlar en todo momento el número de cajas que ve cada uno de los miembros del marco. Al final del juego, todos los contadores deben estar a 4.

Todo esto se guardará en dos arrays, uno para las filas y otro para las columnas, con 4 entradas cada uno, del tipo `col_counter` y `row_counter` respectivamente. -->

### Input (`col_input` y `row_input`)

Vamos a tener dos variables para los inputs, que se llamarán `col_input` y `row_input`, serán de tipo `int[4][2]`, y el primer índice indicará el número de fila o columna, respectivamente, y el segundo índice indicará el contador, que puede ir de 1 (al menos cada sujeto del borde verá una caja) a 4. El primero es el de arriba (resp. izda.), y el segundo el de abajo (resp. dcha.).

<!-- 
Vamos a tener dos estructuras para el input, que se llamarán `col_input` y `row_input`, y cuyos elementos serán: `up`, `down` y `left`, `right`, respectivamente. Habrá uno de estos inputs por cada fila y columna del tablero, de manera adecuada, en total, 8.

#### `col_input`

- `up`: indica el número de cajas que se deben ver desde arriba. Valores posibles: 1, 2, 3, 4.
- `down`: indica el número de cajas que se deben desde abajo. Valores posibles: 1, 2, 3, 4.

#### `row_input`

- `left`: indica el número de cajas que se deben ver desde la izquierda. Valores posibles: 1, 2, 3, 4.
- `right`: indica el número de cajas que se deben ver desde la derecha. Valores posibles: 1, 2, 3, 4.

Esta estructura se usará para guardar el input que se nos da al principio del juego.

Todo esto se guardará en dos arrays, uno para las filas y otro para las columnas, con 4 entradas cada uno, del tipo `col_input` y `row_input` respectivamente. -->


# Variables iniciales

Tendremos varias variables al comienzo del juego, que inicializaremos de acuerdo a lo siguiente:

- `board`: tablero del juego, de tipo `int[4][4]`, con valores posibles: 0, 1, 2, 3, 4. 0 indica que la casilla está vacía, y 1, 2, 3, 4 indican que hay una caja de altura 1, 2, 3, 4 respectivamente. Inicialmente, todas las casillas estarán vacías.
- `remaining_heights`: lista de alturas restantes, de tipo `int[4][4][4]`, con posibles valores 




<!-- 
## Inicialización

### `init_game`

Esta función inicializa el tablero, poniendo todas las casillas a 0 (vacías) y todos los contadores a 0. Además, inicializa la lista de alturas restantes a [1, 2, 3, 4] (todas las alturas están disponibles). También transforma la entrada (un string  de la forma "col1up col2up col3up col4up col1down col2down col3down col4down row1left row2left row3left row4left row1right row2right row3right row4right" donde cada palabra representa un número entre 1 y 4) en 4 estructuras de tipo `col_input` y 4 de tipo `row_input`.

Todo esto se guardará en dos arrays, uno para las filas y otro para las columnas.

### `init_box`

Esta función inicializa una casilla, poniendo todos sus valores a 0. Será usada por `init_game` para inicializar el tablero.

### `init_remaining_heights`

Esta función inicializa la lista de alturas restantes a [1, 2, 3, 4] (todas las alturas están disponibles). Será usada por `init_game` para inicializar la lista de alturas restantes.

### `init_counter`

Esta función inicializa un contador, poniendo todos sus valores a 0. Será usada por `init_game` para inicializar los contadores.

### `init_input`

Esta función inicializa un input, poniendo todos sus valores a 0. Será usada por `init_game` para inicializar los inputs. -->

