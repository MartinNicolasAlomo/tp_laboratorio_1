#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "Input.h"
#define CANTPASAJEROS 15
#define REINTENTOS 3
#define LARGOMENSAJE 100
#define TRUE 1
#define FALSE 0
#define ESTADOACTIVO 1
#define ESTADOTERMINADO 0


int menuOpcionesPasajeros(void){
	int retorno=-1;
	Passenger Pasajeros[CANTPASAJEROS];
	int opcion=0;
	int idPasajeros=0;
	int indiceLibre;
	int idABuscar;
	int idEncontrado;
	int flagPasajero=1;
	int opcionModificar;
	int tipoListado;
	int orden;
	int respuestaInforme;

	char nombre[LARGONOMBRE];
	char apellido[LARGOAPELLIDO];
	float precio=0;
	int tipoPasajero=0;
	char codigoVuelo[LARGOCODIGO];

	char mensajeMenuIngreso[LARGOMENSAJE];
	char mensajeMenuError[LARGOMENSAJE];
	char mensajeModificarID[LARGOMENSAJE];
	char mensajeEliminarID[LARGOMENSAJE];
	char mensajeIDError[LARGOMENSAJE];
	char mensajeInforme[LARGOMENSAJE];
	char mensajeOrdenamiento[LARGOMENSAJE];


	strncpy(mensajeMenuIngreso,"1-Dar de alta un pasajero\n2-Modificar un pasajero\n3-Dar de baja un pasajero\n4-Informar\n5-Salir\n\n",sizeof(mensajeMenuIngreso));
	strncpy(mensajeMenuError,"No es una opción válida, reinténtelo de nuevo.\n\n\n",sizeof(mensajeMenuError));
	strncpy(mensajeModificarID,"Ingrese el ID que desea modificar:\n\n",sizeof(mensajeModificarID));
	strncpy(mensajeEliminarID,"Ingrese el ID que desea eliminar:\n\n",sizeof(mensajeEliminarID));
	strncpy(mensajeIDError,"No es un ID válido, reinténtelo de nuevo.\n\n\n",sizeof(mensajeIDError));
	strncpy(mensajeInforme,"¿Qué desea informar?\n1-Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n2-Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n3-Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’.\n\n",sizeof(mensajeInforme));
	strncpy(mensajeOrdenamiento,"¿En qué orden quiere ordenarlos?\n1-Ascendente\n0-Descendente\n\n",sizeof(mensajeOrdenamiento));


	if(!initPassengers(Pasajeros, CANTPASAJEROS)){
		puts("Se inicializaron los pasajeros.\n\n");
	}
	else{
		puts("Falló la inicialización.\n\n\n");
	}


	do{
		if(!ingresarEntero(&opcion, mensajeMenuIngreso, mensajeMenuError, 1, 5, REINTENTOS)){
			switch(opcion){

		// *************************************************
			case 1:
				indiceLibre=buscarProximoIndiceVacioPasajeros(Pasajeros, CANTPASAJEROS);
				if(indiceLibre>=0){
					if(!addPassenger(Pasajeros, CANTPASAJEROS, idPasajeros, nombre, apellido, precio, tipoPasajero, codigoVuelo)){
						printf("Se cargaron los datos del nuevo pasajero. ID: %d.\n\n",idPasajeros);
						idPasajeros++;
						flagPasajero=0;
					}
					else{
						puts("Falló la carga de datos.\n\n\n");
					}
				}
				else{
					puts("No hay mas lugar disponible.\n\n\n");
				}
				break;

		// *************************************************
			case 2:
				if(flagPasajero){
					puts("Todavía no se ingresó ningún pasajero.\n\n\n");
				}
// 										AGREGAR UN SUBMENU  ******	*******
				else{
					if(!ingresarEntero(&idABuscar, mensajeModificarID, mensajeIDError, 0, idPasajeros, REINTENTOS)){
						idEncontrado=findPassengerById(Pasajeros, CANTPASAJEROS, idABuscar);
						if(idEncontrado>=0){
							puts("opción 2\n\n");
							if(!modificarVectorAlumnos(Pasajeros, CANTPASAJEROS, idEncontrado, nombre, apellido, precio, tipoPasajero, codigoVuelo)){
								printf("Se modificaron los datos del pasajero con el ID: %d.\n\n",idEncontrado);
							}
							else{
								puts("Falló la modificación de datos.\n\n\n");
							}
						}
						else{
							puts("No se encontró el ID solicitado.\n\n\n");
						}
					}
					else{
						puts("No se pudo ingresar el ID.\n\n\n");
					}
				}


				if(){

				}

				break;

		// *************************************************
			case 3:
				if(flagPasajero){
					puts("Todavía no se ingresó ningún pasajero.\n\n\n");
				}
				/*else if( se eliminaron todos los pasjeros y no hay nadie){
					puts("Se eliminaron todos los pasajero previamente, por favor reingrese pasajeros para poder seleccionar esta opción.\n\n");
				}*/

				else{
					if(!ingresarEntero(&idABuscar, mensajeEliminarID, mensajeIDError, 0, idPasajeros, REINTENTOS)){
						idEncontrado=findPassengerById(Pasajeros, CANTPASAJEROS, idABuscar);
						if(idEncontrado>=0){
							puts("opcion 3\n\n");
							if(!removePassenger(Pasajeros, CANTPASAJEROS, idEncontrado)){
								printf("Se eliminaron los datos del pasajero con el ID: %d.\n\n",idEncontrado);
							}
							else{
								puts("Falló la eliminación de datos.\n\n\n");
							}
						}
						else{
							puts("No se encontró el ID solicitado.\n\n\n");
						}
					}
					else{
						puts("No se pudo ingresar el ID.\n\n\n");
					}
				}
				break;

		// *************************************************
			case 4:
				if(flagPasajero){
					puts("Todavía no se ingresó ningún pasajero.\n\n\n");
				}
				else{
					respuestaInforme=ingresarEntero(&tipoListado, mensajeInforme, mensajeMenuError, 1, 3, REINTENTOS);
					if(respuestaInforme==1){
						if(!ingresarEntero(&orden, mensajeOrdenamiento, mensajeMenuError, 0, 1, REINTENTOS)){
							if(!sortPassengers(Pasajeros, CANTPASAJEROS, orden)){
								printPassenger(Pasajeros, CANTPASAJEROS);
							}
							else{
								puts("No se pudo ordenar la lista.\n\n\n");
							}
						}
						else{
							puts("No se pudo ingresar el orden deseado.\n\n\n");
						}
					}
					else if(respuestaInforme==2){




					}
					else if(respuestaInforme==3){
						if(!ingresarEntero(&orden, mensajeOrdenamiento, mensajeMenuError, 0, 1, REINTENTOS)){
							if(!sortPassengers(Pasajeros, CANTPASAJEROS, orden)){
								printPassenger(Pasajeros, CANTPASAJEROS);
							}
							else{
								puts("No se pudo ordenar la lista.\n\n\n");
							}
						}
						else{
							puts("No se pudo ingresar el orden deseado.\n\n\n");
						}
					}
					else{
						puts("No se pudo ingresar una opción.\n\n\n");
					}
				}

				break;

		// *************************************************
			case 5:
				puts("Salió.\n\n");
				retorno=0;
				break;

			}
		}
		else{
			puts("No se pudo ingresar la opcion\n\n");
		}
	}while(opcion!=5);

	return retorno;
}







