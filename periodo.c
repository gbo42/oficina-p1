//Guilherme Bastos de Oliveira
#include <stdio.h>
#include "lcrandom.h"

char rands[17000000];

//zera as informações no vetor
void limpaVetor(long k){
	for (long i = 0; i < k; i++){
		rands[i] = 0;
	}
}

//encontra o periodo
long periodo(long A, long C, long M){
	int cont = 0, stop = 0;
	long numero = 0;
	printf("Limpando vetor...\n");
	limpaVetor(M+1);
	printf("Vetor limpo.\n");
	while(!stop){
	lcrandom_parms(A, C, M);
		if (rands[numero]){
			stop = 1;
			return cont;
		}
		rands[numero] = 1;
		numero = lcrandom();
		cont++;
	}
	return -1;
}

int main(){
	printf("Valores Padrão\n");
	printf("Periodo: %ld\n", periodo(40692, 127, 10000000));
	printf("\nValores da Wikipedia\n");
	lcrandom_seed(0);
	printf("Periodo: %ld\n", periodo(1140671485, 12820163, 16777216));
	return 0;
}
