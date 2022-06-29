#include "ArrayPassenger.h"

static const char TXT_TYPEPASSENGER[CANTTIPOSPASAJERO][LARGOTEXTO]={"Economico","Premium","Ejecutivo","Primera Clase"};
static const char TXT_STATUSFLIGHT[CANTESTADOSVUELO][LARGOTEXTO]={"En Horario","En Vuelo","Demorado","Aterrizado"};

static int idIncremental=1;
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
	int totalPasajeros=0;
	float totalPrecios=0;

	if(!initPassengers(aPasajeros, CANTPASAJEROS)){
		puts("Se inicializaron los pasajeros.\n\n");
	}
	else{
		puts("Falló la inicialización.\n\n\n");
	}


	do{
		if(!ingresarEntero(&opcion, MSJ_MENUPRINCIPAL, MSJ_ERROROPCION, 1, 6, REINTENTOS)){
			switch(opcion){
			case 1:
				indiceLibre=pasaj_buscarProximoIndiceVacio(aPasajeros, CANTPASAJEROS);
				if(indiceLibre>=0){
					idPasajeros=pasaj_generarId();
					if(!pasaj_cargarPasajero(aPasajeros, CANTPASAJEROS, idPasajeros)){
						printf("Se cargaron los datos del nuevo pasajero. ID: %d.\n\n",idPasajeros);
						totalPrecios=totalPrecios+aPasajeros[idPasajeros].price;
						totalPasajeros++;
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
				if(!totalPasajeros){
					puts("No hay pasajeros para mostrar.\n\n\n");
				}
				else{
					if(!ingresarEntero(&idABuscar, MSJ_IDMODIFICAR, MSJ_ERRORID, 0, idPasajeros, REINTENTOS)){
						idEncontrado=findPassengerById(aPasajeros, CANTPASAJEROS, idABuscar);
						if(idEncontrado>=0){
							totalPrecios=totalPrecios-aPasajeros[idEncontrado].price;
							if(!pasaj_modificarPasajero(aPasajeros, CANTPASAJEROS, idEncontrado)){
								printf("Se modificaron los datos del pasajero con el ID: %d.\n\n",idEncontrado);
								totalPrecios=totalPrecios+aPasajeros[idEncontrado].price;
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
				if(!totalPasajeros){
					puts("No hay pasajeros para mostrar.\n\n\n");
				}
				else{
					if(!ingresarEntero(&idABuscar, MSJ_IDELIMINAR, MSJ_ERRORID, 0, idPasajeros, REINTENTOS)){
						idEncontrado=findPassengerById(aPasajeros, CANTPASAJEROS, idABuscar);
						if(idEncontrado>=0){
							puts("opcion 3\n\n");
							if(!removePassenger(aPasajeros, CANTPASAJEROS, idEncontrado)){
								printf("Se eliminaron los datos del pasajero con el ID: %d.\n\n",idEncontrado);
								totalPrecios=totalPrecios-aPasajeros[idEncontrado].price;
								totalPasajeros--;
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
				if(!totalPasajeros){
					puts("No hay pasajeros para mostrar.\n\n\n");
				}
				else{
					if(!pasaj_menuInformes(aPasajeros, CANTPASAJEROS, totalPrecios, totalPasajeros)){
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
					if(!pasaj_cargaForzadaPasajero(aPasajeros, CANTPASAJEROS, idPasajeros, "Camila", "Lolo", 9000, "ARG09BA", 1, 3)){
						totalPrecios=totalPrecios+aPasajeros[idPasajeros].price;
						totalPasajeros++;
					}
				}
				else{
					puts("No hay mas lugar disponible.\n");
				}

				indiceLibre=pasaj_buscarProximoIndiceVacio(aPasajeros, CANTPASAJEROS);
				if(indiceLibre>=0){
					idPasajeros=pasaj_generarId();
					if(!pasaj_cargaForzadaPasajero(aPasajeros, CANTPASAJEROS, idPasajeros, "Matias", "Lolo", 60, "ITA18RM", 4, 2)){
						totalPrecios=totalPrecios+aPasajeros[idPasajeros].price;
						totalPasajeros++;
					}
				}
				else{
					puts("No hay mas lugar disponible.\n");
				}

				indiceLibre=pasaj_buscarProximoIndiceVacio(aPasajeros, CANTPASAJEROS);
				if(indiceLibre>=0){
					idPasajeros=pasaj_generarId();
					if(!pasaj_cargaForzadaPasajero(aPasajeros, CANTPASAJEROS, idPasajeros, "Gonzalo", "Cece", 9000, "ARG09BA", 2, 4)){
						totalPrecios=totalPrecios+aPasajeros[idPasajeros].price;
						totalPasajeros++;
					}
				}
				else{
					puts("No hay mas lugar disponible.\n");
				}

				indiceLibre=pasaj_buscarProximoIndiceVacio(aPasajeros, CANTPASAJEROS);
				if(indiceLibre>=0){
					idPasajeros=pasaj_generarId();
					if(!pasaj_cargaForzadaPasajero(aPasajeros, CANTPASAJEROS, idPasajeros, "Daiana", "Vivi", 60, "ARG09BA", 4, 2)){
						totalPrecios=totalPrecios+aPasajeros[idPasajeros].price;
						totalPasajeros++;
					}
				}
				else{
					puts("No hay mas lugar disponible.\n");
				}

				indiceLibre=pasaj_buscarProximoIndiceVacio(aPasajeros, CANTPASAJEROS);
				if(indiceLibre>=0){
					idPasajeros=pasaj_generarId();
					if(!pasaj_cargaForzadaPasajero(aPasajeros, CANTPASAJEROS, idPasajeros, "Ruben", "Lolo", 60, "ITA18RM", 3, 1)){
						totalPrecios=totalPrecios+aPasajeros[idPasajeros].price;
						totalPasajeros++;
					}
				}
				else{
					puts("No hay mas lugar disponible.\n");
				}

				indiceLibre=pasaj_buscarProximoIndiceVacio(aPasajeros, CANTPASAJEROS);
				if(indiceLibre>=0){
					idPasajeros=pasaj_generarId();
					if(!pasaj_cargaForzadaPasajero(aPasajeros, CANTPASAJEROS, idPasajeros, "Zoe", "Cece", 60, "JAP27TK", 1, 3)){
						totalPrecios=totalPrecios+aPasajeros[idPasajeros].price;
						totalPasajeros++;
					}
				}
				else{
					puts("No hay mas lugar disponible.\n");
				}

				puts("Se hardcodearon los pasajeros exitosamente.\n");
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











int pasaj_cargaForzadaPasajero(Passenger* vector,int limite,int id,char* name,char* lastName,float price,char* flyCode,int typePassenger,int statusFlight){
	int retorno=-1;
	Passenger auxPasajero;
	if(vector!=NULL && limite>0 && id>=0 && name!=NULL && lastName!=NULL && price>0 && flyCode!=NULL){
		retorno=0;
		auxPasajero.id=id;
		strncpy(auxPasajero.name,name,LARGONOMBRE);
		strncpy(auxPasajero.lastName,lastName,LARGONOMBRE);
		strncpy(auxPasajero.flyCode,flyCode,LARGOCODIGO);
		auxPasajero.price=price;
		auxPasajero.typePassenger=typePassenger;
		auxPasajero.statusFlight=statusFlight;
		auxPasajero.isEmpty=FALSE;
		vector[id]=auxPasajero;
	}
	return retorno;
}

int initPassengers(Passenger* list,int len){
	int retorno=-1;
	int i;
	if(list!=NULL && len>0){
		retorno=0;
		for(i=0;i<len;i++){
			list[i].isEmpty=TRUE;
		}
	}
	return retorno;
}

int addPassenger(Passenger* list,int len,int id,char name[],char lastName[],float price,int typePassenger,int statusFlight,char flycode[]){
	int retorno=-1;
	Passenger auxPasajero;
	int confirmar;
	if(list!=NULL && len>0 && id>=0 && name!=NULL && lastName!=NULL && price>0 && typePassenger>0 && statusFlight>0 && flycode!=NULL){
		if(!ingresarEntero(&confirmar, MSJ_CONFIRMARAGREGADO, MSJ_ERROROPCION, 0, 1, REINTENTOS)){
			if(confirmar){
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
				printf("Pasajero encontrado:\n|%-10s| %-25s| %-25s| %-15s| %-25s| %-25s| %-25s|\n",
							"Id:","Nombre:","Apellido:","Precio:","Codigo de Vuelo:","Tipo de Pasajero:","Estado de Vuelo:");
				pasaj_imprimirElemento(&list[id]);
				puts("\n\n");
				puts("Confirmado.\n");
			}
			else{
				puts("Cancelado. No se agregó el pasajero.\n");
			}
		}
		else{
			puts("No se pudo confirmar.\n\n");
		}
	}
	return retorno;
}

int pasaj_cargarPasajero(Passenger* vector,int limite,int id){
	int retorno=-1;
	Passenger auxPasajero;
	if(vector!=NULL && limite>0 && id>=0){
		if(!ingresarNombre(auxPasajero.name, LARGONOMBRE, "Ingrese el nombre:\n", "Error. No es un nombre, reinténtelo de nuevo.\n\n\n", REINTENTOS) &&
			!ingresarNombre(auxPasajero.lastName, LARGONOMBRE, "Ingrese el apellido:\n", "Error. No es un apellido, reinténtelo de nuevo.\n\n\n", REINTENTOS) &&
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

int findPassengerById(Passenger* list,int len,int id){
	int retorno=-1;
	int i;
	if(list!=NULL && len>0 && id>=0){
		for(i=0;i<len;i++){
			if(list[i].id==id){
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

int removePassenger(Passenger* list,int len,int id){
	int retorno=-1;
	int confirmar;
	if(list!=NULL && len>0 && id>=0 && list[id].isEmpty==FALSE){
		printf("Pasajero seleccionado:\n|%-10s| %-25s| %-25s| %-15s| %-25s| %-25s| %-25s|\n",
					"Id:","Nombre:","Apellido:","Precio:","Codigo de Vuelo:","Tipo de Pasajero:","Estado de Vuelo:");
		pasaj_imprimirElemento(&list[id]);
		puts("\n\n");
		if(!ingresarEntero(&confirmar, MSJ_CONFIRMARELIMINADO, MSJ_OPCIONORDEN, 0, 1, REINTENTOS)){
			if(confirmar){
				retorno=0;
				list[id].isEmpty=TRUE;
				puts("Confirmado.\n");
			}
			else{
				puts("Cancelado. No se eliminó el pasajero\n");
			}
		}
		else{
			puts("No se pudo confirmar.\n\n");
		}
	}
	return retorno;
}

int sortPassengers(Passenger* list,int len,int order){
	int retorno=-1;
	int flagSwap;
	int i;
	Passenger buffer;
	int auxiliarComparacion;
	int nuevoLimite;
	if(list!=NULL && len>0){
		nuevoLimite=len-1;
		if(order){
			do{
				flagSwap=FALSE;
				for(i=0;i<nuevoLimite;i++){
					if(list[i].isEmpty || list[i+1].isEmpty){
						continue;
					}
					auxiliarComparacion = strncmp(list[i].lastName,list[i+1].lastName,LARGONOMBRE);
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
		else{
			do{
				flagSwap=FALSE;
				for(i=0;i<nuevoLimite;i++){
					if(list[i].isEmpty || list[i+1].isEmpty){
						continue;
					}
					auxiliarComparacion = strncmp(list[i].lastName,list[i+1].lastName,LARGONOMBRE);
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

int sortPassengersByCode(Passenger* list,int len,int order){
	int retorno=-1;
	int flagSwap;
	int i;
	Passenger buffer;
	int auxiliarComparacion;
	int nuevoLimite;
	if(list!=NULL && len>0){
		nuevoLimite=len-1;
		if(order){
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
		else{
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
		retorno=0;
	}
	return retorno;
}

int pasaj_buscarProximoIndiceVacio(Passenger* vector,int limite){
	int retorno=-1;
	int i;
	if(vector!=NULL && limite>0){
		for(i=0;i<limite;i++){
			if(vector[i].isEmpty==TRUE){
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

int pasaj_modificarPasajero(Passenger* vector,int limite,int id){
	int retorno=-1;
	Passenger auxiliar;
	int opcion;
	int flagCambio=1;
	int confirmar;
	if(vector!=NULL && id>=0){
		auxiliar.id=vector[id].id;
		strncpy(auxiliar.name,vector[id].name,sizeof(auxiliar.name));
		strncpy(auxiliar.lastName,vector[id].lastName,sizeof(auxiliar.lastName));
		auxiliar.price=vector[id].price;
		strncpy(auxiliar.flyCode,vector[id].flyCode,sizeof(auxiliar.flyCode));
		auxiliar.typePassenger=vector[id].typePassenger;
		auxiliar.statusFlight=vector[id].statusFlight;
		auxiliar.isEmpty=FALSE;
		printf("Pasajero seleccionado:\n|%-10s| %-25s| %-25s| %-15s| %-25s| %-25s| %-25s|\n",
										"Id:","Nombre:","Apellido:","Precio:","Codigo de Vuelo:","Tipo de Pasajero:","Estado de Vuelo:");
		pasaj_imprimirElemento(&vector[id]);
		puts("\n\n");
		do{
			if(!ingresarEntero(&opcion, MSJ_MENUMODIFICAR, MSJ_ERROROPCION, 1, 6, REINTENTOS)){
				switch(opcion){
				case 1:
					if(!ingresarNombre(auxiliar.name, LARGONOMBRE, "Nuevo nombre:\n", "Error\n\n\n", REINTENTOS) &&
							!pasarInicialesNombreMayusculas(auxiliar.name, LARGOCODIGO)){
						puts("Nombre ingresado correctamente.\n\n");
						flagCambio=0;
					}
					else{
						puts("No se ingresó un nombre válido.\n\n");
					}
					break;
				case 2:
					if(!ingresarNombre(auxiliar.lastName, LARGONOMBRE, "Nuevo apellido:\n", "Error\n\n\n", REINTENTOS) &&
							!pasarInicialesNombreMayusculas(auxiliar.lastName, LARGOCODIGO)){
						puts("Apellido ingresado correctamente.\n\n");
						flagCambio=0;
					}
					else{
						puts("No se ingresó un apellido válido.\n\n");
					}
					break;
				case 3:
					if(!ingresarFlotante(&auxiliar.price, "Nuevo precio:\n", "Error\n\n\n", 0.1, 500000, REINTENTOS)){
						puts("Precio ingresado correctamente.\n\n");
						flagCambio=0;
					}
					else{
						puts("No se ingresó un precio válido.\n\n");
					}
					break;
				case 4:
					if(!ingresarEntero(&auxiliar.typePassenger, "Nuevo tipo de pasajero:\n  1- Económico\n  2- Premium\n  3- Ejecutivo\n  4- Primera Clase\n", "Error\n\n\n", 1, 4, REINTENTOS)){
						puts("Tipo de pasajero ingresado correctamente.\n\n");
						flagCambio=0;
					}
					else{
						puts("No se ingresó un tipo de pasajero válido.\n\n");
					}
					break;
				case 5:
					if(!ingresarAlfanumerico(auxiliar.flyCode, LARGOCODIGO, "Nuevo codigo de vuelo:\n", "Error\n\n\n", REINTENTOS)){
						strupr(auxiliar.flyCode);
						puts("Código de vuelo ingresado correctamente.\n\n");
						flagCambio=0;
					}
					else{
						puts("No se ingresó un código de vuelo válido.\n\n");
					}
					break;
				case 6:
					if(!flagCambio){
						if(!ingresarEntero(&confirmar, MSJ_CONFIRMARMODIFICACION, MSJ_ERROROPCION, 0, 1, REINTENTOS)){
							if(confirmar){
								vector[id]=auxiliar;
								printf("Pasajero modificado:\n|%-10s| %-25s| %-25s| %-15s| %-25s| %-25s| %-25s|\n",
																"Id:","Nombre:","Apellido:","Precio:","Codigo de Vuelo:","Tipo de Pasajero:","Estado de Vuelo:");
								pasaj_imprimirElemento(&vector[id]);
								puts("\n\n");
								retorno=0;
							}
							else{
								puts("No se guardaron los cambios\n\n");
							}
						}
						else{
							puts("No se pudo confirmar.\n\n\n");
						}
					}
					else{
						puts("No se realizó ningun cambio en los datos del álbum.\n\n\n");
					}
					break;
				}
			}
			else{
				puts("No se pudo ingresar una opción.\n\n\n");
			}
		}while(opcion!=6);
	}
	return retorno;
}

int pasaj_menuInformes(Passenger* vector,int limite,float precioTotal,int cantidadTotal){
	int retorno=-1;
	int tipoInforme;
	int orden;
	float promedioPrecios;
	int cantidadMayoresPromedio;
	if(vector!=NULL && precioTotal>0 && cantidadTotal>0){
		if(!ingresarEntero(&tipoInforme, MSJ_MENUINFORME, MSJ_ERROROPCION, 1, 3, REINTENTOS)){
			switch(tipoInforme){
			case 1:
				if(!ingresarEntero(&orden, MSJ_OPCIONORDEN, MSJ_ERROROPCION, 0, 1, REINTENTOS)){
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
				if(!ingresarEntero(&orden, MSJ_OPCIONORDEN, MSJ_ERROROPCION, 0, 1, REINTENTOS)){
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

int pasaj_calcularPrecioPromedio(float* pResultado,float precioTotal,float cantidadTotal){
	int retorno=-1;
	float resultado;
	if(pResultado!=NULL && precioTotal>0 && cantidadTotal>0){
		resultado=precioTotal/cantidadTotal;
		*pResultado=resultado;
		retorno=0;
	}
	return retorno;
}

int pasaj_calcularSuperanPrecioPromedio(Passenger* vector,int limite,int* pResultado,float precioPromedio){
	int retorno=-1;
	int i;
	int contadorMayorPromedio=0;
	if(vector!=NULL && limite>0 && pResultado!=NULL && precioPromedio>0){
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


int printPassengers(Passenger* list,int length){
	int retorno=-1;
	int i;
	if(list!=NULL && length>0){
		retorno=0;
		printf("Lista de pasajeros:\n|%-10s| %-25s| %-25s| %-15s| %-25s| %-25s| %-25s|\n",
										"Id:","Nombre:","Apellido:","Precio:","Codigo de Vuelo:","Tipo de Pasajero:","Estado de Vuelo:");
		for(i=0;i<length;i++){
			pasaj_imprimirElemento(&list[i]);
		}
		puts("\n\n");
	}
	return retorno;
}


//	paramtros ()
int pasaj_imprimirElemento(Passenger* pElemento){
	int retorno=-1;
	if(pElemento!=NULL && pElemento->isEmpty==FALSE){
		retorno=0;
		printf("|%10d| %25s| %25s| %15.2f| %25s| %25s| %25s|\n",pElemento->id,pElemento->name,pElemento->lastName,pElemento->price,pElemento->flyCode,TXT_TYPEPASSENGER[pElemento->typePassenger-1],TXT_STATUSFLIGHT[pElemento->statusFlight-1]);
	}
	return retorno;
}
