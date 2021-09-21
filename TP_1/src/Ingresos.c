#include <stdio.h>
#include <stdlib.h>

int PedirOpcion(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos) {
	int retorno;
	int bufferInt;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0) {
		do {
			printf("%s\n", mensaje);
			scanf("%d", &bufferInt);

			if (bufferInt >= minimo && bufferInt <= maximo) {
				*pResultado = bufferInt;
				retorno = 0; //cero indica exito.
				break;
			} else {
				printf("%s\n", mensajeError);
				reintentos--;
			}
		} while (reintentos >= 0);
	}
	return retorno;
}

float PedirNumero(char mensaje[]) {
	float numeroIngresado;
	printf("%s", mensaje);
	scanf("%f", &numeroIngresado);
	return numeroIngresado;
}
