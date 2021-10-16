#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Input.h"
#include "ArrayEmployees.h"

int IngresarEntero(int *pEntero, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos) {
	int retorno = 0;
	int bufferInt;

	if (pEntero != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0) {
		do {
			printf("%s\n", mensaje);
			if (RecibirEntero(&bufferInt) == 1 && ValidarRangoEntero(bufferInt,minimo,maximo) == 1) {
				*pEntero = bufferInt;
				retorno = 1;
				break;
			}
			printf("%s\n", mensajeError);
			reintentos--;

		} while (reintentos >= 0);
	}
	return retorno;
}

int ValidarRangoEntero(int numeroIngresado, int minimo, int maximo) {
	int retorno = 0;

	if (numeroIngresado >= minimo && numeroIngresado <= maximo) {
		retorno = 1;
	}
	return retorno;
}

int RecibirEntero(int *pResultado) {
	int retorno = 0;
	char buffer[100];

	if(pResultado != NULL){
		if (PedirDatos(buffer,sizeof(buffer)) == 1 && esNumerica(buffer,sizeof(buffer)) == 1) {
			retorno = 1;
			*pResultado = atoi(buffer);
		}
	}

	return retorno;
}

int esNumerica(char *cadena, int limite) {
	int retorno = 0;
	int i;
	if(cadena != NULL && limite > 0){
		for (i = 0; i<limite && cadena[i] != '\0'; i++) {
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-')){
				continue;
			}
			if (cadena[i] >= '0' && cadena[i] <= '9') {
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}


int IngresarFlotante(float *pFlotante, char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos) {
	int retorno = 0;
	float bufferFloat;

	if (pFlotante != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0) {
		do {
			printf("%s\n", mensaje);
			if (RecibirFlotante(&bufferFloat) == 1 && ValidarRangoFlotante(bufferFloat,minimo,maximo) == 1) {
				*pFlotante = bufferFloat;
				retorno = 1;
				break;
			}
			else {
				printf("%s\n", mensajeError);
				reintentos--;
			}
		} while (reintentos >= 0);
	}
	return retorno;
}

int ValidarRangoFlotante(float numeroIngresado, float minimo, float maximo) {
	int retorno = 0;

	if (numeroIngresado >= minimo && numeroIngresado <= maximo) {
		retorno = 1;
	}
	return retorno;
}

int RecibirFlotante(float *pResultado) {
	int retorno = 0;
	char buffer[100];

	if(pResultado != NULL){
		if (PedirDatos(buffer,sizeof(buffer)) == 1 && esFlotante(buffer,sizeof(buffer)) == 1) {
			retorno = 1;
			*pResultado = atof(buffer);
		}
	}

	return retorno;
}

int esFlotante(char *cadena,int limite) {
	int retorno = 1;
	int i;
	int contadorPuntos=0;

	for (i=0; i<limite && cadena[i] != '\0'; i++) {
		if (i==0 && (cadena[0] == '-' || cadena[0] == '+')) {  //para saber si es negativo y validarlo.
			continue;
			}
		if (cadena[i] < '0' || cadena[i] > '9') {
			if(cadena[i] == '.' && contadorPuntos == 0){
				contadorPuntos++;
			}
			else{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


int IngresarNombre(char* pNombre, int limite, char *mensaje, char *mensajeError, int reintentos){
	int retorno = 0;
	char bufferString[100];

	if (pNombre != NULL && limite > 0 && mensaje != NULL && mensajeError != NULL && reintentos >= 0) {
		do {
			printf("%s\n", mensaje);
			if (RecibirNombre(bufferString,sizeof(bufferString)) == 1 && strnlen(bufferString,sizeof(bufferString))) {
				strncpy(pNombre,bufferString,limite);
				retorno = 1;
				break;
			}
			printf("%s\n", mensajeError);
			reintentos--;

		} while (reintentos >= 0);
	}
	return retorno;
}

int RecibirNombre(char *pResultado, int limite) {
	int retorno = 0;
	char bufferString[100];

	if(pResultado != NULL && limite > 0){
		if (PedirDatos(bufferString,sizeof(bufferString)) == 1 && esSoloLetras(bufferString,sizeof(bufferString)) == 1 && strnlen(bufferString,sizeof(bufferString)) < limite) {
			retorno = 1;
			strncpy(pResultado,bufferString,limite);
		}
	}

	return retorno;
}

int esSoloLetras(char *cadena, int limite) {
	int retorno = 1;
	int i = 0;

	if(cadena != NULL && limite > 0){
		for (i = 0; i<limite && cadena[i] != '\0'; i++) {
			if( (cadena[i] != ' ') && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z')) {
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}


int PedirDatos(char *cadena, int longitud){
	int retorno = 0;
	char bufferString[4096];

	if(cadena != NULL && longitud > 0){
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL){
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n'){
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud){
				strncpy(cadena,bufferString,longitud);
				retorno = 1;
			}
		}
	}

	return retorno;
}
