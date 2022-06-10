#include "Controller.h"

static int idIncremental=1001;
/// @brief Genera un id que se incrementa en 1 cada vez que se llama a la funcion
/// @return Retorna el id incrementado en 1 respecto al anterior
static int Controller_generarId(void);
static int Controller_generarId(void){
	return idIncremental++;
}


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


/** \brief - Alta de pasajero. Solicita los datos al usuario y agrega el pasajero al vector
 * \param pArrayListPassenger LinkedList* - Puntero al vector de pasajeros
 * \return int - Retorna 0 (EXITO) - Si se pudieron cargar los datos y se pudo agregar el pasajero a la lista
 * 						-1 (ERROR) - El puntero a LinkedList es NULL
 * 						-2 (ERROR) - No se pudo crear el Pasajero
 * 						-3 (ERROR) - Falló la carga de datos
 * 						-4 (ERROR) - No se obtuvo confirmación. Volvió al menú principal
 * 						-5 (ERROR) - Se canceló la operación. No se agregó el pasajero
 * 						-6 (ERROR) - No se pudieron setear los datos correctamente
 * 						-7 (ERROR) - Se generó un ID invalido
 * 						-8 (ERROR) - No se pudo agregar el pasajero a la lista
 */
int controller_addPassenger(LinkedList* pArrayListPassenger){
    int retorno=-1;
	Passenger auxiliar;
	Passenger* pPasajero=NULL;
	int confirmar;

	if(pArrayListPassenger!=NULL){
		pPasajero=Passenger_new();
		if(pPasajero!=NULL && !Passenger_cargarPasajero(&auxiliar)){
			if(!ingresarEntero(&confirmar, "¿Está seguro/a de quiere agregar este pasajero?\n  1- Si\n  0- No\n\n", MSJ_ERROROPCION, 0, 1, REINTENTOS)){
				if(confirmar==1 && !Passenger_setId(pPasajero, auxiliar.id) &&
						!Passenger_setNombre(pPasajero, auxiliar.nombre) &&
						!Passenger_setApellido(pPasajero, auxiliar.apellido) &&
						!Passenger_setPrecio(pPasajero, auxiliar.precio) &&
						!Passenger_setCodigoVuelo(pPasajero, auxiliar.codigoVuelo)&&
						!Passenger_setTipoPasajero(pPasajero, auxiliar.tipoPasajero) &&
						!Passenger_setEstadoVuelo(pPasajero, auxiliar.estadoVuelo)){
					auxiliar.id=Controller_generarId();
					if(auxiliar.id>0 && !ll_add(pArrayListPassenger, pPasajero)){
						puts("Se cargaron los datos del nuevo pasajero exitosamente.\n");
						retorno=0;
					}
					else if(auxiliar.id<=0){
						retorno=-7;
					}
					else{
						retorno=-8;
					}
				}
				else if(confirmar==2){
					retorno=-5;
				}
				else{
					retorno=-6;
				}
			}
			retorno=-4;
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


int Controller_buscarPorId(LinkedList* pArrayListPassenger,int id){					//	CORREGIR CUANDO PRINTEA EL 	ID QUE SE ENCONTRO
	int retorno=-1;
    Passenger* pPasajero=NULL;
	int i;
    int largo;
    int bufferId;

	if(pArrayListPassenger!=NULL && id>0){
    	largo=ll_len(pArrayListPassenger);
		for(i=0;i<largo;i++){
			pPasajero=(Passenger*)ll_get(pArrayListPassenger, i);
			if(pPasajero!=NULL && !Passenger_getId(pPasajero, &bufferId) && bufferId==id){
				retorno=i;
				break;
			}
			else if(pPasajero==NULL){
				puts("pPasajero es NULO en buscarPorID.\n");
			}
			else if(Passenger_getId(pPasajero, &bufferId)==-1){
				puts("No se pudo obtener el ID del pasajero en buscarPorID.\n");
			}
			else if(bufferId!=id){
				puts("No hubi CONCIDENCIA con NINGUNO buscarPorID.\n");
			}
		}
	}
	else{
		puts("Parametros recibidos en buscarPorID estan MAL.\n");
	}
	return retorno;
}
//****************************************************************************************************************************************************


/** \brief Modificar datos de pasajero Modifica los datos de un pasajero dentro de la lista
 * \param pArrayListPassenger LinkedList* Puntero al vector de pasajeros
 * \return int Retorna 0 (EXITO) - Si se pudieron modificar los datos del Pasajero
 * 						-1 (ERROR) - El puntero a LinkedList es NULL
 * 						-2 (ERROR) - No se pudo encontrar el ID buscado
 * 						-3 (ERROR) - No se pudo obtener el Pasajero
 */
int controller_editPassenger(LinkedList* pArrayListPassenger){
    int retorno=-1;
    Passenger auxiliar;
    Passenger* pPasajero;
	int opcion;
	int confirmar;
	int maximoIdActual=1200;		//	CORREGIR
	int indice;
	int flagCambio=1;



/*	int ll_indexOf(LinkedList* this, void* pElement){
    int returnAux = -1;
    int i;
    void* pElementAux;

    if(this != NULL)
    {
		for(i=0; i<ll_len(this);i++)
		{
			pElementAux = ll_get(this,i);
			if(pElementAux == pElement)
			{
				returnAux = i;
				break;
			}
		}
    }
    return returnAux;
}*/


	/*if (pArrayListEmployee != NULL){---------------
		if (utn_getNumber(&buffer.id, "\nIngrese el id del empleado que quiere modificar: ", "\nError!", 0, INT_MAX, 5) == SUCCESS){
			index = controller_findById(pArrayListEmployee, buffer.id);
			if (index != ERROR){
			}*/
    if(pArrayListPassenger!=NULL){
    	if(!ingresarEntero(&auxiliar.id, "Ingrese el ID del pasajero que desea modificar\n\n", MSJ_ERROROPCION, 1, maximoIdActual, REINTENTOS)){
    		indice=Controller_buscarPorId(pArrayListPassenger, auxiliar.id);
    		//indice=ll_indexOf(pArrayListPassenger, pPasajero);
    		printf("se encontro indice: %d   -   Yo busque el N: %d\n\n",indice,auxiliar.id);
    		if(indice!=-1){
    		Controller_imprimirElemento(pArrayListPassenger, indice);
    			pPasajero=(Passenger*)ll_get(pArrayListPassenger, indice);
				if(pPasajero!=NULL &&
						!Passenger_getNombre(pPasajero, auxiliar.nombre) &&
						!Passenger_getApellido(pPasajero, auxiliar.apellido) &&
						!Passenger_getPrecio(pPasajero, &auxiliar.precio) &&
						!Passenger_getCodigoVuelo(pPasajero, auxiliar.codigoVuelo) &&
						!Passenger_getTipoPasajero(pPasajero, auxiliar.tipoPasajero) &&
						!Passenger_getEstadoVuelo(pPasajero, auxiliar.estadoVuelo)){
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
    							if(!ingresarDescripcion(auxiliar.tipoPasajero, LARGODESCRIPCION, "Nuevo tipo de pasajero: (EconomyClass, ExecutiveClass o FirstClass)\n", "Error. No es un tipo válido, reinténtelo de nuevo.\n\n\n", REINTENTOS)){
									puts("Tipo de pasajero ingresado correctamente.\n\n");
									flagCambio=0;
    							}
    							else{
									puts("No se ingresó un tipo de pasajero válido.\n\n");
    							}
    							break;
    						case 6:
    							if(!ingresarDescripcion(auxiliar.estadoVuelo, LARGODESCRIPCION, "Nuevo estado de vuelo: (En Horario, En Vuelo, Demorado o Aterrizado)\n", "Error. No es un estado válido, reinténtelo de nuevo.\n\n\n", REINTENTOS)){
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
													!Passenger_setTipoPasajero(pPasajero, auxiliar.tipoPasajero) &&
													!Passenger_setEstadoVuelo(pPasajero, auxiliar.estadoVuelo)){
        										retorno=0;
        										puts("Se modificaron los datos exitosamente.\n\n");
        									}
        									else{
            									puts("No se setaron.\n\n");
        									}
        								}
        								else{
        									puts("No se guardaron los cambios.\n\n");
        								}
        							}
        							else{
        								puts("No se pudo confirmar.\n\n\n");
        							}
    							}
    							else{
      								puts("No se realizaron cambios en los datos del pasajero.\n\n");
									retorno=0;
    							}
    							break;
    	            		}
    	            	}
						else{
							puts("No se pudo ingresar una opción.\n\n\n");
						}
    	        	}while(opcion!=7);
				}
				else{
					retorno=-4;
					puts("No se pudo crear el Pasajero, falló la Función Passenger_new.\n");
				}
    		}
    		else{
    			retorno=-3;
        		puts("No se pudo encontrar el ID buscado.\n\n\n");
    		}
		}
    	else{
    		retorno=-2;
    		puts("No se ingresó ningun ID para modificar.\n\n\n");
    	}
    }
    return retorno;
}
//****************************************************************************************************************************************************




