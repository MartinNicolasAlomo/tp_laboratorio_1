#include "Controller.h"

static int idIncremental=1;
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
			puts("Archivo no abre - FOPEN.\n");
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

	//buffer.id = generateNewId(pArrayListEmployee); // it returns error if there's nothing in the list

	if(pArrayListPassenger!=NULL){
		pPasajero=Passenger_new();
		auxiliar.id=Controller_generarId();
		if(pPasajero!=NULL && auxiliar.id>0 && !Passenger_cargarPasajero(&auxiliar)){
			if(!ingresarEntero(&confirmar, "¿Está seguro/a de quiere agregar este pasajero? (1- Si / 2- No)\n\n", MSJ_ERROROPCION, 1, 2, REINTENTOS)){
				if(confirmar==1 && !Passenger_setId(pPasajero, auxiliar.id) &&
					!Passenger_setNombre(pPasajero, auxiliar.nombre) &&
					!Passenger_setApellido(pPasajero, auxiliar.apellido) &&
					!Passenger_setPrecio(pPasajero, auxiliar.precio) &&
					!Passenger_setCodigoVuelo(pPasajero, auxiliar.codigoVuelo)&&
					!Passenger_setTipoPasajero(pPasajero, auxiliar.tipoPasajero) &&
					!Passenger_setEstadoVuelo(pPasajero, auxiliar.estadoVuelo)){
					if(!ll_add(pArrayListPassenger, pPasajero)){
						printf("Se cargaron los datos del nuevo pasajero.\n");
						retorno=0;
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


int Controller_buscarPorId(LinkedList* pArrayListPassenger,int id){
	int retorno=-1;
	int i;
    int largo;
    int auxId;
    Passenger* pPasajero;

	if(pArrayListPassenger!=NULL && id>=0){
    	largo=ll_len(pArrayListPassenger);
		for(i=0;i<largo;i++){
			if(!Passenger_getId(pPasajero, &auxId) && auxId==id){
				retorno=i;
				break;
			}
			else{
				puts("No se encontro el ID.\n");
			}
		}
	}
	else{
		puts("Parametros buscarID estan MAL.\n");
	}
	return retorno;
}
//****************************************************************************************************************************************************


/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger){
    int retorno=-1;
    Passenger auxiliar;
    Passenger* pPasajero;
	int opcion;
	int confirmar;
	int maximoIdActual=1200;	//	CORREGIR
	int auxId;


	// FIJARTE SI USAR	SETTERS O GETTERS *******************

    if(pArrayListPassenger!=NULL){



    	if(!ingresarEntero(&auxId, "Ingrese el ID del pasajero que desea modificar\n\n", MSJ_ERROROPCION, 1, maximoIdActual, REINTENTOS)){

        	do{
            	if(!ingresarEntero(&opcion, MSJ_MENUMODIFICAR, MSJ_ERROROPCION, 1, maximoIdActual, REINTENTOS)){
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
        	}while(opcion!=5);
		}
    }
    else{
		puts("Parametros editPassanger estan MAL.\n");
    }
    return retorno;
}
//****************************************************************************************************************************************************


/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger){
    int retorno=-1;
	//		PREGUNTAR  DE QUE MANERA LO QUIERE ELEMINAR




	return retorno;
}
//****************************************************************************************************************************************************

// DEL MAIN LLAMO CONROLADOR, LE PASO LA LISTA, RECORRO LA LSITA, POR CADA DATO QUE OVTENGO DEL LINKEDLIST CON LL_GET, LE PASO ESE DATO ALA BIBLIO PASSENGER PARA QUE MUESTRE 1


/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
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
    			}
    		}
			puts("\n\n\n");

    	}
    	else{
    		puts("LARGO 0  -  No hay pasajeros\n");
    	}
    }
    else{
		puts("FALLO chequeo contrller\n");

    }
    return retorno;
}




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
			//!Passenger_getTipoPasajero(pPasajero, &auxiliar.tipoPasajero) &&
			//!Passenger_getEstadoVuelo(pPasajero, &auxiliar.estadoVuelo)
			!Passenger_getTipoPasajero(pPasajero, auxiliar.tipoPasajero) &&
			!Passenger_getEstadoVuelo(pPasajero, auxiliar.estadoVuelo)){
			printf("%10d %15s %15s %15.2f %20s %25s %25s\n",auxiliar.id,auxiliar.nombre,auxiliar.apellido,auxiliar.precio,
															auxiliar.codigoVuelo,auxiliar.tipoPasajero,auxiliar.estadoVuelo);
			retorno=0;
		}
		else{
			puts("FALLO la impresion del pasajero\n");
		}
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
    //int i;
    //int largoLista;
    FILE* pArchivo;
	/*int auxId;
	char auxNombre[LARGONOMBRE];
	char auxApellido[LARGONOMBRE];
	float auxPrecio;
	char auxCodigoVuelo[LARGOCODIGO];
	int auxTipoPasajero;
	int auxEstadoVuelo;
*/
    if(path!=NULL && pArrayListPassenger!=NULL){
		pArchivo = fopen(path,"w");
		if(pArchivo!=NULL){
			/*for(i=0;i<largoLista;i++){
				if(pArrayListPassenger[i]!=NULL){
					if(!Passenger_getId(pArrayListPassenger[i], &auxId) &&
						!Passenger_getNombre(pArrayListPassenger[i], auxNombre) &&
						!Passenger_getApellido(pArrayListPassenger[i], auxApellido) &&
						!Passenger_getPrecio(pArrayListPassenger[i], &auxPrecio) &&
						!Passenger_getCodigoVuelo(pArrayListPassenger[i], auxCodigoVuelo) &&
						!Passenger_getTipoPasajero(pArrayListPassenger[i], &auxTipoPasajero) &&
						!Passenger_getEstadoVuelo(pArrayListPassenger[i], &auxEstadoVuelo)){
						fprintf(pArchivo,"%d,%s,%s,%.2f,%s,%d,%d\n",auxId,auxNombre,auxApellido,auxPrecio,
																	auxCodigoVuelo,auxTipoPasajero,auxEstadoVuelo);
					}
				}
			}*/
			fclose(pArchivo);
			retorno=0;
		}
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