int initPassengers(Passenger* list, int len){	// ------------------------
	int retorno = -1;
	int i;
	if(list != NULL && len>0){
		retorno = 0;
		for(i=0;i<len;i++){
			list[i].isEmpty=TRUE;
		}
	}
	return retorno;
}





int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[]){
	int retorno = -1;
	Passenger auxPasajero;
	if(list != NULL && len>0 && id>=0 && name != NULL && lastName != NULL && flycode != NULL){
		if(!ingresarUnSoloNombre(name, LARGONOMBRE, "Ingrese el nombre:\n", "Error. No es un nombre, reinténtelo de nuevo.\n\n\n", REINTENTOS) &&
			!ingresarUnSoloNombre(lastName, LARGOAPELLIDO, "Ingrese el apellido:\n", "Error. No es un nombre, reinténtelo de nuevo.\n\n\n", REINTENTOS) &&
			!ingresarFlotante(&price, "Ingrese el precio del vuelo:\n", "Error. No es un precio válido, reinténtelo de nuevo.\n\n\n", 0.1, 500000, REINTENTOS) &&
			!ingresarEntero(&typePassenger, "Ingrese el tipo de pasajero:\n", "Error. No es un tipo válido, reinténtelo de nuevo.\n\n\n", 1, 3, REINTENTOS) &&
			!ingresarAlfanumerico(flycode, LARGOCODIGO, "Ingrese el codigo de pasaje:\n", "Error. No es un tipo válido, reinténtelo de nuevo.\n\n\n", REINTENTOS))	{
			retorno=0;
			strncpy(auxPasajero.name,name,sizeof(auxPasajero.name));
			strncpy(auxPasajero.lastName,lastName,sizeof(auxPasajero.lastName));
			strncpy(auxPasajero.flyCode,flycode,sizeof(auxPasajero.flyCode));
			auxPasajero.price=price;
			auxPasajero.typePassenger=typePassenger;
			auxPasajero.id=id;
			auxPasajero.statusFlight=TRUE;
			auxPasajero.isEmpty=FALSE;
			list[id]=auxPasajero;
		}
	}
	return retorno;
}



