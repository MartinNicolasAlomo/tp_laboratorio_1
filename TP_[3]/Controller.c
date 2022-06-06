#include "Controller.h"

static int idIncremental=1001;
/// @brief Genera un id que se incrementa en 1 cada vez que se llama a la funcion
/// @return Retorna el id incrementado en 1 respecto al anterior
static int Controller_generarId(void);
static int Controller_generarId(void){
	return idIncremental++;
}



/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 * \param path char* Ruta del archivo a cargar
 * \param pArrayListPassenger LinkedList* Puntero al vector de pasajeros
 * \return int Retorna 0 (EXITO) - Si se pudieron cargar los datos desde el archivo,
 * 						-1 (ERROR) - La ruta del Archivo no es valida
 * 						-2 (ERROR) - El puntero a LinkedList es NULL
 * 						-3 (ERROR) - No se pudo abrir el Archivo
 * 						-4 (ERROR) - No se pudieron parsear los Datos del Archivo
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger){
	int retorno=-1;
	FILE* pArchivo;
	if(path!=NULL && pArrayListPassenger!=NULL){
		pArchivo = fopen(path,"r");
		if(pArchivo!=NULL){
			if(!parser_PassengerFromText(pArchivo, pArrayListPassenger)){
				retorno=0;
				fclose(pArchivo);
			}
			else{
				puts("No funcionó el PARSEO\n");
				retorno=-4;
			}
		}
		else{
			puts("Archivo no abre - FOPEN falló.\n");
			retorno=-3;
		}
	}
	else if(pArrayListPassenger==NULL){
		puts("VectorPasajeros es NULO\n");
		retorno=-2;
	}
	else{
		puts("Archivo RUTA esta MAL\n");
	}
    return retorno;
}
//****************************************************************************************************************************************************


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 * \param path char* ruta del archivo a cargar
 * \param pArrayListPassenger LinkedList* puntero al vector de pasajeros
 * \return int Retorna 0 (EXITO) si se pudieron cargar los datos desde el archivo,
 * 						-1 (ERROR) si el puntero a LinkedList es NULL o la ruta no es valida
 * 						-2 (ERROR) si no se pudo abrir el archivo
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger){
	int retorno=-1;
	FILE* pArchivo;

	if(path!=NULL && pArrayListPassenger!=NULL){
		pArchivo = fopen(path,"rb");
		if(pArchivo!=NULL){
			if(!parser_PassengerFromBinary(pArchivo, pArrayListPassenger)){
				retorno=0;
				fclose(pArchivo);
			}
		}
		else{
			retorno=-2;
		}
	}
	return retorno;
}
//****************************************************************************************************************************************************


/** \brief Alta de pasajero Pide los datos al usuario y lo agrega al vector
 * \param pArrayListPassenger LinkedList* Puntero al vector de pasajeros
 * \return int Retorna 0 (EXITO) si se pudieron cargar los datos y agregar al nuevo pasajero,
 * 						-1 (ERROR) si no se pudo
 */
