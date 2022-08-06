#include "Input.h"

int obtenerCadena(char* cadena, int limite){
	int retorno=-1;
	char bufferString[MAX_BUFFER_STR];
	if(cadena!=NULL && limite>0){
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL){
			if(bufferString[strnlen(bufferString, sizeof(bufferString))-1] == '\n'){
				bufferString[strnlen(bufferString, sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString, sizeof(bufferString)) <= limite){
				strncpy(cadena, bufferString, limite);
				retorno=0;
			}
		}
	}
	return retorno;
}

int ingresarEntero(int* pEntero, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos) {
	int retorno=-1;
	int bufferInt;
	if(pEntero!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0){
		do{
			printf("%s", mensaje);
			if(!conseguirEntero(&bufferInt) && validarRangoEntero(bufferInt, minimo, maximo)){
				*pEntero=bufferInt;
				retorno=0;
				break;
			}
			else{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}

int conseguirEntero(int* pEntero){
	int retorno=-1;
	char bufferString[MAX_BUFFER_STR];
	if(pEntero!=NULL){
		if(!obtenerCadena(bufferString, sizeof(bufferString)) && esEntero(bufferString, sizeof(bufferString))){
			*pEntero=atoi(bufferString);
			retorno=0;
		}
	}
	return retorno;
}

int ingresarFlotante(float* pFlotante, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos) {
	int retorno=-1;
	float bufferFloat;
	if(pFlotante!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0){
		do{
			printf("%s", mensaje);
			if(!conseguirFlotante(&bufferFloat) && validarRangoFlotante(bufferFloat, minimo, maximo)){
				*pFlotante=bufferFloat;
				retorno=0;
				break;
			}
			else{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}

int conseguirFlotante(float* pFlotante){
	int retorno=-1;
	char bufferString[MAX_BUFFER_STR];
	if(pFlotante!=NULL){
		if(!obtenerCadena(bufferString, sizeof(bufferString)) && esFlotante(bufferString, sizeof(bufferString))){
			*pFlotante=atof(bufferString);
			retorno=0;
		}
	}
	return retorno;
}

int ingresarNombre(char* pNombre, int limite, char* mensaje, char* mensajeError, int reintentos){
	int retorno=-1;
	char bufferString[limite];
	if(pNombre!=NULL && limite>0 && mensaje!=NULL && mensajeError!=NULL && reintentos>=0){
		do{
			printf("%s", mensaje);
			if(!conseguirNombre(bufferString, limite) && !pasarInicialesMayusculas(bufferString, limite)){
				strncpy(pNombre, bufferString, limite);
				retorno=0;
				break;
			}
			else{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}

int conseguirNombre(char* pNombre, int limite){
	int retorno=-1;
	char bufferString[limite];
	if(pNombre!=NULL && limite>0){
		if(!obtenerCadena(bufferString, limite) && esNombre(bufferString, limite) && strnlen(bufferString, limite)<limite){
			strncpy(pNombre, bufferString, limite);
			retorno=0;
		}
	}
	return retorno;
}

int ingresarDescripcion(char* pDescripcion, int limite, char* mensaje, char* mensajeError, int reintentos){
	int retorno=-1;
	char bufferString[limite];
	if(pDescripcion!=NULL && limite>0 && mensaje!=NULL && mensajeError!=NULL && reintentos>=0){
		do{
			printf("%s", mensaje);
			if(!conseguirDescipcion(bufferString, limite)){
				strncpy(pDescripcion, bufferString, limite);
				retorno=0;
				break;
			}
			else{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}

int conseguirDescipcion(char* pDescripcion, int limite){
	int retorno=-1;
	char bufferString[limite];
	if(pDescripcion!=NULL && limite>0){
		if(!obtenerCadena(bufferString, limite) && esDescripcion(bufferString, limite) && strnlen(bufferString, limite)<limite){
			strncpy(pDescripcion, bufferString, limite);
			retorno=0;
		}
	}
	return retorno;
}

int ingresarAlfanumerico(char* pAlfanumerico, int limite, char* mensaje, char* mensajeError, int reintentos){
	int retorno=-1;
	char bufferString[limite];
	if(pAlfanumerico!=NULL && limite>0 && mensaje!=NULL && mensajeError!=NULL && reintentos>=0){
		do{
			printf("%s", mensaje);
			if(!conseguirAlfanumerico(bufferString, limite)){
				strncpy(pAlfanumerico, bufferString, limite);
				retorno=0;
				break;
			}
			else{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}

int conseguirAlfanumerico(char* pAlfanumerico, int limite){
	int retorno=-1;
	char bufferString[limite];
	if(pAlfanumerico!=NULL && limite>0){
		if(!obtenerCadena(bufferString, limite) && esAlfanumerico(bufferString, limite) && strnlen(bufferString, limite)<limite){
			strncpy(pAlfanumerico, bufferString, limite);
			retorno=0;
		}
	}
	return retorno;
}

int pasarInicialesMayusculas(char* nombre, int limite){
	int retorno=-1;
	int i;
	if(nombre!=NULL){
		strlwr(nombre);
		nombre[0]=toupper(nombre[0]);
		for(i=0;i<limite;i++){
			if((nombre[i]==' ' && nombre[i+1]!=' ') || (nombre[i]=='-' && nombre[i+1]!='-') || (nombre[i]=='(' && nombre[i+1]!='(') ||
			   (nombre[i]=='¿' && nombre[i+1]!='¿') || (nombre[i]=='"' && nombre[i+1]!='"') || (nombre[i]=='¡' && nombre[i+1]!='¡')){
				nombre[i+1]=toupper(nombre[i+1]);
			}
		}
		retorno=0;
	}
	return retorno;
}



int ingresarArchivo(char* pArchivo, int limite, char* mensaje, char* mensajeError, int reintentos){
	int retorno=-1;
	char bufferString[limite];
	if(pArchivo!=NULL && limite>0 && mensaje!=NULL && mensajeError!=NULL && reintentos>=0){
		do{
			printf("%s", mensaje);
			if(!conseguirArchivo(bufferString, limite)){
				strncpy(pArchivo, bufferString, limite);
				retorno=0;
				break;
			}
			else{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}

int conseguirArchivo(char* pArchivo, int limite){
	int retorno=-1;
	char bufferString[limite];
	if(pArchivo!=NULL && limite>0){
		if(!obtenerCadena(bufferString, limite) && esArchivo(bufferString, limite) && strnlen(bufferString, limite)<limite){
			strncpy(pArchivo, bufferString, limite);
			retorno=0;
		}
	}
	return retorno;
}

int ingresarArchivoCSV(char* pArchivoCSV, int limite, char* mensaje, char* mensajeError, int reintentos){
	int retorno=-1;
	if(pArchivoCSV!=NULL && limite>0 && mensaje!=NULL && mensajeError!=NULL && reintentos>=0){
		if(!ingresarArchivo(pArchivoCSV, limite, mensaje, mensajeError, reintentos) &&
				esArchivoCSV(pArchivoCSV, limite)){
			retorno=0;
		}
	}
	return retorno;
}