int modificarVectorAlumnos(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[]){	// --------------------------
	int retorno = -1;
		Passenger auxPasajero;
		if(list != NULL && len>0 && id>=0 && name != NULL && lastName != NULL && flycode != NULL){
		if(!ingresarUnSoloNombre(name, LARGONOMBRE, "Ingrese el nombre:\n", "Error. No es un nombre, reinténtelo de nuevo.\n\n\n", REINTENTOS) &&
				!ingresarUnSoloNombre(lastName, LARGOAPELLIDO, "Ingrese el apellido:\n", "Error. No es un nombre, reinténtelo de nuevo.\n\n\n", REINTENTOS) &&
				!ingresarFlotante(&price, "Ingrese el precio del vuelo:\n", "Error. No es un precio válido, reinténtelo de nuevo.\n\n\n", 0.1, 500000, REINTENTOS) &&
				!ingresarEntero(&typePassenger, "Ingrese el tipo de pasajero:\n", "Error. No es un tipo válido, reinténtelo de nuevo.\n\n\n", 1, 3, REINTENTOS) &&
				!ingresarAlfanumerico(flycode, LARGOCODIGO, "Ingrese el codigo de pasaje:\n", "Error. No es un tipo válido, reinténtelo de nuevo.\n\n\n", REINTENTOS))	{
			retorno=0;
			strncpy(auxPasajero.name,name,sizeof(auxPasajero.name));
			strncpy(auxPasajero.lastName,lastName,sizeof(auxPasajero.lastName));
			strncpy(auxPasajero.flyCode,flycode,sizeof(auxPasajero.flyCode));
			auxPasajero.price=price;
			auxPasajero.typePassenger=typePassenger;
			auxPasajero.id=list[id].id;
			auxPasajero.statusFlight=TRUE;
			auxPasajero.isEmpty=FALSE;
			list[id]=auxPasajero;
		}
	}
	return retorno;
}

