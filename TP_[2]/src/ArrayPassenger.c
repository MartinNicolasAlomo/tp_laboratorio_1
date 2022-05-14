#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "Input.h"
#define CANTPASAJEROS 4
#define CANTTIPOSPASAJERO 4
#define CANTESTADOSVUELO 4
#define REINTENTOS 3
#define LARGOMENSAJE 500
#define LARGOTEXTO 16
#define TRUE 1
#define FALSE 0

static const char TXT_TYPEPASSENGER[CANTTIPOSPASAJERO][LARGOTEXTO]={"Economico","Premium","Ejecutivo","Primera Clase"};
static const char TXT_STATUSFLIGHT[CANTESTADOSVUELO][LARGOTEXTO]={"Activo","Demorado","Reprogramado","Cancelado"};

static int idIncremental=0;
/// @brief Genera un codigo que se incrementa en 1 cada vez que se llama a la funcion
/// @return Retorna el codigo incrementado en 1 respecto al anterior
static int pasaj_generarId(void);
static int pasaj_generarId(void){
	return idIncremental++;
}


int pasaj_menuPrincipal(void){
	int retorno=-1;
	Passenger aPasajeros[CANTPASAJEROS];
	int opcion=0;
	int idPasajeros;
	int indiceLibre;
	int idABuscar;
	int idEncontrado;
	int cantidadIngresos=0;
	float calculadorPrecios=0;
	int contadorPasajeros=0;
	char mensajeOpcionIngreso[LARGOMENSAJE];
	char mensajeOpcionError[LARGOMENSAJE];
	char mensajeIDModificar[LARGOMENSAJE];
	char mensajeOpcionModificar[LARGOMENSAJE];
	char mensajeIDEliminar[LARGOMENSAJE];
	char mensajeIDError[LARGOMENSAJE];
	char mensajeInforme[LARGOMENSAJE];
	char mensajeOrden[LARGOMENSAJE];

	strncpy(mensajeOpcionIngreso,"1-Dar de alta un pasajero\n2-Modificar un pasajero\n3-Dar de baja un pasajero\n4-Informar\n5-Carga forzada\n6-Salir\n\n",sizeof(mensajeOpcionIngreso));
	strncpy(mensajeOpcionError,"No es una opción válida, reinténtelo de nuevo.\n\n\n",sizeof(mensajeOpcionError));
	strncpy(mensajeIDModificar,"Ingrese el ID que desea modificar:\n\n",sizeof(mensajeIDModificar));
	strncpy(mensajeOpcionModificar,"¿Qué desea informar?\n1-Nombre\n2-Apellido\n3-Precio\n4-Tipo de pasajero\n5-Codigo de vuelo\n6-Finalizar cambios\n\n",sizeof(mensajeOpcionModificar));
	strncpy(mensajeIDEliminar,"Ingrese el ID que desea eliminar:\n\n",sizeof(mensajeIDEliminar));
	strncpy(mensajeIDError,"No es un ID válido, reinténtelo de nuevo.\n\n\n",sizeof(mensajeIDError));
	strncpy(mensajeInforme,"¿Qué desea informar?\n1-Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n2-Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n3-Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’.\n\n",sizeof(mensajeInforme));
	strncpy(mensajeOrden,"¿En qué orden quiere ordenarlos?\n1-Ascendente\n0-Descendente\n\n",sizeof(mensajeOrden));

	if(!initPassengers(aPasajeros, CANTPASAJEROS)){
		puts("Se inicializaron los pasajeros.\n\n");
	}
	else{
		puts("Falló la inicialización.\n\n\n");
	}

	do{
		if(!ingresarEntero(&opcion, mensajeOpcionIngreso, mensajeOpcionError, 1, 6, REINTENTOS)){
			switch(opcion){
			case 1:
				indiceLibre=pasaj_buscarProximoIndiceVacio(aPasajeros, CANTPASAJEROS);
				if(indiceLibre>=0){
					idPasajeros=pasaj_generarId();
					if(!pasaj_cargarPasajero(aPasajeros, CANTPASAJEROS, idPasajeros)){
						printf("Se cargaron los datos del nuevo pasajero. ID: %d.\n\n",idPasajeros);
						calculadorPrecios=calculadorPrecios+aPasajeros[idPasajeros].price;
						contadorPasajeros++;
						cantidadIngresos++;
					}
					else{
						puts("Falló la carga de datos.\n\n\n");
					}
				}
				else{
					puts("No hay mas lugar disponible.\n\n\n");
				}
				break;
			case 2:
				if(cantidadIngresos==0){
					puts("No hay pasajeros para mostrar.\n\n\n");
				}
				else{
					if(!ingresarEntero(&idABuscar, mensajeIDModificar, mensajeIDError, 0, idPasajeros, REINTENTOS)){
						idEncontrado=findPassengerById(aPasajeros, CANTPASAJEROS, idABuscar);
						if(idEncontrado>=0){
							puts("opción 2.\n\n");
							calculadorPrecios=calculadorPrecios-aPasajeros[idEncontrado].price;
							if(!pasaj_modificarPasajero(aPasajeros, CANTPASAJEROS, idEncontrado, mensajeOpcionModificar, mensajeOpcionError)){
								printf("Se modificaron los datos del pasajero con el ID: %d.\n\n",idEncontrado);
								calculadorPrecios=calculadorPrecios+aPasajeros[idEncontrado].price;
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
				break;
			case 3:
				if(cantidadIngresos==0){
					puts("No hay pasajeros para mostrar.\n\n\n");
				}
				else{
					if(!ingresarEntero(&idABuscar, mensajeIDEliminar, mensajeIDError, 0, idPasajeros, REINTENTOS)){
						idEncontrado=findPassengerById(aPasajeros, CANTPASAJEROS, idABuscar);
						if(idEncontrado>=0){
							puts("opcion 3\n\n");
							if(!removePassenger(aPasajeros, CANTPASAJEROS, idEncontrado)){
								printf("Se eliminaron los datos del pasajero con el ID: %d.\n\n",idEncontrado);
								calculadorPrecios=calculadorPrecios-aPasajeros[idEncontrado].price;
								contadorPasajeros--;
								cantidadIngresos--;
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
			case 4:
				if(cantidadIngresos==0){
					puts("No hay pasajeros para mostrar.\n\n\n");
				}
				else{
					if(!pasaj_menuInformes(aPasajeros, CANTPASAJEROS, mensajeInforme, mensajeOrden, mensajeOpcionError, calculadorPrecios, contadorPasajeros)){
						puts("Informe finalizado.\n\n\n");
					}
					else{
						puts("No se pudo mostrar el informe.\n\n\n");
					}
				}
				break;
			case 5:
				indiceLibre=pasaj_buscarProximoIndiceVacio(aPasajeros, CANTPASAJEROS);
				if(indiceLibre>=0){
					idPasajeros=pasaj_generarId();
					if(!pasaj_cargaForzadaPasajero(aPasajeros, CANTPASAJEROS, idPasajeros, "Camila", "Lolo", 9000, "AJ028", 1, 3)){
						calculadorPrecios=calculadorPrecios+aPasajeros[idPasajeros].price;
						contadorPasajeros++;
						cantidadIngresos++;
					}
				}
				else{
					puts("No hay mas lugar disponible.\n");
				}

				indiceLibre=pasaj_buscarProximoIndiceVacio(aPasajeros, CANTPASAJEROS);
				if(indiceLibre>=0){
					idPasajeros=pasaj_generarId();
					if(!pasaj_cargaForzadaPasajero(aPasajeros, CANTPASAJEROS, idPasajeros, "Matias", "Lolo", 60, "CL046", 4, 2)){
						calculadorPrecios=calculadorPrecios+aPasajeros[idPasajeros].price;
						contadorPasajeros++;
						cantidadIngresos++;
					}
				}
				else{
					puts("No hay mas lugar disponible.\n");
				}

				indiceLibre=pasaj_buscarProximoIndiceVacio(aPasajeros, CANTPASAJEROS);
				if(indiceLibre>=0){
					idPasajeros=pasaj_generarId();
					if(!pasaj_cargaForzadaPasajero(aPasajeros, CANTPASAJEROS, idPasajeros, "Gonzalo", "Cece", 9000, "CL046", 2, 4)){
						calculadorPrecios=calculadorPrecios+aPasajeros[idPasajeros].price;
						contadorPasajeros++;
						cantidadIngresos++;
					}
				}
				else{
					puts("No hay mas lugar disponible.\n");
				}

				indiceLibre=pasaj_buscarProximoIndiceVacio(aPasajeros, CANTPASAJEROS);
				if(indiceLibre>=0){
					idPasajeros=pasaj_generarId();
					if(!pasaj_cargaForzadaPasajero(aPasajeros, CANTPASAJEROS, idPasajeros, "Daiana", "Vivi", 60, "AJ028", 4, 2)){
						calculadorPrecios=calculadorPrecios+aPasajeros[idPasajeros].price;
						contadorPasajeros++;
						cantidadIngresos++;
					}
				}
				else{
					puts("No hay mas lugar disponible.\n");
				}

				indiceLibre=pasaj_buscarProximoIndiceVacio(aPasajeros, CANTPASAJEROS);
				if(indiceLibre>=0){
					idPasajeros=pasaj_generarId();
					if(!pasaj_cargaForzadaPasajero(aPasajeros, CANTPASAJEROS, idPasajeros, "Ruben", "Lolo", 60, "AJ028", 3, 1)){
						calculadorPrecios=calculadorPrecios+aPasajeros[idPasajeros].price;
						contadorPasajeros++;
						cantidadIngresos++;
					}
				}
				else{
					puts("No hay mas lugar disponible.\n");
				}

				indiceLibre=pasaj_buscarProximoIndiceVacio(aPasajeros, CANTPASAJEROS);
				if(indiceLibre>=0){
					idPasajeros=pasaj_generarId();
					if(!pasaj_cargaForzadaPasajero(aPasajeros, CANTPASAJEROS, idPasajeros, "Zoe", "Cece", 60, "EN050", 1, 3)){
						calculadorPrecios=calculadorPrecios+aPasajeros[idPasajeros].price;
						contadorPasajeros++;
						cantidadIngresos++;
					}
				}
				else{
					puts("No hay mas lugar disponible.\n");
				}

				puts("Se hardcodearon los 6 pasajeros exitosamente.\n");
				printPassengers(aPasajeros, CANTPASAJEROS);
				break;
			case 6:
				puts("Usted finalizó la operación.\n\n");
				retorno=0;
				break;
			}
		}
		else{
			puts("No se pudo ingresar la opción\n\n\n");
		}
	}while(opcion!=6);
	return retorno;
}



int pasaj_cargaForzadaPasajero(Passenger vector[], int limite, int id,char name[],char lastName[],float price,char flyCode[],int typePassenger,int statusFlight){
	int retorno = -1;
	Passenger auxPasajero;
	if(vector != NULL && limite>0 && id>=0 && name != NULL && lastName != NULL && price>0 && flyCode != NULL){
		retorno=0;
		auxPasajero.id=id;
		strncpy(auxPasajero.name,name,LARGONOMBRE);
		strncpy(auxPasajero.lastName,lastName,LARGOAPELLIDO);
		strncpy(auxPasajero.flyCode,flyCode,LARGOCODIGO);
		auxPasajero.price=price;
		auxPasajero.typePassenger=typePassenger;
		auxPasajero.statusFlight=statusFlight;
		auxPasajero.isEmpty=FALSE;
		vector[id]=auxPasajero;
	}
	return retorno;
}

int initPassengers(Passenger* list, int len){
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

int addPassenger(Passenger* list,int len,int id, char name[],char lastName[],float price,int typePassenger,int statusFlight,char flycode[]){
	int retorno = -1;
	Passenger auxPasajero;
	int confirmar;
	if(list != NULL && len>0 && id>=0 && name != NULL && lastName != NULL && price>0 && typePassenger>0 && statusFlight>0 && flycode != NULL){
		if(!ingresarEntero(&confirmar, "\n¿Está seguro/a de quiere agregar este pasajero? (1- Si / 2- No)\n\n", "No es una opción válida, reinténtelo de nuevo.\n\n\n", 1, 2, REINTENTOS)){
			if(confirmar==1){
				retorno=0;
				strncpy(auxPasajero.name,name,sizeof(auxPasajero.name));
				strncpy(auxPasajero.lastName,lastName,sizeof(auxPasajero.lastName));
				auxPasajero.price=price;
				auxPasajero.typePassenger=typePassenger;
				auxPasajero.statusFlight=statusFlight;
				strncpy(auxPasajero.flyCode,flycode,sizeof(auxPasajero.flyCode));
				auxPasajero.id=id;
				auxPasajero.isEmpty=FALSE;
				list[id]=auxPasajero;
				puts("Confirmado.\n");
			}
			else if(confirmar==2){
				puts("Cancelado. No se agregó el pasajero.\n");
			}
		}
		else{
			puts("No se pudo confirmar.\n\n");
		}
	}
	return retorno;
}

int pasaj_cargarPasajero(Passenger vector[],int limite,int id){
	int retorno=-1;
	Passenger auxPasajero;
	if(vector != NULL && limite>0 && id>=0){
		if(!ingresarNombreUnico(auxPasajero.name, LARGONOMBRE, "Ingrese el nombre:\n", "Error. No es un nombre, reinténtelo de nuevo.\n\n\n", REINTENTOS) &&
			!ingresarNombreUnico(auxPasajero.lastName, LARGOAPELLIDO, "Ingrese el apellido:\n", "Error. No es un apellido, reinténtelo de nuevo.\n\n\n", REINTENTOS) &&
			!ingresarFlotante(&auxPasajero.price, "Ingrese el precio del vuelo:\n", "Error. No es un precio válido, reinténtelo de nuevo.\n\n\n", 0.1, 500000, REINTENTOS) &&
			!ingresarEntero(&auxPasajero.typePassenger, "Ingrese el tipo de pasajero: (1 Económico, 2 Premium, 3 Ejecutivo o 4 Primera Clase)\n", "Error. No es un tipo válido, reinténtelo de nuevo.\n\n\n", 1, 4, REINTENTOS) &&
			!ingresarEntero(&auxPasajero.statusFlight, "Indique el estado de su vuelo: (1 Activo, 2 Demorado, 3 Reprogramado o 4 Cancelado)\n", "Error. No es un estado válido, reinténtelo de nuevo.\n\n\n", 1, 4, REINTENTOS) &&
			!ingresarAlfanumerico(auxPasajero.flyCode, LARGOCODIGO, "Ingrese el codigo de pasaje:\n", "Error. No es un tipo válido, reinténtelo de nuevo.\n\n\n", REINTENTOS)){
			if(!addPassenger(vector,limite,id,auxPasajero.name,auxPasajero.lastName,auxPasajero.price,auxPasajero.typePassenger,auxPasajero.statusFlight,auxPasajero.flyCode)){
				retorno=0;
			}
		}
	}
	return retorno;
}

int findPassengerById(Passenger* list, int len,int id){
	int retorno = -1;
	int i;
	if(list != NULL && len>0 && id>=0){
		for(i=0;i<len;i++){
			if(list[i].id==id){
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

int removePassenger(Passenger* list, int len, int id){
	int retorno = -1;
	int confirmar;
	if(list != NULL && len>0 && id>=0 && list[id].isEmpty==FALSE){
		if(!pasaj_imprimirElemento(&list[id])){
			if(!ingresarEntero(&confirmar, "¿Está seguro/a de quiere eliminar este pasajero? (1- Si / 2- No)\n\n", "No es una opción válida, reinténtelo de nuevo.\n\n\n", 1, 2, REINTENTOS)){
				if(confirmar==1){
					retorno=0;
					list[id].isEmpty=TRUE;
					puts("Confirmado.\n");
				}
				else if(confirmar==2){
					puts("Cancelado. No se eliminó el pasajero\n");
				}
			}
			else{
				puts("No se pudo confirmar.\n\n");
			}
		}
		else{
			puts("No se pudo mostrar el pasajero seleccionado.\n\n");
		}
	}
	return retorno;
}

int sortPassengers(Passenger* list, int len, int order){
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
				flagSwap=FALSE;
				for(i=0;i<nuevoLimite;i++){
					if(list[i].isEmpty || list[i+1].isEmpty){
						continue;
					}
					auxiliarComparacion = strncmp(list[i].lastName,list[i+1].lastName,LARGOAPELLIDO);
					if(auxiliarComparacion>0 || (auxiliarComparacion==0 && list[i].typePassenger > list[i+1].typePassenger)){
						flagSwap=TRUE;
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
				flagSwap=FALSE;
				for(i=0;i<nuevoLimite;i++){
					if(list[i].isEmpty || list[i+1].isEmpty){
						continue;
					}
					auxiliarComparacion = strncmp(list[i].lastName,list[i+1].lastName,LARGOAPELLIDO);
					if(auxiliarComparacion<0 || (auxiliarComparacion==0 && list[i].typePassenger < list[i+1].typePassenger)){
						flagSwap=TRUE;
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

int printPassengers(Passenger* list, int length){
	int retorno = -1;
	int i;
	if(list != NULL && length >0){
		retorno = 0;
		puts("  Id	     Nombre	    Apellido	     Precio	Codigo Vuelo	    Tipo Pasajero 	  Estado Vuelo\n");
		for(i=0;i<length;i++){
			pasaj_imprimirElemento(&list[i]);
		}
		puts("\n\n");

	}
	return retorno;
}

int sortPassengersByCode(Passenger* list, int len, int order){
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
				flagSwap=FALSE;
				for(i=0;i<nuevoLimite;i++){
					if(list[i].isEmpty || list[i+1].isEmpty){
						continue;
					}
					auxiliarComparacion = strncmp(list[i].flyCode,list[i+1].flyCode,LARGOCODIGO);
					if(auxiliarComparacion>0 || (auxiliarComparacion==0 && list[i].statusFlight > list[i+1].statusFlight)){
						flagSwap=TRUE;
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
				flagSwap=FALSE;
				for(i=0;i<nuevoLimite;i++){
					if(list[i].isEmpty || list[i+1].isEmpty){
						continue;
					}
					auxiliarComparacion = strncmp(list[i].flyCode,list[i+1].flyCode,LARGOCODIGO);
					if(auxiliarComparacion<0 || (auxiliarComparacion==0 && list[i].statusFlight < list[i+1].statusFlight)){
						flagSwap=TRUE;
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

int pasaj_buscarProximoIndiceVacio(Passenger vector[],int limite){
	int retorno = -1;
	int i;
	if(vector != NULL && limite>0){
		for(i=0;i<limite;i++){
			if(vector[i].isEmpty==TRUE){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int pasaj_modificarPasajero(Passenger vector[],int limite,int id,char mensajeOpcionModificar[],char mensajeOpcionError[]){
	int retorno=-1;
	Passenger auxPasajero;
	int opcion;
	int confirmar;
	if(vector != NULL && id>=0 && mensajeOpcionModificar != NULL && mensajeOpcionError != NULL){
		auxPasajero.id=vector[id].id;
		strncpy(auxPasajero.name,vector[id].name,sizeof(auxPasajero.name));
		strncpy(auxPasajero.lastName,vector[id].lastName,sizeof(auxPasajero.lastName));
		auxPasajero.price=vector[id].price;
		strncpy(auxPasajero.flyCode,vector[id].flyCode,sizeof(auxPasajero.flyCode));
		auxPasajero.typePassenger=vector[id].typePassenger;
		auxPasajero.statusFlight=vector[id].statusFlight;
		auxPasajero.isEmpty=FALSE;
		if(!pasaj_imprimirElemento(&vector[id])){
			do{
				if(!ingresarEntero(&opcion, mensajeOpcionModificar, mensajeOpcionError, 1, 6, REINTENTOS)){
					switch(opcion){
					case 1:
						if(!ingresarNombreUnico(auxPasajero.name, LARGONOMBRE, "Nuevo nombre:\n", "Error\n\n\n", REINTENTOS)){
							puts("Se modificó el nombre exitosamente.\n\n");
						}
						else{
							puts("Falló la modificación del nombre.\n\n\n");
						}
						break;
					case 2:
						if(!ingresarNombreUnico(auxPasajero.lastName, LARGOAPELLIDO, "Nuevo apellido:\n", "Error\n\n\n", REINTENTOS)){
							puts("Se modificó el apellido exitosamente.\n\n");
						}
						else{
							puts("Falló la modificación del apellido.\n\n\n");
						}
						break;
					case 3:
						if(!ingresarFlotante(&auxPasajero.price, "Nuevo precio:\n", "Error\n\n\n", 0.1, 500000, REINTENTOS)){
							puts("Se modificó el precio exitosamente.\n\n");
						}
						else{
							puts("Falló la modificación del precio.\n\n\n");
						}
						break;
					case 4:
						if(!ingresarEntero(&auxPasajero.typePassenger, "Nuevo tipo de pasajero: (1 Económico, 2 Premium, 3 Ejecutivo o 4 Primera Clase)\n", "Error\n\n\n", 1, 4, REINTENTOS)){
							puts("Se modificó el tipo de pasajero exitosamente.\n\n");
						}
						else{
							puts("Falló la modificación del tipo de pasajero.\n\n\n");
						}
						break;
					case 5:
						if(!ingresarAlfanumerico(auxPasajero.flyCode, LARGOCODIGO, "Nuevo codigo de vuelo:\n", "Error\n\n\n", REINTENTOS)){
							puts("Se modificó el codigo de vuelo exitosamente.\n\n");
						}
						else{
							puts("Falló la modificación del codigo de vuelo.\n\n\n");
						}
						break;
					case 6:
						if(!ingresarEntero(&confirmar, "¿Está seguro/a de quiere realizar las modificaciones? (1- Si / 2- No)\n\n", "No es una opción válida, reinténtelo de nuevo.\n\n\n", 1, 2, REINTENTOS)){
							if(confirmar==1){
								retorno=0;
								vector[id]=auxPasajero;
							}
							else if(confirmar==2){
								puts("No se guardaron los cambios\n\n");
							}
						}
						else{
							puts("No se pudo confirmar.\n\n\n");
						}

						break;
					}
				}
				else{
					puts("No se pudo ingresar una opción.\n\n\n");
				}
			}while(opcion!=6);
		}
	}
	return retorno;
}

int pasaj_menuInformes(Passenger vector[],int limite,char mensajeInforme[],char mensajeOrden[],char mensajeOpcionError[],float precioTotal,int cantidadTotal){
	int retorno=-1;
	int tipoInforme;
	int orden;
	float promedioPrecios;
	int cantidadMayoresPromedio;
	if(vector != NULL && mensajeInforme != NULL && mensajeOrden != NULL && mensajeOpcionError != NULL && precioTotal>0 && cantidadTotal>0){
		if(!ingresarEntero(&tipoInforme, mensajeInforme, mensajeOpcionError, 1, 3, REINTENTOS)){
			switch(tipoInforme){
			case 1:
				if(!ingresarEntero(&orden, mensajeOrden, mensajeOpcionError, 0, 1, REINTENTOS)){
					if(!sortPassengers(vector, limite, orden)){
						printPassengers(vector, limite);
						retorno=0;
					}
					else{
						puts("No se pudo ordenar la lista.\n\n\n");
					}
				}
				else{
					puts("No se pudo ingresar el orden deseado.\n\n\n");
				}
				break;
			case 2:
				if(!pasaj_calcularPrecioPromedio(&promedioPrecios, precioTotal, cantidadTotal)){
					printf("El total de los precios es: %.2f\n",precioTotal);
					printf("El promedio de los precios es: %.2f\n",promedioPrecios);
					if(!pasaj_calcularSuperanPrecioPromedio(vector, limite, &cantidadMayoresPromedio, promedioPrecios)){
						printf("La cantidad de pasajeros que supera el precio promedio es: %d\n\n",cantidadMayoresPromedio);
						retorno=0;
					}
					else{
						puts("No se pudo calcular lo solicitado");
					}
				}
				break;
			case 3:
				if(!ingresarEntero(&orden, mensajeOrden, mensajeOpcionError, 0, 1, REINTENTOS)){
					if(!sortPassengersByCode(vector, limite, orden)){
						printPassengers(vector, limite);
						retorno=0;
					}
					else{
						puts("No se pudo ordenar la lista.\n\n\n");
					}
				}
				else{
					puts("No se pudo ingresar el orden deseado.\n\n\n");
				}
				break;

			}
		}
		else{
			puts("No se pudo ingresar una opción.\n\n\n");
		}
	}
	return retorno;
}

int pasaj_calcularPrecioPromedio(float* pResultado, float precioTotal, float cantidadTotal){
	int retorno = -1;
	float resultado;
	if(pResultado != NULL && precioTotal>0 && cantidadTotal>0){
		resultado = precioTotal / cantidadTotal;
		*pResultado = resultado;
		retorno = 0;
	}
	return retorno;
}

int pasaj_calcularSuperanPrecioPromedio(Passenger vector[],int limite,int* pResultado, float precioPromedio){
	int retorno = -1;
	int i;
	int contadorMayorPromedio=0;
	if(vector != NULL && limite>0 && pResultado != NULL && precioPromedio>0){
		for(i=0;i<limite;i++){
			if(vector[i].isEmpty==FALSE && vector[i].price>precioPromedio){
				contadorMayorPromedio++;
			}
		}
		*pResultado=contadorMayorPromedio;
		retorno=0;
	}
	return retorno;
}

int pasaj_imprimirElemento(Passenger* pElemento){
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty==FALSE){
		retorno = 0;
		printf("%4d %15s %15s %15.2f %15s %20s %20s\n",pElemento->id,pElemento->name,pElemento->lastName,pElemento->price,pElemento->flyCode,TXT_TYPEPASSENGER[pElemento->typePassenger-1],TXT_STATUSFLIGHT[pElemento->statusFlight-1]);
	}
	return retorno;
}
