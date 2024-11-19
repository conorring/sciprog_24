#include <stdio.h>
#include <stdlib.h>
#define MAX_FILE_NAME 100
#include "magic_square.h"

int getlines(char filename[MAX_FILE_NAME]);

int main(){  

    //define our file variable
    FILE *f;  
    char filename[MAX_FILE_NAME];
    printf("Enter file name: ");
    scanf("%s", filename);
    
    // ##! n function which gets the number of lines
    int n = getlines(filename);

    // TODO: Open the file 
    f = fopen(filename, "r");

    int i;
    // TODO: Allocating a matrix for storing the magic square
    // as an array of pointers, where each pointer is a row 
    int **magic_square = (int **) malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        magic_square[i] = (int *) malloc(n * sizeof(int));
    }

    // TODO:inputting integer data into the matrix;
    int j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            fscanf(f, "%d", &magic_square[i][j]);
        }
    }    


    int is_square_magic = isMagicSquare(magic_square, n);     

    if (is_square_magic == 1)
    {
        printf("Square is magic\n");
    }
    if (is_square_magic == 0)
    {
        printf("Square is not magic\n");
    }


    // TODO: Freeing each row separately before freeing the array of pointers
    for (i = 0; i < n; i++)
    {
        free(magic_square[i]);
    }

    free(magic_square);
    // TODO:Close the file
    fclose(f);

    return 0;
}  

//##!

int getlines(char filename[MAX_FILE_NAME]) {
    FILE *fp;
    fp = fopen(filename, "r");
    
    int ch_read;
    int count = 0;

    while( (ch_read = fgetc(fp)) != EOF)
    {
        if (ch_read == '\n'){
            count++;
        }
    }

    printf("No. lines, %d\n", count);
    fclose(fp); 
    return count;
}
