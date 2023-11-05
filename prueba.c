// // declaro e inicializo un puntero a un array de enteros que cambiaré en la función prueba
// // y lo imprimo en el main, antes y después de llamar a la función prueba


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int **board;
    int i, j;

    // allocate memory for array of pointers
    board = malloc(4 * sizeof(int *));

    // allocate memory for each row
    for (i = 0; i < 4; i++)
        board[i] = malloc(4 * sizeof(int));

    // initialize array
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            board[i][j] = i * 4 + j;

    // print array
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            printf("%2d ", board[i][j]);
        printf("\n");
    }

	// ahora cambio el valor de la posición 0,0 y la posición 3,3, les sumo 30 a cada una. Luego imprimo el array de nuevo, con write

	board[0][0] = board[0][0] + 30;
	board[3][3] = board[3][3] + 30;

	// print array

	write(1, "\n", 1);
	write(1, "\n", 1);

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++){
			printf("%2d ", board[i][j]);
			// write(1, &board[i][j], 1);
		}
		printf("\n");
	}


    // free array of pointers
    for (i = 0; i < 4; i++)
        free(board[i]);
    free(board);

    return 0;
}




// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>





// void	prueba(int *pvar)
// 	{
// 		*pvar = 5;
// 	}

// int	main(void)
// {
// 	int	*p;

// 	p = malloc(sizeof(int));

// 	printf("p antes de la prueba = %d\n", *p);
// 	prueba(p);
// 	printf("p despues de la prueba = %d\n", *p);
// 	return (0);
// }

// Replicate the above code but for a 2D array of integers instead of a single integer.


// // The answer is here:
// // https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
// // https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
// // https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
// // https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new