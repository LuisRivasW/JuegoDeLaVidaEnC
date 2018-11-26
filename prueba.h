//#include"funciones.h"
#include <stdio.h>
#include <stdlib.h>
int PruebaVerificar()
{
    printf("La salida deberia de ser 0 0 1 0 0 1\n");
    printf("%i", verificar(0, 1));
    printf("%i", verificar(1, 0));
    printf("%i", verificar(1, 2));
    printf("%i", verificar(1, 1));
    printf("%i", verificar(1, 4));
    printf("%i\n", verificar(0, 3));
    return 0;
}

int PruebaVecinos()
{
    int **matriz;
    matriz = (int **)malloc(3 * sizeof(int *));
    int i, j;
    for (i = 0; i < 3; i++)
        matriz[i] = (int *)malloc(3 * sizeof(int));

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            matriz[i][j] = 0;
        }
    }

    matriz[0][1] = 1;
    matriz[1][1] = 1;
    matriz[0][2] = 1;
    matriz[2][1] = 1;


    // imprimirMatriz(matriz, 3, 3);

    // printf("%i\n", vecinosVivos(matriz, 2, 2, 3, 3, 1));
    // printf("%i\n", vecinosVivos(matriz, 2, 2, 3, 3, 2));
    // printf("%i\n", vecinosVivos(matriz, 2, 2, 3, 3, 3));

    logicaPrincipal(matriz, 5, 3, 3);

    return 0;
}