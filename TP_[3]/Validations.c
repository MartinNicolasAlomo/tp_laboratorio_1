#include "Validations.h"


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


int esNombre(char cadena[], int limite){
	int retorno = -1;
	int i;
	if(cadena != NULL && limite > 0){
		retorno = 1;
		for (i = 0; i<limite && cadena[i] != '\0'; i++) {
			if(((cadena[i] != ' ') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') &&
				(cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') &&
				(cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') &&
				(cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') &&
				(cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') &&
				(cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z')) || (cadena[0] == ' ')) {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


int esDescripcion(char cadena[], int limite){
	int retorno = -1;
	int i;
	if(cadena != NULL && limite > 0){
		retorno = 1;
		for (i = 0; i<limite && cadena[i] != '\0'; i++) {
			if((cadena[0] == ' ') || ((cadena[i] != ' ') && (cadena[i] != '.') && (cadena[i] != ',') && (cadena[i] != ';') &&
				(cadena[i] != ':') && (cadena[i] != '-') && (cadena[i] != '�') && (cadena[i] != '�') &&
				(cadena[i] != '(') && (cadena[i] != ')') && (cadena[i] != '"') && (cadena[i] != '�') && (cadena[i] != '!') &&
				(cadena[i] != '�') && (cadena[i] != '?') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') &&
				(cadena[i] != '$') && (cadena[i] != '�') && (cadena[i] != '&') && (cadena[i] != '�') && (cadena[i] != '�') &&
				(cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') &&
				(cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') &&
				(cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') &&
				(cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') &&
				(cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < '0' || cadena[i] > '9'))) {
				retorno = 0;
				break;
			}
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
			if((cadena[0] == ' ') || ((cadena[i] != ' ') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') &&
				(cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') &&
				(cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') &&
				(cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < '0' || cadena[i] > '9'))) {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