int controller_addPassenger(LinkedList* pArrayListPassenger){
    int retorno=-1;
	Passenger auxiliar;
	Passenger* pPasajero;
	int confirmar;

	if(pArrayListPassenger!=NULL){
		pPasajero=Passenger_new();
		if(pPasajero!=NULL && !Passenger_cargarPasajero(&auxiliar)){
			if(!ingresarEntero(&confirmar, "¿Está seguro/a de quiere agregar este pasajero? (1- Si / 2- No)\n\n", MSJ_ERROROPCION, 1, 2, REINTENTOS)){
				if(confirmar==1 && !Passenger_setId(pPasajero, auxiliar.id) &&
					!Passenger_setNombre(pPasajero, auxiliar.nombre) &&
					!Passenger_setApellido(pPasajero, auxiliar.apellido) &&
					!Passenger_setPrecio(pPasajero, auxiliar.precio) &&
					!Passenger_setCodigoVuelo(pPasajero, auxiliar.codigoVuelo)&&
					!Passenger_setTipoPasajero(pPasajero, auxiliar.tipoPasajero) &&
					!Passenger_setEstadoVuelo(pPasajero, auxiliar.estadoVuelo)){
					auxiliar.id=Controller_generarId();
					if(auxiliar.id>0 && !ll_add(pArrayListPassenger, pPasajero)){
						puts("Se cargaron los datos del nuevo pasajero.\n");
						retorno=0;
					}
					else if(auxiliar.id<=0){
						puts("El ID es igual o menor que cero.\n\n\n");
					}
				}
				else if(confirmar==2){
					puts("Cancelado. No se agregó el álbum.\n\n\n");
				}
				else if(Passenger_setId(pPasajero, auxiliar.id)==-1){
					puts("FALLO el  SETTER del  ID.\n\n\n");
				}
				else if(Passenger_setNombre(pPasajero, auxiliar.nombre)==-1){
					puts("FALLO el  SETTER del  NOMBRE.\n\n\n");
				}
				else if(Passenger_setApellido(pPasajero, auxiliar.apellido)==-1){
					puts("FALLO el  SETTER del  apellido.\n\n\n");
				}
				else if(Passenger_setCodigoVuelo(pPasajero, auxiliar.codigoVuelo)==-1){
					puts("FALLO el  SETTER del  codigoVuelo.\n\n\n");
				}
				else if(Passenger_setTipoPasajero(pPasajero, auxiliar.tipoPasajero)==-1){
					puts("FALLO el  SETTER del  tipoPasajero.\n\n\n");
				}
				else if(Passenger_setEstadoVuelo(pPasajero, auxiliar.estadoVuelo)==-1){
					puts("FALLO el  SETTER del  estadoVuelo.\n\n\n");
				}
				else if(Passenger_setPrecio(pPasajero, auxiliar.precio)==-1){
					puts("FALLO el  SETTER del  PRECIO.\n\n\n");
				}
				else{
					puts("No se pudieron cargar los datos correctamente.\n\n\n");
				}
			}
		}
		else{
			puts("Falló la carga de datos.\n\n\n");
		}
	}
    return retorno;
}
//****************************************************************************************************************************************************


