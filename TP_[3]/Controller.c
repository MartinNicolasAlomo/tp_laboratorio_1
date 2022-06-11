#include "Controller.h"
#define ARCHIVO_ID "id.txt"


//****************************************************************************************************************************************************
static const char TXT_TYPEPASSENGER[3][LARGODESCRIPCION]={"EconomyClass","ExecutiveClass","FirstClass"};
static const char TXT_STATUSFLIGHT[4][LARGODESCRIPCION]={"En Horario","En Vuelo","Demorado","Aterrizado"};
//****************************************************************************************************************************************************


int idGlobal=0;
//****************************************************************************************************************************************************


/// @brief - Incrementa el id recibido en 1 y lo devuelve
/// @return - Retorna el id incrementado
static int idIncremental(){
	idGlobal++;
	return idGlobal;
}
//****************************************************************************************************************************************************


int Controller_cargarUltimoId(){
	int retorno=-1;
	FILE* pArchivo;
	char auxId[20];

	pArchivo=fopen(ARCHIVO_ID,"r");
	if(pArchivo!=NULL && fscanf(pArchivo,"%s",auxId)==1){
		idGlobal=atoi(auxId);
		fclose(pArchivo);
		retorno=0;
	}
	else if(fscanf(pArchivo,"%s",auxId)!=1){
		retorno=-2;
	}
	return retorno;
}
//****************************************************************************************************************************************************


int Controller_guardarUltimoId(){
	int retorno=-1;
	FILE* pArchivo;

	pArchivo=fopen(ARCHIVO_ID,"w");
	if(pArchivo!=NULL){
		fprintf(pArchivo,"%d",idGlobal);
		fclose(pArchivo);
	}
	return retorno;
}
//****************************************************************************************************************************************************


int controller_loadFromText(char* path , LinkedList* pArrayListPassenger){
	int retorno=-1;
	FILE* pArchivo=NULL;
	if(path!=NULL && pArrayListPassenger!=NULL){
		pArchivo = fopen(path,"r");
		if(pArchivo!=NULL){
			if(!parser_PassengerFromText(pArchivo, pArrayListPassenger)){
				retorno=0;
				fclose(pArchivo);
			}
			else{
				retorno=-4;
			}
		}
		else{
			retorno=-3;
		}
	}
	else if(pArrayListPassenger==NULL){
		retorno=-2;
	}
    return retorno;
}
//****************************************************************************************************************************************************


int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger){
	int retorno=-1;
	FILE* pArchivo=NULL;

	if(path!=NULL && pArrayListPassenger!=NULL){
		pArchivo = fopen(path,"rb");
		if(pArchivo!=NULL){
			if(!parser_PassengerFromBinary(pArchivo, pArrayListPassenger)){
				retorno=0;
				fclose(pArchivo);
			}
			else{
				retorno=-4;
			}
		}
		else{
			retorno=-3;
		}
	}
	else if(pArrayListPassenger==NULL){
		retorno=-2;
	}
	return retorno;
}
//****************************************************************************************************************************************************


