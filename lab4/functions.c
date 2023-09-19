#include "functions.h"

int** readFile(FILE* fp, int *size)
{
    fscanf(fp, "%d", &size);
    int num = *size;
    int index = 0;
    
    int** mat = (int**)malloc(num * sizeof(int));
    for(index = 0; index < num; index++)
        mat[index] = (int*)malloc(num * sizeof(int)); 

    int row = 0; 
    int col = 0;
    for(; row < num; row++)
    {
        for(; col < num; col++)
        {
            fscanf(fp, "%d", mat[row][col]);
        }
    }
    return mat;
}


void printMatrix (int** mat, int num)
{
    int row = 0; 
    int col = 0;
    for(row = 0; row < num; row++)
    {
        for(col = 0; col < num; col++)
        {
            printf("%.2d\t", mat[row][col]);
        }
        printf("\n");
    }
    
}