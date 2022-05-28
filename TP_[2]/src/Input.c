#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "Input.h"


int obtenerCadena(char* cadena, int limite){
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
		if(!obtenerCadena(bufferString,sizeof(bufferString)) && esEntero(bufferString,sizeof(bufferString))){
			*pResultado = atoi(bufferString);
			retorno = 0;
		}
	}
	return retorno;
}

int esEntero(char cadena[], int limite){
	int retorno = -1;
	int i;
	if(cadena != NULL && limite > 0){
		retorno = 1;
		for (i = 0; i<limite && cadena[i] != '\0'; i++) {
			if(i == 0 && (cadena[i] == '+' || cadena[i] == '-')){
				continue;
			}
			if (cadena[i] < '0' || cadena[i] > '9') {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int validarRangoEntero(int numeroIngresado, int minimo, int maximo){
	int retorno = 0;
	if (numeroIngresado >= minimo && numeroIngresado <= maximo) {
		retorno = 1;
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
		if(!obtenerCadena(bufferString,sizeof(bufferString)) && esFlotante(bufferString,sizeof(bufferString))){
			*pResultado = atof(bufferString);
			retorno = 0;
		}
	}
	return retorno;
}

int esFlotante(char cadena[],int limite){
	int retorno = -1;
	int i;
	int contadorPuntos=0;
	if(cadena != NULL && limite > 0){
		retorno = 1;
		for (i=0; i<limite && cadena[i] != '\0'; i++) {
			if (i==0 && (cadena[0] == '-' || cadena[0] == '+')) {
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
	}
	return retorno;
}

int validarRangoFlotante(float numeroFlotante, float minimo, float maximo){
	int retorno = 0;
	if (numeroFlotante >= minimo && numeroFlotante <= maximo) {
		retorno = 1;
	}
	return retorno;
}

		// 		CAMBIAR FUNCION
int ingresarNombreUnico(char *pNombre, int limiteNombre, char *mensaje, char *mensajeError,int reintentos){
	int retorno = -1;
	char bufferString[limiteNombre];
	if(pNombre != NULL && limiteNombre > 0 && mensaje != NULL && mensajeError != NULL && reintentos >= 0){
		do{
			printf("%s",mensaje);
			if(!conseguirNombreUnico(bufferString,limiteNombre) && strnlen(bufferString,limiteNombre)<limiteNombre){
				bufferString[0] = toupper(bufferString[0]);
				strncpy(pNombre,bufferString,limiteNombre);
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

int conseguirNombreUnico(char* pResultado, int limiteNombre){
	int retorno = -1;
	char bufferString[limiteNombre];
	if(pResultado != NULL && limiteNombre>0){
		if(!obtenerCadena(bufferString,limiteNombre) && esNombreUnico(bufferString,limiteNombre) && strnlen(bufferString,limiteNombre)<limiteNombre){
			strncpy(pResultado,bufferString,limiteNombre);
			retorno = 0;
		}
	}
	return retorno;
}

int esNombreUnico(char cadena[], int limite){
	int retorno = -1;
	int i;
	if(cadena != NULL && limite > 0){
		retorno = 1;
		for (i = 0; i<limite && cadena[i] != '\0'; i++) {
			if((cadena[i] != 'ñ') && (cadena[i] != 'Ñ') && (cadena[i] != 'Ç') && (cadena[i] != 'ç') &&
				(cadena[i] != 'á') && (cadena[i] != 'é') && (cadena[i] != 'í') && (cadena[i] != 'ó') && (cadena[i] != 'ú') &&
				(cadena[i] != 'Á') && (cadena[i] != 'É') && (cadena[i] != 'Í') && (cadena[i] != 'Ó') && (cadena[i] != 'Ú') &&
				(cadena[i] != 'ä') && (cadena[i] != 'ë') && (cadena[i] != 'ï') && (cadena[i] != 'ö') && (cadena[i] != 'ü') &&
				(cadena[i] != 'Ä') && (cadena[i] != 'Ë') && (cadena[i] != 'Ï') && (cadena[i] != 'Ö') && (cadena[i] != 'Ü') &&
				(cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z')) {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


int ingresarAlfanumerico(char *pAlfanumerico, int limiteAlfanumerico, char *mensaje, char *mensajeError,int reintentos){
	int retorno = -1;
	char bufferString[limiteAlfanumerico];
	if(pAlfanumerico != NULL && limiteAlfanumerico > 0 && mensaje != NULL && mensajeError != NULL && reintentos >= 0){
		do{
			printf("%s",mensaje);
			if(!conseguirAlfanumerico(bufferString,limiteAlfanumerico) && strnlen(bufferString,limiteAlfanumerico)<limiteAlfanumerico){
				bufferString[0] = toupper(bufferString[0]);
				strncpy(pAlfanumerico,bufferString,limiteAlfanumerico);
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

int conseguirAlfanumerico(char* pResultado,int limiteAlfanumerico){
	int retorno = -1;
	char bufferString[limiteAlfanumerico];
	if(pResultado != NULL && limiteAlfanumerico>0){
		if(!obtenerCadena(bufferString,limiteAlfanumerico) && esAlfanumerico(bufferString,limiteAlfanumerico) && strnlen(bufferString,limiteAlfanumerico)<limiteAlfanumerico){
			strncpy(pResultado,bufferString,limiteAlfanumerico);
			retorno = 0;
		}
	}
	return retorno;
}

int esAlfanumerico(char cadena[], int limite){
	int retorno = -1;
	int i;
	if(cadena != NULL && limite > 0){
		retorno = 1;
		for (i = 0; i<limite && cadena[i] != '\0'; i++) {
			if((cadena[i] != ' ') && (cadena[i] != 'ñ') && (cadena[i] != 'Ñ') && (cadena[i] != 'Ç') && (cadena[i] != 'ç') &&
				(cadena[i] != 'á') && (cadena[i] != 'é') && (cadena[i] != 'í') && (cadena[i] != 'ó') && (cadena[i] != 'ú') &&
				(cadena[i] != 'Á') && (cadena[i] != 'É') && (cadena[i] != 'Í') && (cadena[i] != 'Ó') && (cadena[i] != 'Ú') &&
				(cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < '0' || cadena[i] > '9')) {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