int controller_addPassenger(LinkedList* pArrayListPassenger){
    int retorno=-1;
	Passenger auxiliar;
	Passenger* pPasajero=NULL;
	int confirmar;

	if(pArrayListPassenger!=NULL){
		pPasajero=Passenger_new();
		if(pPasajero!=NULL && !Passenger_cargarPasajero(&auxiliar)){
			if(!ingresarEntero(&confirmar, "¿Está seguro/a de quiere agregar este pasajero?\n  1- Si\n  0- No\n\n", MSJ_ERROROPCION, 0, 1, REINTENTOS)){
				if(confirmar){
					auxiliar.id=idIncremental();
					if(auxiliar.id>0 && !Passenger_setId(pPasajero, auxiliar.id) &&
							!Passenger_setNombre(pPasajero, auxiliar.nombre) &&
							!Passenger_setApellido(pPasajero, auxiliar.apellido) &&
							!Passenger_setPrecio(pPasajero, auxiliar.precio) &&
							!Passenger_setCodigoVuelo(pPasajero, auxiliar.codigoVuelo)&&
							!Passenger_setTipoPasajeroNumerico(pPasajero, auxiliar.tipoPasajero) &&
							!Passenger_setEstadoVueloNumerico(pPasajero, auxiliar.estadoVuelo) &&
							!ll_add(pArrayListPassenger, pPasajero)){
						puts("Se cargaron los datos del nuevo pasajero exitosamente.\n");
						retorno=0;
					}
					else if(auxiliar.id<=0){
						retorno=-6;
					}
					else if(ll_add(pArrayListPassenger, pPasajero)==-1){
						retorno=-8;
					}
					else{
						Passenger_delete(&auxiliar);
						if(!ll_remove(pArrayListPassenger, auxiliar.id)){
							retorno=-7;
						}
					}
				}
				else if(!confirmar){
					retorno=-5;
				}
			}
			else{
				retorno=-4;
			}
		}
		else if(pPasajero==NULL){
			retorno=-2;
		}
		else{
			retorno=-3;
		}
	}
    return retorno;
}
//****************************************************************************************************************************************************


int Controller_buscarPorId(LinkedList* pArrayListPassenger,int id){
	int retorno=-1;
    Passenger* pPasajero=NULL;
	int i;
    int largo;
    int bufferId;

	if(pArrayListPassenger!=NULL && id>0){
    	largo=ll_len(pArrayListPassenger);
		for(i=0;i<largo;i++){
			pPasajero=(Passenger*)ll_get(pArrayListPassenger, i);
			if(pPasajero!=NULL && !Passenger_getId(pPasajero, &bufferId) && id==bufferId){
				retorno=i;
				break;
			}
			else if(pPasajero==NULL){
				puts("No se pudo obtener el pasajero en la busqueda de id.\n");
			}
			else if(Passenger_getId(pPasajero, &bufferId)==-1){
				puts("No se pudo obtener el ID del pasajero en la busqueda de id.\n");
			}
		}
	}
	return retorno;
}
//****************************************************************************************************************************************************


