#include "parser.h"

int parser_PassengerFromText(FILE* pFile,LinkedList* pArrayListPassenger){
    int retorno=-1;
    Passenger* pPasajero=NULL;
    int numeroPasajero=0;
    char auxTitulo[100];
    char auxId[100];
	char auxNombre[100];
	char auxApellido[100];
	char auxPrecio[100];
	char auxCodigoVuelo[100];
	char auxTipoPasajero[100];
	char auxEstadoVuelo[100];

	if(pFile!=NULL && pArrayListPassenger!=NULL){
		fscanf(pFile, "%[^\n]\n", auxTitulo);
		do{
			numeroPasajero++;
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo, auxTipoPasajero, auxEstadoVuelo)==7){
				pPasajero=Passenger_newParametros(numeroPasajero, auxId, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo, auxTipoPasajero, auxEstadoVuelo);
				if(pPasajero!=NULL && !ll_add(pArrayListPassenger, pPasajero)){
					retorno=0;
				}
				else{
					printf("No se pudo agregar pasajero n° %d de la lista.", numeroPasajero);
				}
			}
			else{
				printf("No se pudo leer el elemento n° %d de la lista.\n", numeroPasajero);
				break;
			}
		}while(!feof(pFile));
	}
	return retorno;
}
//***********************************************************************************************************************************


int parser_PassengerFromBinary(FILE* pFile, LinkedList* pArrayListPassenger){
	int retorno=-1;
	Passenger* pPasajero=NULL;
    int numeroPasajero=0;

	if(pFile!=NULL && pArrayListPassenger!=NULL){
		do{
			numeroPasajero++;
			pPasajero=Passenger_new();
			if(pPasajero!=NULL && fread(pPasajero, sizeof(Passenger), 1, pFile) && !ll_add(pArrayListPassenger, pPasajero)){
				retorno=0;
			}
			else if(pPasajero==NULL){
				printf("*No se creó el pasajero n° %d de la lista, no hay espacio en memoria suficiente.\n", numeroPasajero);
			}
			else{
				puts("*No se pudo agregar pasajero n° %d de la lista");
				Passenger_delete(pPasajero);
				break;
			}
		}while(!feof(pFile));
	}
	return retorno;
}
