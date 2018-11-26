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
/**
 * matriz => La matriz  
 * n y m => Dimensiones de la matriz
 * forma=>las formas en que se va mover las celulas y matriz
 * x e y el pivote
 * */
int vecinosVivos(int **matriz, int x, int y, int n, int m, int forma)
{

    int i, j, contador = 0;
    for (i = x - 1; i < x + 2; i++)
    {
        for (j = y - 1; j < y + 2; j++)
        {
            switch (forma)
            {
            case 1:
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
                break;

            case 2:
                if (i >= 0 && i < n)
                {
                    if (j >= -1 && j <= m)
                    {
                        if (!(i == x && j == y))
                        {
                            if (j == -1)
                            {
                                contador += matriz[i][m - 1];
                            }
                            else if (j == m)
                            {
                                contador += matriz[i][0];
                            }
                            else
                                contador += matriz[i][j];
                        }
                    }
                }
                break;

            case 3:
                if (j >= 0 && j < n)
                {
                    if (i >= -1 && i <= m)
                    {
                        if (!(i == x && j == y))
                        {
                            if (i == -1)
                            {
                                contador += matriz[m - 1][j];
                            }
                            else if (i == m)
                            {
                                contador += matriz[0][j];
                            }
                            else
                                contador += matriz[i][j];
                        }
                    }
                }
                break;
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

void logicaPrincipal(int **matriz, int iteraciones, int n, int m)
{
    int i, j, conInt = 0; //conInt es el contador de iteraciones
    int **matrizAux;      //Usamos una matriz auxiliar para ir transfiriendo las celulas desde la matriz principal para asi evitar un problema de que se sobreescriba

    matrizAux = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
        matrizAux[i] = (int *)malloc(m * sizeof(int));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            matrizAux[i][j] = 0;
        }
    }

    while (conInt < iteraciones)
    {

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                matrizAux[i][j] = verificar(matriz[i][j], vecinosVivos(matriz, i, j, n, m, 1));
            }
        }
        conInt++;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                matriz[i][j] = matrizAux[i][j];
            }
        }

        printf("Iteracion numero %i \n\n", conInt);
        imprimirMatriz(matriz, n, m);
        printf("\n\n");
    }
}