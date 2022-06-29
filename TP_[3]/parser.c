#include "parser.h"

int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger){
    int retorno=-1;
    Passenger* pPasajero=NULL;
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
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo, auxTipoPasajero, auxEstadoVuelo)==7){
				pPasajero = Computer_newParametros(auxId, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo, auxTipoPasajero, auxEstadoVuelo);
				if(pPasajero!=NULL){
					if(!ll_add(pArrayListPassenger, pPasajero)){
						retorno=0;
					}
					else{
						puts("No se pudo agregar al Pasajero a la Lista, falló la Función ll_add.\n");
					}
				}
				else{
					puts("No se creó el Pasajero, falló la Función Passenger_newParametros.\n");
				}
			}
			else{
				puts("No funcionó la Función de lectura FSCANF.\n");
				break;
			}
		}while(!feof(pFile));
	}
	return retorno;
}
//***********************************************************************************************************************************


int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger){
	int retorno=-1;
	Passenger* pPasajero=NULL;

	if(pFile!=NULL && pArrayListPassenger!=NULL){
		do{
			pPasajero=Computer_new();
			if(pPasajero!=NULL && fread(pPasajero,sizeof(Passenger),1,pFile)){
				if(!ll_add(pArrayListPassenger, pPasajero)){
					retorno=0;
				}
				else{
					puts("No se pudo agregar al Pasajero a la Lista, falló la Función ll_add.\n");
					Passenger_delete(pPasajero);
					break;
					retorno=-3;
				}
			}
			else if(pPasajero==NULL){
				puts("No se creó el Pasajero, falló la Función Passenger_newParametros.\n");
			}
		}while(!feof(pFile));
	}
	return retorno;
}
