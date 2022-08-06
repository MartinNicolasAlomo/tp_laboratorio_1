#include "Validations.h"

int esEntero(char* cadena, int limite, char* mensajeFallo){
	int retorno=-1;
	int error=-1;
	int i;
	if(cadena!=NULL && limite>0){
		retorno=1;
		for (i=0;i<limite && cadena[i]!='\0';i++) {
			if(cadena[0] == '\0' || cadena[1] == '\0'){
				if(cadena[0] == ' ' || cadena[0] == '\0' || cadena[0] == '\n'){
					retorno=0;
					error=-2;
					break;
				}
				else if(cadena[i]<'0' || cadena[i]>'9'){
					retorno=0;
					error=-4;
					break;
				}
			}
			else if(cadena[i] == ' ' && cadena[i+1] == ' ' && (cadena[i+2] == ' ' || cadena[i+2] == '\n' || cadena[i+2] == '\0')){
				retorno=0;
				error=-3;
				break;
			}
			else if(i==0 && (cadena[i]=='+' || cadena[i]=='-')){
				continue;
			}
			else if(cadena[i]<'0' || cadena[i]>'9'){
				retorno=0;
				error=-4;
				break;
			}
		}
	}
	if(error==-1){
		strncpy(mensajeFallo, "(Se recibieron mal los parametros para validar si es un n�mero entero).\n", LARGO_MENSAJE);
	}
	else if(error==-2){
		strncpy(mensajeFallo, "(No se ingreso ning�n n�mero).\n", LARGO_MENSAJE);
	}
	else if(error==-3){
		strncpy(mensajeFallo, "(Se ingresaron m�ltiples espacios en blanco consecutivos).\n", LARGO_MENSAJE);
	}
	else if(error==-4){
		strncpy(mensajeFallo, "(El dato ingresado no corresponde con un n�mero entero).\n", LARGO_MENSAJE);
	}
	return retorno;
}

int validarRangoEntero(int numero, int minimo, int maximo, char* mensajeFallo){
	int retorno=-1;
	int error=-1;
	if(minimo<=maximo && mensajeFallo!=NULL){
		if (numero>=minimo && numero<=maximo) {
			retorno=1;
		}
		else{
			retorno=0;
			error=-2;
		}
	}
	if(error==-1){
		strncpy(mensajeFallo, "(Se recibieron mal los parametros para validar si el n�mero esta dentro del rango).", LARGO_MENSAJE);
	}
	else if(error==-2){
		strncpy(mensajeFallo, "(El n�mero ingresado esta fuera del rango establecido).", LARGO_MENSAJE);
	}
	return retorno;
}

int esFlotante(char* cadena, int limite, char* mensajeFallo){
	int retorno=-1;
	int error=-1;
	int i;
	int contadorPuntos=0;
	if(cadena!=NULL && limite>0){
		retorno=1;
		for (i=0;i<limite && cadena[i]!='\0';i++) {
			if(cadena[0] == '\0' || cadena[1] == '\0'){
				if(cadena[0] == ' ' || cadena[0] == '\0' || cadena[0] == '\n'){
					retorno=0;
					error=-2;
					break;
				}
				else if(cadena[i]<'0' || cadena[i]>'9'){
					if(cadena[i]=='.' && contadorPuntos==0){
						contadorPuntos++;
					}
					else{
						retorno=0;
						error=-4;
						break;
					}
				}
			}
			else if(cadena[i] == ' ' && cadena[i+1] == ' ' && (cadena[i+2] == ' ' || cadena[i+2] == '\n' || cadena[i+2] == '\0')){
				retorno=0;
				error=-3;
				break;
			}
			else if(i==0 && (cadena[0] == '-' || cadena[0] == '+')){
				continue;
			}
			else if(cadena[i]<'0' || cadena[i]>'9'){
				if(cadena[i]=='.' && contadorPuntos==0){
					contadorPuntos++;
				}
				else{
					retorno=0;
					error=-4;
					break;
				}
			}
		}
	}
	if(error==-1){
		strncpy(mensajeFallo, "(Se recibieron mal los parametros para validar si es un n�mero con decimales).", LARGO_MENSAJE);
	}
	else if(error==-2){
		strncpy(mensajeFallo, "(No se ingreso ning�n n�mero).\n", LARGO_MENSAJE);
	}
	else if(error==-3){
		strncpy(mensajeFallo, "(Se ingresaron m�ltiples espacios en blanco consecutivos).\n", LARGO_MENSAJE);
	}
	else if(error==-4){
		strncpy(mensajeFallo, "(El dato ingresado no corresponde con un n�mero con decimales).", LARGO_MENSAJE);
	}
	return retorno;
}

