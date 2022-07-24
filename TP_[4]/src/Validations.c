#include "Validations.h"

int esEntero(char* cadena, int limite){
	int retorno=-1;
	int i;
	if(cadena!=NULL && limite>0){
		retorno=1;
		for (i=0;i<limite && cadena[i]!='\0';i++) {
			if(i==0 && (cadena[i]=='+' || cadena[i]=='-')){
				continue;
			}
			if(cadena[i]<'0' || cadena[i]>'9'){
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int validarRangoEntero(int numero, int minimo, int maximo){
	int retorno=0;
	if (numero>=minimo && numero<=maximo) {
		retorno=1;
	}
	return retorno;
}

int esFlotante(char* cadena, int limite){
	int retorno=-1;
	int i;
	int contadorPuntos=0;
	if(cadena!=NULL && limite>0){
		retorno=1;
		for (i=0;i<limite && cadena[i]!='\0';i++) {
			if(i==0 && (cadena[0]=='-' || cadena[0]=='+')){
				continue;
				}
			if(cadena[i]<'0' || cadena[i]>'9'){
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

int validarRangoFlotante(float numero, float minimo, float maximo){
	int retorno=0;
	if (numero>=minimo && numero<=maximo) {
		retorno=1;
	}
	return retorno;
}

int esNombre(char* cadena, int limite){
	int retorno=-1;
	int i;
	if(cadena!=NULL && limite>0){
		retorno=1;
		for (i=0;i<limite && cadena[i]!='\0';i++){
			if((i==0 && (cadena[0] == ' ' || cadena[0] == '-' || cadena[0] == '\0')) ||
				(cadena[i] == ' ' && (cadena[i+1] == ' ' || cadena[i+1] == '-' || cadena[i+1] == '\0')) ||
				(cadena[i] == '-' && (cadena[i+1] == ' ' || cadena[i+1] == '-' || cadena[i+1] == '\0')) ||
				((cadena[i] != ' ') && (cadena[i] != '-') &&
				(cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z') &&
				(cadena[i] != 'ñ') && (cadena[i] != 'Ñ') && (cadena[i] != 'ç') && (cadena[i] != 'Ç') &&
				(cadena[i] != 'á') && (cadena[i] != 'é') && (cadena[i] != 'í') && (cadena[i] != 'ó') && (cadena[i] != 'ú') &&
				(cadena[i] != 'Á') && (cadena[i] != 'É') && (cadena[i] != 'Í') && (cadena[i] != 'Ó') && (cadena[i] != 'Ú') &&
				(cadena[i] != 'ä') && (cadena[i] != 'ë') && (cadena[i] != 'ï') && (cadena[i] != 'ö') && (cadena[i] != 'ü') &&
				(cadena[i] != 'Ä') && (cadena[i] != 'Ë') && (cadena[i] != 'Ï') && (cadena[i] != 'Ö') && (cadena[i] != 'Ü'))){
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int esDescripcion(char* cadena, int limite){
	int retorno=-1;
	int i;
	if(cadena!=NULL && limite>0){
		retorno=1;
		for (i=0;i<limite && cadena[i]!='\0';i++){
			if((i==0 && (cadena[0] == ' ' || cadena[0] == '-' || cadena[0] == '.' || cadena[0] == ',' ||
				cadena[0] == '@' || cadena[0] == '*' || cadena[0] == ';' || cadena[0] == ':' || cadena[0] == '°' || cadena[0] == '\0')) ||
				(cadena[i] == ' ' && cadena[i+1] == '\0') ||
				(cadena[i] == '-' && cadena[i+1] == '\0') ||
				((cadena[i] != ' ') && (cadena[i] != '.') && (cadena[i] != ',') && (cadena[i] != ';') && (cadena[i] != '@') &&
				(cadena[i] != ':') && (cadena[i] != '-') && (cadena[i] != 'Ç') && (cadena[i] != 'ç') && (cadena[i] != '*') &&
				(cadena[i] != '_') && (cadena[i] != '#') &&
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
	if(retorno==-1){
		puts("*Se recibieron mal los parametros - fn: esDescripcion");
	}
	else if(retorno==0){
		puts("*No es una descripción valida\n");
	}
	return retorno;
}

int esAlfanumerico(char* cadena, int limite){
	int retorno=-1;
	int i;
	if(cadena!=NULL && limite>0){
		retorno=1;
		for (i=0;i<limite && cadena[i]!='\0';i++){
			if((i==0 && (cadena[0] == ' ' || cadena[0] == '\0')) ||
				(cadena[i] == ' ' && (cadena[i+1] == ' ' || cadena[i+1] == '\0')) ||
				((cadena[i] != ' ') &&
				(cadena[i] != 'ñ') && (cadena[i] != 'Ñ') && (cadena[i] != 'Ç') && (cadena[i] != 'ç') &&
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

int esArchivo(char* cadena, int limite){
	int retorno=-1;
	int i;
	if(cadena!=NULL && limite>0){
		retorno=1;
		for (i=0;i<limite && cadena[i]!='\0';i++){
			if((i==0 && (cadena[0] == ' ' || cadena[0] == '.' || cadena[0] == '-' || cadena[0] == '_' || cadena[0] == '\0')) ||
				(cadena[i] == ' ' && cadena[i+1] == '\0') ||
				(cadena[i] == '-' && cadena[i+1] == '\0') ||
				(cadena[i] == '%') || (cadena[i] == '&') || (cadena[i] == '{') || (cadena[i] == '}') || (cadena[i] == '\\') ||
				(cadena[i] == '<') || (cadena[i] == '>') || (cadena[i] == '*') || (cadena[i] == '$') || (cadena[i] == '=') ||
				(cadena[i] == '"') || (cadena[i] == ':') ||
				(cadena[i] == '¿') || (cadena[i] == '?') || (cadena[i] == '/') || (cadena[i] == '#') || (cadena[i] == '@') ||
				(cadena[i] == '+') || (cadena[i] == '`') || (cadena[i] == '|') || (cadena[i] == '!') || (cadena[i] == '¡')){
				retorno=0;
				break;
			}
		}
	}
	if(retorno==-1){
		puts("*Se recibieron mal los parametros - fn: esArchivo");
	}
	else if(retorno==0){
		puts("*Caracteres inválidos\n");
	}
	return retorno;
}

int esArchivoCSV(char* cadena, int limite){
	int retorno=-1;
	int i;
	if(cadena!=NULL && limite>0){
		retorno=0;
		for (i=0;i<limite && cadena[i]!='\0';i++){
			if(cadena[i]=='.' &&  cadena[i+1]=='c' && cadena[i+2]=='s' && cadena[i+3]=='v' &&
					(cadena[i+4]=='\0' || cadena[i+4]=='\n')){
				retorno=1;
				break;
			}
		}
	}
	if(retorno==-1){
		printf("*Recibió mal los parametros para validar CSV\n");
	}
	else if(retorno==0){
		printf("*No corresponde con un archivo .csv\n");
	}
	return retorno;
}