int Controller_buscarPorId(LinkedList* pArrayListPassenger,int id){					//	CORREGIR CUANDO PRINTEA EL 	ID QUE SE ENCONTRO
	int retorno=-1;
	int i;
    int largo;
    int bufferId;
    Passenger* pPasajero;

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
    Passenger* pPasajero=NULL;
	int opcion;
	int confirmar;
	int maximoIdActual=1200;		//	CORREGIR
	int indice;

	//	CORREGIR	-	SE MODIFICAN LOS DATOS AUNQUE SE HAYAN CANCELADO AL FINALIZAR

    if(pArrayListPassenger!=NULL){
    	if(!ingresarEntero(&auxiliar.id, "Ingrese el ID del pasajero que desea modificar\n\n", MSJ_ERROROPCION, 1, maximoIdActual, REINTENTOS)){
    		indice=Controller_buscarPorId(pArrayListPassenger, auxiliar.id);
    		printf("se encontro indice: %d   -   Yo busque el N: %d\n\n",indice,auxiliar.id);
    		if(indice>0){
    		Controller_imprimirElemento(pArrayListPassenger, indice);
    			pPasajero=(Passenger*)ll_get(pArrayListPassenger, indice);
				if(pPasajero!=NULL){
    	        	do{
    	            	if(!ingresarEntero(&opcion, MSJ_MENUMODIFICAR, MSJ_ERROROPCION, 1, 7, REINTENTOS)){
    	            		switch(opcion){
    	            		case 1:
    							if(!ingresarNombre(auxiliar.nombre, LARGONOMBRE, "Nuevo nombre:\n", "Error\n\n\n", REINTENTOS)){
    								if(!Passenger_setNombre(pPasajero, auxiliar.nombre)){
    									puts("Se modificó el nombre exitosamente.\n\n");
    								}
    								else{
    									puts("Falló la modificación del nombre.\n\n\n");
    								}
    							}
    							break;
   							case 2:
    							if(!ingresarNombre(auxiliar.apellido, LARGONOMBRE, "Nuevo apellido:\n", "Error\n\n\n", REINTENTOS)){
    								if(!Passenger_setApellido(pPasajero, auxiliar.apellido)){
    									puts("Se modificó el apellido exitosamente.\n\n");
    								}
    								else{
    									puts("Falló la modificación del apellido.\n\n\n");
    								}
    							}
    							break;
    						case 3:
    							if(!ingresarFlotante(&auxiliar.precio, "Nuevo precio:\n", "Error\n\n\n", 0.1, 500000, REINTENTOS)){
    								if(!Passenger_setPrecio(pPasajero, auxiliar.precio)){
    									puts("Se modificó el precio exitosamente.\n\n");
    								}
    								else{
    									puts("Falló la modificación del precio.\n\n\n");
    								}
    							}
    							break;
    						case 4:
    							if(!ingresarAlfanumerico(auxiliar.codigoVuelo, LARGOCODIGO, "Nuevo código de vuelo:\n", "Error\n\n\n", REINTENTOS)){
    								if(!Passenger_setCodigoVuelo(pPasajero, auxiliar.codigoVuelo)){
    									puts("Se modificó el código de vuelo exitosamente.\n\n");
    								}
    								else{
    									puts("Falló la modificación del código de vuelo.\n\n\n");
    								}
    							}
    							break;
    						case 5:
    							if(!ingresarDescripcion(auxiliar.tipoPasajero, LARGODESCRIPCION, "Nuevo tipo de pasajero: (EconomyClass, ExecutiveClass o FirstClass)\n", "Error. No es un tipo válido, reinténtelo de nuevo.\n\n\n", REINTENTOS)){
    								if(!Passenger_setTipoPasajero(pPasajero, auxiliar.tipoPasajero)){
    									puts("Se modificó el tipo de pasajero exitosamente.\n\n");
    								}
    								else{
    									puts("Falló la modificación del tipo de pasajero.\n\n\n");
    								}
    							}
    							break;
    						case 6:
    							if(!ingresarDescripcion(auxiliar.estadoVuelo, LARGODESCRIPCION, "Nuevo estado de vuelo: (En Horario, En Vuelo, Demorado o Aterrizado)\n", "Error. No es un estado válido, reinténtelo de nuevo.\n\n\n", REINTENTOS)){
    								if(!Passenger_setEstadoVuelo(pPasajero, auxiliar.estadoVuelo)){
    									puts("Se modificó el estado de su vuelo exitosamente.\n\n");
    								}
    								else{
    									puts("Falló la modificación del estado de su vuelo.\n\n\n");
    								}
    							}
    							break;
    						case 7:
    							if(!ingresarEntero(&confirmar, "¿Está seguro/a de quiere realizar las modificaciones? (1- Si / 2- No)\n\n", "No es una opción válida, reinténtelo de nuevo.\n\n\n", 1, 2, REINTENTOS)){
    								if(confirmar==1){
    									retorno=0;
    								}
    								else if(confirmar==2){
    									puts("No se guardaron los cambios.\n\n");
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
    	        	}while(opcion!=7);
				}
				else{
					retorno=-3;
	        		puts("No se pudo obtener el Pasajero en CONTROLLER  EDIT.\n");
				}
    		}
    		else{
    			retorno=-2;
        		puts("No se pudo encontrar el ID buscado en CONTROLLER  EDIT.\n");
    		}
		}
    	else{
    		puts("No se pudo ingresar ningun ID en CONTROLLER  EDIT.\n");
    	}
    }
    else{
		puts("VectorPasajeros es NULO en CONTROLLER  EDIT.\n");
    }
    return retorno;
}
//****************************************************************************************************************************************************


/** \brief Baja de pasajero Elimina un pasajero del sistema
 * \param pArrayListPassenger LinkedList* Puntero al vector de pasajeros
 * \return int Retorna 0 (EXITO) - Si se eliminar el pasajero del sistema
 * 						-1 (ERROR) - El puntero a LinkedList es NULL
 * 						-2 (ERROR) - No se pudo encontrar el ID buscado
 * 						-3 (ERROR) - No se pudo obtener el Pasajero
 * 						-4 (ERROR) - Se eliminó el pasajero de memoria pero no se pudo eliminar de la lista
 */
int controller_removePassenger(LinkedList* pArrayListPassenger){
    int retorno=-1;
    Passenger* pPasajero=NULL;
	int indice;
	int bufferId;
	int maximoIdActual=1200;		//	CORREGIR
	int confirmar;

	if(pArrayListPassenger!=NULL){
    	if(!ingresarEntero(&bufferId, "Ingrese el ID del pasajero que desea eliminar\n\n", MSJ_ERROROPCION, 1, maximoIdActual, REINTENTOS)){
    		indice=Controller_buscarPorId(pArrayListPassenger, bufferId);
    		printf("se encontro indice: %d   -   Yo busque el n: %d\n\n",indice,bufferId);
    		if(indice>0){
    			Controller_imprimirElemento(pArrayListPassenger, indice);
    			pPasajero=(Passenger*)ll_get(pArrayListPassenger, indice);
				if(pPasajero!=NULL){
					if(!ingresarEntero(&confirmar, "¿Está seguro/a de quiere eliminar este pasajero? (1- Si / 2- No)\n\n", MSJ_ERROROPCION, 1, 2, REINTENTOS)){
						if(confirmar==1){
							Passenger_delete(pPasajero);
							if(!ll_remove(pArrayListPassenger, indice)){
								retorno=0;
							}
							else{
								retorno=-4;
								puts("Se eliminó el pasajero de memoria pero no se pudo eliminar de la lista.\n\n");
							}
						}
						else if(confirmar==2){
							puts("No se eliminó el pasajero.\n\n");
						}
					}
					else{
						puts("No se pudo confirmar.\n\n\n");
					}
				}
				else{
					retorno=-3;
					puts("No se pudo obtener el Pasajero.\n");
				}
			}
    		else{
    			retorno=-2;
    			puts("No se pudo encontrar el ID buscado.\n");
    		}
    	}
    	else{
    		puts("No opcion.\n");
    	}
	}
	else{
		puts("VectorPasajeros es NULO.\n");
	}
	return retorno;
}
//****************************************************************************************************************************************************


/** \brief Listar pasajeros Imprime todos los pasajeros de la lista
 * \param pArrayListPassenger LinkedList*
 * \return int Retorna 0 (EXITO) - Si se eliminar el pasajero del sistema
 * 						-1 (ERROR) - El puntero a LinkedList es NULL
 * 						-2 (ERROR) - La lista esta vacia, no hay pasajeros
 * 						-3 (ERROR) - No se pudo obtener el Pasajero
 */
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
    			else{
    				puts("FALLO controller llamado impresor\n");
    				retorno=-3;
    				break;
    			}
    		}
			puts("\n\n\n");
    	}
    	else{
    		retorno=-2;
    		puts("Lista vacia, No hay pasajeros\n");
    	}
    }
    else{
		puts("FALLO chequeo contrller\n");
    }
    return retorno;
}
//****************************************************************************************************************************************************


