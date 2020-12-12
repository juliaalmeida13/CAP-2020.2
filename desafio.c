#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAM_MAX 2000

//criando um registro
struct pontos
{
    double x;
    double y;
};

void leitura(struct pontos coordenadas[], int* n)
{
    //determinando o número de pontos;
    printf("Digite a quantidade de coordenadas: ");
    scanf("%d", n);
    
    //leitura dos pontos
    printf("\nAgora digite os pontos: ");
    for(int i=0; i<(*n); i++){
        scanf("%lf", &coordenadas[i].x);
        scanf("%lf", &coordenadas[i].y);
    }
}

double area(struct pontos coordenadas[], int n)
{
    double area, soma;
    int i;
    //formula fornecida pelo enunciado
    soma = ((coordenadas[0].x)*(coordenadas[n-1].y))-((coordenadas[0].y)*(coordenadas[n-1].x));
    for(i=1; i<n; i++){
        soma += (((coordenadas[i].x)*(coordenadas[i-1].y))-((coordenadas[i].y)*(coordenadas[i-1].x)));
    }
    area = (fabs(soma))/2;

    return area;
}

int main()
{
    //declaração das variáveis locais
    int n, m;
    double aux1, aux2;
    struct pontos poligono1[TAM_MAX], poligono2[TAM_MAX];

    printf("----- Leitura do poligono 1 -----\n");
    printf("atencao!! insira cada coordenada (x e y) em linhas diferentes e nao se esqueca de inserir coordenadas que formem um poligono, caso contrario a area sera 0\n");
    leitura(poligono1, &n);
    aux1 = area(poligono1, n);

    printf("----- Leitura do poligono 2 -----\n");
    leitura(poligono2, &m);
    aux2 = area(poligono2, m);

    if(aux1>aux2)
        printf("\n->Area do maior poligono: %lf, poligono 1", area(poligono1, n));
    else
        printf("\n->Area do maior poligono: %lf, poligono 2", area(poligono2, n));
    
    return 0;
}