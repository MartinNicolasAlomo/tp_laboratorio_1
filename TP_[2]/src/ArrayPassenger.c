#include "ArrayPassenger.h"

//static const char TXT_STATUSFLIGHT[CANT_ESTADOS_VUELOS][LARGO_TEXTO]={"En Horario","En Vuelo","Demorado","Aterrizado"};
//static const char TXT_TYPEPASSENGER[CANT_TIPOS_PASAJEROS][LARGO_TEXTO]={"Economico","Premium","Ejecutivo","Primera Clase"};

static int idIncremental=1;
/// @brief Genera un codigo que se incrementa en 1 cada vez que se llama a la funcion
/// @return Retorna el codigo incrementado en 1 respecto al anterior
static int pasaj_generarId(void);
static int pasaj_generarId(void){
	return idIncremental++;
}

int pasaj_menuPrincipal(void){
	int retorno=-1;
	ePasajero aPasajeros[CANT_PASAJEROS];
	eEstadoVuelo aEstadosVuelos[CANT_ESTADOS_VUELOS]={{1,"En Horario"},{2,"En Vuelo"},{3,"Demorado"},{4,"Aterrizado"}};
	eTipoPasajero aTiposPasajeros[CANT_TIPOS_PASAJEROS]={{1,"Economico"},{2,"Premium"},{3,"Ejecutivo"},{4,"Primera Clase"}};
	int opcion=0;
	int indiceNuevo;
	int indiceBuscado;
	float precioPrevio;
	int totalPasajeros=0;
	float totalPrecios=0;

	if(!pasaj_inicializarLista(aPasajeros, CANT_PASAJEROS)){
		puts("Se inicializó el programa exitosamente.\n\n");
	}
	else{
		puts("Falló la inicialización del programa.\n\n\n");
	}
	do{
		if(!ingresarEntero(&opcion, MSJ_MENU_PRINCIPAL, MSJ_ERROR_OPCION, 1, 6, REINTENTOS)){
			switch(opcion){
			case 1:
				if(!pasaj_agregarPasajero(aPasajeros, CANT_PASAJEROS, &indiceNuevo)){
					printf("Se cargaron los datos del nuevo pasajero. ID n°: %d.\n\n", aPasajeros[indiceNuevo].id);
					totalPrecios=totalPrecios+aPasajeros[indiceNuevo].price;
					totalPasajeros++;
					pasaj_imprimirLista(aPasajeros, CANT_PASAJEROS, aEstadosVuelos, CANT_ESTADOS_VUELOS, aTiposPasajeros, CANT_TIPOS_PASAJEROS);
				}
				break;
			case 2:
				if(!totalPasajeros){
					puts("No hay pasajeros para mostrar.\n\n\n");
				}
				else{
					if(!pasaj_modificarPasajero(aPasajeros, CANT_PASAJEROS, &indiceBuscado, &precioPrevio)){
						printf("Se modificaron los datos del pasajero con el ID: %d.\n\n", aPasajeros[indiceBuscado].id);
						totalPrecios=totalPrecios-precioPrevio;
						totalPrecios=totalPrecios+aPasajeros[indiceBuscado].price;
						pasaj_imprimirLista(aPasajeros, CANT_PASAJEROS, aEstadosVuelos, CANT_ESTADOS_VUELOS, aTiposPasajeros, CANT_TIPOS_PASAJEROS);
					}
				}
				break;
			case 3:
				if(!totalPasajeros){
					puts("No hay pasajeros para mostrar.\n\n\n");
				}
				else{
					if(!pasaj_eliminarPasajero(aPasajeros, CANT_PASAJEROS, &indiceBuscado)){
						printf("Se eliminaron los datos del pasajero con el ID: %d.\n\n", aPasajeros[indiceBuscado].id);
						totalPrecios=totalPrecios-aPasajeros[indiceBuscado].price;
						totalPasajeros--;
						pasaj_imprimirLista(aPasajeros, CANT_PASAJEROS, aEstadosVuelos, CANT_ESTADOS_VUELOS, aTiposPasajeros, CANT_TIPOS_PASAJEROS);
					}
				}
				break;
			case 4:
				if(!totalPasajeros){
					puts("No hay pasajeros para mostrar.\n\n\n");
				}
				else{
					if(!pasaj_menuInformes(aPasajeros, CANT_PASAJEROS, aEstadosVuelos, CANT_ESTADOS_VUELOS, aTiposPasajeros, CANT_TIPOS_PASAJEROS, totalPrecios, totalPasajeros)){
						puts("Informe finalizado.\n\n\n");
					}
					else{
						puts("No se pudo mostrar el informe.\n\n\n");
					}
				}
				break;
			case 5:
				if(!pasaj_cargaForzadaPasajero(aPasajeros, CANT_PASAJEROS, &indiceNuevo, "Camila", "Lolo", 9000, "ARG09BA", 1, 3)){
					totalPrecios=totalPrecios+aPasajeros[indiceNuevo].price;
					totalPasajeros++;
				}
				if(!pasaj_cargaForzadaPasajero(aPasajeros, CANT_PASAJEROS, &indiceNuevo, "Matías", "Lolo", 60, "ITA18RM", 4, 2)){
					totalPrecios=totalPrecios+aPasajeros[indiceNuevo].price;
					totalPasajeros++;
				}
				if(!pasaj_cargaForzadaPasajero(aPasajeros, CANT_PASAJEROS, &indiceNuevo, "Gonzalo", "Cece", 9000, "ARG09BA", 2, 4)){
					totalPrecios=totalPrecios+aPasajeros[indiceNuevo].price;
					totalPasajeros++;
				}
				if(!pasaj_cargaForzadaPasajero(aPasajeros, CANT_PASAJEROS, &indiceNuevo, "Daiana", "Vivi", 60, "ARG09BA", 4, 1)){
					totalPrecios=totalPrecios+aPasajeros[indiceNuevo].price;
					totalPasajeros++;
				}
				if(!pasaj_cargaForzadaPasajero(aPasajeros, CANT_PASAJEROS, &indiceNuevo, "Ruben", "Lolo", 60, "ITA18RM", 3, 1)){
					totalPrecios=totalPrecios+aPasajeros[indiceNuevo].price;
					totalPasajeros++;
				}
				if(!pasaj_cargaForzadaPasajero(aPasajeros, CANT_PASAJEROS, &indiceNuevo, "Agostina", "Cece", 60, "ITA18RM", 1, 1)){
					totalPrecios=totalPrecios+aPasajeros[indiceNuevo].price;
					totalPasajeros++;
				}
				if(!pasaj_cargaForzadaPasajero(aPasajeros, CANT_PASAJEROS, &indiceNuevo, "Zoe", "Nene", 9000, "JAP27TK", 1, 3)){
					totalPrecios=totalPrecios+aPasajeros[indiceNuevo].price;
					totalPasajeros++;
				}
				puts("Se hardcodearon los pasajeros.\n");
				pasaj_imprimirLista(aPasajeros, CANT_PASAJEROS, aEstadosVuelos, CANT_ESTADOS_VUELOS, aTiposPasajeros, CANT_TIPOS_PASAJEROS);
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

int pasaj_cargaForzadaPasajero(ePasajero* aPasajeros, int limite, int* indiceNuevo, char* name, char* lastName, float price,
									char* flyCode, int typePassenger, int statusFlight){
	int retorno=-1;
	ePasajero auxiliar;
	int indiceLibre;
	if(aPasajeros!=NULL && limite>0 && name!=NULL && lastName!=NULL && price>0 && flyCode!=NULL){
		indiceLibre=pasaj_buscarIndiceVacio(aPasajeros, CANT_PASAJEROS);
		if(indiceLibre>=0){
			auxiliar.id=pasaj_generarId();
			strncpy(auxiliar.name,name,LARGO_NOMBRE);
			strncpy(auxiliar.lastName,lastName,LARGO_NOMBRE);
			strncpy(auxiliar.flyCode,flyCode,LARGO_CODIGO);
			auxiliar.price=price;
			auxiliar.idTipoPasajero=typePassenger;
			auxiliar.idEstadoVuelo=statusFlight;
			auxiliar.isEmpty=FALSE;
			aPasajeros[indiceLibre]=auxiliar;
			*indiceNuevo=indiceLibre;
			retorno=0;
		}
	}
	return retorno;
}

int pasaj_inicializarLista(ePasajero* aPasajeros, int limite){
	int retorno=-1;
	int i;
	if(aPasajeros!=NULL && limite>0){
		retorno=0;
		for(i=0;i<limite;i++){
			aPasajeros[i].isEmpty=TRUE;
		}
	}
	return retorno;
}

int pasaj_buscarIndiceVacio(ePasajero* vector, int limite){
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

int pasaj_buscarPasajeroPorId(ePasajero* aPasajeros, int limite, int id){
	int retorno=-1;
	int i;
	if(aPasajeros!=NULL && limite>0 && id>0){
		for(i=0;i<limite;i++){
			if(aPasajeros[i].id==id){
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

int pasaj_agregarPasajero(ePasajero* aPasajeros, int limite, int* indiceNuevo){
	int retorno=-1;
	ePasajero auxiliar;
	int indiceLibre;
	int confirmar;
	if(aPasajeros!=NULL && limite>0 && indiceNuevo!=NULL){
		indiceLibre=pasaj_buscarIndiceVacio(aPasajeros, limite);
		if(indiceLibre>=0 && !pasaj_cargarDatosPasajero(&auxiliar) &&
				!ingresarEntero(&confirmar, MSJ_CONFIRMAR_AGREGADO, MSJ_ERROR_OPCION, 0, 1, REINTENTOS) && confirmar){
			auxiliar.id=pasaj_generarId();
			auxiliar.isEmpty=FALSE;
			aPasajeros[indiceLibre]=auxiliar;
			*indiceNuevo=indiceLibre;
			puts("Confirmado.\n");
			retorno=0;
		}
	}
	return retorno;
}

int pasaj_cargarDatosPasajero(ePasajero* pElemento){
	int retorno=-1;
	ePasajero auxiliar;
	if(pElemento!=NULL){
		if(!ingresarNombre(auxiliar.name, LARGO_NOMBRE, "Ingrese el nombre:\n", "Error. No es un nombre, reinténtelo de nuevo.\n\n\n", REINTENTOS) &&
			!ingresarNombre(auxiliar.lastName, LARGO_NOMBRE, "\nIngrese el apellido:\n", "Error. No es un apellido, reinténtelo de nuevo.\n\n\n", REINTENTOS) &&
			!ingresarFlotante(&auxiliar.price, "\nIngrese el precio del vuelo:\n", "Error. No es un precio válido, reinténtelo de nuevo.\n\n\n", 0.1, 500000, REINTENTOS) &&
			!ingresarAlfanumerico(auxiliar.flyCode, LARGO_CODIGO, "\nIngrese el codigo de pasaje:\n", "Error. No es un tipo válido, reinténtelo de nuevo.\n\n\n", REINTENTOS) &&
			!ingresarEntero(&auxiliar.idTipoPasajero, "\nIngrese el tipo de pasajero: (1 Económico, 2 Premium, 3 Ejecutivo o 4 Primera Clase)\n", "Error. No es un tipo válido, reinténtelo de nuevo.\n\n\n", 1, 4, REINTENTOS) &&
			!ingresarEntero(&auxiliar.idEstadoVuelo, "\nIndique el estado de su vuelo: (1 Activo, 2 Demorado, 3 Reprogramado o 4 Cancelado)\n", "Error. No es un estado válido, reinténtelo de nuevo.\n\n\n", 1, 4, REINTENTOS)){
			strupr(auxiliar.flyCode);
			*pElemento=auxiliar;
			retorno=0;
		}
	}
	return retorno;
}

int pasaj_modificarPasajero(ePasajero* aPasajeros, int limite, int* indiceBuscado, float* precioPrevio){
	int retorno=-1;
	ePasajero auxiliar;
	int codigoModificar;
	int indiceCodigo;
	int flagCambio;
	int confirmar;
	if(aPasajeros!=NULL && limite>0 && indiceBuscado!=NULL && precioPrevio!=NULL &&
			!ingresarEntero(&codigoModificar, MSJ_ID_MODIFICAR, MSJ_ERROR_ID, 0, idIncremental, REINTENTOS)){
		indiceCodigo=pasaj_buscarPasajeroPorId(aPasajeros, CANT_PASAJEROS, codigoModificar);
		if(indiceCodigo>=0 && aPasajeros[indiceCodigo].isEmpty==FALSE){
			*indiceBuscado=indiceCodigo;
			*precioPrevio=aPasajeros[indiceCodigo].price;
			auxiliar=aPasajeros[indiceCodigo];
			if(!pasaj_menuModificar(&auxiliar, &flagCambio) && !flagCambio &&
					!ingresarEntero(&confirmar, MSJ_CONFIRMAR_MODIFICACION, MSJ_ERROR_OPCION, 0, 1, REINTENTOS) && confirmar){
				aPasajeros[indiceCodigo]=auxiliar;
				retorno=0;
			}
		}
	}
	return retorno;
}

int pasaj_menuModificar(ePasajero* pElemento, int* cambios){
	int retorno=-1;
	ePasajero auxiliar;
	int opcion;
	int flagCambios;
	if(pElemento!=NULL && cambios!=NULL){
		auxiliar=*pElemento;
		do{
			if(!ingresarEntero(&opcion, MSJ_MENU_MODIFICAR, MSJ_ERROR_OPCION, 1, 6, REINTENTOS)){
				switch(opcion){
				case 1:
					if(!ingresarNombre(auxiliar.name, LARGO_NOMBRE, "Nuevo nombre:\n", "Error\n\n\n", REINTENTOS)){
						puts("Nombre ingresado correctamente.\n\n");
						flagCambios=0;
					}
					else{
						puts("No se ingresó un nombre válido.\n\n");
					}
					break;
				case 2:
					if(!ingresarNombre(auxiliar.lastName, LARGO_NOMBRE, "Nuevo apellido:\n", "Error\n\n\n", REINTENTOS)){
						puts("Apellido ingresado correctamente.\n\n");
						flagCambios=0;
					}
					else{
						puts("No se ingresó un apellido válido.\n\n");
					}
					break;
				case 3:
					if(!ingresarFlotante(&auxiliar.price, "Nuevo precio:\n", "Error\n\n\n", 0.1, 500000, REINTENTOS)){
						puts("Precio ingresado correctamente.\n\n");
						flagCambios=0;
					}
					else{
						puts("No se ingresó un precio válido.\n\n");
					}
					break;
				case 4:
					//if(!ingresarEntero(&auxiliar.typePassenger, "Nuevo tipo de pasajero:\n  1- Económico\n  2- Premium\n  3- Ejecutivo\n  4- Primera Clase\n", "Error\n\n\n", 1, 4, REINTENTOS)){
					if(!ingresarEntero(&auxiliar.idTipoPasajero, "Nuevo tipo de pasajero:\n  1- Económico\n  2- Premium\n  3- Ejecutivo\n  4- Primera Clase\n", "Error\n\n\n", 1, 4, REINTENTOS)){
					puts("Tipo de pasajero ingresado correctamente.\n\n");
						flagCambios=0;
					}
					else{
						puts("No se ingresó un tipo de pasajero válido.\n\n");
					}
					break;
				case 5:
					if(!ingresarAlfanumerico(auxiliar.flyCode, LARGO_CODIGO, "Nuevo codigo de vuelo:\n", "Error\n\n\n", REINTENTOS)){
						strupr(auxiliar.flyCode);
						puts("Código de vuelo ingresado correctamente.\n\n");
						flagCambios=0;
					}
					else{
						puts("No se ingresó un código de vuelo válido.\n\n");
					}
					break;
				case 6:
					*cambios=flagCambios;
					*pElemento=auxiliar;
					retorno=0;
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

int pasaj_eliminarPasajero(ePasajero* aPasajeros, int limite, int* indiceBuscado){
	int retorno=-1;
	int idEliminar;
	int indiceCodigo;
	int confirmar;
	if(aPasajeros!=NULL && limite>0 && indiceBuscado!=NULL && !ingresarEntero(&idEliminar, MSJ_ID_ELIMINAR, MSJ_ERROR_ID, 1, idIncremental, REINTENTOS)){
		indiceCodigo=pasaj_buscarPasajeroPorId(aPasajeros, CANT_PASAJEROS, idEliminar);
		if(indiceCodigo>=0 && aPasajeros[indiceCodigo].isEmpty==FALSE &&
				!ingresarEntero(&confirmar, MSJ_CONFIRMAR_ELIMINADO, MSJ_OPCIONORDEN, 0, 1, REINTENTOS) && confirmar){
			aPasajeros[indiceCodigo].isEmpty=TRUE;
			*indiceBuscado=indiceCodigo;
			puts("Confirmado.\n");
			retorno=0;
		}
	}
	return retorno;
}

int pasaj_coincidirPasajeroConTipoPasajero(ePasajero unPasajero, eTipoPasajero* aTiposPasajeros, int limTiposPasajeros, eTipoPasajero* auxiliar){
	int retorno=-1;
	int i;
	if(1){
		for(i=0;i<limTiposPasajeros;i++){
			if(aTiposPasajeros[i].id==unPasajero.idTipoPasajero){
				*auxiliar=aTiposPasajeros[i];
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int pasaj_coincidirPasajeroConEstadoVuelo(ePasajero unPasajero, eEstadoVuelo* aEstadosVuelos, int limEstadosVuelos, eEstadoVuelo* auxiliar){
	int retorno=-1;
	int i;
	if(1){
		for(i=0;i<limEstadosVuelos;i++){
			if(aEstadosVuelos[i].id==unPasajero.idTipoPasajero){
				*auxiliar=aEstadosVuelos[i];
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int pasaj_imprimirLista(ePasajero* aPasajeros, int limPasajeros, eEstadoVuelo* aEstadosVuelos, int limEstadosVuelos,
							eTipoPasajero* aTiposPasajeros, int limTiposPasajeros){
	int retorno=-1;
	int i;
	eEstadoVuelo auxEstadoVuelo;
	eTipoPasajero auxTipoPasajeros;
	if(aPasajeros!=NULL && limPasajeros>0){
		retorno=0;
		printf("Lista de pasajeros:\n|%-11s|%-26s|%-26s|%-16s|%-21s|%-21s|%-21s|\n",
				"Id:", "Nombre:", "Apellido:", "Precio:", "Codigo de Vuelo:", "Estado de Vuelo:", "Tipo de Pasajero:");
		for(i=0;i<limPasajeros;i++){
			if(aPasajeros[i].isEmpty==FALSE &&
					!pasaj_coincidirPasajeroConTipoPasajero(aPasajeros[i], aTiposPasajeros, limTiposPasajeros, &auxTipoPasajeros) &&
					!pasaj_coincidirPasajeroConEstadoVuelo(aPasajeros[i], aEstadosVuelos, limEstadosVuelos, &auxEstadoVuelo)){
				pasaj_imprimirElemento(&aPasajeros[i], &auxEstadoVuelo, &auxTipoPasajeros);
			}
		}
		puts("\n\n");
	}
	return retorno;
}

int pasaj_imprimirElemento(ePasajero* pasajero, eEstadoVuelo* estadoVuelo, eTipoPasajero* tipoPasajero){
	int retorno=-1;
	if(pasajero!=NULL && pasajero->isEmpty==FALSE && estadoVuelo!=NULL && tipoPasajero!=NULL){
		retorno=0;
		printf("|%11d|%26s|%26s|%16.2f|%21s|%21s|%21s|\n",
				pasajero->id, pasajero->name, pasajero->lastName, pasajero->price,
				pasajero->flyCode, estadoVuelo->descripcion, tipoPasajero->descripcion);
	}
	return retorno;
}

int pasaj_ordenarPorApellidoYTipoPasajero(ePasajero* aPasajeros, int limite, int orden){
	int retorno=-1;
	int flagSwap;
	int i;
	ePasajero buffer;
	int auxComparacion;
	int nuevoLimite;
	if(aPasajeros!=NULL && limite>0){
		nuevoLimite=limite-1;
		if(orden){
			do{
				flagSwap=FALSE;
				for(i=0;i<nuevoLimite;i++){
					if(aPasajeros[i].isEmpty || aPasajeros[i+1].isEmpty){
						continue;
					}
					auxComparacion = strncmp(aPasajeros[i].lastName,aPasajeros[i+1].lastName,LARGO_NOMBRE);
					if(auxComparacion>0 || (auxComparacion==0 && aPasajeros[i].idTipoPasajero > aPasajeros[i+1].idTipoPasajero)){
						flagSwap=TRUE;
						buffer = aPasajeros[i];
						aPasajeros[i] = aPasajeros[i+1];
						aPasajeros[i+1] = buffer;
					}
				}
				nuevoLimite--;
			}while(flagSwap);
		}
		else{
			do{
				flagSwap=FALSE;
				for(i=0;i<nuevoLimite;i++){
					if(aPasajeros[i].isEmpty || aPasajeros[i+1].isEmpty){
						continue;
					}
					auxComparacion = strncmp(aPasajeros[i].lastName,aPasajeros[i+1].lastName,LARGO_NOMBRE);
					if(auxComparacion<0 || (auxComparacion==0 && aPasajeros[i].idTipoPasajero < aPasajeros[i+1].idTipoPasajero)){
						flagSwap=TRUE;
						buffer = aPasajeros[i];
						aPasajeros[i] = aPasajeros[i+1];
						aPasajeros[i+1] = buffer;
					}
				}
				nuevoLimite--;
			}while(flagSwap);
		}
		retorno = 0;
	}
	return retorno;
}

int pasaj_ordenarPorCodigoVueloYEstadoVuelo(ePasajero* aPasajeros, int limite, int orden){
	int retorno=-1;
	int flagSwap;
	int i;
	ePasajero buffer;
	int auxiliarComparacion;
	int nuevoLimite;
	if(aPasajeros!=NULL && limite>0){
		nuevoLimite=limite-1;
		if(orden){
			do{
				flagSwap=FALSE;
				for(i=0;i<nuevoLimite;i++){
					if(aPasajeros[i].isEmpty || aPasajeros[i+1].isEmpty){
						continue;
					}
					auxiliarComparacion = strncmp(aPasajeros[i].flyCode,aPasajeros[i+1].flyCode,LARGO_CODIGO);
					if(auxiliarComparacion>0 || (auxiliarComparacion==0 && aPasajeros[i].idEstadoVuelo > aPasajeros[i+1].idEstadoVuelo)){
						flagSwap=TRUE;
						buffer = aPasajeros[i];
						aPasajeros[i] = aPasajeros[i+1];
						aPasajeros[i+1] = buffer;
					}
				}
				nuevoLimite--;
			}while(flagSwap);
		}
		else{
			do{
				flagSwap=FALSE;
				for(i=0;i<nuevoLimite;i++){
					if(aPasajeros[i].isEmpty || aPasajeros[i+1].isEmpty){
						continue;
					}
					auxiliarComparacion = strncmp(aPasajeros[i].flyCode,aPasajeros[i+1].flyCode,LARGO_CODIGO);
					if(auxiliarComparacion<0 || (auxiliarComparacion==0 && aPasajeros[i].idEstadoVuelo < aPasajeros[i+1].idEstadoVuelo)){
						flagSwap=TRUE;
						buffer = aPasajeros[i];
						aPasajeros[i] = aPasajeros[i+1];
						aPasajeros[i+1] = buffer;
					}
				}
				nuevoLimite--;
			}while(flagSwap);
		}
		retorno=0;
	}
	return retorno;
}

int pasaj_menuInformes(ePasajero* aPasajeros, int limPasajeros, eEstadoVuelo* aEstadosVuelos, int limEstadosVuelos,
						eTipoPasajero* aTiposPasajeros, int limTiposPasajeros, float totalPrecios, int totalPasajeros){
	int retorno=-1;
	int tipoInforme;
	int orden;
	float precioPromedio;
	int totalSuperanPromedio;
	if(aPasajeros!=NULL && totalPrecios>0 && totalPasajeros>0){
		if(!ingresarEntero(&tipoInforme, MSJ_MENU_INFORME, MSJ_ERROR_OPCION, 1, 3, REINTENTOS)){
			switch(tipoInforme){
			case 1:
				if(!ingresarEntero(&orden, MSJ_OPCIONORDEN, MSJ_ERROR_OPCION, 0, 1, REINTENTOS)){
					if(!pasaj_ordenarPorApellidoYTipoPasajero(aPasajeros, limPasajeros, orden)){
						pasaj_imprimirLista(aPasajeros, limPasajeros, aEstadosVuelos, limEstadosVuelos, aTiposPasajeros, limTiposPasajeros);
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
				if(!pasaj_calcularPrecioPromedio(&precioPromedio, totalPrecios, totalPasajeros)){
					printf("El total de los precios es: %.2f\n",totalPrecios);
					printf("El promedio de los precios es: %.2f\n",precioPromedio);
					if(!pasaj_calcularSuperanPrecioPromedio(aPasajeros, limPasajeros, &totalSuperanPromedio, precioPromedio)){
						printf("La cantidad de pasajeros que supera el precio promedio es: %d\n\n",totalSuperanPromedio);
						retorno=0;
					}
					else{
						puts("No se pudo calcular lo solicitado");
					}
				}
				break;
			case 3:
				if(!ingresarEntero(&orden, MSJ_OPCIONORDEN, MSJ_ERROR_OPCION, 0, 1, REINTENTOS)){
					if(!pasaj_ordenarPorCodigoVueloYEstadoVuelo(aPasajeros, limPasajeros, orden)){
						pasaj_imprimirLista(aPasajeros, limPasajeros, aEstadosVuelos, limEstadosVuelos, aTiposPasajeros, limTiposPasajeros);
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

int pasaj_calcularPrecioPromedio(float* pResultado, float totalPrecios, int totalPasajeros){
	int retorno=-1;
	float resultado;
	if(pResultado!=NULL && totalPrecios>0 && totalPasajeros>0){
		resultado=totalPrecios/totalPasajeros;
		*pResultado=resultado;
		retorno=0;
	}
	return retorno;
}

int pasaj_calcularSuperanPrecioPromedio(ePasajero* aPasajeros, int limite, int* pResultado, float precioPromedio){
	int retorno=-1;
	int i;
	int contadorMayorPromedio=0;
	if(aPasajeros!=NULL && limite>0 && pResultado!=NULL && precioPromedio>0){
		for(i=0;i<limite;i++){
			if(aPasajeros[i].isEmpty==FALSE && aPasajeros[i].price>precioPromedio){
				contadorMayorPromedio++;
			}
		}
		*pResultado=contadorMayorPromedio;
		retorno=0;
	}
	return retorno;
}
