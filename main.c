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


// We first declare the functions and the variables we are going to use





int	main(argc, argv)
{
// Variables

// -----------------------------------------

int		**board;
int		***remaining_heights;
int		**remaining_heights_row;
int		**col_counter;
int		**row_counter;
int		**col_input;
int		**row_input;
int		row;
int		col;
int		yesno;
int		height;

// -----------------------------------------




// Allocation of memory
// -----------------------------------------


// Allocate memory for the array board
board = malloc(4 * sizeof(int *));
// Allocate memory for each row
for (row = 0; row < 4; row++)
	board[row] = malloc(4 * sizeof(int));
// Initialize array
for (row = 0; row < 4; row++)
	for (col = 0; col < 4; col++)
		board[row][col] = 0;


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
			remaining_heights[row][col][height] = 0;


// Allocate memory for the array remaining_heights_row
remaining_heights_row = malloc(4 * sizeof(int *));
// Allocate memory for the first dimension
for (row = 0; row < 4; row++)
	remaining_heights_row[row] = malloc(4 * sizeof(int));
// Allocate memory for the second dimension
for (row = 0; row < 4; row++)
	remaining_heights_row[row] = malloc(4 * sizeof(int));


// Allocate memory for the array col_counter
col_counter = malloc(4 * sizeof(int *));
// Allocate memory for each row
for (row = 0; row < 4; row++)
	col_counter[row] = malloc(2 * sizeof(int));
// Initialize array
for (row = 0; row < 4; row++)
	for (col = 0; col < 2; col++)
		col_counter[row][col] = 0;


// Allocate memory for the array row_counter
row_counter = malloc(4 * sizeof(int *));
// Allocate memory for each row
for (row = 0; row < 4; row++)
	row_counter[row] = malloc(2 * sizeof(int));
// Initialize array
for (row = 0; row < 4; row++)
	for (col = 0; col < 2; col++)
		row_counter[row][col] = 0;


// Allocate memory for the array col_input
col_input = malloc(4 * sizeof(int *));
// Allocate memory for each row
for (row = 0; row < 4; row++)
	col_input[row] = malloc(4 * sizeof(int));
// Initialize array
for (row = 0; row < 4; row++)
	for (col = 0; col < 4; col++)
		col_input[row][col] = 0;


// Allocate memory for the array row_input
row_input = malloc(4 * sizeof(int *));
// Allocate memory for each row
for (row = 0; row < 4; row++)
	row_input[row] = malloc(4 * sizeof(int));
// Initialize array
for (row = 0; row < 4; row++)
	for (col = 0; col < 4; col++)
		row_input[row][col] = 0;


// -----------------------------------------



int solver(int **col_input, int **row_input)
{
	int row;
	int col;
	int height;
	int yesno;

	yesno = 0;
	row = 0;
	col = 0;
	height = 0;

	// if (board[0][0] == 0)
	// {
	// 	board[0][0] = 1;
	// 	yesno = 1;
	// }
	// else if (board[0][1] == 0)
	// {
	// 	board[0][1] = 1;
	// 	yesno = 1;
	// }
	// else if (board[0][2] == 0)
	// {
	// 	board[0][2] = 1;
	// 	yesno = 1;
	// }
	// else if (board[0][3] == 0)
	// {
	// 	board[0][3] = 1;
	// 	yesno = 1;
	// }
	// else if (board[1][0] == 0)
	// {
	// 	board[1][0] = 1;
	// 	yesno = 1;
	// }
	// else if (board[1][1] == 0)
	// {
	// 	board[1][1] = 1;
	// 	yesno = 1;
	// }
	// else if (board[1][2] == 0)
	// {
	// 	board[1][2] = 1;
	// 	yesno = 1;
	// }
	// else if (board[1][3] == 0)
	// {
	// 	board[1][3] = 1;
	// 	yesno = 1;
	// }
	// else if (board[2][0] == 0)
	// {
	// 	board[2][0] = 1;
	// 	yesno = 1;
	// }
	// else if (board[2][1] == 0)
	// {
	// 	board[2][1] = 1;




}