int findPassengerById(Passenger* list, int len,int id){		// --------------------------
	int retorno = -1;
	int i;
	if(list != NULL && len>0 && id>=0){
		for(i=0;i<len;i++){
			if(list[i].id==id){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}


int removePassenger(Passenger* list, int len, int id){		// XXXXXXXXXXXXXXXXXXXXXXXX
	int retorno = -1;
	if(list != NULL && len>0 && id>=0 && list[id].isEmpty==FALSE){
			retorno=0;
			list[id].isEmpty=TRUE;
	}
	return retorno;
}


int sortPassengers(Passenger* list, int len, int order){	// ----------------------------
	int retorno = -1;
	int flagSwap;
	int i;
	Passenger buffer;
	int auxiliarComparacion;
	int nuevoLimite;
	if(list != NULL && len > 0){
		nuevoLimite = len - 1;
		if(order==1){
			do{
				flagSwap=0;
				for(i=0;i<nuevoLimite;i++){
					if(list[i].isEmpty || list[i+1].isEmpty){
						continue;
					}
					auxiliarComparacion = strncmp(list[i].lastName,list[i+1].lastName,LARGOAPELLIDO);
					if(auxiliarComparacion>0 || (auxiliarComparacion==0 && list[i].typePassenger > list[i+1].typePassenger)){
						flagSwap=1;
						buffer = list[i];
						list[i] = list[i+1];
						list[i+1] = buffer;
					}
				}
				nuevoLimite--;
			}while(flagSwap);
		}
		else if(order==0){
			do{
				flagSwap=0;
				for(i=0;i<nuevoLimite;i++){
					if(list[i].isEmpty || list[i+1].isEmpty){
						continue;
					}
					auxiliarComparacion = strncmp(list[i].lastName,list[i+1].lastName,LARGOAPELLIDO);
					if(auxiliarComparacion<0 || (auxiliarComparacion==0 && list[i].typePassenger < list[i+1].typePassenger)){
						flagSwap=1;
						buffer = list[i];
						list[i] = list[i+1];
						list[i+1] = buffer;
					}
				}
				nuevoLimite--;
			}while(flagSwap);
		}
		retorno = 0;
	}
	return retorno;
}


int printPassenger(Passenger* list, int length){	// ------------------------
	int retorno = -1;
	int i;
	if(list != NULL && length >0){
		retorno = 0;
		for(i=0;i<length;i++){
			imprimirElementoPasajeros(&list[i]);
		}
	}
	return retorno;
}


int sortPassengersByCode(Passenger* list, int len, int order){	// ---------------------------
	int retorno = -1;
	int flagSwap;
	int i;
	Passenger buffer;
	int auxiliarComparacion;
	int nuevoLimite;
	if(list != NULL && len > 0){
		nuevoLimite = len - 1;
		if(order==1){
			do{
				flagSwap=0;
				for(i=0;i<nuevoLimite;i++){
					if(list[i].isEmpty || list[i+1].isEmpty){
						continue;
					}
					auxiliarComparacion = strncmp(list[i].flyCode,list[i+1].flyCode,LARGOCODIGO);
					if(auxiliarComparacion>0 || (auxiliarComparacion==0 && list[i].statusFlight > list[i+1].statusFlight)){
						flagSwap=1;
						buffer = list[i];
						list[i] = list[i+1];
						list[i+1] = buffer;
					}
				}
				nuevoLimite--;
			}while(flagSwap);
		}
		else if(order==0){
			do{
				flagSwap=0;
				for(i=0;i<nuevoLimite;i++){
					if(list[i].isEmpty || list[i+1].isEmpty){
						continue;
					}
					auxiliarComparacion = strncmp(list[i].flyCode,list[i+1].flyCode,LARGOCODIGO);
					if(auxiliarComparacion<0 || (auxiliarComparacion==0 && list[i].statusFlight < list[i+1].statusFlight)){
						flagSwap=1;
						buffer = list[i];
						list[i] = list[i+1];
						list[i+1] = buffer;
					}
				}
				nuevoLimite--;
			}while(flagSwap);
		}
		retorno = 0;
	}
	return retorno;
}


int imprimirElementoPasajeros(Passenger* pPasajero){	// --------------------
	int retorno = -1;
	if(pPasajero != NULL && pPasajero->isEmpty==0){
		retorno = 0;
		printf("ID: %d - Name: %s - Last Name: %s - Price: %.2f - FlyCode: %s - Type Passenger: %d\n",pPasajero->id,pPasajero->name,pPasajero->lastName,pPasajero->price,pPasajero->flyCode,pPasajero->typePassenger);
	}
	return retorno;
}



int buscarProximoIndiceVacioPasajeros(Passenger listaPasajeros[],int limite){	// -----------------------
	int retorno = -1;
	int i;
	if(listaPasajeros != NULL && limite>0){
		for(i=0;i<limite;i++){
			if(listaPasajeros[i].isEmpty==TRUE){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
