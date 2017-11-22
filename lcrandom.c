//Guilherme Bastos de Oliveira
#include "lcrandom.h"

//valores default
long lcr_a=40692, lcr_c=127, lcr_m=10000000, lcr_x=0;

//gera valor aleatoria
unsigned long lcrandom (){
	lcr_x = ((lcr_a * lcr_x) + lcr_c) % lcr_m;
	return lcr_x;
}

//define semente
void lcrandom_seed (unsigned long s){
	lcr_x = s;
}

//retorna o valor maximo gerado
unsigned long lcrandom_max (){
	return lcr_m-1;
}

//define parametros
void lcrandom_parms (unsigned long A, unsigned long C, unsigned long M){
	lcr_a = A;
	lcr_c = C;
	lcr_m = M;
}