int controller_editPassenger(LinkedList* pArrayListPassenger){
    int retorno=-1;
    Passenger auxiliar;
    Passenger* pPasajero;
	int opcion;
	int confirmar;
	int indice;
	int flagCambio=1;

    if(pArrayListPassenger!=NULL){
    	if(!controller_ListPassenger(pArrayListPassenger) &&
    			!ingresarEntero(&auxiliar.id, "Ingrese el ID del pasajero que desea modificar\n\n", MSJ_ERROROPCION, 1, idGlobal, REINTENTOS)){
    		indice=Controller_buscarPorId(pArrayListPassenger, auxiliar.id);
    		if(indice!=-1){
    		Controller_imprimirElemento(pArrayListPassenger, indice);
    			pPasajero=(Passenger*)ll_get(pArrayListPassenger, indice);
				if(pPasajero!=NULL &&
						!Passenger_getNombre(pPasajero, auxiliar.nombre) &&
						!Passenger_getApellido(pPasajero, auxiliar.apellido) &&
						!Passenger_getPrecio(pPasajero, &auxiliar.precio) &&
						!Passenger_getCodigoVuelo(pPasajero, auxiliar.codigoVuelo) &&
						!Passenger_getTipoPasajeroNumerico(pPasajero, &auxiliar.tipoPasajero) &&
						!Passenger_getEstadoVueloNumerico(pPasajero, &auxiliar.estadoVuelo)){
    	        	do{
    	            	if(!ingresarEntero(&opcion, MSJ_MENUMODIFICAR, MSJ_ERROROPCION, 1, 7, REINTENTOS)){
    	            		switch(opcion){
    	            		case 1:
    							if(!ingresarNombre(auxiliar.nombre, LARGONOMBRE, "Nuevo nombre:\n", "Error\n\n\n", REINTENTOS)){
    								puts("Nombre ingresado correctamente.\n\n");
									flagCambio=0;
    							}
    							else{
									puts("No se ingresó un nombre inválido.\n\n");
    							}
    							break;
   							case 2:
    							if(!ingresarNombre(auxiliar.apellido, LARGONOMBRE, "Nuevo apellido:\n", "Error\n\n\n", REINTENTOS)){
									puts("Apellido ingresado correctamente.\n\n");
									flagCambio=0;
    							}
    							else{
									puts("No se ingresó un apellido válido.\n\n");
    							}
    							break;
    						case 3:
    							if(!ingresarFlotante(&auxiliar.precio, "Nuevo precio:\n", "Error\n\n\n", 0.1, 500000, REINTENTOS)){
									puts("Precio ingresado correctamente.\n\n");
									flagCambio=0;
    							}
    							else{
									puts("No se ingresó un precio válido.\n\n");
    							}
    							break;
    						case 4:
    							if(!ingresarAlfanumerico(auxiliar.codigoVuelo, LARGOCODIGO, "Nuevo código de vuelo:\n", "Error\n\n\n", REINTENTOS)){
									puts("Código de vuelo ingresado correctamente.\n\n");
									flagCambio=0;
    							}
    							else{
									puts("No se ingresó un código de vuelo válido.\n\n");
    							}
    							break;
    						case 5:
    							if(!ingresarEntero(&auxiliar.tipoPasajero, "Nuevo tipo de pasajero: (1- EconomyClass, 2- ExecutiveClass o 3- FirstClass)\n", "Error. No es un tipo válido, reinténtelo de nuevo.\n\n\n", 1, 3, REINTENTOS)){
									puts("Tipo de pasajero ingresado correctamente.\n\n");
									flagCambio=0;
    							}
    							else{
									puts("No se ingresó un tipo de pasajero válido.\n\n");
    							}
    							break;
    						case 6:
    							if(!ingresarEntero(&auxiliar.estadoVuelo, "Nuevo estado de vuelo: (1- En Horario, 2- En Vuelo, 3- Demorado o 4- Aterrizado)\n", "Error. No es un estado válido, reinténtelo de nuevo.\n\n\n", 1, 4, REINTENTOS)){
									puts("Estado de vuelo ingresado correctamente.\n\n");
									flagCambio=0;
    							}
    							else{
									puts("No se ingresó un estado de vuelo válido.\n\n");
    							}
    							break;
    						case 7:
    							if(!flagCambio){
        							if(!ingresarEntero(&confirmar, "¿Está seguro/a de quiere realizar las modificaciones?\n  1- Si\n  0- No\n\n", MSJ_ERROROPCION, 0, 1, REINTENTOS)){
        								if(confirmar==1){
        									if(!Passenger_setNombre(pPasajero, auxiliar.nombre) &&
													!Passenger_setApellido(pPasajero, auxiliar.apellido) &&
													!Passenger_setPrecio(pPasajero, auxiliar.precio) &&
													!Passenger_setCodigoVuelo(pPasajero, auxiliar.codigoVuelo) &&
													!Passenger_setTipoPasajeroNumerico(pPasajero, auxiliar.tipoPasajero) &&
													!Passenger_setEstadoVueloNumerico(pPasajero, auxiliar.estadoVuelo)){
        										retorno=0;
        									}
        									else{
        										retorno=-10;
        									}
        								}
        								else{
        									retorno=-9;
        								}
        							}
        							else{
        								retorno=-8;
        							}
    							}
    							else{
									retorno=-7;
    							}
    							break;
    	            		}
    	            	}
						else{
							retorno=-6;
						}
    	        	}while(opcion!=7);
				}
				else if(pPasajero==NULL){
					retorno=-4;
				}
				else{
					retorno=-5;
				}
    		}
    		else{
    			retorno=-3;
    		}
		}
    	else{
    		retorno=-2;
    	}
    }
    return retorno;
}
//****************************************************************************************************************************************************


