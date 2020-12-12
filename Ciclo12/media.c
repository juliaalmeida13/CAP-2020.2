#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct aluno{
  int RA;
  double notas[3];
  double media;
};

int main()
{
  int n, i, j, aux;
  double soma, media;
  scanf("%d", &n);

  struct aluno alunos[n];
  
  for(i = 0; i< n; i++){
    scanf("%d", &alunos[i].RA);
    for(j=0; j<3; j++)
      scanf("%lf", &alunos[i].notas[j]);
  }

  //ordenando na forma decrescente o vetor de notas utilizando o bubble sort
  for(i=0;i<n;i++)
    for(j=0;j<3;j++)
      if(alunos[i].notas[j]<alunos[i+1].notas[j+1]){
        aux = alunos[i].notas[j];
        alunos[i].notas[j] = alunos[i+1].notas[j+1];
        alunos[i+1].notas[j+1] = aux;
      }

  soma=media=0;

  //cálculo da média aritmética das 2 maiores notas de cada aluno
  for(i=0; i<n; i++){
    soma = 0;
    printf("---ALUNO %d---\n", i);
    printf("RA: %d\n", alunos[i].RA);
    for(j=0; j<2; j++){//pegando apenas as 2 maiores notas
      soma += alunos[i].notas[j];
    alunos[i].media = soma/2;
    printf("Media: %lf", alunos[i].media);
    }
  }

return 0;
}