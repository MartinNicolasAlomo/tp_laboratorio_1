#include "parser.h"


/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 * \param pFile FILE* Puntero al archivo a cargar
 * \param pArrayListPassenger LinkedList* Puntero al vector de pasajeros
 * \return int Retorna 0 (EXITO) - Si se pudieron parsear los datos desde el archivo correctamente
 * 						-1 (ERROR) - El puntero a pFile es NULL
 * 						-2 (ERROR) - El puntero a LinkedList es NULL
 * 						-3 (ERROR) - No se pudo agregar el pasajero a la lista
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger){
    int retorno=-1;
    Passenger* pPasajero;
    char auxTitulo[100];
    char auxId[100];
	char auxNombre[100];
	char auxApellido[100];
	char auxPrecio[100];
	char auxCodigoVuelo[100];
	char auxTipoPasajero[100];
	char auxEstadoVuelo[100];
		// LOGRAR LEER CADA LINEA, CONVERTIO MEM DINA CON COSNTRUCTROM Y AGREGARLO CON ADD AL LINKEDLIST
		// JUNTAR CALSE GERMAN Y GIANNI

		// SEGUN GIANNI - 	EL ID DE LOS QUE AGREGA EL USUARIO ARRANCA EN 1001,		XQ LOS DEL ARCHIVO YA ESTAN ESTABLECIDOS Y NO SE PUEDEN CAMBIAR

	if(pFile!=NULL && pArrayListPassenger!=NULL){
		fscanf(pFile, "%[^\n]\n", auxTitulo);
		do{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo, auxTipoPasajero, auxEstadoVuelo)==7){
				pPasajero = Passenger_newParametros(auxId, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo, auxTipoPasajero, auxEstadoVuelo);
				if(pPasajero!=NULL){
					if(!ll_add(pArrayListPassenger, pPasajero)){
						retorno=0;
					}
					else{
						puts("No se pudo AGREGAR  -  falló ll_add\n");
						retorno=-3;
					}
				}
				else{
					puts("No se creó pasajero  -  Passenger_newParametros esta MAL.\n");
				}
			}
			else{
				puts("No funcionó el FSCANF.\n");
				break;
			}
		}while(!feof(pFile));
	}
	else if(pArrayListPassenger==NULL){
		puts("VectorPasajeros es NULO.\n");
		retorno=-2;
	}
	else{
		puts("Archivo RUTA esta MAL.\n");
	}
	return retorno;
}
//***********************************************************************************************************************************


/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger){		//	FREAD
	int retorno=-1;
	//Passenger* pPasajero;



	//	usar PassengerNEW  para crear pasaejro del archivo, y FREAD para leer binario, ADD para agregar
	//  Borrar pasajero ??? con delete




	return retorno;
}