/*	    Passenger* pPasajero=NULL;
 * 		pPasajero = Passenger_newParametros(auxId, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo, auxTipoPasajero, auxEstadoVuelo);
				if(pPasajero!=NULL){
					if(!ll_add(pArrayListPassenger, pPasajero)){
						indice=ll_indexOf(pArrayListPassenger, pPasajero);
						printf("indexOf me tira %d\n",indice);
 * */

int controller_removePassenger(LinkedList* pArrayListPassenger){
    int retorno=-1;
    Passenger* pPasajero=NULL;
	int indice;
	int bufferId;
	int maximoIdActual=1200;		//	CORREGIR
	int confirmar;

	//	LLAMAR		LL_GET  ID
	if(pArrayListPassenger!=NULL){
    	if(!controller_ListPassenger(pArrayListPassenger) && !ingresarEntero(&bufferId, "Ingrese el ID del pasajero que desea eliminar\n\n", MSJ_ERROROPCION, 1, maximoIdActual, REINTENTOS)){
    		indice=Controller_buscarPorId(pArrayListPassenger, bufferId);
    		printf("se encontro indice: %d   -   Yo busque el n: %d\n\n\n\n",indice,bufferId);

    		indice=ll_indexOf(pArrayListPassenger, pPasajero);
    		printf("se encontro indice: %d   -   Yo busque el n: %d\n\n",indice,bufferId);
    		//printf("El id obtenido del pPasajero es %d\n\n",pPasajero->id);
    		if(indice!=-1){
    			Controller_imprimirElemento(pArrayListPassenger, indice);
    			pPasajero=(Passenger*)ll_get(pArrayListPassenger, indice);
				if(pPasajero!=NULL){
					if(!ingresarEntero(&confirmar, "¿Está seguro/a de quiere eliminar este pasajero?\n  1- Si\n  0- No\n\n", MSJ_ERROROPCION, 0, 1, REINTENTOS)){
						if(confirmar==1){
							Passenger_delete(pPasajero);
							if(!ll_remove(pArrayListPassenger, indice)){
								retorno=0;
							}
							else{
								retorno=-7;
							}
						}
						else{
							retorno=-6;
						}
					}
					else{
						retorno=-5;
					}
				}
				else{
					retorno=-4;
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
			!Passenger_getTipoPasajero(pPasajero, auxiliar.tipoPasajero) &&
			!Passenger_getEstadoVuelo(pPasajero, auxiliar.estadoVuelo)){
			printf("%10d %15s %15s %15.2f %20s %25s %25s\n",auxiliar.id,auxiliar.nombre,auxiliar.apellido,auxiliar.precio,
															auxiliar.codigoVuelo,auxiliar.tipoPasajero,auxiliar.estadoVuelo);
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
		if(!ingresarEntero(&opcion, MSJ_MENUORDENAR, MSJ_ERROROPCION, 1, 5, REINTENTOS)){
			if(!ingresarEntero(&orden, "¿En qué orden quiere ordenarlos?\n  1- Ascendente\n  0- Descendente\n\n", MSJ_ERROROPCION, 0, 1, REINTENTOS)){
				switch(opcion){
				case 1:
					if(!ll_sort(pArrayListPassenger, Passenger_comparaPorId, orden)){
						puts("Se ordenó por ID exitosamente.\n\n");
						retorno=0;
					}
					else{
						puts("No se pudo ordenar por ID.\n\n\n");
					}
					break;
				case 2:
					if(!ll_sort(pArrayListPassenger, Passenger_comparaPorApellido, orden)){
						puts("Se ordenó por apellido exitosamente.\n\n");
						retorno=0;
					}
					else{
						puts("No se pudo ordenar por apellido.\n\n\n");
					}
					break;
				case 3:
					if(!ll_sort(pArrayListPassenger, Passenger_comparaPorPrecio, orden)){
						puts("Se ordenó por precio exitosamente.\n\n");
						retorno=0;
					}
					else{
						puts("No se pudo ordenar por precio.\n\n\n");
					}
					break;
				case 4:
					if(!ll_sort(pArrayListPassenger, Passenger_comparaPorCodigoVuelo, orden)){
						puts("Se ordenó por código de vuelo exitosamente.\n\n");
						retorno=0;
					}
					else{
						puts("No se pudo ordenar por código de vuelo.\n\n\n");
					}
					break;
				case 5:
					puts("Usted volvió al Menú Principal.\n\n");
					retorno=0;
					break;
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
			for(i=0;i<largo;i++){
				pPasajero=(Passenger*)ll_get(pArrayListPassenger, i);
				if(pPasajero!=NULL &&
					!Passenger_getId(pPasajero, &auxId) &&
					!Passenger_getNombre(pPasajero, auxNombre) &&
					!Passenger_getApellido(pPasajero, auxApellido) &&
					!Passenger_getPrecio(pPasajero, &auxPrecio) &&
					!Passenger_getCodigoVuelo(pPasajero, auxCodigoVuelo) &&
					!Passenger_getTipoPasajero(pPasajero, auxTipoPasajero) &&
					!Passenger_getEstadoVuelo(pPasajero, auxEstadoVuelo)){
					fprintf(pArchivo,"%d,%s,%s,%.2f,%s,%s,%s\n",auxId,auxNombre,auxApellido,auxPrecio, auxCodigoVuelo,auxTipoPasajero,auxEstadoVuelo);
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
			for(i=0;i<largo;i++){
				pPasajero=(Passenger*)ll_get(pArrayListPassenger, i);
				if(pPasajero!=NULL){
					fwrite(pPasajero, sizeof(Passenger), 1, pArchivo);
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
//****************************************************************************************************************************************************