int controller_removePassenger(LinkedList* pArrayListPassenger){
    int retorno=-1;
    Passenger* pPasajero=NULL;
	int indice;
	int bufferId;
	int confirmar;
	int opcion;

	if(pArrayListPassenger!=NULL){
		if(!controller_ListPassenger(pArrayListPassenger) &&
				!ingresarEntero(&opcion, "¿Que desea eliminar?\n  1- Un pasajero\n  2- La lista completa\n\n", MSJ_ERROROPCION, 1, 2, REINTENTOS)){
			if(opcion==1 && !ingresarEntero(&bufferId, "Ingrese el ID del pasajero que desea eliminar\n\n", MSJ_ERROROPCION, 1, idGlobal, REINTENTOS)){
				indice=Controller_buscarPorId(pArrayListPassenger, bufferId);
	    		if(indice!=-1){
	    			pPasajero=(Passenger*)ll_get(pArrayListPassenger, indice);
					if(pPasajero!=NULL && !Controller_imprimirElemento(pArrayListPassenger, indice)){
						if(!ingresarEntero(&confirmar, "¿Está seguro/a de quiere eliminar este pasajero?\n  1- Si\n  0- No\n\n", MSJ_ERROROPCION, 0, 1, REINTENTOS)){
							if(confirmar==1){
								Passenger_delete(pPasajero);
								if(!ll_remove(pArrayListPassenger, indice)){
									retorno=0;
								}
								else{
									retorno=-10;
								}
							}
							else{
				        		retorno=-9;
							}
						}
						else{
			        		retorno=-8;
						}
					}
					else{
		        		retorno=-7;
					}
	    		}
	    		else{
	        		retorno=-6;
	    		}
			}
			else if(opcion==2){
				if(!ingresarEntero(&confirmar, "¿Está seguro/a de quiere eliminar la lista?\n  1- Si\n  0- No\n\n", MSJ_ERROROPCION, 0, 1, REINTENTOS)){
					if(confirmar==1){
						if(!ll_clear(pArrayListPassenger) && !ll_deleteLinkedList(pArrayListPassenger)){
							retorno=1;
						}
						else if(ll_clear(pArrayListPassenger)==-1){
							retorno=-12;
						}
						else{
							retorno=-13;
						}
					}
					else{
		        		retorno=-11;
					}
				}
				else{
	        		retorno=-8;
				}
			}
			else{
				retorno=-5;
			}
		}
		else if(controller_ListPassenger(pArrayListPassenger)==-1){
    		retorno=-3;
		}
		else{
    		retorno=-4;
		}
	}
	return retorno;
}
//****************************************************************************************************************************************************


int controller_ListPassenger(LinkedList* pArrayListPassenger){
    int retorno=-1;
    int i;
    int largo;

    if(pArrayListPassenger!=NULL){
    	largo = ll_len(pArrayListPassenger);
    	if(largo>0){
    		printf("%10s %15s %15s %15s %20s %25s %25s\n","ID","NOMBRE","APELLIDO","PRECIO","CODIGO DE VUELO","TIPO DE PASAJERO","ESTADO DE VUELO");
    		for(i=0;i<largo;i++){
    			if(!Controller_imprimirElemento(pArrayListPassenger,i)){
    				retorno=0;
    			}
    		}
			puts("\n\n\n");
    	}
    	else{
    		retorno=-2;
    	}
    }
    return retorno;
}
//****************************************************************************************************************************************************


