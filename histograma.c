//Guilherme Bastos de Oliveira
#include <stdio.h>
#include "lcrandom.h"

long valores[100];

//desenha e calcula histograma
void histograma(long A, long C, long M){
  int j, k;
  long i, maior;
  //define valores iniciais
  lcrandom_seed(0);
  lcrandom_parms(A, C, M);
  for(j = 0; j < 100; j++){
    valores[j] = 0;
  }
  //gera numeros aleatorios
  for(i = 0; i < 1000000; i++){
    valores[lcrandom() % 100]++;
  }
  //desenha a tabela
  for(j = 0; j < 101; j += 10){
    printf("%5d", j);
  }
  printf("\n    ");
  for(j = 0; j < 51; j++){
    printf("%s", j%5?"-":"+");
  }
  printf("\n");
  maior = valores[0];
  for(j = 0; j < 100; j++){
    //normaliza os valores antes de imprimir
    maior = maior<valores[j]?valores[j]:maior;
  }
  for(j = 0; j < 100; j++){
    valores[j] = (100*valores[j])/maior;
    printf("%3d |", j);
    for(k = 0; k < valores[j]; k += 2){
      printf("*");
    }
    printf("\n");
  }
}

int main(){
  printf("\n    Valores Padrão\n\n");
  histograma(40692, 127, 10000000);
  printf("\n\n\n    Valores da Wikipedia\n\n");
	lcrandom_seed(0);
  histograma(1140671485, 12820163, 16777216);
  return 0;
}
