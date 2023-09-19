#include <stdio.h> 
#include <stdlib.h>


int main(int argc, char** argv)
{
    printf("cheking command line arguments\n");

    if (argc < 3)
    { 
        printf("not enought argument: ./exe filename\n"); 
        exit(-1);
    }

    FILE* fp = fopen(argv[1], "w");
    if(fp==NULL)
    {
        printf("fp did not open\n"); 
        exit(-1);
    }
    int size = 0;
    int **mat = readFile(fp, &size);
    printMatrix(mat, size);

    return 0;
}