int Controller_imprimirElemento(LinkedList* pArrayListPassenger,int indice){
	int retorno=-1;
	Passenger auxiliar;
	Passenger* pPasajero=NULL;

	if(pArrayListPassenger!=NULL && indice>=0){
		pPasajero=(Passenger*)ll_get(pArrayListPassenger, indice);
		if(pPasajero!=NULL &&
			!Passenger_getId(pPasajero, &auxiliar.id) &&
			!Passenger_getNombre(pPasajero, auxiliar.nombre) &&
			!Passenger_getApellido(pPasajero, auxiliar.apellido) &&
			!Passenger_getPrecio(pPasajero, &auxiliar.precio) &&
			!Passenger_getCodigoVuelo(pPasajero, auxiliar.codigoVuelo) &&
			!Passenger_getTipoPasajeroNumerico(pPasajero, &auxiliar.tipoPasajero) &&
			!Passenger_getEstadoVueloNumerico(pPasajero, &auxiliar.estadoVuelo)){
			printf("%10d %15s %15s %15.2f %20s %25s %25s\n",auxiliar.id,auxiliar.nombre,auxiliar.apellido,auxiliar.precio,auxiliar.codigoVuelo,
															TXT_TYPEPASSENGER[auxiliar.tipoPasajero-1],TXT_STATUSFLIGHT[auxiliar.estadoVuelo-1]);
			retorno=0;
		}
		else if(pPasajero==NULL){
			puts("Falló la impresión, no se pudo obtener el pasajero.\n");
		}
		else{
			puts("Falló la impresión, no se pudo obtener los datos del pasajero correctamente.\n");
		}
	}
	else if(indice<0){
		puts("El indice es incorrecto.\n");
	}
	else{
		puts("El puntero a LinkedList es NULL.\n");
	}
	return retorno;
}
//****************************************************************************************************************************************************


int controller_sortPassenger(LinkedList* pArrayListPassenger){
	int retorno=-1;
	int opcion;
	int orden;

	if(pArrayListPassenger!=NULL){
		if(!ingresarEntero(&opcion, MSJ_MENUORDENAR, MSJ_ERROROPCION, 1, 8, REINTENTOS)){
			if(opcion!=8 && !ingresarEntero(&orden, "¿En qué orden quiere ordenarlos?\n  1- Ascendente\n  0- Descendente\n\n", MSJ_ERROROPCION, 0, 1, REINTENTOS)){
				switch(opcion){
				case 1:
					if(!ll_sort(pArrayListPassenger, Passenger_compararPorId, orden)){
						puts("Se ordenó por ID exitosamente.\n\n");
						retorno=0;
					}
					else{
						puts("No se pudo ordenar por ID.\n\n\n");
					}
					break;
				case 2:
					if(!ll_sort(pArrayListPassenger, Passenger_compararPorNombre, orden)){
						puts("Se ordenó por nombre exitosamente.\n\n");
						retorno=0;
					}
					else{
						puts("No se pudo ordenar por nombre.\n\n\n");
					}
					break;
				case 3:
					if(!ll_sort(pArrayListPassenger, Passenger_compararPorApellido, orden)){
						puts("Se ordenó por apellido exitosamente.\n\n");
						retorno=0;
					}
					else{
						puts("No se pudo ordenar por apellido.\n\n\n");
					}
					break;
				case 4:
					if(!ll_sort(pArrayListPassenger, Passenger_compararPorPrecio, orden)){
						puts("Se ordenó por precio exitosamente.\n\n");
						retorno=0;
					}
					else{
						puts("No se pudo ordenar por precio.\n\n\n");
					}
					break;
				case 5:
					if(!ll_sort(pArrayListPassenger, Passenger_compararPorCodigoVuelo, orden)){
						puts("Se ordenó por código de vuelo exitosamente.\n\n");
						retorno=0;
					}
					else{
						puts("No se pudo ordenar por código de vuelo.\n\n\n");
					}
					break;
				case 6:
					if(!ll_sort(pArrayListPassenger, Passenger_compararPorTipoPasajero, orden)){
						puts("Se ordenó por tipo de pasajero exitosamente.\n\n");
						retorno=0;
					}
					else{
						puts("No se pudo ordenar por tipo de pasajero.\n\n\n");
					}
					break;
				case 7:
					if(!ll_sort(pArrayListPassenger, Passenger_compararPorEstadoVuelo, orden)){
						puts("Se ordenó por estado de vuelo exitosamente.\n\n");
						retorno=0;
					}
					else{
						puts("No se pudo ordenar por estado de vuelo.\n\n\n");
					}
					break;
				}
			}
			else if(opcion==8){
				retorno=-3;
			}
			else{
				retorno=-4;
			}
		}
		else{
			retorno=-2;
		}
	}
    return retorno;
}
//****************************************************************************************************************************************************