int validarRangoFlotante(float numero, float minimo, float maximo, char* mensajeFallo){
	int retorno=0;
	int error=-1;
 	if(minimo<=maximo && mensajeFallo!=NULL){
		if (numero>=minimo && numero<=maximo) {
			retorno=1;
		}
		else{
			retorno=0;
			error=-2;
		}
	}
	if(error==-1){
		strncpy(mensajeFallo, "(Se recibieron mal los parametros para validar si el n�mero esta dentro del rango).", LARGO_MENSAJE);
	}
	else if(error==-2){
		strncpy(mensajeFallo, "(El n�mero ingresado esta fuera del rango establecido).", LARGO_MENSAJE);
	}
	return retorno;
}

int esNombre(char* cadena, int limite, char* mensajeFallo){
	int retorno=-1;
	int error=-1;
	int i;
	if(cadena!=NULL && limite>0){
		retorno=1;
		for (i=0;i<limite && cadena[i]!='\0';i++){
			if(cadena[i] == ' ' && (cadena[i+1] == ' ' || cadena[i+2] == '\n' || cadena[i+2] == '\0')){
				retorno=0;
				error=-2;
				break;
			}
			else if((i==0 && (cadena[0] == ' ' || cadena[0] == '-' || cadena[0] == '\0')) ||
					(cadena[i] == ' ' && (cadena[i+1] == ' ' || cadena[i+1] == '-' || cadena[i+1] == '\0')) ||
					(cadena[i] == '-' && (cadena[i+1] == ' ' || cadena[i+1] == '-' || cadena[i+1] == '\0')) ){
				retorno=0;
				error=-3;
				break;
			}
			else if(
					(cadena[i] != ' ') && (cadena[i] != '-') &&
					(cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z') &&
					(cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') &&
					(cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') &&
					(cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') &&
					(cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') &&
					(cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') ){
				retorno=0;
				error=-4;
				break;
			}
		}
	}
	if(error==-1){
		strncpy(mensajeFallo, "(Se recibieron mal los parametros para validar).\n", LARGO_MENSAJE);
	}
	else if(error==-2){
		strncpy(mensajeFallo, "(No se ingreso ning�n car�cter).\n", LARGO_MENSAJE);
	}
	else if(error==-3){
		strncpy(mensajeFallo, "(Se escribieron espacios en blanco o caracteres en posiciones no debidas).\n", LARGO_MENSAJE);
	}
	else if(error==-4){
		strncpy(mensajeFallo, "(Se ingresaron caracteres no aceptados).\n", LARGO_MENSAJE);
	}

	/*else if(error==-3){
		strncpy(mensajeFallo, "(Se ingresaron m�ltiples espacios en blanco consecutivos).\n", LARGO_MENSAJE);
	}
	else if(error==-4){
		strncpy(mensajeFallo, "(Se escribieron caracteres en posiciones no debidas).\n", LARGO_MENSAJE);
	}
	else if(error==-5){
		strncpy(mensajeFallo, "(Se ingresaron caracteres no aceptados).\n", LARGO_MENSAJE);
	}*/
	return retorno;
}

int esDescripcion(char* cadena, int limite, char* mensajeFallo){
	int retorno=-1;
	int error=-1;
	int i;
	if(cadena!=NULL && limite>0){
		retorno=1;
		for (i=0;i<limite && cadena[i]!='\0';i++){
			if(cadena[0] == '\0' || cadena[1] == '\0'){
				if(cadena[0] == ' ' || cadena[0] == '\0' || cadena[0] == '\n'){
					retorno=0;
					error=-2;
					break;
				}
				else if((cadena[i] != ' ') && (cadena[i] != '.') && (cadena[i] != ',') && (cadena[i] != ';') && (cadena[i] != '@') &&
						(cadena[i] != '%') && (cadena[i] != '_') && (cadena[i] != '#') &&
						(cadena[i] != ':') && (cadena[i] != '-') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '*') &&
						(cadena[i] != '(') && (cadena[i] != ')') && (cadena[i] != '"') && (cadena[i] != '�') && (cadena[i] != '!') &&
						(cadena[i] != '�') && (cadena[i] != '?') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') &&
						(cadena[i] != '$') && (cadena[i] != '�') && (cadena[i] != '&') && (cadena[i] != '�') && (cadena[i] != '�') &&
						(cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') &&
						(cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') &&
						(cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') &&
						(cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') &&
						(cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < '0' || cadena[i] > '9') ){
					retorno=0;
					error=-5;
					break;
				}
			}
			else if(cadena[i] == ' ' && cadena[i+1] == ' ' && (cadena[i+2] == ' ' || cadena[i+2] == '\n' || cadena[i+2] == '\0')){
				retorno=0;
				error=-3;
				break;
			}
			else if(
					(i==0 && (cadena[0] == ' ' || cadena[0] == '-' || cadena[0] == '.' || cadena[0] == ',' ||
					cadena[0] == '@' || cadena[0] == '*' || cadena[0] == ';' || cadena[0] == ':' ||
					cadena[0] == '�' || cadena[0] == '\0' || cadena[0] == '\n')  ) ||
					(cadena[i] == ' ' && cadena[i+1] == '\0') ||
					(cadena[i] == '-' && cadena[i+1] == '\0') ){
				retorno=0;
				error=-4;
				break;
			}
			else if(
					(cadena[i] != ' ') && (cadena[i] != '.') && (cadena[i] != ',') && (cadena[i] != ';') && (cadena[i] != '@') &&
					(cadena[i] != '%') && (cadena[i] != '_') && (cadena[i] != '#') &&
					(cadena[i] != ':') && (cadena[i] != '-') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '*') &&
					(cadena[i] != '(') && (cadena[i] != ')') && (cadena[i] != '"') && (cadena[i] != '�') && (cadena[i] != '!') &&
					(cadena[i] != '�') && (cadena[i] != '?') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') &&
					(cadena[i] != '$') && (cadena[i] != '�') && (cadena[i] != '&') && (cadena[i] != '�') && (cadena[i] != '�') &&
					(cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') &&
					(cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') &&
					(cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') &&
					(cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') &&
					(cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < '0' || cadena[i] > '9') ){
				retorno=0;
				error=-5;
				break;
			}
		}
	}
	if(error==-1){
		strncpy(mensajeFallo, "(Se recibieron mal los parametros para validar).\n", LARGO_MENSAJE);
	}
	else if(error==-2){
		strncpy(mensajeFallo, "(No se ingreso ning�n car�cter).\n", LARGO_MENSAJE);
	}
	else if(error==-3){
		strncpy(mensajeFallo, "(Se ingresaron m�ltiples espacios en blanco consecutivos).\n", LARGO_MENSAJE);
	}
	else if(error==-4){
		strncpy(mensajeFallo, "(Se escribieron caracteres en posiciones no debidas).\n", LARGO_MENSAJE);
	}
	else if(error==-5){
		strncpy(mensajeFallo, "(Se ingresaron caracteres no aceptados).\n", LARGO_MENSAJE);
	}
	return retorno;
}

int esAlfanumerico(char* cadena, int limite, char* mensajeFallo){
	int retorno=-1;
	int error=-1;
	int i;
	if(cadena!=NULL && limite>0){
		retorno=1;
		for (i=0;i<limite && cadena[i]!='\0';i++){
			if(cadena[i] == ' ' && (cadena[i+1] == ' ' || cadena[i+2] == '\n' || cadena[i+2] == '\0')){
				retorno=0;
				error=-2;
				break;
			}
			else if((i==0 && (cadena[0] == ' ' || cadena[0] == '\0')) ||
					(cadena[i] == ' ' && (cadena[i+1] == ' ' || cadena[i+1] == '\0'))){
				retorno=0;
				error=-3;
				break;
			}
			else if(
					(cadena[i] != ' ') &&
					(cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') &&
					(cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') &&
					(cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') &&
					(cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') &&
					(cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') && (cadena[i] != '�') &&
					(cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < '0' || cadena[i] > '9') ){
				retorno=0;
				error=-4;
				break;
			}
		}
	}
	if(error==-1){
		strncpy(mensajeFallo, "(Se recibieron mal los parametros para validar).\n", LARGO_MENSAJE);
	}
	else if(error==-2){
		strncpy(mensajeFallo, "(No se ingreso ning�n car�cter).\n", LARGO_MENSAJE);
	}
	else if(error==-3){
		strncpy(mensajeFallo, "(Se escribieron espacios en blanco en posiciones no debidas).\n", LARGO_MENSAJE);
	}
	else if(error==-4){
		strncpy(mensajeFallo, "(Se ingresaron caracteres no aceptados).\n", LARGO_MENSAJE);
	}
	return retorno;
}

int esAnioBisiesto(int anio){
	int retorno=-1;
	if(anio!=0){
		retorno=0;
		if(anio%400==0 || (anio%4==0 && anio%100!=0)){
			retorno=1;
		}
	}
	return retorno;
}
