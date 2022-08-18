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

int obtenerCadenaVersion2(char* cadena, int limite, char* mensajeFallo){
	int retorno=-1;
	char bufferString[MAX_BUFFER_STR];
	if(cadena!=NULL && limite>0){
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL){
			if(		(bufferString[0] == '\n' && bufferString[1] == '\n') ||
					(bufferString[0] == '\n' && bufferString[1] == '\0') ||
					(bufferString[0] == '\0' && bufferString[1] == '\n') ||
					(bufferString[0] == '\0' && bufferString[1] == '\0')  ){
				retorno=-1;
				bufferString[0] = ' ';
			}
			if(bufferString[strnlen(bufferString, sizeof(bufferString))-1] == '\n'){
				bufferString[strnlen(bufferString, sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString, sizeof(bufferString)) <= limite){
				strncpy(cadena, bufferString, limite);
				retorno=0;
			}
			else{
				strncpy(mensajeFallo, "Se excedió el limite de caracteres permitidos\n", limite);
			}
		}
	}
	return retorno;
}


//		*****************************************************************************************
int obtenerCadenaVersion89764321(char* cadena, int limite, char* mensajeFallo){
	int retorno=-1;
	char* bufferString=malloc(sizeof(char)*limite);

	if(cadena!=NULL && limite>0 && bufferString!=NULL){
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL){
			if(		(bufferString[0] == '\n' && bufferString[1] == '\n') ||
					(bufferString[0] == '\n' && bufferString[1] == '\0') ||
					(bufferString[0] == '\0' && bufferString[1] == '\n') ||
					(bufferString[0] == '\0' && bufferString[1] == '\0')  ){
				retorno=-1;
				bufferString[0] = ' ';
			}
			if(bufferString[strnlen(bufferString, sizeof(bufferString))-1] == '\n'){
				bufferString[strnlen(bufferString, sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString, sizeof(bufferString)) <= limite){
				strncpy(cadena, bufferString, limite);
				retorno=0;
			}
			else{
				strncpy(mensajeFallo, "Se excedió el limite de caracteres permitidos\n", limite);
			}
		}
	}
	return retorno;
}