int controller_saveAsText(char* path , LinkedList* pArrayListPassenger){
    int retorno=-1;
    FILE* pArchivo;
    Passenger* pPasajero=NULL;
	int i;
    int largo;
	int auxId;
	char auxNombre[LARGONOMBRE];
	char auxApellido[LARGONOMBRE];
	float auxPrecio;
	char auxCodigoVuelo[LARGOCODIGO];
	char auxTipoPasajero[LARGODESCRIPCION];
	char auxEstadoVuelo[LARGODESCRIPCION];

    if(path!=NULL && pArrayListPassenger!=NULL){
		pArchivo = fopen(path,"w");
    	largo = ll_len(pArrayListPassenger);
		if(pArchivo!=NULL && largo>0){
			fprintf(pArchivo, "id,name,lastName,price,flyCode,typePassenger,statusFlight\n");
			ll_sort(pArrayListPassenger, Passenger_compararPorId, 1);
			for(i=0;i<largo;i++){
				pPasajero=(Passenger*)ll_get(pArrayListPassenger, i);
				if(pPasajero!=NULL &&
					!Passenger_getId(pPasajero, &auxId) &&
					!Passenger_getNombre(pPasajero, auxNombre) &&
					!Passenger_getApellido(pPasajero, auxApellido) &&
					!Passenger_getPrecio(pPasajero, &auxPrecio) &&
					!Passenger_getCodigoVuelo(pPasajero, auxCodigoVuelo) &&
					!Passenger_getTipoPasajeroNUM_TXT(pPasajero, auxTipoPasajero) &&
					!Passenger_getEstadoVueloNUM_TXT(pPasajero, auxEstadoVuelo)){
					fprintf(pArchivo,"%d,%s,%s,%.2f,%s,%s,%s\n",auxId,auxNombre,auxApellido,auxPrecio, auxCodigoVuelo,auxTipoPasajero,auxEstadoVuelo);
					Controller_guardarUltimoId();
				}
				else if(pPasajero==NULL){
					puts("No se pudieron guardar los cambios, no se pudo obtener el pasajero.\n");
				}
				else{
					puts("No se pudieron guardar los cambios, no se pudieron obtener los datos pasajero.\n");
				}
			}
			fclose(pArchivo);
			retorno=0;
		}
		else if(pArchivo==NULL){
			retorno=-3;
		}
		else{
			retorno=-4;
		}
    }
	else if(pArrayListPassenger==NULL){
		retorno=-2;
	}

    return retorno;
}
//****************************************************************************************************************************************************


int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger){
    int retorno=-1;
    FILE* pArchivo;
    Passenger* pPasajero=NULL;
	int i;
    int largo;

    if(path!=NULL && pArrayListPassenger!=NULL){
    	pArchivo = fopen(path,"wb");
    	largo = ll_len(pArrayListPassenger);
		if(pArchivo!=NULL && largo>0){
			ll_sort(pArrayListPassenger, Passenger_compararPorId, 1);
			for(i=0;i<largo;i++){
				pPasajero=(Passenger*)ll_get(pArrayListPassenger, i);
				if(pPasajero!=NULL){
					fwrite(pPasajero, sizeof(Passenger), 1, pArchivo);
					Controller_guardarUltimoId();
				}
				else{
					puts("No se pudieron guardar los cambios, no se pudo obtener el pasajero.\n");
				}
			}
			fclose(pArchivo);
			retorno=0;
		}
		else if(pArchivo==NULL){
			retorno=-3;
		}
		else{
			retorno=-4;
		}
	}
	else if(pArrayListPassenger==NULL){
		retorno=-2;
	}
	return retorno;
}
