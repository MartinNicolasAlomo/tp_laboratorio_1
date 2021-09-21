#include <stdio.h>
#include <stdlib.h>

int VerificarSigno(int numeroIngresado){
	int signoVerificado = -1;
	if(numeroIngresado==0){
		signoVerificado = 0;
	}
	else if(numeroIngresado>0){
		signoVerificado = 1;
	}
	return signoVerificado;
}
