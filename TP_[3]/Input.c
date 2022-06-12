#include "Input.h"
#define REINTENTOS 3



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


int ingresarNombre(char *pNombre, int limiteNombre, char *mensaje, char *mensajeError,int reintentos){
	int retorno = -1;
	char bufferString[limiteNombre];
	if(pNombre != NULL && limiteNombre > 0 && mensaje != NULL && mensajeError != NULL && reintentos >= 0){
		do{
			printf("%s",mensaje);
			if(!conseguirNombre(bufferString,limiteNombre) && strnlen(bufferString,limiteNombre)<limiteNombre){
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

int conseguirNombre(char* pResultado, int limiteNombre){
	int retorno = -1;
	char bufferString[limiteNombre];
	if(pResultado != NULL && limiteNombre>0){
		if(!obtenerCadena(bufferString,limiteNombre) && esNombre(bufferString,limiteNombre) && strnlen(bufferString,limiteNombre)<limiteNombre){
			strncpy(pResultado,bufferString,limiteNombre);
			retorno = 0;
		}
	}
	return retorno;
}


int ingresarDescripcion(char *pDescripcion, int limiteDescripcion, char *mensaje, char *mensajeError,int reintentos){
	int retorno = -1;
	char bufferString[limiteDescripcion];
	if(pDescripcion != NULL && limiteDescripcion > 0 && mensaje != NULL && mensajeError != NULL && reintentos >= 0){
		do{
			printf("%s",mensaje);
			if(!conseguirDescipcion(bufferString,limiteDescripcion) && strnlen(bufferString,limiteDescripcion)<limiteDescripcion){
				strncpy(pDescripcion,bufferString,limiteDescripcion);
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

int conseguirDescipcion(char* pResultado,int limiteDescripcion){
	int retorno = -1;
	char bufferString[limiteDescripcion];
	if(pResultado != NULL && limiteDescripcion>0){
		if(!obtenerCadena(bufferString,limiteDescripcion) && esDescripcion(bufferString,limiteDescripcion) && strnlen(bufferString,limiteDescripcion)<limiteDescripcion){
			strncpy(pResultado,bufferString,limiteDescripcion);
			retorno = 0;
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


int pasarInicialesNombreMayusculas(char* nombre,int limite){
	int retorno=-1;
	int i;

	if(nombre!=NULL){
		strlwr(nombre);
		nombre[0]=toupper(nombre[0]);
		for(i=0;i<limite;i++){
			if((nombre[i]==' ' && nombre[i+1]!=' ') || (nombre[i]=='-' && nombre[i+1]!='-')){
				nombre[i+1]=toupper(nombre[i+1]);
			}
		}
		retorno=0;
	}
	return retorno;
}