int ingresarEntero(int* pEntero, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos) {
	int retorno=-1;
	int bufferInt;
	char mensajeFallo[LARGO_MENSAJE_LARGO];
	if(pEntero!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0){
		do{
			printf("\n%s\n", mensaje);
			if(!conseguirEntero(&bufferInt, mensajeFallo) && validarRangoEntero(bufferInt, minimo, maximo, mensajeFallo)){
				*pEntero=bufferInt;
				retorno=0;
				break;
			}
			else{
				printf("¡Error! %s %s\n\n", mensajeError, mensajeFallo);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}

int conseguirEntero(int* pEntero, char* mensajeFallo){
	int retorno=-1;
	char bufferString[MAX_BUFFER_STR];
	if(pEntero!=NULL &&	mensajeFallo!=NULL &&
			!obtenerCadenaVersion2(bufferString, sizeof(bufferString), mensajeFallo) && esEntero(bufferString, sizeof(bufferString), mensajeFallo)){
		*pEntero=atoi(bufferString);
		retorno=0;
	}
	return retorno;
}

int ingresarFlotante(float* pFlotante, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos) {
	int retorno=-1;
	float bufferFloat;
	char mensajeFallo[LARGO_MENSAJE_LARGO];
	if(pFlotante!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0){
		do{
			printf("\n%s\n", mensaje);
			if(!conseguirFlotante(&bufferFloat, mensajeFallo) && validarRangoFlotante(bufferFloat, minimo, maximo, mensajeFallo)){
				*pFlotante=bufferFloat;
				retorno=0;
				break;
			}
			else{
				printf("¡Error! %s %s\n\n", mensajeError, mensajeFallo);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}

int conseguirFlotante(float* pFlotante, char* mensajeFallo){
	int retorno=-1;
	char bufferString[MAX_BUFFER_STR];
	if(pFlotante!=NULL && mensajeFallo!=NULL &&
			!obtenerCadenaVersion2(bufferString, sizeof(bufferString), mensajeFallo) && esFlotante(bufferString, sizeof(bufferString), mensajeFallo)){
		*pFlotante=atof(bufferString);
		retorno=0;
	}
	return retorno;
}

int ingresarNombre(char* pNombre, int limite, char* mensaje, char* mensajeError, int reintentos){
	int retorno=-1;
	char bufferString[limite];
	char mensajeFallo[LARGO_MENSAJE_LARGO];
	if(pNombre!=NULL && limite>0 && mensaje!=NULL && mensajeError!=NULL && reintentos>=0){
		do{
			printf("\n%s\n", mensaje);
			if(!conseguirNombre(bufferString, limite, mensajeFallo) && !pasarInicialesMayusculas(bufferString, limite)){
				strncpy(pNombre, bufferString, limite);
				retorno=0;
				break;
			}
			else{
				printf("¡Error! %s %s\n\n", mensajeError, mensajeFallo);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}

int conseguirNombre(char* pNombre, int limite, char* mensajeFallo){
	int retorno=-1;
	char bufferString[limite];
	if(pNombre!=NULL && limite>0 && mensajeFallo!=NULL &&
			!obtenerCadenaVersion2(bufferString, limite, mensajeFallo) && esNombre(bufferString, limite, mensajeFallo)){
		strncpy(pNombre, bufferString, limite);
		retorno=0;
	}
	return retorno;
}

int ingresarDescripcion(char* pDescripcion, int limite, char* mensaje, char* mensajeError, int reintentos){
	int retorno=-1;
	char bufferString[limite];
	char mensajeFallo[LARGO_MENSAJE_LARGO];
	if(pDescripcion!=NULL && limite>0 && mensaje!=NULL && mensajeError!=NULL && reintentos>=0){
		do{
			printf("\n%s\n", mensaje);
			if(!conseguirDescipcion(bufferString, limite, mensajeFallo)){
				strncpy(pDescripcion, bufferString, limite);
				retorno=0;
				break;
			}
			else{
				printf("¡Error! %s %s\n\n", mensajeError, mensajeFallo);
				reintentos--;
			}
			if(reintentos<0){
				break;
			}
		}while(reintentos>=0);
	}
	return retorno;
}

int conseguirDescipcion(char* pDescripcion, int limite, char* mensajeFallo){
	int retorno=-1;
	char bufferString[limite];
	if(pDescripcion!=NULL && limite>0 && mensajeFallo!=NULL &&
			!obtenerCadenaVersion2(bufferString, limite, mensajeFallo) && esDescripcion(bufferString, limite, mensajeFallo)){
		strncpy(pDescripcion, bufferString, limite);
		retorno=0;
	}
	return retorno;
}

int ingresarAlfanumerico(char* pAlfanumerico, int limite, char* mensaje, char* mensajeError, int reintentos){
	int retorno=-1;
	char bufferString[limite];
	char mensajeFallo[LARGO_MENSAJE_LARGO];
	if(pAlfanumerico!=NULL && limite>0 && mensaje!=NULL && mensajeError!=NULL && reintentos>=0){
		do{
			printf("\n%s\n", mensaje);
			if(!conseguirAlfanumerico(bufferString, limite, mensajeFallo)){
				strncpy(pAlfanumerico, bufferString, limite);
				retorno=0;
				break;
			}
			else{
				printf("¡Error! %s %s\n\n", mensajeError, mensajeFallo);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}

int conseguirAlfanumerico(char* pAlfanumerico, int limite, char* mensajeFallo){
	int retorno=-1;
	char bufferString[limite];
	if(pAlfanumerico!=NULL && limite>0 && mensajeFallo!=NULL &&
			!obtenerCadenaVersion2(bufferString, limite, mensajeFallo) && esAlfanumerico(bufferString, limite, mensajeFallo)){
		strncpy(pAlfanumerico, bufferString, limite);
		retorno=0;
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
			   (nombre[i]=='¿' && nombre[i+1]!='¿') || (nombre[i]=='"' && nombre[i+1]!='"') || (nombre[i]=='¡' && nombre[i+1]!='¡') ){
				nombre[i+1]=toupper(nombre[i+1]);
			}
		}
		retorno=0;
	}
	return retorno;
}
