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

int VerificarEntero(float numeroIngresado){
	int numeroEntero = 0;
	if(numeroIngresado==(int)numeroIngresado){
		numeroEntero = 1;
	}
	return numeroEntero;
}
