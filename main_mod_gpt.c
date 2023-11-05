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
#include <stdio.h>


// We first declare the functions and the variables we are going to use




// Memory allocation


// Pasamos la variable por referencia para que se modifique en la función

int mallocation(int ***board, int ***colup_counter, int ***coldown_counter, int ***rowleft_counter, int ***rowright_counter)
{
    int row;
    int col;

    // Allocate memory for the array board
    *board = (int **)malloc(4 * sizeof(int *));
    // Allocate memory for each row
    for (row = 0; row < 4; row++)
        (*board)[row] = (int *)malloc(4 * sizeof(int));
    // Initialize array
    for (row = 0; row < 4; row++)
        for (col = 0; col < 4; col++)
            (*board)[row][col] = 0;

    // Allocate memory for the array colup_counter
    *colup_counter = (int **)malloc(4 * sizeof(int *));
    // Allocate memory for each row in colup_counter
    for (col = 0; col < 4; col++)
        (*colup_counter)[col] = (int *)malloc(sizeof(int));

    // Allocate memory for the array coldown_counter
    *coldown_counter = (int **)malloc(4 * sizeof(int *));
    // Allocate memory for each row in coldown_counter
    for (col = 0; col < 4; col++)
        (*coldown_counter)[col] = (int *)malloc(sizeof(int));

    // Initialize arrays
    for (col = 0; col < 4; col++)
    {
        (*colup_counter)[col][0] = 0;
        (*coldown_counter)[col][0] = 0;
    }

    // Allocate memory for the array rowleft_counter
    *rowleft_counter = (int **)malloc(4 * sizeof(int *));
    // Allocate memory for each row in rowleft_counter
    for (row = 0; row < 4; row++)
        (*rowleft_counter)[row] = (int *)malloc(sizeof(int));

    // Allocate memory for the array rowright_counter
    *rowright_counter = (int **)malloc(4 * sizeof(int *));
    // Allocate memory for each row in rowright_counter
    for (row = 0; row < 4; row++)
        (*rowright_counter)[row] = (int *)malloc(sizeof(int));

    // Initialize arrays
    for (row = 0; row < 4; row++)
    {
        (*rowleft_counter)[row][0] = 0;
        (*rowright_counter)[row][0] = 0;
    }

    return 0;
}






// Vision

