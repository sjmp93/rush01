/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javimar2 <javimar2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:30:11 by javimar2          #+#    #+#             */
/*   Updated: 2023/11/05 14:30:14 by javimar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>


// We first declare the functions and the variables we are going to use


main(int argc, char *argv[]) {

// Variables

// -----------------------------------------


int		colup_input[4];
int		coldown_input[4];
int		rowleft_input[4];
int		rowright_input[4];
int		row;
int		col;
int		yesno;
int		height;

// -----------------------------------------




// Allocation of memory
// -----------------------------------------


int mallocation(int **board, int *colup_counter, int *coldown_counter, int *rowleft_counter, int *rowright_counter)
{
	// Allocate memory for the array board
	board = malloc(4 * sizeof(int *));
	// Allocate memory for each row
	for (row = 0; row < 4; row++)
		board[row] = malloc(4 * sizeof(int));
	// Initialize array
	for (row = 0; row < 4; row++)
		for (col = 0; col < 4; col++)
			board[row][col] = 0;


	// Allocate memory for the array colup_counter
	col_counter = malloc(4 * sizeof(int *));
	// Allocate memory for the array coldown_counter
	coldown_counter = malloc(4 * sizeof(int *));

	// Initialize arrays
	for (col = 0; col < 4; col++)
		col_counter[col] = 0;
		coldown_counter[col] = 0;


	// Allocate memory for the array rowleft_counter
	rowleft_counter = malloc(4 * sizeof(int *));
	// Allocate memory for the array rowright_counter
	rowright_counter = malloc(4 * sizeof(int *));

	// Initialize array
	for (row = 0; row < 4; row++)
		rowright_counter[row] = 0;
		rowleft_counter[row] = 0;
}


// Allocate memory for the array remaining_heights
	remaining_heights = malloc(4 * sizeof(int *));
	// Allocate memory for the first dimension
	for (row = 0; row < 4; row++)
		remaining_heights[row] = malloc(4 * sizeof(int));
	// Allocate memory for the second dimension
	for (row = 0; row < 4; row++)
		for (col = 0; col < 4; col++)
			remaining_heights[row][col] = malloc(4 * sizeof(int));
	// Initialize array
	for (row = 0; row < 4; row++)
		for (col = 0; col < 4; col++)
			for (int height = 0; height < 4; height++)
				remaining_heights[row][col][height] = 1;
			// todas las entradas están disponibles, por eso se inicializan a 1


	// Allocate memory for the array remaining_heights_row
	remaining_heights_row = malloc(4 * sizeof(int *));
	// Allocate memory for the first dimension
	for (row = 0; row < 4; row++)
		remaining_heights_row[row] = malloc(4 * sizeof(int));
	// Initialize array
	for (row = 0; row < 4; row++)
		for (col = 0; col < 4; col++)
			remaining_heights_row[row][col] = 1;
			// todas las entradas están disponibles, por eso se inicializan a 4



// -----------------------------------------

colup_input = [4, 3, 2, 1];
coldown_input = [1, 2, 2, 2];

rowleft_input = [4, 3, 2, 1];
rowright_input = [1, 2, 2, 2];

// -----------------------------------------



// Vision

int ft_vision_up(int **board, int col, int *colup_counter) {

	// 1. Arriba (colup_counter)
		// Cuenta cuántas casillas en esa columna cumplen que su valor de board es mayor que el de todas las que están encima de ella.

	int	i;
	int count;
	int itsbigger;
	i = 0;
	j = 0;
	itsbigger = 0;

	count = 0;

	
	while (i < 4)
	{
		while (j < i)
		{
			if (board[i][col] > board[j][col])
				itsbigger = 1;
			else
				itsbigger = 0;
			j++;
		}
		if (itsbigger == 1)
			count++;
		i++;
	}
	colup_counter[col] = count;

}


int ft_vision_down(int **board, int col, int *coldown_counter) {

	// 2. Abajo (coldown_counter)
		// Cuenta cuántas casillas en esa columna cumplen que su valor de board es mayor que el de todas las que están debajo de ella.

	int	i;
	int count;
	int itsbigger;
	i = 0;
	j = 0;
	itsbigger = 0;

	count = 0;

	while (i < 4)
	{
		while ((j > i) && (j < 4))
		{
			if (board[i][col] > board[j][col])
				itsbigger = 1;
			else
				itsbigger = 0;
			j++;
		}
		if (itsbigger == 1)
			count++;
		i++;
	}
	coldown_counter[col] = count;
}

int ft_vision_left(int **board, int row, int *rowleft_counter) {
	// 3. Izquierda (rowleft_counter)
		// Cuenta cuántas casillas en esa fila cumplen que su valor de board es mayor que el de todas las que están a su izquierda.


	int	i;
	int count;
	int itsbigger;
	i = 0;
	j = 0;
	itsbigger = 0;

	count = 0;

	while (i < 4)
	{
		while (j < i)
		{
			if (board[row][i] > board[row][j])
				itsbigger = 1;
			else
				itsbigger = 0;
			j++;
		}
		if (itsbigger == 1)
			count++;
		i++;
	}

	rowleft_counter[row] = count;

}


int ft_vision_right(int **board, int row, int *rowright_counter) {
	// 4. Derecha (rowright_counter)
		// Cuenta cuántas casillas en esa fila cumplen que su valor de board es mayor que el de todas las que están a su derecha.

	int	i;
	int count;
	int itsbigger;
	i = 0;
	j = 0;
	itsbigger = 0;

	count = 0;

	while (i < 4)
	{
		while ((j > i) && (j < 4))
		{
			if (board[row][i] > board[row][j])
				itsbigger = 1;
			else
				itsbigger = 0;
			j++;
		}
		if (itsbigger == 1)
			count++;
		i++;
	}

	rowright_counter[row] = count;

	return (0);
}

// TODAS

int ft_vision(int **board, int row, int col, int *colup_counter, int *coldown_counter, int *rowleft_counter, int *rowright_counter) {
	// Cuenta cuántas cajas ve cada uno en cada uno de los pasos:
	
	ft_vision_up(board, col, colup_counter);
	ft_vision_down(board, col, coldown_counter);
	ft_vision_left(board, row, rowleft_counter);
	ft_vision_right(board, row, rowright_counter);

	return (0);
}
	



// No repetición

int ft_check_repeated_in_row(int **board, int row, int col) {
	// Comprueba que el número que se va a poner en esa casilla no esté ya en la fila.
	int i;
	int itsrepeated;
	i = 0;
	itsrepeated = 0;

	while (i < 4)
	{
		if (board[row][i] == board[row][col])
			itsrepeated = 1;
		i++;
	}

	return (itsrepeated);
}

int ft_check_repeated_in_col(int **board, int row, int col) {
	// Comprueba que el número que se va a poner en esa casilla no esté ya en la columna.
	int i;
	int itsrepeated;
	i = 0;
	itsrepeated = 0;

	while (i < 4)
	{
		if (board[i][col] == board[row][col])
			itsrepeated = 1;
		i++;
	}

	return (itsrepeated);
}

// TODAS

int ft_check_repeated(int **board, int row, int col) {
	// Comprueba que el número que se va a poner en esa casilla no esté ya en la fila ni en la columna.
	int itsrepeated;
	itsrepeated = 0;

	if (ft_check_non_repeated_in_row(board, row, col) == 1)
		itsrepeated = 1;
	if (ft_check_non_repeated_in_col(board, row, col) == 1)
		itsrepeated = 1;

	return (itsrepeated);
}


int ft_check_non_repeated(int **board, int row, int col)
{
	return (ft_check_repeated(board, row, col) == 0);
}


// Contadores parciales

int ft_check_colup_count(int **board, int *colup_input, int *colup_counter) {
	// Comprueba que el número que se va a poner en esa casilla cumple con la condición de que el número de cajas que ve en esa columna es el que se indica en colup_input.
	int itsok;
	itsok = 1;
	int col;
	col = 0;

	while ((col < 4) && (itsok == 1))
	{	
		if (colup_input[col] <= colup_counter[col])
			itsok = 1;
		else
			itsok = 0;
		col++;
	}
	return (itsok);
}

int ft_check_coldown_count(int **board, int *coldown_input, int *coldown_counter) {
	// Comprueba que el número que se va a poner en esa casilla cumple con la condición de que el número de cajas que ve en esa columna es el que se indica en coldown_input.
	int itsok;
	itsok = 1;
	int col;
	col = 0;

	while ((col < 4) && (itsok == 1))
	{
		if (coldown_input[col] <= coldown_counter[col])
			itsok = 1;
		else
			itsok = 0;
		col++;
	}
	return (itsok);
}

int ft_check_rowleft_count(int **board, int *rowleft_input, int *rowleft_counter) {
	// Comprueba que el número que se va a poner en esa casilla cumple con la condición de que el número de cajas que ve en esa fila es el que se indica en rowleft_input.
	int itsok;
	itsok = 1;
	int row;
	row = 0;

	while ((row < 4) && (itsok == 1))
	{
		if (rowleft_input[row] <= rowleft_counter[row])
			itsok = 1;
		else
			itsok = 0;
		row++;
	}
	return (itsok);
}

int ft_check_rowright_count(int **board, int *rowright_input, int *rowright_counter) {
	// Comprueba que el número que se va a poner en esa casilla cumple con la condición de que el número de cajas que ve en esa fila es el que se indica en rowright_input.
	int itsok;
	itsok = 1;
	int row;
	row = 0;

	while ((row < 4) && (itsok == 1))
	{
		if (rowright_input[row] <= rowright_counter[row])
			itsok = 1;
		else
			itsok = 0;
		row++;
	}
	return (itsok);
}

// TODAS

int ft_check_count(int **board, int *colup_input, int *coldown_input, int *rowleft_input, int *rowright_input, int *colup_counter, int *coldown_counter, int *rowleft_counter, int *rowright_counter) {
	// Comprueba que el número que se va a poner en esa casilla cumple con la condición de que el número de cajas que ve en esa fila y columna es el que se indica en colup_input, coldown_input, rowleft_input y rowright_input.
	int itsok;
	itsok = 1;

	if (ft_check_colup_count(board, colup_input, colup_counter) == 1)
		itsok = 1;
	else
		itsok = 0;
	if (ft_check_coldown_count(board, coldown_input, coldown_counter) == 1)
		itsok = 1;
	else
		itsok = 0;
	if (ft_check_rowleft_count(board, rowleft_input, rowleft_counter) == 1)
		itsok = 1;
	else
		itsok = 0;
	if (ft_check_rowright_count(board, rowright_input, rowright_counter) == 1)
		itsok = 1;
	else
		itsok = 0;

	return (itsok);
}




// Contadores





int ft_check_colup_count_end(int **board, int *colup_input, int *colup_counter) {
	// Comprueba que el número que se va a poner en esa casilla cumple con la condición de que el número de cajas que ve en esa columna es el que se indica en colup_input.
	int itsok;
	itsok = 1;
	int col;
	col = 0;

	while ((col < 4) && (itsok == 1))
	{	
		if (colup_input[col] == colup_counter[col])
			itsok = 1;
		else
			itsok = 0;
		col++;
	}
	return (itsok);
}

int ft_check_coldown_count_end(int **board, int *coldown_input, int *coldown_counter) {
	// Comprueba que el número que se va a poner en esa casilla cumple con la condición de que el número de cajas que ve en esa columna es el que se indica en coldown_input.
	int itsok;
	itsok = 1;
	int col;
	col = 0;

	while ((col < 4) && (itsok == 1))
	{
		if (coldown_input[col] == coldown_counter[col])
			itsok = 1;
		else
			itsok = 0;
		col++;
	}
	return (itsok);
}

int ft_check_rowleft_count_end(int **board, int *rowleft_input, int *rowleft_counter) {
	// Comprueba que el número que se va a poner en esa casilla cumple con la condición de que el número de cajas que ve en esa fila es el que se indica en rowleft_input.
	int itsok;
	itsok = 1;
	int row;
	row = 0;

	while ((row < 4) && (itsok == 1))
	{
		if (rowleft_input[row] == rowleft_counter[row])
			itsok = 1;
		else
			itsok = 0;
		row++;
	}
	return (itsok);
}

int ft_check_rowright_count_end(int **board, int *rowright_input, int *rowright_counter) {
	// Comprueba que el número que se va a poner en esa casilla cumple con la condición de que el número de cajas que ve en esa fila es el que se indica en rowright_input.
	int itsok;
	itsok = 1;
	int row;
	row = 0;

	while ((row < 4) && (itsok == 1))
	{
		if (rowright_input[row] == rowright_counter[row])
			itsok = 1;
		else
			itsok = 0;
		row++;
	}
	return (itsok);
}

// TODAS

int ft_check_count_end(int **board, int *colup_input, int *coldown_input, int *rowleft_input, int *rowright_input, int *colup_counter, int *coldown_counter, int *rowleft_counter, int *rowright_counter) {
	// Comprueba que el número que se va a poner en esa casilla cumple con la condición de que el número de cajas que ve en esa fila y columna es el que se indica en colup_input, coldown_input, rowleft_input y rowright_input.
	int itsok;
	itsok = 1;

	if (ft_check_colup_count(board, colup_input, colup_counter) == 1)
		itsok = 1;
	else
		itsok = 0;
	if (ft_check_coldown_count(board, coldown_input, coldown_counter) == 1)
		itsok = 1;
	else
		itsok = 0;
	if (ft_check_rowleft_count(board, rowleft_input, rowleft_counter) == 1)
		itsok = 1;
	else
		itsok = 0;
	if (ft_check_rowright_count(board, rowright_input, rowright_counter) == 1)
		itsok = 1;
	else
		itsok = 0;

	return (itsok);
}



int ft_check_everything(int **board, int *colup_input, int *coldown_input, int *rowleft_input, int *rowright_input, int *colup_counter, int *coldown_counter, int *rowleft_counter, int *rowright_counter) {
	// Comprueba que el número que se va a poner en esa casilla cumple con todas las condiciones.
	int itsok;
	itsok = 1;

	if (ft_check_non_repeated(board, row, col) == 1)
		itsok = 1;
	else
		return (0);
	if (ft_check_count(board, colup_input, coldown_input, rowleft_input, rowright_input, colup_counter, coldown_counter, rowleft_counter, rowright_counter) == 1)
		itsok = 1;
	else
		return (0);
	if ()

	return (itsok);
}


	int		**board;
	int		*colup_counter;
	int		*coldown_counter;
	int		*rowleft_counter;
	int		*rowright_counter;

	// Allocate memory for the arrays
	mallocation(board, remaining_heights, remaining_heights_row, colup_counter, coldown_counter, rowleft_counter, rowright_counter);



// Resolución

int ft_solve(int	**board, int	*colup_counter,	int	*coldown_counter,	int		*rowleft_counter, int		*rowright_counter, int row, int col,  int *colup_input, int *coldown_input, int *rowleft_input, int *rowright_input, int ***remaining_heights, int **remaining_heights_row) {


	//  Resolvemos el problema con el algoritmo que hemos pensado.


	

	int height;
	int row;
	int col;
	int tempheight;
	height = 0;
	tempheight = 0;
	row = 0;
	col = 0;

	// Empezamos en la casilla row, col
	// Si el valor de la casilla es 0, entonces probamos a ponerle el primer elemento que la lista remaining_heights_row indique que está disponible. Usualmente será el 1. 
	// Si el valor de la casilla es distinto de 0, entonces pasamos a la siguiente casilla, sumando 1 a la columna. Si la columna es 4, entonces pasamos a la siguiente fila, sumando 1 a la fila y poniendo la columna a 0. Si la casilla tiene el valor `altura`, entonces ponemos a 0 la entrada de remaining_heights_row que corresponda a esa fila y a esa altura, es decir, remaining_heights_row[row][altura-1] = 0 (porque la altura 1 está en la posición 0, la altura 2 en la posición 1, etc.).

	if (row == -1)
		return (0);
	if (row == 4)
		return (1);
	if (col == -1)
		return (ft_solve(board, colup_counter, coldown_counter, rowleft_counter, rowright_counter, row -1, 3, colup_input, coldown_input, rowleft_input, rowright_input, remaining_heights, remaining_heights_row));
	if (col == 4)
		return (ft_solve(board, colup_counter, coldown_counter, rowleft_counter, rowright_counter, row + 1, 0, colup_input, coldown_input, rowleft_input, rowright_input, remaining_heights, remaining_heights_row));
	if (board[row][col] != 0)
	{
		// ponemos la altura de esta posición a 0 en la lista de alturas disponibles por fila y en la lista de alturas disponibles por para la SIGUIENTE casilla (cuidado de no hacerlo con la presente casilla)
		remaining_heights_row[row][board[row][col]-1] = 0;
		remaining_heights[row][col+1][board[row][col]-1] = 0;
		return (ft_solve(board, colup_counter, coldown_counter, rowleft_counter, rowright_counter, row, col + 1, colup_input, coldown_input, rowleft_input, rowright_input, remaining_heights, remaining_heights_row));
	}
	else
	{
		// Ponemos el primer la altura correspondiente a la primera entrada no nula de remaining_heights[row][col] y ponemos dicha entrada a 0. Ponemos a 0 la entrada correspondiente a la altura en remaining_heights_row[row][].
		while ((height < 4) && (remaining_heights[row][col][height] == 0))
			height++;
		if (height == 4)
			// no hay altura disponible para esta casilla, así que tenemos que volver atrás
			return ft_solve(board, colup_counter, coldown_counter, rowleft_counter, rowright_counter, row , col - 1, colup_input, coldown_input, rowleft_input, rowright_input, remaining_heights, remaining_heights_row);
		else
		{
			// ponemos la altura de esta posición a 0 en la lista de alturas disponibles por fila y en la lista de alturas disponibles por para la SIGUIENTE casilla (cuidado de no hacerlo con la presente casilla)
			remaining_heights_row[row][height] = 0;
			remaining_heights[row][col+1][height] = 0;
			board[row][col] = height + 1;

			// miramos cuántas cajas ven los de alrededor
			ft_vision(board, row, col, colup_counter, coldown_counter, rowleft_counter, rowright_counter);
			// comprobamos que todo está bien
			if (ft_check_everything(board, colup_input, coldown_input, rowleft_input, rowright_input, colup_counter, coldown_counter, rowleft_counter, rowright_counter) == 0)
				// si no está bien, volvemos atrás
				return ft_solve(board, colup_counter, coldown_counter, rowleft_counter, rowright_counter,row, col -1, colup_input, coldown_input, rowleft_input, rowright_input, remaining_heights, remaining_heights_row);
			else
				// si está bien, seguimos adelante
				return (ft_solve(board, colup_counter, coldown_counter, rowleft_counter, rowright_counter, row, col + 1, colup_input, coldown_input, rowleft_input, rowright_input, remaining_heights, remaining_heights_row));
		}
	}


	return (1);

}

// -----------------------------------------

	// Si todo va bien, pinta el board usando la función write.

if (ft_solve(board, colup_counter, coldown_counter, rowleft_counter, rowright_counter, 0, 0, colup_input, coldown_input, rowleft_input, rowright_input, remaining_heights, remaining_heights_row))
{
	// print array
	for (row = 0; row < 4; row++)
	{
		for (col = 0; col < 4; col++)
			printf("%2d ", board[row][col]);
		printf("\n");
	}
}
else
{
	write(1, "Error\n", 6);
	return (0);

}

return (0);
}