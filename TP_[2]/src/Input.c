#include "Input.h"
#define REINTENTOS 3

int obtenerCadena(char* cadena,int limite){
	int retorno=-1;
	char bufferString[4096];
	if(cadena!=NULL && limite>0){
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL){
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n'){
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= limite){
				strncpy(cadena,bufferString,limite);
				retorno=0;
			}
		}
	}
	return retorno;
}


int ingresarEntero(int* pEntero,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos) {
	int retorno=-1;
	int bufferInt;
	if(pEntero!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0){
		do{
			printf("%s",mensaje);
			if(!conseguirEntero(&bufferInt) && validarRangoEntero(bufferInt,minimo,maximo)){
				*pEntero=bufferInt;
				retorno=0;
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
	int retorno=-1;
	char bufferString[4086];
	if(pResultado!=NULL){
		if(!obtenerCadena(bufferString,sizeof(bufferString)) && esEntero(bufferString,sizeof(bufferString))){
			*pResultado=atoi(bufferString);
			retorno=0;
		}
	}
	return retorno;
}

int esEntero(char* cadena,int limite){
	int retorno=-1;
	int i;
	if(cadena!=NULL && limite>0){
		retorno = 1;
		for (i=0;i<limite && cadena[i]!='\0';i++) {
			if(i==0 && (cadena[i]=='+' || cadena[i]=='-')){
				continue;
			}
			if (cadena[i]<'0' || cadena[i]>'9'){
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int validarRangoEntero(int numero,int minimo,int maximo){
	int retorno=0;
	if (numero>=minimo && numero<=maximo) {
		retorno=1;
	}
	return retorno;
}


int ingresarFlotante(float* pFlotante,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos) {
	int retorno=-1;
	float bufferFloat;
	if(pFlotante!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0){
		do{
			printf("%s",mensaje);
			if(!conseguirFlotante(&bufferFloat) && validarRangoFlotante(bufferFloat,minimo,maximo)){
				*pFlotante=bufferFloat;
				retorno=0;
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
	int retorno=-1;
	char bufferString[4086];		//*****************************************
	if(pResultado!=NULL){
		if(!obtenerCadena(bufferString,sizeof(bufferString)) && esFlotante(bufferString,sizeof(bufferString))){
			*pResultado=atof(bufferString);
			retorno=0;
		}
	}
	return retorno;
}

int esFlotante(char* cadena,int limite){
	int retorno=-1;
	int i;
	int contadorPuntos=0;
	if(cadena!=NULL && limite>0){
		retorno=1;
		for (i=0;i<limite && cadena[i]!='\0';i++) {
			if (i==0 && (cadena[0]=='-' || cadena[0]=='+')){
				continue;
				}
			if (cadena[i]<'0' || cadena[i]>'9'){
				if(cadena[i]=='.' && contadorPuntos==0){
					contadorPuntos++;
				}
				else{
					retorno=0;
					break;
				}
			}
		}
	}
	return retorno;
}

int validarRangoFlotante(float numero,float minimo,float maximo){
	int retorno=0;
	if (numero>=minimo && numero<=maximo) {
		retorno=1;
	}
	return retorno;
}


int ingresarNombre(char* pNombre,int limite,char* mensaje,char* mensajeError,int reintentos){
	int retorno=-1;
	char bufferString[limite];
	if(pNombre!=NULL && limite>0 && mensaje!=NULL && mensajeError!=NULL && reintentos>=0){
		do{
			printf("%s",mensaje);
			if(!conseguirNombre(bufferString,limite) && strnlen(bufferString,limite)<limite){
				strncpy(pNombre,bufferString,limite);
				retorno=0;
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

int conseguirNombre(char* cadena,int limite){
	int retorno=-1;
	char bufferString[limite];
	if(cadena!=NULL && limite>0){
		if(!obtenerCadena(bufferString,limite) && esNombre(bufferString,limite) && strnlen(bufferString,limite)<limite){
			strncpy(cadena,bufferString,limite);
			retorno=0;
		}
	}
	return retorno;
}

int esNombre(char* cadena,int limite){
	int retorno=-1;
	int i;
	if(cadena!=NULL && limite>0){
		retorno=1;
		for (i=0;i<limite && cadena[i]!='\0';i++){
			if(((cadena[i] != ' ') && (cadena[i] != '-') && (cadena[i] != 'ñ') && (cadena[i] != 'Ñ') && (cadena[i] != 'ç') && (cadena[i] != 'Ç') &&
				(cadena[i] != 'á') && (cadena[i] != 'é') && (cadena[i] != 'í') && (cadena[i] != 'ó') && (cadena[i] != 'ú') &&
				(cadena[i] != 'Á') && (cadena[i] != 'É') && (cadena[i] != 'Í') && (cadena[i] != 'Ó') && (cadena[i] != 'Ú') &&
				(cadena[i] != 'ä') && (cadena[i] != 'ë') && (cadena[i] != 'ï') && (cadena[i] != 'ö') && (cadena[i] != 'ü') &&
				(cadena[i] != 'Ä') && (cadena[i] != 'Ë') && (cadena[i] != 'Ï') && (cadena[i] != 'Ö') && (cadena[i] != 'Ü') &&
				(cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z')) || (cadena[0] == ' ')){
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}


int ingresarDescripcion(char* pDescripcion,int limite,char* mensaje,char* mensajeError,int reintentos){
	int retorno=-1;
	char bufferString[limite];
	if(pDescripcion!=NULL && limite>0 && mensaje!=NULL && mensajeError!=NULL && reintentos>=0){
		do{
			printf("%s",mensaje);
			if(!conseguirDescipcion(bufferString,limite) && strnlen(bufferString,limite)<limite){
				strncpy(pDescripcion,bufferString,limite);
				retorno=0;
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

int conseguirDescipcion(char* cadena,int limite){
	int retorno=-1;
	char bufferString[limite];
	if(cadena!=NULL && limite>0){
		if(!obtenerCadena(bufferString,limite) && esDescripcion(bufferString,limite) && strnlen(bufferString,limite)<limite){
			strncpy(cadena,bufferString,limite);
			retorno=0;
		}
	}
	return retorno;
}

int esDescripcion(char* cadena,int limite){
	int retorno=-1;
	int i;
	if(cadena!=NULL && limite>0){
		retorno=1;
		for (i=0;i<limite && cadena[i]!='\0';i++){
			if((cadena[0] == ' ') || ((cadena[i] != ' ') && (cadena[i] != '.') && (cadena[i] != ',') && (cadena[i] != ';') &&
				(cadena[i] != ':') && (cadena[i] != '-') && (cadena[i] != 'Ç') && (cadena[i] != 'ç') &&
				(cadena[i] != '(') && (cadena[i] != ')') && (cadena[i] != '"') && (cadena[i] != '¡') && (cadena[i] != '!') &&
				(cadena[i] != '¿') && (cadena[i] != '?') && (cadena[i] != '®') && (cadena[i] != '©') && (cadena[i] != '°') &&
				(cadena[i] != '$') && (cadena[i] != '¢') && (cadena[i] != '&') && (cadena[i] != 'ñ') && (cadena[i] != 'Ñ') &&
				(cadena[i] != 'á') && (cadena[i] != 'é') && (cadena[i] != 'í') && (cadena[i] != 'ó') && (cadena[i] != 'ú') &&
				(cadena[i] != 'Á') && (cadena[i] != 'É') && (cadena[i] != 'Í') && (cadena[i] != 'Ó') && (cadena[i] != 'Ú') &&
				(cadena[i] != 'ä') && (cadena[i] != 'ë') && (cadena[i] != 'ï') && (cadena[i] != 'ö') && (cadena[i] != 'ü') &&
				(cadena[i] != 'Ä') && (cadena[i] != 'Ë') && (cadena[i] != 'Ï') && (cadena[i] != 'Ö') && (cadena[i] != 'Ü') &&
				(cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < '0' || cadena[i] > '9'))){
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}


int ingresarAlfanumerico(char* pAlfanumerico,int limite,char* mensaje,char* mensajeError,int reintentos){
	int retorno=-1;
	char bufferString[limite];
	if(pAlfanumerico!=NULL && limite>0 && mensaje!=NULL && mensajeError!=NULL && reintentos>=0){
		do{
			printf("%s",mensaje);
			if(!conseguirAlfanumerico(bufferString,limite) && strnlen(bufferString,limite)<limite){
				strncpy(pAlfanumerico,bufferString,limite);
				retorno=0;
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

int conseguirAlfanumerico(char* cadena,int limite){
	int retorno=-1;
	char bufferString[limite];
	if(cadena!=NULL && limite>0){
		if(!obtenerCadena(bufferString,limite) && esAlfanumerico(bufferString,limite) && strnlen(bufferString,limite)<limite){
			strncpy(cadena,bufferString,limite);
			retorno=0;
		}
	}
	return retorno;
}

int esAlfanumerico(char* cadena,int limite){
	int retorno=-1;
	int i;
	if(cadena!=NULL && limite>0){
		retorno=1;
		for (i=0;i<limite && cadena[i]!='\0';i++){
			if((cadena[0] == ' ') || ((cadena[i] != ' ') && (cadena[i] != 'ñ') && (cadena[i] != 'Ñ') && (cadena[i] != 'Ç') && (cadena[i] != 'ç') &&
				(cadena[i] != 'á') && (cadena[i] != 'é') && (cadena[i] != 'í') && (cadena[i] != 'ó') && (cadena[i] != 'ú') &&
				(cadena[i] != 'Á') && (cadena[i] != 'É') && (cadena[i] != 'Í') && (cadena[i] != 'Ó') && (cadena[i] != 'Ú') &&
				(cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < '0' || cadena[i] > '9'))){
				retorno=0;
				break;
			}
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
