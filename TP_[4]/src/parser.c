#include "parser.h"

int parser_PassengerFromText(FILE* pFile, LinkedList* pArrayList){
    int retorno=-1;
    eComputer* pComputer=NULL;
    char auxTitulo[100];
    char auxId[100];
	char auxDescripcion[200];
	char auxPrecio[100];
	char auxIdTipo[100];

	if(pFile!=NULL && pArrayList!=NULL){
		fscanf(pFile, "%[^\n]\n", auxTitulo);
		do{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxDescripcion, auxPrecio, auxIdTipo)==4){
				pComputer=Computer_newParametros(auxId, auxDescripcion, auxPrecio, auxIdTipo);
				if(pComputer!=NULL){
					if(!ll_add(pArrayList, pComputer)){
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
