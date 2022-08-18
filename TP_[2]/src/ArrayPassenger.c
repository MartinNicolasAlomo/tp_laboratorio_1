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
	eVuelo aVuelos[CANT_VUELOS]={{1,"ARG 09 BA","En Horario"},{2,"JPN 18 TK","En Vuelo"},{3,"USA 72 WA","Demorado"},
									{4,"ITA 63 RM","Aterrizado"},{5,"FRA 54 PR","En Horario"},{6,"BRA 71 BS","Aterrizado"}};
	eTipoPasajero aTiposPasajeros[CANT_TIPOS_PASAJEROS]={{1,"Economico"},{2,"Premium"},{3,"Ejecutivo"},{4,"Primera Clase"}};

	int opcion=0;
	int indiceNuevo;
	int totalPasajeros=0;
	float totalPrecios=0;

	if(!pasaj_inicializarLista(aPasajeros, CANT_PASAJEROS)){
		puts("Se inicializó el programa correctamente.\n\n");
	}
	else{
		puts("Falló la inicialización del programa.\n\n\n");
	}
	do{
		if(!ingresarEntero(&opcion, MSJ_MENU_PRINCIPAL, MSJ_ERROR_OPCION, 1, 6, REINTENTOS)){
			switch(opcion){
			case 1:
				if(!pasaj_agregarPasajero(aPasajeros, CANT_PASAJEROS, aVuelos, CANT_VUELOS, aTiposPasajeros, CANT_TIPOS_PASAJEROS, &totalPrecios, &totalPasajeros)){
				}
				break;
			case 2:
				if(!totalPasajeros){
					puts("No hay pasajeros para mostrar.\n\n\n");
				}
				else{
					if(!pasaj_modificarPasajero(aPasajeros, CANT_PASAJEROS, aVuelos, CANT_VUELOS, aTiposPasajeros, CANT_TIPOS_PASAJEROS, &totalPrecios)){
					}
				}
				break;
			case 3:
				if(!totalPasajeros){
					puts("No hay pasajeros para mostrar.\n\n\n");
				}
				else{
					if(!pasaj_eliminarPasajero(aPasajeros, CANT_PASAJEROS, aVuelos, CANT_VUELOS, aTiposPasajeros, CANT_TIPOS_PASAJEROS, &totalPrecios, &totalPasajeros)){
					}
				}
				break;
			case 4:
				if(!totalPasajeros){
					puts("No hay pasajeros para mostrar.\n\n\n");
				}
				else{
					if(!pasaj_menuInformes(aPasajeros, CANT_PASAJEROS, aVuelos, CANT_VUELOS, aTiposPasajeros, CANT_TIPOS_PASAJEROS, totalPrecios, totalPasajeros)){
						puts("Informe finalizado.\n\n\n");
					}
					else{
						puts("No se pudo mostrar el informe.\n\n\n");
					}
				}
				break;
			case 5:
				if(!pasaj_altaForzadaPasajero(aPasajeros, CANT_PASAJEROS, &indiceNuevo, "Camila", "Lolo", 9000, 1, 1)){
					totalPrecios=totalPrecios+aPasajeros[indiceNuevo].precio;
					totalPasajeros++;
				}
				if(!pasaj_altaForzadaPasajero(aPasajeros, CANT_PASAJEROS, &indiceNuevo, "Matías", "Lolo", 60, 2, 4)){
					totalPrecios=totalPrecios+aPasajeros[indiceNuevo].precio;
					totalPasajeros++;
				}
				if(!pasaj_altaForzadaPasajero(aPasajeros, CANT_PASAJEROS, &indiceNuevo, "Gonzalo", "Cece", 9000, 1, 2)){
					totalPrecios=totalPrecios+aPasajeros[indiceNuevo].precio;
					totalPasajeros++;
				}
				if(!pasaj_altaForzadaPasajero(aPasajeros, CANT_PASAJEROS, &indiceNuevo, "Daiana", "Vivi", 60, 1, 4)){
					totalPrecios=totalPrecios+aPasajeros[indiceNuevo].precio;
					totalPasajeros++;
				}
				if(!pasaj_altaForzadaPasajero(aPasajeros, CANT_PASAJEROS, &indiceNuevo, "Ruben", "Lolo", 60, 2, 3)){
					totalPrecios=totalPrecios+aPasajeros[indiceNuevo].precio;
					totalPasajeros++;
				}
				if(!pasaj_altaForzadaPasajero(aPasajeros, CANT_PASAJEROS, &indiceNuevo, "Agostina", "Cece", 60, 2, 1)){
					totalPrecios=totalPrecios+aPasajeros[indiceNuevo].precio;
					totalPasajeros++;
				}
				if(!pasaj_altaForzadaPasajero(aPasajeros, CANT_PASAJEROS, &indiceNuevo, "Zoe", "Nene", 9000, 3, 1)){
					totalPrecios=totalPrecios+aPasajeros[indiceNuevo].precio;
					totalPasajeros++;
				}
				puts("Se hardcodearon los pasajeros.\n");
				pasaj_imprimirLista(aPasajeros, CANT_PASAJEROS, aVuelos, CANT_VUELOS, aTiposPasajeros, CANT_TIPOS_PASAJEROS);
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
			if(aPasajeros[i].idPasajero==id){
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}




int pasaj_altaForzadaPasajero(ePasajero* aPasajeros, int limite, int* indiceNuevo, char* nombre, char* apellido, float precio,
									int idVuelo, int idTipoPasajero){
	int retorno=-1;
	ePasajero auxiliar;
	int indiceLibre;
	if(aPasajeros!=NULL && limite>0 && nombre!=NULL && apellido!=NULL && precio>0 && idVuelo>0 && idTipoPasajero>0){
		indiceLibre=pasaj_buscarIndiceVacio(aPasajeros, CANT_PASAJEROS);
		if(indiceLibre>=0){
			auxiliar.idPasajero=pasaj_generarId();
			strncpy(auxiliar.nombre,nombre,LARGO_NOMBRE);
			strncpy(auxiliar.apellido,apellido,LARGO_NOMBRE);
			auxiliar.idVuelo=idVuelo;
			auxiliar.precio=precio;
			auxiliar.idTipoPasajero=idTipoPasajero;
			auxiliar.isEmpty=FALSE;
			aPasajeros[indiceLibre]=auxiliar;
			*indiceNuevo=indiceLibre;
			retorno=0;
		}
	}
	return retorno;
}

int pasaj_agregarPasajero(ePasajero* aPasajeros, int limPasajeros, eVuelo* aVuelos, int limVuelos,
								eTipoPasajero* aTiposPasajeros, int limTiposPasajeros, float* totalPrecios, int* totalPasajeros){
	int retorno=-1;
	ePasajero auxiliar;
	int indiceLibre;
	int confirmar;
	if(aPasajeros!=NULL && limPasajeros>0){
		indiceLibre=pasaj_buscarIndiceVacio(aPasajeros, limPasajeros);
		if(indiceLibre>=0 && !pasaj_cargarDatosPasajero(&auxiliar, aPasajeros, limPasajeros, aVuelos, limVuelos, aTiposPasajeros, limTiposPasajeros) &&
				!pasaj_vistaPrevia(&auxiliar, "Vista previa pasajero agregado:", aVuelos, limVuelos, aTiposPasajeros, limTiposPasajeros) &&
				!ingresarEntero(&confirmar, MSJ_CONFIRMAR_AGREGADO, MSJ_ERROR_OPCION, 0, 1, REINTENTOS) && confirmar){
			puts("Confirmado.\n");
			auxiliar.idPasajero=pasaj_generarId();
			auxiliar.isEmpty=FALSE;
			aPasajeros[indiceLibre]=auxiliar;
			*totalPrecios=*totalPrecios+aPasajeros[indiceLibre].precio;
			(*totalPasajeros)++;
			pasaj_imprimirLista(aPasajeros, limPasajeros, aVuelos, limVuelos, aTiposPasajeros, limTiposPasajeros);
			printf("Se cargaron los datos del nuevo pasajero. ID n°: %d.\n\n", aPasajeros[indiceLibre].idPasajero);
			retorno=0;
		}
	}
	return retorno;
}

int pasaj_cargarDatosPasajero(ePasajero* pElemento, ePasajero* aPasajeros, int limPasajeros,
								eVuelo* aVuelos, int limVuelos, eTipoPasajero* aTiposPasajeros, int limTiposPasajeros){
	int retorno=-1;
	ePasajero auxiliar;
	if(pElemento!=NULL && aPasajeros!=NULL && limPasajeros>0 && aVuelos!=NULL && limVuelos>0 && aTiposPasajeros!=NULL && limTiposPasajeros>0){
		if(!ingresarNombre(auxiliar.nombre, LARGO_NOMBRE, "Ingrese el nombre:", "No es un nombre válido.", REINTENTOS) &&
			!pasarInicialesMayusculas(auxiliar.nombre, LARGO_NOMBRE) &&
			!ingresarNombre(auxiliar.apellido, LARGO_NOMBRE, "Ingrese el apellido:", "No es un apellido válido.", REINTENTOS) &&
			!pasarInicialesMayusculas(auxiliar.apellido, LARGO_NOMBRE) &&
			!ingresarFlotante(&auxiliar.precio, "Ingrese el precio del vuelo:", "No es un precio válido.", 0.1, 500000, REINTENTOS) &&
			!vuelo_imprimirListaVuelos(aVuelos, limVuelos) &&
			!ingresarEntero(&auxiliar.idVuelo, "Indique el id del vuelo:", "No es un id de vuelo válido.", 1, 6, REINTENTOS) &&
			!tipoPasajero_imprimirListaTiposPasajeros(aTiposPasajeros, limTiposPasajeros) &&
			!ingresarEntero(&auxiliar.idTipoPasajero, "Ingrese el id del tipo de pasajero:", "No es un id de tipo de pasajero válido.", 1, 4, REINTENTOS)
		){
			*pElemento=auxiliar;
			retorno=0;
		}
	}
	return retorno;
}


int pasaj_modificarPasajero(ePasajero* aPasajeros, int limPasajeros, eVuelo* aVuelos, int limVuelos,
								eTipoPasajero* aTiposPasajeros, int limTiposPasajeros, float* totalPrecios){
	int retorno=-1;
	ePasajero auxiliar;
	int codigoModificar;
	int indiceCodigo;
	int flagCambio;
	int confirmar;
	if(aPasajeros!=NULL && limPasajeros>0 &&
			!ingresarEntero(&codigoModificar, MSJ_ID_MODIFICAR, MSJ_ERROR_ID, 0, idIncremental, REINTENTOS)){
		indiceCodigo=pasaj_buscarPasajeroPorId(aPasajeros, CANT_PASAJEROS, codigoModificar);
		if(indiceCodigo>=0 && aPasajeros[indiceCodigo].isEmpty==FALSE &&
				!pasaj_vistaPrevia(&aPasajeros[indiceCodigo], "Se encontro este pasajero:", aVuelos, limVuelos, aTiposPasajeros, limTiposPasajeros)){
			*totalPrecios=*totalPrecios-aPasajeros[indiceCodigo].precio;
			auxiliar=aPasajeros[indiceCodigo];
			if(!pasaj_menuModificar(&auxiliar, &flagCambio, aVuelos, limVuelos, aTiposPasajeros, limTiposPasajeros) && !flagCambio &&
					!pasaj_vistaPrevia(&auxiliar, "Vista previa cambios hechos", aVuelos, limVuelos, aTiposPasajeros, limTiposPasajeros) &&
					!ingresarEntero(&confirmar, MSJ_CONFIRMAR_MODIFICACION, MSJ_ERROR_OPCION, 0, 1, REINTENTOS) && confirmar){
				aPasajeros[indiceCodigo]=auxiliar;
				*totalPrecios=*totalPrecios+aPasajeros[indiceCodigo].precio;
				pasaj_imprimirLista(aPasajeros, limPasajeros, aVuelos, limVuelos, aTiposPasajeros, limTiposPasajeros);
				printf("Se modificaron los datos del pasajero con el ID: %d.\n\n", aPasajeros[indiceCodigo].idPasajero);
				retorno=0;
			}
		}
	}
	return retorno;
}

int pasaj_menuModificar(ePasajero* unAlbum, int* cambios, eVuelo* aVuelos, int limVuelos, eTipoPasajero* aTiposPasajeros, int limTiposPasajeros){
	int retorno=-1;
	ePasajero auxiliar;
	int opcion;
	int flagCambios;
	if(unAlbum!=NULL && cambios!=NULL){
		auxiliar=*unAlbum;
		do{
			if(!ingresarEntero(&opcion, MSJ_MENU_MODIFICAR, MSJ_ERROR_OPCION, 1, 6, REINTENTOS)){
				switch(opcion){
				case 1:
					if(!ingresarNombre(auxiliar.nombre, LARGO_NOMBRE, "Nuevo nombre:", "No es un nombre válido:", REINTENTOS)
							&& !pasarInicialesMayusculas(auxiliar.nombre, LARGO_NOMBRE)){
						puts("Nombre ingresado correctamente.\n\n");
						flagCambios=0;
					}
					else{
						puts("No se ingresó un nombre válido.\n\n");
					}
					break;
				case 2:
					if(!ingresarNombre(auxiliar.apellido, LARGO_NOMBRE, "Nuevo apellido:", "No es un apellido válido:", REINTENTOS)
							&& !pasarInicialesMayusculas(auxiliar.apellido, LARGO_NOMBRE)){
						puts("Apellido ingresado correctamente.\n\n");
						flagCambios=0;
					}
					else{
						puts("No se ingresó un apellido válido.\n\n");
					}
					break;
				case 3:
					if(!ingresarFlotante(&auxiliar.precio, "Nuevo precio:", "No es un apellido válido:", 0.1, 500000, REINTENTOS)){
						puts("Precio ingresado correctamente.\n\n");
						flagCambios=0;
					}
					else{
						puts("No se ingresó un precio válido.\n\n");
					}
					break;
				case 4:
					if(!vuelo_imprimirListaVuelos(aVuelos, limVuelos)
							&& !ingresarEntero(&auxiliar.idVuelo, "Nuevo id de vuelo:", "No es un id de vuelo válido:", 1, 6, REINTENTOS)){
					puts("Id de vuelo ingresado correctamente.\n\n");
						flagCambios=0;
					}
					else{
						puts("No se ingresó un id de vuelo válido.\n\n");
					}
					break;
				case 5:
					if(!tipoPasajero_imprimirListaTiposPasajeros(aTiposPasajeros, limTiposPasajeros)
							&& !ingresarEntero(&auxiliar.idTipoPasajero, "Nuevo id de tipo de pasajero:", "No es un id de tipo de pasajero válido:", 1, 4, REINTENTOS)){
					puts("Id de tipo de pasajero ingresado correctamente.\n\n");
						flagCambios=0;
					}
					else{
						puts("No se ingresó un id de tipo de pasajero válido.\n\n");
					}
					break;
				case 6:
					*cambios=flagCambios;
					*unAlbum=auxiliar;
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


int pasaj_eliminarPasajero(ePasajero* aPasajeros, int limPasajeros, eVuelo* aVuelos, int limVuelos,
								eTipoPasajero* aTiposPasajeros, int limTiposPasajeros, float* totalPrecios, int* totalPasajeros){
	int retorno=-1;
	int idEliminar;
	int indiceCodigo;
	int confirmar;
	if(aPasajeros!=NULL && limPasajeros>0 && !ingresarEntero(&idEliminar, MSJ_ID_ELIMINAR, MSJ_ERROR_ID, 1, idIncremental, REINTENTOS)){
		indiceCodigo=pasaj_buscarPasajeroPorId(aPasajeros, CANT_PASAJEROS, idEliminar);
		if(indiceCodigo>=0 && aPasajeros[indiceCodigo].isEmpty==FALSE &&
				!pasaj_vistaPrevia(&aPasajeros[indiceCodigo], "Se encontró este pasajero:", aVuelos, limVuelos, aTiposPasajeros, limTiposPasajeros) &&
				!ingresarEntero(&confirmar, MSJ_CONFIRMAR_ELIMINADO, MSJ_OPCIONORDEN, 0, 1, REINTENTOS) && confirmar){
			puts("Confirmado.\n");
			aPasajeros[indiceCodigo].isEmpty=TRUE;
			*totalPrecios=*totalPrecios-aPasajeros[indiceCodigo].precio;
			(*totalPasajeros)--;
			pasaj_imprimirLista(aPasajeros, limPasajeros, aVuelos, limVuelos, aTiposPasajeros, limTiposPasajeros);
			printf("Se eliminaron los datos del pasajero con el ID: %d.\n\n", aPasajeros[indiceCodigo].idPasajero);
			retorno=0;
		}
	}
	return retorno;
}


int pasaj_imprimirAlbumIndividual(ePasajero* unPasajero, eVuelo* unVuelo, eTipoPasajero* unTipoPasajero){
	int retorno=-1;
	if(unPasajero!=NULL && unPasajero->isEmpty==FALSE && unVuelo!=NULL && unTipoPasajero!=NULL){
		retorno=0;
		printf("|%11d|%26s|%26s|%16.2f|%21s|%21s|%21s|\n",
				unPasajero->idPasajero, unPasajero->nombre, unPasajero->apellido, unPasajero->precio,
				unVuelo->codigoVuelo, unVuelo->estadoVuelo, unTipoPasajero->descripcion);
	}
	return retorno;
}

int pasaj_imprimirLista(ePasajero* aPasajeros, int limPasajeros, eVuelo* aVuelos, int limVuelos, eTipoPasajero* aTiposPasajeros, int limTiposPasajeros){
	int retorno=-1;
	int i;
	eVuelo auxVuelo;
	eTipoPasajero auxTipoPasajeros;
	if(aPasajeros!=NULL && limPasajeros>0){
		retorno=0;
		printf("Lista de pasajeros:\n|%-11s|%-26s|%-26s|%-16s|%-21s|%-21s|%-21s|\n",
				"Id:", "Nombre:", "Apellido:", "Precio:", "Codigo de Vuelo:", "Estado de Vuelo:", "Tipo de Pasajero:");
		for(i=0;i<limPasajeros;i++){
			if(aPasajeros[i].isEmpty==FALSE &&
					!pasaj_coincidirPasajeroConVuelo(&aPasajeros[i], aVuelos, limVuelos, &auxVuelo) &&
					!pasaj_coincidirPasajeroConTipoPasajero(&aPasajeros[i], aTiposPasajeros, limTiposPasajeros, &auxTipoPasajeros)){
				pasaj_imprimirAlbumIndividual(&aPasajeros[i], &auxVuelo, &auxTipoPasajeros);
			}
		}
		puts("\n\n");
	}
	return retorno;
}

int pasaj_vistaPrevia(ePasajero* unPasajero, char* mensajePrevio, eVuelo* aVuelos, int limVuelos, eTipoPasajero* aTiposPasajeros, int limTiposPasajeros){
	int retorno=-1;
	eVuelo auxVuelo;
	eTipoPasajero auxTipoPasajero;
	if(unPasajero!=NULL &&
			!pasaj_coincidirPasajeroConVuelo(unPasajero, aVuelos, limVuelos, &auxVuelo) &&
			!pasaj_coincidirPasajeroConTipoPasajero(unPasajero, aTiposPasajeros, limTiposPasajeros, &auxTipoPasajero)){
		printf("\n\n%s\n\n|%-11s|%-26s|%-26s|%-16s|%-21s|%-21s|%-21s|\n",
				mensajePrevio, "Id:", "Nombre:", "Apellido:", "Precio:", "Codigo de Vuelo:", "Estado de Vuelo:", "Tipo de Pasajero:");
		pasaj_imprimirAlbumIndividual(unPasajero, &auxVuelo, &auxTipoPasajero);
		retorno=0;
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
					auxComparacion = strncmp(aPasajeros[i].apellido,aPasajeros[i+1].apellido,LARGO_NOMBRE);
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
					auxComparacion = strncmp(aPasajeros[i].apellido,aPasajeros[i+1].apellido,LARGO_NOMBRE);
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


int pasaj_coincidirPasajeroConVuelo(ePasajero* unPasajero, eVuelo* aVuelos, int limVuelos, eVuelo* auxVuelo){
	int retorno=-1;
	int i;
	if(1){
		for(i=0;i<limVuelos;i++){
			if(aVuelos[i].idVuelo==unPasajero->idTipoPasajero){
				*auxVuelo=aVuelos[i];
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int pasaj_coincidirPasajeroConTipoPasajero(ePasajero* unPasajero, eTipoPasajero* aTiposPasajeros, int limTiposPasajeros, eTipoPasajero* auxTipoPasajero){
	int retorno=-1;
	int i;
	if(1){
		for(i=0;i<limTiposPasajeros;i++){
			if(aTiposPasajeros[i].idTipoPasajero==unPasajero->idTipoPasajero){
				*auxTipoPasajero=aTiposPasajeros[i];
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}



/*int pasaj_ordenarPorCodigoVueloYEstadoVuelo(ePasajero* aPasajeros, int limPasajeros, eVuelo* aVuelos, int limVuelos, int orden){
	int retorno=-1;
	int flagSwap;
	int i;
	ePasajero buffer;
	int auxiliarComparacion;
	int nuevoLimite;
	if(aPasajeros!=NULL && limPasajeros>0){
		nuevoLimite=limPasajeros-1;
		if(orden){
			do{
				flagSwap=FALSE;
				for(i=0;i<nuevoLimite;i++){
					if(aPasajeros[i].isEmpty || aPasajeros[i+1].isEmpty){
						continue;
					}
					pasaj_coincidirPasajeroConVuelo(&buffer, aVuelos, limVuelos, auxVuelo)
					auxiliarComparacion = strncmp(aPasajeros[i].codigoVuelo,aPasajeros[i+1].codigoVuelo,LARGO_CODIGO);
					if(auxiliarComparacion>0 || (auxiliarComparacion==0 && aPasajeros[i].idVuelo > aPasajeros[i+1].idVuelo)){
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
					auxiliarComparacion = strncmp(aPasajeros[i].codigoVuelo,aPasajeros[i+1].codigoVuelo,LARGO_CODIGO);
					if(auxiliarComparacion<0 || (auxiliarComparacion==0 && aPasajeros[i].idVuelo < aPasajeros[i+1].idVuelo)){
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
*/

int pasaj_menuInformes(ePasajero* aPasajeros, int limPasajeros, eVuelo* aVuelos, int limVuelos,
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
				if(!ingresarEntero(&orden, MSJ_OPCIONORDEN, MSJ_ERROR_OPCION, 0, 1, REINTENTOS) &&
						!pasaj_ordenarPorApellidoYTipoPasajero(aPasajeros, limPasajeros, orden) &&
						!pasaj_imprimirLista(aPasajeros, limPasajeros, aVuelos, limVuelos, aTiposPasajeros, limTiposPasajeros)){
						retorno=0;
				}
				break;
			case 2:
				if(!pasaj_calcularPrecioPromedio(&precioPromedio, totalPrecios, totalPasajeros) &&
						!pasaj_calcularSuperanPrecioPromedio(aPasajeros, limPasajeros, &totalSuperanPromedio, precioPromedio)){
						printf("El total de los precios es: %.2f\n",totalPrecios);
						printf("El promedio de los precios es: %.2f\n",precioPromedio);
						printf("La cantidad de pasajeros que supera el precio promedio es: %d\n\n",totalSuperanPromedio);
						retorno=0;
				}
				break;
			/*case 3:
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
				break;*/
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
			if(aPasajeros[i].isEmpty==FALSE && aPasajeros[i].precio>precioPromedio){
				contadorMayorPromedio++;
			}
		}
		*pResultado=contadorMayorPromedio;
		retorno=0;
	}
	return retorno;
}




int vuelo_imprimirListaVuelos(eVuelo* aVuelos, int limVuelos){
	int retorno=-1;
	int i;
	if(aVuelos!=NULL && limVuelos>0){
		printf("\n\nListado de Vuelos:\n|%-16s|%-21s|%-21s|\n", "Id Vuelo:", "Código de Vuelo:", "Estado de Vuelo:");
		retorno=0;
		for(i=0;i<limVuelos;i++){
			printf("|%16d|%21s|%21s|\n", aVuelos[i].idVuelo, aVuelos[i].codigoVuelo, aVuelos[i].estadoVuelo);
		}
	}
	return retorno;
}

int tipoPasajero_imprimirListaTiposPasajeros(eTipoPasajero* aTiposPasajeros, int limTiposPasajeros){
	int retorno=-1;
	int i;
	if(aTiposPasajeros!=NULL && limTiposPasajeros>0){
		printf("\n\nListado de Tipos de Pasajeros:\n|%-16s|%-21s|\n", "Id Vuelo:", "Tipos de Pasajeros:");
		retorno=0;
		for(i=0;i<limTiposPasajeros;i++){
			printf("|%16d|%21s|\n", aTiposPasajeros[i].idTipoPasajero, aTiposPasajeros[i].descripcion);
		}
	}
	return retorno;
}

