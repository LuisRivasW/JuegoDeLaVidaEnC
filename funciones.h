#include <stdio.h>

int verificar(int estado, int vecinos)
{
    switch (estado)
    {
    case 1:
        if (vecinos <= 1 || vecinos >= 4)
        {
            return 0;
        }
        else
        {
            return 1;
        }
        break;
    case 0:
        if (vecinos == 3)
        {
            return 1;
        }
        else
        {
            return 0;
        }

        break;
    }

    return -1;
}
int vecinosVivos(int **matriz, int x, int y, int n, int m, int forma)
{
    int i, j, contador = 0;
    for (i = x - 1; i < x + 2; i++)
    {
        for (j = y - 1; j < y + 2; j++)
        {

            if (i >= 0 && i < n)
            {
                if (j >= 0 && j < m)
                {
                    if (!(i == x && j == y))
                    {
                        contador += matriz[i][j];
                    }
                }
            }
        }
    }
    return contador;
}

void imprimirMatriz(int **matriz, int n, int m)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%i |", matriz[i][j]);
        }
        printf("\n");
    }
}
