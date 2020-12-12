#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int dimensao, soma_desejada, soma = 0, verifica = 1;
    int i, j, k, l;
    scanf("%d", &dimensao);

    soma_desejada = (dimensao * ((dimensao * dimensao) + 1)) / 2;

    int mat[dimensao][dimensao];
    
    //verifica se o número está dentro do intervalo [1, dimensão*dimensão] e se ele é distinto dos outros
    for (i = 0; i < dimensao && verifica; i++)
    {
        for (j = 0; j < dimensao; j++)
        {
            scanf("%d", &mat[i][j]);
            if (mat[i][j] < 1 || mat[i][j] > (dimensao * dimensao))
                verifica = 0;
            else
            {
                for (k = 0; k < i; k++)
                    for (l = 0; l < j; l++)
                        if (mat[i][j] == mat[k][l])
                            verifica = 0;
            }
        }
    }
    if (verifica)
    {
        //verifica a soma das linhas
        for (i = 0; i < dimensao && verifica; i++)
        {
            soma = 0;
            for (j = 0; j < dimensao; j++)
                soma += mat[i][j];
            if (soma != soma_desejada)
                verifica = 0;
        }
    }

    if (verifica)
    {
        //verifica soma das colunas
        for (i = 0; i < dimensao && verifica; i++)
        {
            soma = 0;
            for (j = 0; j < dimensao; j++)
                soma += mat[j][i];
            if (soma != soma_desejada)
                verifica = 0;
        }
    }

    if (verifica)
    {
        //verifica soma da diagonal principal
        soma = 0;
        for (i = 0; i < dimensao; i++)
            soma += mat[i][i];
        if (soma != soma_desejada)
            verifica = 0;
    }

    if (verifica)
    {
        //verifica soma da diagonal secundária
        soma = 0;
        for (i = dimensao - 1; i >= 0; i--)
            soma += mat[i][i];
        if (soma != soma_desejada)
            verifica = 0;
    }

    switch (verifica)
    {
        case 0:
            printf("invalido\n");
        break;
    
        case 1:
            printf("valido\n");
        break;
    }

    return 0;
}
