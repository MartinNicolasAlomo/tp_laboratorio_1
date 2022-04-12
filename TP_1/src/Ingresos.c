#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Ingresos.h"
#include "Validaciones.h"
#include "Operaciones.h"


int obtenerDatos(char* cadena, int limite){
	int retorno = -1;
	char bufferString[4096];
	if(cadena != NULL && limite > 0){
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL){
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n'){
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= limite){
				strncpy(cadena,bufferString,limite);
				retorno = 0;
			}
		}
	}
	return retorno;
}


int ingresarEntero(int *pEntero, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos) {
	int retorno = -1;
	int bufferInt;
	if(pEntero != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){
		do{
			printf("%s",mensaje);
			if(!conseguirEntero(&bufferInt) && validarRangoEntero(bufferInt,minimo,maximo)){
				*pEntero = bufferInt;
				retorno = 0;
				break;
			}
			else{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}


int conseguirEntero(int* pResultado){
	int retorno = -1;
	char bufferString[4086];
	if(pResultado != NULL){
		if(!obtenerDatos(bufferString,sizeof(bufferString)) && esNumerica(bufferString,sizeof(bufferString))){
			*pResultado = atoi(bufferString);
			retorno = 0;
		}
	}
	return retorno;
}


int ingresarFlotante(float *pFlotante, char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos) {
	int retorno = -1;
	float bufferFloat;
	if(pFlotante != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){
		do{
			printf("%s",mensaje);
			if(!conseguirFlotante(&bufferFloat) && validarRangoFlotante(bufferFloat,minimo,maximo)){
				*pFlotante = bufferFloat;
				retorno = 0;
				break;
			}
			else{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}


int conseguirFlotante(float* pResultado){
	int retorno = -1;
	char bufferString[4086];
	if(pResultado != NULL){
		if(!obtenerDatos(bufferString,sizeof(bufferString)) && esFlotante(bufferString,sizeof(bufferString))){
			*pResultado = atof(bufferString);
			retorno = 0;
		}
	}
	return retorno;
}