int Controller_imprimirElemento(LinkedList* pArrayListPassenger,int indice){
	int retorno=-1;
	Passenger auxiliar;
	Passenger* pPasajero;
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
			puts("No se obtuvo el pasajero\n");
		}
		else{
			puts("No se obtuvieron los datos del pasajero correctamente\n");
		}
	}
	else if(indice<0){
		puts("indice incorrecto\n");
	}
	else{
		puts("FALLO impresor el chequeo\n");

	}
	return retorno;
}
//****************************************************************************************************************************************************


/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger){
	int retorno=-1;
	int opcion;
	int orden;

	// AGREGAR LOS CRITEIOS DE ORDEN QUE FALTAN

	if(pArrayListPassenger!=NULL){
		if(!ingresarEntero(&opcion, MSJ_MENUORDENAR, MSJ_ERROROPCION, 1, 5, REINTENTOS)){
			if(!ingresarEntero(&orden, "¿En qué orden quiere ordenarlos?  (1- Ascendente  -  0- Descendente)\n\n", MSJ_ERROROPCION, 0, 1, REINTENTOS)){
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
		}
	}
    return retorno;
}
//****************************************************************************************************************************************************


/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger){
    int retorno=-1;
    FILE* pArchivo;
    Passenger* pPasajero;
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
			for(i=0;i<largo;i++){
				pPasajero=(Passenger*)ll_get(pArrayListPassenger, i);
				if(!Passenger_getId(pPasajero, &auxId) &&
					!Passenger_getNombre(pPasajero, auxNombre) &&
					!Passenger_getApellido(pPasajero, auxApellido) &&
					!Passenger_getPrecio(pPasajero, &auxPrecio) &&
					!Passenger_getCodigoVuelo(pPasajero, auxCodigoVuelo) &&
					!Passenger_getTipoPasajero(pPasajero, auxTipoPasajero) &&
					!Passenger_getEstadoVuelo(pPasajero, auxEstadoVuelo)){
					fprintf(pArchivo,"%d,%s,%s,%.2f,%s,%s,%s\n",auxId,auxNombre,auxApellido,auxPrecio, auxCodigoVuelo,auxTipoPasajero,auxEstadoVuelo);
				}
			}
			fclose(pArchivo);
			retorno=0;
		}
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
//****************************************************************************************************************************************************


/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger){
    int retorno=-1;


    	//	FWRITE

	return retorno;
}
//****************************************************************************************************************************************************