void ft_vision_up(int **board, int col, int *colup_counter) {

	// 1. Arriba (colup_counter)
		// Cuenta cuántas casillas en esa columna cumplen que su valor de board es mayor que el de todas las que están encima de ella.

	int	i;
	int	j;
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


void ft_vision_down(int **board, int col, int *coldown_counter) {

	// 2. Abajo (coldown_counter)
		// Cuenta cuántas casillas en esa columna cumplen que su valor de board es mayor que el de todas las que están debajo de ella.

	int	i;
	int	j;
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

void ft_vision_left(int **board, int row, int *rowleft_counter) {
	// 3. Izquierda (rowleft_counter)
		// Cuenta cuántas casillas en esa fila cumplen que su valor de board es mayor que el de todas las que están a su izquierda.


	int	i;
	int	j;
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


void ft_vision_right(int **board, int row, int *rowright_counter) {
	// 4. Derecha (rowright_counter)
		// Cuenta cuántas casillas en esa fila cumplen que su valor de board es mayor que el de todas las que están a su derecha.

	int	i;
	int	j;
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

	if (ft_check_repeated_in_row(board, row, col) == 1)
		itsrepeated = 1;
	if (ft_check_repeated_in_col(board, row, col) == 1)
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




int ft_check_everything(int **board, int *colup_input, int *coldown_input, int *rowleft_input, int *rowright_input, int *colup_counter, int *coldown_counter, int *rowleft_counter, int *rowright_counter, int row, int col) {
	// Comprueba que el número que se va a poner en esa casilla cumple con todas las condiciones.
	int	itsok;
	itsok = 1;

	if (ft_check_non_repeated(board, row, col) == 1)
		itsok = 1;
	else
		return (0);
	if (ft_check_count(board, colup_input, coldown_input, rowleft_input, rowright_input, colup_counter, coldown_counter, rowleft_counter, rowright_counter) == 1)
		itsok = 1;
	else
		return (0);
	return (itsok);
}



// -----------------------------------------

// Resolución
int ft_solve(int ***board, int **colup_counter, int **coldown_counter, int **rowleft_counter, int **rowright_counter, int row, int col, int *colup_input, int *coldown_input, int *rowleft_input, int *rowright_input, int remaining_heights[4][4][4], int remaining_heights_row[4][4])
{
    if (row == -1)
        return 0;
    if (row == 4)
        return 1;
    if (col == -1)
        return ft_solve(board, colup_counter, coldown_counter, rowleft_counter, rowright_counter, row - 1, 3, colup_input, coldown_input, rowleft_input, rowright_input, remaining_heights, remaining_heights_row);
    if (col == 4)
        return ft_solve(board, colup_counter, coldown_counter, rowleft_counter, rowright_counter, row + 1, 0, colup_input, coldown_input, rowleft_input, rowright_input, remaining_heights, remaining_heights_row);

    int height = 0;

    // Find the first available height
    while (height < 4 && remaining_heights[row][col][height] == 0)
        height++;

    if (height == 4)
        return ft_solve(board, colup_counter, coldown_counter, rowleft_counter, rowright_counter, row, col - 1, colup_input, coldown_input, rowleft_input, rowright_input, remaining_heights, remaining_heights_row);
    else
    {
        remaining_heights_row[row][col] = 0;
        remaining_heights[row][col + 1][height] = 0;
        (*board)[row][col] = height + 1;

        ft_vision(*board, row, col, *colup_counter, *coldown_counter, *rowleft_counter, *rowright_counter);

        if (ft_check_everything(*board, colup_input, coldown_input, rowleft_input, rowright_input, *colup_counter, *coldown_counter, *rowleft_counter, *rowright_counter, row, col) == 0)
        {
            remaining_heights_row[row][col] = 1;
            remaining_heights[row][col + 1][height] = 1;
            (*board)[row][col] = 0;
            return ft_solve(board, colup_counter, coldown_counter, rowleft_counter, rowright_counter, row, col - 1, colup_input, coldown_input, rowleft_input, rowright_input, remaining_heights, remaining_heights_row);
        }
        else
            return ft_solve(board, colup_counter, coldown_counter, rowleft_counter, rowright_counter, row, col + 1, colup_input, coldown_input, rowleft_input, rowright_input, remaining_heights, remaining_heights_row);
    }
}


int main(void) {

	// Variables
	// -----------------------------------------

	printf("Declarando variables: ");

	int		colup_input[4];
	int		coldown_input[4];
	int		rowleft_input[4];
	int		rowright_input[4];
	int		row;
	int		col;
	int		yesno;
	int		height;

	// -----------------------------------------


	printf("Declarando variables importantes: ");
	// Important variables

	int		**board;
	int		**colup_counter;
	int		**coldown_counter;
	int		**rowleft_counter;
	int		**rowright_counter;
	int		remaining_heights[4][4][4];
	int		remaining_heights_row[4][4];





	// // Allocate memory for the array remaining_heights
	// remaining_heights = malloc(4 * sizeof(int *));
	// // Allocate memory for the first dimension
	// for (row = 0; row < 4; row++)
	// 	remaining_heights[row] = malloc(4 * sizeof(int));
	// // Allocate memory for the second dimension
	// for (row = 0; row < 4; row++)
	// 	for (col = 0; col < 4; col++)
	// 		remaining_heights[row][col] = malloc(4 * sizeof(int));
	// Initialize array
	for (row = 0; row < 4; row++)
		for (col = 0; col < 4; col++)
			for (int height = 0; height < 4; height++)
				remaining_heights[row][col][height] = 1;
			// todas las entradas están disponibles, por eso se inicializan a 1


	// // Allocate memory for the array remaining_heights_row
	// remaining_heights_row = malloc(4 * sizeof(int *));
	// // Allocate memory for the first dimension
	// for (row = 0; row < 4; row++)
	// 	remaining_heights_row[row] = malloc(4 * sizeof(int));
	// Initialize array
	for (row = 0; row < 4; row++)
		for (col = 0; col < 4; col++)
			remaining_heights_row[row][col] = 1;
			// todas las entradas están disponibles, por eso se inicializan a 4



	// -----------------------------------------




	// colup_input = [4, 3, 2, 1];
	// coldown_input = [1, 2, 2, 2];

	// rowleft_input = [4, 3, 2, 1];
	// rowright_input = [1, 2, 2, 2];


	colup_input[0] = 4;
	colup_input[1] = 3;
	colup_input[2] = 2;
	colup_input[3] = 1;

	coldown_input[0] = 1;
	coldown_input[1] = 2;
	coldown_input[2] = 2;
	coldown_input[3] = 2;

	rowleft_input[0] = 4;
	rowleft_input[1] = 3;
	rowleft_input[2] = 2;
	rowleft_input[3] = 1;

	rowright_input[0] = 1;
	rowright_input[1] = 2;
	rowright_input[2] = 2;
	rowright_input[3] = 2;




	// -----------------------------------------


	// Allocate memory for the arrays
mallocation(&board, &colup_counter, &coldown_counter, &rowleft_counter, &rowright_counter);

	// -----------------------------------------

	// Si todo va bien, pinta el board usando la función write.
	row = 0;
	col = 0;
	if (ft_solve(&board, colup_counter, coldown_counter, rowleft_counter, rowright_counter, 0, 0, colup_input, coldown_input, rowleft_input, rowright_input, remaining_heights, remaining_heights_row))
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