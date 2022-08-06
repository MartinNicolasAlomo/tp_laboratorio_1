#include "Album.h"

static int codigoIncremental=13;

/// @brief Genera un codigo que se incrementa en 1 cada vez que se llama a la funcion
/// @return Retorna el codigo incrementado en 1 respecto al anterior
static int album_generarCodigo(void);
static int album_generarCodigo(void){
	return codigoIncremental++;
}

int album_menuPrincipal(void){
	int retorno=-1;
	eAlbum aAlbumes[CANT_ALBUMES];
	eArtista aArtistas[CANT_ARTISTAS]={{1,"Soda Stereo"},{2,"Miranda!"},{3,"Damas Gratis"},{4,"Piazzolla"},{5,"Mercedes Sosa"}};
	eGenero aGeneros[CANT_GENEROS]={{1,"Rock"},{2,"Pop"},{3,"Cumbia"},{4,"Tango"},{5,"Folclore"}};
	eTipoArtista aTiposArtistas[CANT_TIPOS_ARTISTAS]={{1,"Solista"},{2,"Banda"}};
	eTipoAlbum aTiposAlbumes[CANT_TIPOS_ALBUMES]={{1,"Vinilo"},{2,"Cinta"},{3,"CD"}};
	int opcion=0;
	int indiceNuevo;
	int indiceBuscado;
	float importePrevio;
	float totalImportes=0;
	int totalAlbumes=0;

	if(!album_inicializarLista(aAlbumes, CANT_ALBUMES)){
		puts("Se inicializÛ el programa correctamente.\n\n");
	}
	else{
		puts("FallÛ la inicializaciÛn del programa.\n\n\n");
	}
	if(		!album_agregarAlbumForzado(aAlbumes, CANT_ALBUMES, 0, 1, "Signos",					5, 3, 1986, 9000, 1, 1, 2, 3) &&
			!album_agregarAlbumForzado(aAlbumes, CANT_ALBUMES, 1, 2, "CanciÛn Animal", 			28, 1, 1990, 10000, 1, 1, 2, 1) &&
			!album_agregarAlbumForzado(aAlbumes, CANT_ALBUMES, 2, 3, "Nada Personal", 			28, 1, 1985, 10000, 1, 1, 2, 1) &&

			!album_agregarAlbumForzado(aAlbumes, CANT_ALBUMES, 3, 4, "Como Un P·jaro Libre", 	22, 10, 1983, 500, 5, 5, 1, 2) &&
			!album_agregarAlbumForzado(aAlbumes, CANT_ALBUMES, 4, 5, "La Negra", 				8, 8, 1988, 10000, 5, 5, 1, 1) &&

			!album_agregarAlbumForzado(aAlbumes, CANT_ALBUMES, 5, 6, "Solo Para Entendidos", 	11, 11, 2006, 500, 3, 3, 2, 3) &&
			!album_agregarAlbumForzado(aAlbumes, CANT_ALBUMES, 6, 7, "Esquivando El …xito", 	18, 3, 2011, 500, 3, 3, 2, 3) &&
			!album_agregarAlbumForzado(aAlbumes, CANT_ALBUMES, 7, 8, "100% Negro Cumbiero", 	5, 9, 2004, 9000, 3, 3, 2, 1) &&

			!album_agregarAlbumForzado(aAlbumes, CANT_ALBUMES, 8, 9, "Libertango", 			31, 4, 1983, 10000, 4, 4, 1, 2)	&&

			!album_agregarAlbumForzado(aAlbumes, CANT_ALBUMES, 9, 10, "Sin Restricciones", 		17, 8, 2004, 500, 2, 2, 2, 1) &&
			!album_agregarAlbumForzado(aAlbumes, CANT_ALBUMES, 10, 11, "El Disco De Tu CorazÛn", 1, 4, 2007, 9000, 2, 2, 2, 3) &&
			!album_agregarAlbumForzado(aAlbumes, CANT_ALBUMES, 11, 12, "Es Imposible!", 		24, 8, 2009, 9000, 2, 2, 2, 3)	){
		totalImportes=totalImportes+aAlbumes[0].importe;
		totalImportes=totalImportes+aAlbumes[1].importe;
		totalImportes=totalImportes+aAlbumes[2].importe;
		totalImportes=totalImportes+aAlbumes[3].importe;
		totalImportes=totalImportes+aAlbumes[4].importe;
		totalImportes=totalImportes+aAlbumes[5].importe;
		totalImportes=totalImportes+aAlbumes[6].importe;
		totalImportes=totalImportes+aAlbumes[7].importe;
		totalImportes=totalImportes+aAlbumes[8].importe;
		totalImportes=totalImportes+aAlbumes[9].importe;
		totalImportes=totalImportes+aAlbumes[10].importe;
		totalImportes=totalImportes+aAlbumes[11].importe;
		totalAlbumes=totalAlbumes+12;
	}

	do{
		if(!ingresarEntero(&opcion, MSJ_MENU_PRINCIPAL, MSJ_ERROR_OPCION, 1, 6, REINTENTOS)){
			switch(opcion){
			case 1:
				if(!album_agregarAlbum(aAlbumes, CANT_ALBUMES, &indiceNuevo, aArtistas, CANT_ARTISTAS, aGeneros, CANT_GENEROS,
							aTiposArtistas, CANT_TIPOS_ARTISTAS, aTiposAlbumes, CANT_TIPOS_ALBUMES) ){
					totalImportes=totalImportes+aAlbumes[indiceNuevo].importe;
					totalAlbumes++;
					album_ordenarPorCodigo(aAlbumes, CANT_ALBUMES);
					album_imprimirListaAlbumes(aAlbumes, CANT_ALBUMES, aArtistas, CANT_ARTISTAS, aGeneros, CANT_GENEROS,
													aTiposArtistas, CANT_TIPOS_ARTISTAS, aTiposAlbumes, CANT_TIPOS_ALBUMES);
					printf("\nSe agregÛ el nuevo ·lbum al final de la lista. CÛdigo N∞: %d.\n\n\n\n", aAlbumes[indiceNuevo].codigo);
				}
				break;
			case 2:
				if(totalAlbumes==0){
					puts("No hay ·lbumes en el sistema.\n\n\n");
				}
				else{
					if(!album_modificarAlbum(aAlbumes, CANT_ALBUMES, &indiceBuscado, &importePrevio, aArtistas, CANT_ARTISTAS, aGeneros, CANT_GENEROS,
								aTiposArtistas, CANT_TIPOS_ARTISTAS, aTiposAlbumes, CANT_TIPOS_ALBUMES)	){
						totalImportes=totalImportes-importePrevio;
						totalImportes=totalImportes+aAlbumes[indiceBuscado].importe;
						album_imprimirListaAlbumes(aAlbumes, CANT_ALBUMES, aArtistas, CANT_ARTISTAS, aGeneros, CANT_GENEROS,
														aTiposArtistas, CANT_TIPOS_ARTISTAS, aTiposAlbumes, CANT_TIPOS_ALBUMES);
						printf("\nSe modificaron los datos del ·lbum con el cÛdigo: %d.\n\n\n\n", aAlbumes[indiceBuscado].codigo);
					}
				}
				break;
			case 3:
				if(totalAlbumes==0){
					puts("No hay ·lbumes en el sistema.\n\n\n");
				}
				else{
					if(!album_eliminarAlbum(aAlbumes, CANT_ALBUMES, &indiceBuscado, aArtistas, CANT_ARTISTAS, aGeneros, CANT_GENEROS,
							aTiposArtistas, CANT_TIPOS_ARTISTAS, aTiposAlbumes, CANT_TIPOS_ALBUMES) ){
						totalImportes=totalImportes-aAlbumes[indiceBuscado].importe;
						totalAlbumes--;
						album_imprimirListaAlbumes(aAlbumes, CANT_ALBUMES, aArtistas, CANT_ARTISTAS, aGeneros, CANT_GENEROS,
														aTiposArtistas, CANT_TIPOS_ARTISTAS, aTiposAlbumes, CANT_TIPOS_ALBUMES);
						printf("\nSe eliminaron los datos del ·lbum con el cÛdigo: %d.\n\n\n\n", aAlbumes[indiceBuscado].codigo);
					}
				}
				break;
			case 4:
				if(totalAlbumes==0){
					puts("No hay ·lbumes en el sistema.\n\n\n");
				}
				else{
					if(!album_menuInformes(aAlbumes, CANT_ALBUMES, aArtistas, CANT_ARTISTAS, aGeneros, CANT_GENEROS,
							aTiposArtistas, CANT_TIPOS_ARTISTAS, aTiposAlbumes, CANT_TIPOS_ALBUMES, totalImportes, totalAlbumes)){
						puts("\n\n\nInforme finalizado.\n\n\n");
					}
				}
				break;
			case 5:
				if(totalAlbumes==0){
					puts("No hay ·lbumes en el sistema.\n\n\n");
				}
				else{
					if(!album_menuListado(aAlbumes, CANT_ALBUMES, aArtistas, CANT_ARTISTAS, aGeneros, CANT_GENEROS,
							aTiposArtistas, CANT_TIPOS_ARTISTAS, aTiposAlbumes, CANT_TIPOS_ALBUMES, totalImportes, totalAlbumes)){
						puts("\n\nListado finalizado.\n\n\n");
					}
				}
				break;
			case 6:
				puts("SeleccionÛ la opciÛn SALIR.\n\n");
				retorno=0;
				break;
			}
		}
		else{
			puts("No se pudo ingresar la opciÛn\n\n\n");
		}
	}while(opcion!=6);
	return retorno;
}


int album_inicializarLista(eAlbum* aAlbumes, int limAlbumes){
	int retorno=-1;
	int i;
	if(aAlbumes!=NULL && limAlbumes>0){
		retorno=0;
		for(i=0;i<limAlbumes;i++){
			aAlbumes[i].isEmpty=TRUE;
		}
	}
	return retorno;
}

int album_buscarIndiceVacio(eAlbum* aAlbumes, int limAlbumes){
	int retorno=-1;
	int i;
	if(aAlbumes!=NULL && limAlbumes>0){
		for(i=0;i<limAlbumes;i++){
			if(aAlbumes[i].isEmpty==TRUE){
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

int album_buscarPorCodigo(eAlbum* aAlbumes, int limAlbumes, int codigo){
	int retorno=-1;
	int i;
	if(aAlbumes!=NULL && limAlbumes>0 && codigo>0){
		for(i=0;i<limAlbumes;i++){
			if(aAlbumes[i].codigo==codigo){
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}


int album_agregarAlbumForzado(eAlbum* aAlbumes, int limAlbumes, int indiceLibre, int codigo, char* titulo, int dia, int mes, int anio,
								float importe, int idArtista, int idGenero, int idTipoArtista, int idTipoAlbum){
	int retorno=-1;
	eAlbum auxiliar;
	if(aAlbumes!=NULL && limAlbumes>0 && codigo>0 && titulo!=NULL && importe>0){
		auxiliar.codigo=codigo;
		strncpy(auxiliar.titulo,titulo,LARGO_TEXTO);
		auxiliar.fechaPublicacion.dia=dia;
		auxiliar.fechaPublicacion.mes=mes;
		auxiliar.fechaPublicacion.anio=anio;
		auxiliar.importe=importe;
		auxiliar.idArtista=idArtista;
		auxiliar.idGenero=idGenero;
		auxiliar.idTipoArtista=idTipoArtista;
		auxiliar.idTipoAlbum=idTipoAlbum;
		auxiliar.isEmpty=FALSE;
		aAlbumes[indiceLibre]=auxiliar;
		retorno=0;
	}
	return retorno;
}

int album_agregarAlbum(eAlbum* aAlbumes, int limAlbumes, int* indiceNuevo, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
							eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes){
	int retorno=-1;
	eAlbum auxiliar;
	int indiceLibre;
	int confirmar;
	if(aAlbumes!=NULL && limAlbumes>0 && indiceNuevo!=NULL && aArtistas!=NULL && limArtistas>0 &&
			aGeneros!=NULL && limGeneros>0 && aTiposArtistas!=NULL && limTiposArtistas>0 && aTiposAlbumes!=NULL && limTiposAlbumes>0){
		indiceLibre=album_buscarIndiceVacio(aAlbumes, limAlbumes);
		if(indiceLibre>=0 &&
				!album_cargarDatos(&auxiliar, aAlbumes, limAlbumes, aArtistas, limArtistas,
						aGeneros, limGeneros, aTiposArtistas, limTiposArtistas, aTiposAlbumes, limTiposAlbumes) &&
				!album_vistaPrevia(&auxiliar, MSJ_VISTA_NUEVO, aArtistas, limArtistas, aGeneros, limGeneros,
						aTiposArtistas, limTiposArtistas, aTiposAlbumes, limTiposAlbumes) &&
				!ingresarEntero(&confirmar, MSJ_CONFIRMAR_AGREGADO, MSJ_ERROR_OPCION, 0, 1, REINTENTOS) &&	confirmar ){
			auxiliar.codigo=album_generarCodigo();
			auxiliar.isEmpty=FALSE;
			aAlbumes[indiceLibre]=auxiliar;
			*indiceNuevo=indiceLibre;
			puts("Confirmado.\n");
			retorno=0;
		}
		else if(indiceLibre<0){
			puts("No hay mas espacio para agregar ·lbumes.\n\n\n");
		}
		else{
			puts("Hubo un error en la carga.\n\n\n");
		}
	}

	return retorno;
}

int album_cargarDatos(eAlbum* pElemento, eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
							eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes){
	int retorno=-1;
	eAlbum auxiliar;
	char mensajeYaExistente[LARGO_MENSAJE];
	if(pElemento!=NULL && aAlbumes!=NULL && limAlbumes>0 && aArtistas!=NULL && limArtistas>0 && aGeneros!=NULL && limGeneros>0 &&
			aTiposArtistas!=NULL && limTiposArtistas>0 && aTiposAlbumes!=NULL && limTiposAlbumes>0 &&
		!ingresarDescripcion(auxiliar.titulo, LARGO_TEXTO, "Ingrese el tÌtulo:", "No es un tÌtulo v·lido.", REINTENTOS) &&
		!pasarInicialesMayusculas(auxiliar.titulo, LARGO_TEXTO) &&
		!album_esAlbumExistente(aAlbumes, limAlbumes, auxiliar.titulo, mensajeYaExistente)&&
		!album_cargarFecha(&auxiliar, MSJ_INGRESO_ANIO, ANIO_MIN, ANIO_ACTUAL) &&
		!ingresarFlotante(&auxiliar.importe, "Ingrese el importe del ·lbum:", "No es un importe v·lido.", IMPORTE_MIN, IMPORTE_MAX, REINTENTOS) &&
		!artista_imprimirListaArtistas(aArtistas, limArtistas) &&
		!ingresarEntero(&auxiliar.idArtista, "Ingrese el ID del artista del ·lbum:", "No es un artista v·lido.", 1, 5, REINTENTOS) &&
		!genero_imprimirListaGeneros(aGeneros, limGeneros) &&
		!ingresarEntero(&auxiliar.idGenero, "Ingrese el ID del gÈnero del ·lbum:", "No es un gÈnero v·lido.", 1, 5, REINTENTOS) &&
		!tipoArtista_imprimirListaTiposArtistas(aTiposArtistas, limTiposArtistas) &&
		!ingresarEntero(&auxiliar.idTipoArtista, "Ingrese el ID del tipo de artista del ·lbum::", "No es un tipo de artista v·lido.", 1, 2, REINTENTOS) &&
		!tipoAlbum_imprimirListaTiposAlbumes(aTiposAlbumes, limTiposAlbumes) &&
		!ingresarEntero(&auxiliar.idTipoAlbum, "Ingrese el ID del tipo de album del ·lbum:", "No es un tipo de artista v·lido.", 1, 3, REINTENTOS)	){
		retorno=0;
		*pElemento=auxiliar;
	}
	else{
		printf("%s", mensajeYaExistente);
	}
	return retorno;
}

int album_esAlbumExistente(eAlbum* aAlbumes, int limAlbumes, char* titulo, char* mensajeYaExistente){
	int retorno=-1;
	int error;
	int i;
	if(aAlbumes!=NULL && limAlbumes>0 && titulo!=NULL){
		retorno=0;
		for(i=0;i<limAlbumes;i++){
			if(aAlbumes[i].isEmpty==FALSE && strncmp(aAlbumes[i].titulo, titulo, LARGO_TEXTO)==0){
				retorno=1;
				error=-1;
				break;
			}
		}
	}
	if(error==-1){
		strncpy(mensajeYaExistente, "Ya existe un ·lbum con este tÌtulo.\n\n\n", LARGO_MENSAJE);
	}
	return retorno;
}

int album_cargarFecha(eAlbum* auxiliar, char* mensaje, int anioMinimo, int anioMaximo){
	int retorno=-1;
	char mensajeAnio[LARGO_TEXTO];
	char mensajeMesAnterior[LARGO_TEXTO];
	int anio;
	int mes;
	int dia;
	int esBisiesto;
	if(auxiliar!=NULL && mensaje!=NULL){
		snprintf(mensajeAnio, sizeof(mensajeAnio), mensaje,anioMinimo, anioMaximo);
		snprintf(mensajeMesAnterior, sizeof(mensajeMesAnterior), MSJ_INGRESO_MESANTERIOR, MES_ANTERIOR);

		if(!ingresarEntero(&anio, mensajeAnio, MSJ_ERROR_OPCION, anioMinimo, anioMaximo, REINTENTOS) && anio!=0){
			esBisiesto=esAnioBisiesto(anio);
			if(anio==ANIO_ACTUAL){
				printf("Actualmente estamos en el aÒo %d. Solo se ingresaron ·lbumes hasta el 31/07/2022, inclusive.\n\n", anio);
				if(esBisiesto){
					printf("*El aÒo %d es un aÒo Bisiesto, tiene 366 dias, febrero tuvo 29 dias.\n\n", anio);
				}
				else{
					printf("*El aÒo %d es un aÒo Normal, tuvo 365 dias, febrero tuvo 28 dias.\n\n", anio);
				}
				if(!ingresarEntero(&mes, mensajeMesAnterior, MSJ_ERROR_OPCION, 1, MES_ANTERIOR, REINTENTOS) &&
						((mes==2 && esBisiesto && !ingresarEntero(&dia, "Ingrese el dÌa: (del 1 al 29, ya que fue un aÒo bisiesto)", MSJ_ERROR_OPCION, 1, 29, REINTENTOS)) ||
						(mes==2 && !esBisiesto && !ingresarEntero(&dia, "Ingrese el dÌa: (del 1 al 28, fue un aÒo normal)", MSJ_ERROR_OPCION, 1, 28, REINTENTOS)) ||
						((mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) && !ingresarEntero(&dia, "Ingrese el dÌa: (del 1 al 31)", MSJ_ERROR_OPCION, 1, 31, REINTENTOS)) ||
						((mes==4 || mes==6 || mes==9 || mes==11) && !ingresarEntero(&dia, "Ingrese el dÌa: (del 1 al 30)", MSJ_ERROR_OPCION, 1, 30, REINTENTOS))
				)){
					auxiliar->fechaPublicacion.anio=anio;
					auxiliar->fechaPublicacion.mes=mes;
					auxiliar->fechaPublicacion.dia=dia;
					retorno=0;
				}
			}
			else{
				if(esBisiesto){
					printf("*El aÒo %d fue un aÒo Bisiesto, tuvo 366 dias, febrero tuvo 29 dias.\n\n", anio);
				}
				else{
					printf("*El aÒo %d fue un aÒo Normal, tuvo 365 dias, febrero tuvo 28 dias.\n\n", anio);
				}
				if(!ingresarEntero(&mes, "Ingrese el mes: (del 1 al 12)", MSJ_ERROR_OPCION, 1, 12, REINTENTOS) &&
						((mes==2 && esBisiesto && !ingresarEntero(&dia, "Ingrese el dÌa: (del 1 al 29, ya que fue un aÒo bisiesto)", MSJ_ERROR_OPCION, 1, 29, REINTENTOS)) ||
						(mes==2 && !esBisiesto && !ingresarEntero(&dia, "Ingrese el dÌa: (del 1 al 28, fue un aÒo normal)", MSJ_ERROR_OPCION, 1, 28, REINTENTOS)) ||
						((mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) && !ingresarEntero(&dia, "Ingrese el dÌa: (del 1 al 31)", MSJ_ERROR_OPCION, 1, 31, REINTENTOS)) ||
						((mes==4 || mes==6 || mes==9 || mes==11) && !ingresarEntero(&dia, "Ingrese el dÌa: (del 1 al 30)", MSJ_ERROR_OPCION, 1, 30, REINTENTOS))
				)){
					auxiliar->fechaPublicacion.anio=anio;
					auxiliar->fechaPublicacion.mes=mes;
					auxiliar->fechaPublicacion.dia=dia;
					retorno=0;
				}
			}
		}
	}
	return retorno;
}

int album_modificarAlbum(eAlbum* aAlbumes, int limAlbumes, int* indiceBuscado, float* importePrevio, eArtista* aArtistas, int limArtistas,
							eGenero* aGeneros, int limGeneros, eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes){
	int retorno=-1;
	eAlbum auxiliar;
	int codigoModificar;
	int indiceCodigo;
	int flagCambio;
	int confirmar;
	if(aAlbumes!=NULL && limAlbumes>0 && indiceBuscado!=NULL && importePrevio!=NULL && aArtistas!=NULL && limArtistas>0 &&
			aGeneros!=NULL && limGeneros>0 && aTiposArtistas!=NULL && limTiposArtistas>0 && aTiposAlbumes!=NULL && limTiposAlbumes>0 &&
			!ingresarEntero(&codigoModificar, MSJ_CODIGO_MODIFICAR, MSJ_ERROR_CODIGO, 1, codigoIncremental, REINTENTOS) ){
		indiceCodigo=album_buscarPorCodigo(aAlbumes, limAlbumes, codigoModificar);
		if(indiceCodigo>=0 && aAlbumes[indiceCodigo].isEmpty==FALSE &&
				!album_vistaPrevia(&aAlbumes[indiceCodigo], MSJ_VISTA_ENCONTRADO, aArtistas, limArtistas, aGeneros, limGeneros,
						aTiposArtistas, limTiposArtistas, aTiposAlbumes, limTiposAlbumes) ){
			*indiceBuscado=indiceCodigo;
			*importePrevio=aAlbumes[indiceCodigo].importe;
			auxiliar=aAlbumes[indiceCodigo];
			if(!album_menuModificar(&auxiliar, &flagCambio, aAlbumes, limAlbumes, aTiposAlbumes, limTiposAlbumes) && !flagCambio &&
					!album_vistaPrevia(&auxiliar, MSJ_VISTA_MODIFICADO, aArtistas, limArtistas, aGeneros, limGeneros,
							aTiposArtistas, limTiposArtistas, aTiposAlbumes, limTiposAlbumes) &&
					!ingresarEntero(&confirmar, MSJ_CONFIRMAR_MODIFICACION, MSJ_ERROR_OPCION, 0, 1, REINTENTOS) && confirmar ){
				aAlbumes[indiceCodigo]=auxiliar;
				puts("Confirmado.\n");
				retorno=0;
			}
			else if(flagCambio){
				puts("No se realizaron cambios.\n\n");
			}
			else if(!confirmar){
				puts("Se cancelÛ la modificaciÛn del ·lbum.\n\n");
			}
		}
		else if(indiceCodigo<0 || aAlbumes[indiceCodigo].isEmpty==TRUE){
			puts("No existe ning˙n ·lbum con ese id.\n\n");
		}
	}
	return retorno;
}

int album_menuModificar(eAlbum* pElemento, int* cambios, eAlbum* aAlbumes, int limAlbumes, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes){
	int retorno=-1;
	eAlbum auxiliar;
	char albumExistente[LARGO_MENSAJE];
	int flagExiste;
	int opcion;
	int flagCambios=1;
	if(pElemento!=NULL && aAlbumes!=NULL && limAlbumes>0 && cambios!=NULL && aTiposAlbumes!=NULL && limTiposAlbumes>0){
		auxiliar=*pElemento;
		do{
			if(!ingresarEntero(&opcion, MSJ_MENU_MODIFICAR, MSJ_ERROR_OPCION, 1, 5, REINTENTOS)){
				switch(opcion){
				case 1:
					if(!ingresarDescripcion(auxiliar.titulo, LARGO_TEXTO, "Nuevo tÌtulo:", "No es un tÌtulo v·lido.", REINTENTOS) &&
							!pasarInicialesMayusculas(auxiliar.titulo, LARGO_TEXTO)){
						flagExiste=album_esAlbumExistente(aAlbumes, limAlbumes, auxiliar.titulo, albumExistente);
						if(!flagExiste){
							puts("TÌtulo ingresado correctamente.\n\n");
							flagCambios=0;
						}
						else{
							printf("%s", albumExistente);
						}
					}
					else{
						puts("No se ingresÛ un tÌtulo v·lido.\n\n");
					}
					break;
				case 2:
					if(!album_cargarFecha(&auxiliar, "Nuevo aÒo: %d-%d", ANIO_MIN, ANIO_ACTUAL)){
						puts("Fecha ingresada correctamente.\n\n");
						flagCambios=0;
					}
					else{
						puts("No se ingresÛ un importe v·lido.\n\n");
					}
					break;
				case 3:
					if(!ingresarFlotante(&auxiliar.importe, "Nuevo importe:", "No es un importe v·lido.", IMPORTE_MIN, IMPORTE_MAX, REINTENTOS)){
						puts("Importe ingresado correctamente.\n\n");
						flagCambios=0;
					}
					else{
						puts("No se ingresÛ un importe v·lido.\n\n");
					}
					break;
				case 4:
					if(!tipoAlbum_imprimirListaTiposAlbumes(aTiposAlbumes, limTiposAlbumes) &&
							!ingresarEntero(&auxiliar.idTipoAlbum, "Nuevo tipo de album:", "No es un tipo de artista v·lido.", 1, 3, REINTENTOS)){
						puts("Tipo de ·lbum ingresado correctamente.\n\n");
						flagCambios=0;
					}
					else{
						puts("No se ingresÛ un tipo de ·lbum v·lido.\n\n");
					}
					break;
				case 5:
					*cambios=flagCambios;
					*pElemento=auxiliar;
					retorno=0;
					break;
				}
			}
			else{
				puts("No se pudo ingresar una opciÛn.\n\n\n");
			}
		}while(opcion!=5);
	}
	return retorno;
}

int album_eliminarAlbum(eAlbum* aAlbumes, int limAlbumes, int* indiceBuscado, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
							eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes){
	int retorno=-1;
	int codigoEliminar;
	int indiceCodigo;
	int confirmar;
	if(aAlbumes!=NULL && limAlbumes>0 && indiceBuscado!=NULL && aArtistas!=NULL && limArtistas>0 && aGeneros!=NULL && limGeneros>0 &&
			aTiposArtistas!=NULL && limTiposArtistas>0 && aTiposAlbumes!=NULL && limTiposAlbumes>0 &&
			!ingresarEntero(&codigoEliminar, MSJ_CODIGO_ELIMINAR, MSJ_ERROR_CODIGO, 0, codigoIncremental, REINTENTOS) ){
		indiceCodigo=album_buscarPorCodigo(aAlbumes, limAlbumes, codigoEliminar);
		if(indiceCodigo>=0 && aAlbumes[indiceCodigo].isEmpty==FALSE &&
				!album_vistaPrevia(&aAlbumes[indiceCodigo], MSJ_VISTA_ENCONTRADO, aArtistas, limArtistas, aGeneros, limGeneros,
						aTiposArtistas, limTiposArtistas, aTiposAlbumes, limTiposAlbumes) &&
				!ingresarEntero(&confirmar, MSJ_CONFIRMAR_ELIMINADO, MSJ_ERROR_OPCION, 0, 1, REINTENTOS) && confirmar){
			aAlbumes[indiceCodigo].isEmpty=TRUE;
			*indiceBuscado=indiceCodigo;
			puts("Confirmado.\n\n");
			retorno=0;
		}
		else if(indiceCodigo<0 || aAlbumes[indiceCodigo].isEmpty==TRUE){
			printf("No existe ning˙n ·lbum con el id %d.\n\n", codigoEliminar);
		}
		else{
			puts("Hubo un error en la eliminacÛn del ·lbum.\n\n");
		}
	}
	return retorno;
}

int album_vistaPrevia(eAlbum* pElemento, char* mensajePrevio, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
									eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes){
	int retorno=-1;
	eArtista auxArtista;
	eGenero auxGenero;
	eTipoArtista auxTipoArtista;
	eTipoAlbum auxTipoAlbum;
	if(pElemento!=NULL && aArtistas!=NULL && limArtistas>0 && aGeneros!=NULL && limGeneros>0 &&
			aTiposArtistas!=NULL && limTiposArtistas>0 && aTiposAlbumes!=NULL && limTiposAlbumes>0 &&
			!album_coincidirAlbumConArtista(*pElemento, aArtistas, limArtistas, &auxArtista) &&
			!album_coincidirAlbumConGenero(*pElemento, aGeneros, limGeneros, &auxGenero) &&
			!album_coincidirAlbumConTipoArtista(*pElemento, aTiposArtistas, limTiposArtistas, &auxTipoArtista) &&
			!album_coincidirAlbumConTipoAlbum(*pElemento, aTiposAlbumes, limTiposAlbumes, &auxTipoAlbum) ){
		printf("\n\n%s\n\n|%-11s|%-31s|%-21s|%-16s|%-21s|%-21s|%-21s|%-21s|\n", mensajePrevio,
				"CÛdigo:", "TÌtulo:","Fecha:","Importe:","Artista:","Genero:","Tipo de Artista:","Tipo de ¡lbum:");
		album_imprimirUnAlbumPorParametros(pElemento, &auxArtista, &auxGenero, &auxTipoArtista, &auxTipoAlbum);
		retorno=0;
	}
	return retorno;
}

int album_imprimirListaAlbumes(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
									eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes){
	int retorno=-1;
	int i;
	eArtista auxArtista;
	eGenero auxGenero;
	eTipoArtista auxTipoArtista;
	eTipoAlbum auxTipoAlbum;
	if(aAlbumes!=NULL && limAlbumes>0 && aArtistas!=NULL && limArtistas>0 && aGeneros!=NULL && limGeneros>0 &&
			aTiposArtistas!=NULL && limTiposArtistas>0 && aTiposAlbumes!=NULL && limTiposAlbumes>0){
		printf("\n\nLista de ·lbumes:\n|%-11s|%-31s|%-21s|%-16s|%-21s|%-21s|%-21s|%-21s|\n",
						"CÛdigo:", "TÌtulo:", "Fecha:", "Importe:", "Artista:", "Genero:", "Tipo de Artista:", "Tipo de ¡lbum:");
		for(i=0;i<limAlbumes;i++){
			if(aAlbumes[i].isEmpty==FALSE &&
					!album_coincidirAlbumConArtista(aAlbumes[i], aArtistas, limArtistas, &auxArtista) &&
					!album_coincidirAlbumConGenero(aAlbumes[i], aGeneros, limGeneros, &auxGenero) &&
					!album_coincidirAlbumConTipoArtista(aAlbumes[i], aTiposArtistas, limTiposArtistas, &auxTipoArtista) &&
					!album_coincidirAlbumConTipoAlbum(aAlbumes[i], aTiposAlbumes, limTiposAlbumes, &auxTipoAlbum))
			{
				album_imprimirUnAlbumPorParametros(&aAlbumes[i], &auxArtista, &auxGenero, &auxTipoArtista, &auxTipoAlbum);
			}
		}
		retorno=0;
	}
	return retorno;
}

int album_imprimirUnAlbumPorParametros(eAlbum* album, eArtista* artista, eGenero* genero, eTipoArtista* tipoArtista, eTipoAlbum* tipoAlbum){
	int retorno=-1;
	if(album!=NULL && album->isEmpty==FALSE && artista!=NULL && genero!=NULL && tipoAlbum!=NULL && tipoArtista!=NULL){
		retorno=0;
		printf("|%11d|%31s|%13.02d/%02d/%4d|%16.2f|%21s|%21s|%21s|%21s|\n",
				album->codigo, album->titulo, album->fechaPublicacion.dia,
				album->fechaPublicacion.mes, album->fechaPublicacion.anio, album->importe,
				artista->nombre, genero->descripcion, tipoArtista->descripcion, tipoAlbum->descripcion);
	}
	return retorno;
}

int album_ordenarPorCodigo(eAlbum* aAlbumes, int limAlbumes){
	int retorno=-1;
	eAlbum auxAlbum;
	int i;
	int nuevoLimite;
	int flagSwap;
	if(aAlbumes!=NULL && limAlbumes>0){
		nuevoLimite=limAlbumes-1;
		do{
			flagSwap=FALSE;
			for(i=0;i<nuevoLimite;i++){
				if(aAlbumes[i].isEmpty || aAlbumes[i+1].isEmpty){
					continue;
				}
				if(aAlbumes[i].codigo>aAlbumes[i+1].codigo){
					flagSwap=TRUE;
					auxAlbum=aAlbumes[i];
					aAlbumes[i]=aAlbumes[i+1];
					aAlbumes[i+1]=auxAlbum;
				}
			}
			nuevoLimite--;
		}while(flagSwap);
		retorno=0;
	}
	return retorno;
}

//	https://onlinegdb.com/pyXJISMgW


int album_menuInformes(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
							eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes, float totalImportes, int totalAlbumes){
	int retorno=-1;
	int tipoInforme;
	float importePromedio;
	int totalMayoresPromedio;
	int totalAnterioresAnio;
	int anioBuscado;
	int totalSolistasAnio;
	int totalBandasGenero;
	char descripcionGenero[LARGO_TEXTO];

	if(aAlbumes!=NULL && limAlbumes>0 && aArtistas!=NULL && limArtistas>0 && aGeneros!=NULL && limGeneros>0 &&
			aTiposArtistas!=NULL && limTiposArtistas>0 && aTiposAlbumes!=NULL && limTiposAlbumes>0 && totalImportes>0 && totalAlbumes>0){
			if(!ingresarEntero(&tipoInforme, MSJ_MENU_INFORME, MSJ_ERROR_OPCION, 1, 4, REINTENTOS)){
			switch(tipoInforme){
			case 1:
				if(!album_calcularImportePromedio(&importePromedio, totalImportes, totalAlbumes) &&
						!album_contarAlbumesSuperanImportePromedio(aAlbumes, limAlbumes, &totalMayoresPromedio, importePromedio)){
					printf("El total de los importes es: %.2f\nEl promedio de los importes es: %.2f\nLa cantidad de ·lbumes que superan el importe promedio es: %d",
							totalImportes, importePromedio, totalMayoresPromedio);
					retorno=0;
				}
				break;
			case 2:
				if(!album_contarAlbumesAnterioresAnio(aAlbumes, limAlbumes, &totalAnterioresAnio, &anioBuscado)){
					printf("La cantidad de ·lbumes publicados antes del aÒo %d es: %d", anioBuscado, totalAnterioresAnio);
					retorno=0;
				}
				else{
					puts("No se pudieron encontrar ·lbumes publicados antes del aÒo 2000.\n\n\n");
				}
				break;
			case 3:
				if(!album_contarSolistasAnioDeterminado(aAlbumes, limAlbumes, aTiposArtistas, limTiposArtistas, &totalSolistasAnio, &anioBuscado)){
					printf("La cantidad de solistas del aÒo %d es: %d", anioBuscado, totalSolistasAnio);
					retorno=0;
				}
				break;
			case 4:
				if(!album_contarBandasGeneroDeterminado(aAlbumes, limAlbumes, aArtistas, limArtistas, aGeneros, limGeneros, aTiposArtistas, limTiposArtistas, &totalBandasGenero, descripcionGenero)){
					printf("La cantidad de ·lbumes de banda del genero %s es: %d", descripcionGenero, totalBandasGenero);
					retorno=0;
				}
				break;
				//
			}
		}
		else{
			puts("No se pudo ingresar una opciÛn.\n\n\n");
		}
	}
	return retorno;
}

// 1.a)
int album_calcularImportePromedio(float* pResultado, float totalImportes, float totalAlbumes){
	int retorno=-1;
	float promedio;
	if(pResultado!=NULL && totalImportes>0 && totalAlbumes>0){
		promedio=totalImportes/totalAlbumes;
		*pResultado=promedio;
		retorno=0;
	}
	return retorno;
}

// 1.b)
int album_contarAlbumesSuperanImportePromedio(eAlbum* aAlbumes, int limite, int* pResultado, float importePromedio){
	int retorno=-1;
	int i;
	int totalMayoresPromedio=0;
	if(aAlbumes!=NULL && limite>0 && pResultado!=NULL && importePromedio>0){
		for(i=0;i<limite;i++){
			if(aAlbumes[i].isEmpty==FALSE && aAlbumes[i].importe>importePromedio){
				totalMayoresPromedio++;
			}
		}
		*pResultado=totalMayoresPromedio;
		retorno=0;
	}
	return retorno;
}

// 2)
int album_contarAlbumesAnterioresAnio(eAlbum* aAlbumes, int limite, int* pResultado, int* anioBuscado){
	int retorno=-1;
	//char mensajeAnio[LARGO_MENSAJE];
	int anioEncontrado;
	int totalAlbumesAnteriores=0;
	int i;
	if(aAlbumes!=NULL && limite>0 && pResultado!=NULL && anioBuscado!=NULL){
		//snprintf(mensajeAnio, sizeof(mensajeAnio), MSJ_INGRESO_ANIO, ANIO_MIN, ANIO_ACTUAL);
		//if(!ingresarEntero(&anioEncontrado, mensajeAnio, MSJ_ERROROPCION, ANIO_MIN, ANIO_ACTUAL, REINTENTOS)){
			anioEncontrado=2000;
			for(i=0;i<limite;i++){
				if(aAlbumes[i].isEmpty==FALSE && aAlbumes[i].fechaPublicacion.anio<anioEncontrado){
					totalAlbumesAnteriores++;
				}
			}
			*pResultado=totalAlbumesAnteriores;
			*anioBuscado=anioEncontrado;
			retorno=0;
		//}
	}
	return retorno;
}

// 3)
int album_contarSolistasAnioDeterminado(eAlbum* aAlbumes, int limAlbumes, eTipoArtista* aTiposArtistas, int limTiposArtistas, int* pResultado, int* anioBuscado){
	int retorno=-1;
	char mensajeAnio[LARGO_MENSAJE];
	int anioEncontrado;
	int totalSolistasAnio=0;
	int i;
	eTipoArtista auxTipoArtista;
	if(aAlbumes!=NULL && limAlbumes>0 && aTiposArtistas!=NULL && limTiposArtistas>0 && pResultado!=NULL && anioBuscado!=NULL){
		snprintf(mensajeAnio, sizeof(mensajeAnio), MSJ_INGRESO_ANIO, ANIO_MIN, ANIO_ACTUAL);
		if(!ingresarEntero(&anioEncontrado, mensajeAnio, MSJ_ERROR_OPCION, ANIO_MIN, ANIO_ACTUAL, REINTENTOS)){
			for(i=0;i<limAlbumes;i++){
				if(aAlbumes[i].isEmpty==FALSE &&
						aAlbumes[i].fechaPublicacion.anio==anioEncontrado &&
						!album_coincidirAlbumConTipoArtista(aAlbumes[i], aTiposArtistas, limTiposArtistas, &auxTipoArtista) &&
						auxTipoArtista.idTipoArtista==1)
				{
					totalSolistasAnio++;
				}
			}
			*pResultado=totalSolistasAnio;
			*anioBuscado=anioEncontrado;
			retorno=0;
		}
	}
	return retorno;
}



// 4)
int album_contarBandasGeneroDeterminado(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros, eTipoArtista* aTiposArtistas, int limTiposArtistas,
											int* pResultado, char* descripcionGenero){
	int retorno=-1;
	int idGeneroEncontrado;
	int totalAlbumes=0;
	int i;
	eTipoArtista auxTipoArtista;
	if(aAlbumes!=NULL && limAlbumes>0 && aTiposArtistas!=NULL && limTiposArtistas>0 && pResultado!=NULL){
		if(!genero_imprimirListaGeneros(aGeneros, limGeneros) &&
				!ingresarEntero(&idGeneroEncontrado, "\nIngrese el id del genero que desea buscar:\n", MSJ_ERROR_OPCION, 1, 5, REINTENTOS) &&
				!genero_conseguirDescipcion(aGeneros, limGeneros, descripcionGenero, idGeneroEncontrado)){
			for(i=0;i<limAlbumes;i++){
				if(aAlbumes[i].isEmpty==FALSE &&
						aAlbumes[i].idGenero==idGeneroEncontrado &&
						!album_coincidirAlbumConTipoArtista(aAlbumes[i], aTiposArtistas, limTiposArtistas, &auxTipoArtista) &&
						auxTipoArtista.idTipoArtista==2)
				{
					totalAlbumes++;
				}
			}
			*pResultado=totalAlbumes;
			retorno=0;
		}
	}
	return retorno;
}



int album_menuListado(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
					eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes, float totalImportes, int totalAlbumes){
	int retorno=-1;
	char mensajeListado[LARGO_MENSAJE];
	int tipoListado;
	float importePromedio;
	if(aAlbumes!=NULL && limAlbumes>0 && aArtistas!=NULL && limArtistas>0 && aGeneros!=NULL && limGeneros>0 &&
			aTiposArtistas!=NULL && limTiposArtistas>0 && aTiposAlbumes!=NULL && limTiposAlbumes>0 && totalImportes>0 && totalAlbumes>0){
		snprintf(mensajeListado,sizeof(mensajeListado),"%s%s%s", MSJ_MENU_LISTADO_01_05, MSJ_MENU_LISTADO_06_10,MSJ_MENU_LISTADO_11_14);
		if(!ingresarEntero(&tipoListado, mensajeListado, MSJ_ERROR_OPCION, 1, 15, REINTENTOS)){
			switch(tipoListado){
			case 1:
				if(!genero_imprimirListaGeneros(aGeneros, limGeneros)){
					retorno=0;
				}
				else{
					puts("ERROR\n");
				}
				break;
			case 2:
				if(!tipoArtista_imprimirListaTiposArtistas(aTiposArtistas, limTiposArtistas)){
					retorno=0;
				}
				else{
					puts("ERROR\n");
				}
				break;
			case 3:
				if(!artista_imprimirListaArtistas(aArtistas, limArtistas)){
					retorno=0;
				}
				else{
					puts("ERROR\n");
				}
				break;
			case 4:
				if(!album_imprimirListaAlbumes(aAlbumes, limAlbumes, aArtistas, limArtistas, aGeneros, limGeneros,
						aTiposArtistas, limTiposArtistas, aTiposAlbumes, limTiposAlbumes)){
					retorno=0;
				}
				else{
					puts("ERROR\n");
				}
				break;
			case 5:
				puts("Lista:\n");
				if(!album_ordenarPorImporteYTitulo(aAlbumes, limAlbumes) &&
						!album_imprimirListaAlbumes(aAlbumes, limAlbumes, aArtistas, limArtistas, aGeneros, limGeneros,
								aTiposArtistas, limTiposArtistas, aTiposAlbumes, limTiposAlbumes) &&
						!album_ordenarPorCodigo(aAlbumes, limAlbumes)){
					puts("\nSe ordenÛ el vector exitÛsamente.\n");
					retorno=0;
				}
				else{
					puts("ERROR\n");
				}
				break;
			case 6:
				if(!album_listarAlbumAnteriorAFecha(aAlbumes, limAlbumes, aArtistas, limArtistas, aGeneros, limGeneros,
						aTiposArtistas, limTiposArtistas, aTiposAlbumes, limTiposAlbumes)){
					retorno=0;
				}
				else{
					puts("ERROR\n");
				}
				break;
			case 7:
				if(!album_calcularImportePromedio(&importePromedio, totalImportes, totalAlbumes) &&
						!album_listarSuperanImportePromedio(aAlbumes, limAlbumes, aArtistas, limArtistas, aGeneros, limGeneros,
								aTiposArtistas, limTiposArtistas, aTiposAlbumes, limTiposAlbumes, importePromedio)){
					retorno=0;
				}
				else{
					puts("ERROR\n");
				}
				break;
			case 8:
				if(!album_listarAlbumesCadaArtista(aAlbumes, limAlbumes, aArtistas, limArtistas, aGeneros, limGeneros,
						aTiposArtistas, limTiposArtistas, aTiposAlbumes, limTiposAlbumes)){
					retorno=0;
				}
				else{
					puts("ERROR\n");
				}
				break;
			case 9:
				if(!album_listarAlbumAnioDeterminado(aAlbumes, limAlbumes, aArtistas, limArtistas, aGeneros, limGeneros,
						aTiposArtistas, limTiposArtistas, aTiposAlbumes, limTiposAlbumes)){
					retorno=0;
				}
				else{
					puts("ERROR\n");
				}
				break;
			case 10:
				if(!album_listarAlbumesMasCaros(aAlbumes, limAlbumes, aArtistas, limArtistas, aGeneros, limGeneros,
						aTiposArtistas, limTiposArtistas, aTiposAlbumes, limTiposAlbumes)){
					retorno=0;
				}
				else{
					puts("ERROR\n");
				}
				break;
			case 11:
				if(!tipoAlbum_imprimirListaTiposAlbumes(aTiposAlbumes, limTiposAlbumes)){
					retorno=0;
				}
				else{
					puts("ERROR\n");
				}
				break;
			case 12:
				if(!album_listarAlbumesNoSonVinilos(aAlbumes, limAlbumes, aArtistas, limArtistas, aGeneros, limGeneros,
						aTiposArtistas, limTiposArtistas, aTiposAlbumes, limTiposAlbumes)){
					retorno=0;
				}
				else{
					puts("ERROR\n");
				}
				break;
			case 13:
				if(!album_listarAlbumesVinilosArtistaDeterminado(aAlbumes, limAlbumes, aArtistas, limArtistas, aGeneros, limGeneros,
						aTiposArtistas, limTiposArtistas, aTiposAlbumes, limTiposAlbumes)){
					retorno=0;
				}
				else{
					puts("ERROR\n");
				}
				break;
			case 14:
				if(!album_listarAlbumesGeneroYTipoAlbumDeterminados(aAlbumes, limAlbumes, aArtistas, limArtistas, aGeneros, limGeneros,
						aTiposArtistas, limTiposArtistas, aTiposAlbumes, limTiposAlbumes)){
					retorno=0;
				}
				else{
					puts("ERROR\n");
				}
				break;
			case 15:
				if(!album_listarAlbumesArtistaYTipoAlbumDeterminados(aAlbumes, limAlbumes, aArtistas, limArtistas, aGeneros, limGeneros,
						aTiposArtistas, limTiposArtistas, aTiposAlbumes, limTiposAlbumes)){
					retorno=0;
				}
				else{
					puts("ERROR\n");
				}
				break;
			}
		}
		else{
			puts("No se pudo ingresar una opciÛn.\n\n\n");
		}
	}
	return retorno;
}


//	1)
int genero_imprimirListaGeneros(eGenero* aGeneros, int limGeneros){
	int retorno=-1;
	int i;
	if(aGeneros!=NULL && limGeneros>0){
		printf("\n\nListado de Generos:\n|%-16s|%-21s|\n", "Id Genero:", "Generos:");
		retorno=0;
		for(i=0;i<limGeneros;i++){
			printf("|%16d|%21s|\n", aGeneros[i].idGenero, aGeneros[i].descripcion);
		}
	}
	return retorno;
}

//	2)
int tipoArtista_imprimirListaTiposArtistas(eTipoArtista* aTiposArtistas, int limTiposArtistas){
	int retorno=-1;
	int i;
	if(aTiposArtistas!=NULL && limTiposArtistas>0){
		printf("\n\nListado de Tipos de Artistas:\n|%-21s|%-21s|\n", "Id Tipo Artista:", "Tipos Artistas:");
		retorno=0;
		for(i=0;i<limTiposArtistas;i++){
			printf("|%21d|%21s|\n", aTiposArtistas[i].idTipoArtista, aTiposArtistas[i].descripcion);
		}
	}
	return retorno;
}

//	3)
int artista_imprimirListaArtistas(eArtista* aArtistas, int limArtistas){
	int retorno=-1;
	int i;
	if(aArtistas!=NULL && limArtistas>0){
		printf("\n\nListado de Artistas:\n|%-16s|%-21s|\n", "Id Artista:", "Artista:");
		retorno=0;
		for(i=0;i<limArtistas;i++){
			printf("|%16d|%21s|\n", aArtistas[i].idArtista, aArtistas[i].nombre);
		}
	}
	return retorno;
}

//	4)		Funcion:	album_imprimirListaAlbumes

//	5)
int album_ordenarPorImporteYTitulo(eAlbum* aAlbumes, int limite){
	int retorno=-1;
	eAlbum auxAlbum;
	int i;
	int nuevoLimite;
	int flagSwap;
	if(aAlbumes!=NULL && limite>0){
		nuevoLimite=limite-1;
		do{
			flagSwap=FALSE;
			for(i=0;i<nuevoLimite;i++){
				if(aAlbumes[i].isEmpty || aAlbumes[i+1].isEmpty){
					continue;
				}
				if(aAlbumes[i].importe<aAlbumes[i+1].importe ||
						(aAlbumes[i].importe==aAlbumes[i+1].importe && strncmp(aAlbumes[i].titulo,aAlbumes[i+1].titulo,LARGO_TEXTO)>0)){
					flagSwap=TRUE;
					auxAlbum=aAlbumes[i];
					aAlbumes[i]=aAlbumes[i+1];
					aAlbumes[i+1]=auxAlbum;
				}
			}
			nuevoLimite--;
		}while(flagSwap);
		retorno = 0;
	}
	return retorno;
}


//	6)
int album_listarAlbumAnteriorAFecha(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
											eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes){
	int retorno=-1;
	int anioBuscado;
	int i;
	int totalAlbumesEncontrados=0;
	eArtista auxArtista;
	eGenero auxGenero;
	eTipoArtista auxTipoArtista;
	eTipoAlbum auxTipoAlbum;
	if(aAlbumes!=NULL && limAlbumes>0 && aArtistas!=NULL && limArtistas>0 && aGeneros!=NULL && limGeneros>0 &&
			aTiposArtistas!=NULL && limTiposArtistas>0 && aTiposAlbumes!=NULL && limTiposAlbumes>0
			//&& !ingresarEntero(&anioBuscado, MSJ_INGRESO_ANIO, MSJ_ERROR_OPCION, ANIO_MIN, ANIO_ACTUAL, REINTENTOS)
	){
		anioBuscado=2000;
		printf("\n\nSe publicaron antes del %d:\n|%-11s|%-31s|%-21s|%-16s|%-21s|%-21s|%-21s|%-21s|\n",
				anioBuscado, "CÛdigo:", "TÌtulo:", "Fecha:", "Importe:", "Artista:", "Genero:", "Tipo de Artista:", "Tipo de ¡lbum:");
		for(i=0;i<limAlbumes;i++){
			if(aAlbumes[i].isEmpty==FALSE &&
					aAlbumes[i].fechaPublicacion.anio<anioBuscado &&
					!album_coincidirAlbumConArtista(aAlbumes[i], aArtistas, limArtistas, &auxArtista) &&
					!album_coincidirAlbumConGenero(aAlbumes[i], aGeneros, limGeneros, &auxGenero) &&
					!album_coincidirAlbumConTipoArtista(aAlbumes[i], aTiposArtistas, limTiposArtistas, &auxTipoArtista) &&
					!album_coincidirAlbumConTipoAlbum(aAlbumes[i], aTiposAlbumes, limTiposAlbumes, &auxTipoAlbum))
			{
				totalAlbumesEncontrados++;
				album_imprimirUnAlbumPorParametros(&aAlbumes[i], &auxArtista, &auxGenero, &auxTipoArtista, &auxTipoAlbum);
			}
		}
		retorno=0;
	}
	if(totalAlbumesEncontrados==0){
		puts("\nNo hay ·lbumes que cumplan con las caracterÌsticas pedidas.\n\n");
	}
	return retorno;
}

//	7)
int album_listarSuperanImportePromedio(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
												eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes, float importePromedio){
	int retorno=-1;
	int i;
	int totalAlbumesEncontrados=0;
	eArtista auxArtista;
	eGenero auxGenero;
	eTipoArtista auxTipoArtista;
	eTipoAlbum auxTipoAlbum;
	if(aAlbumes!=NULL && limAlbumes>0 && aArtistas!=NULL && limArtistas>0 && aGeneros!=NULL && limGeneros>0 &&
			aTiposArtistas!=NULL && limTiposArtistas>0 && aTiposAlbumes!=NULL && limTiposAlbumes>0){
		printf("\n\nEl promedio de los importes es: %.2f\n\n\n¡lbumes que superan el importe promedio:\n|%-11s|%-31s|%-21s|%-16s|%-21s|%-21s|%-21s|%-21s|\n",
				importePromedio, "CÛdigo:", "TÌtulo:", "Fecha:", "Importe:", "Artista:", "Genero:", "Tipo de Artista:", "Tipo de ¡lbum:");
		for(i=0;i<limAlbumes;i++){
			if(aAlbumes[i].isEmpty==FALSE &&
					aAlbumes[i].importe>importePromedio &&
					!album_coincidirAlbumConArtista(aAlbumes[i], aArtistas, limArtistas, &auxArtista) &&
					!album_coincidirAlbumConGenero(aAlbumes[i], aGeneros, limGeneros, &auxGenero) &&
					!album_coincidirAlbumConTipoArtista(aAlbumes[i], aTiposArtistas, limTiposArtistas, &auxTipoArtista) &&
					!album_coincidirAlbumConTipoAlbum(aAlbumes[i], aTiposAlbumes, limTiposAlbumes, &auxTipoAlbum))
			{
				totalAlbumesEncontrados++;
				album_imprimirUnAlbumPorParametros(&aAlbumes[i], &auxArtista, &auxGenero, &auxTipoArtista, &auxTipoAlbum);
			}
		}
		retorno=0;
	}
	if(totalAlbumesEncontrados==0){
		puts("\nNo hay ·lbumes que cumplan con las caracterÌsticas pedidas.\n\n");
	}
	return retorno;
}

//	8)
int album_listarAlbumesCadaArtista(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
											eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes){
	int retorno=-1;
	int i;
	int k;
	eGenero auxGenero;
	eTipoArtista auxTipoArtista;
	eTipoAlbum auxTipoAlbum;
	if(aAlbumes!=NULL && limAlbumes>0 && aArtistas!=NULL && limArtistas>0 && aGeneros!=NULL && limGeneros>0 &&
			aTiposArtistas!=NULL && limTiposArtistas>0 && aTiposAlbumes!=NULL && limTiposAlbumes>0){
		puts("Lista de ¡lbumes:");
		for(i=0;i<limArtistas;i++){
			printf("\n\n¡lbumes de %s:\n|%-11s|%-31s|%-21s|%-16s|%-21s|%-21s|%-21s|%-21s|\n",
					aArtistas[i].nombre, "CÛdigo:", "TÌtulo:", "Fecha:", "Importe:", "Artista:", "Genero:", "Tipo de Artista:", "Tipo de ¡lbum:");
			for(k=0;k<limAlbumes;k++){
				if(aAlbumes[k].isEmpty==FALSE &&
						aAlbumes[k].idArtista==aArtistas[i].idArtista &&
						!album_coincidirAlbumConGenero(aAlbumes[k], aGeneros, limGeneros, &auxGenero) &&
						!album_coincidirAlbumConTipoArtista(aAlbumes[k], aTiposArtistas, limTiposArtistas, &auxTipoArtista) &&
						!album_coincidirAlbumConTipoAlbum(aAlbumes[k], aTiposAlbumes, limTiposAlbumes, &auxTipoAlbum))
				{
					album_imprimirUnAlbumPorParametros(&aAlbumes[k], &aArtistas[i], &auxGenero, &auxTipoArtista, &auxTipoAlbum);
				}
			}
		}
		retorno=0;
	}
	return retorno;
}

//	9)
int album_listarAlbumAnioDeterminado(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
											eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes){
	int retorno=-1;
	char mensajeAnio[LARGO_MENSAJE];
	int anioBuscado;
	int i;
	int totalAlbumesEncontrados=0;
	eArtista auxArtista;
	eGenero auxGenero;
	eTipoArtista auxTipoArtista;
	eTipoAlbum auxTipoAlbum;

	snprintf(mensajeAnio, sizeof(mensajeAnio), "øDe quÈ aÒo quiere buscar el ·lbum? (entre %d y julio de %d)\n\n", ANIO_MIN, ANIO_ACTUAL);
	if(aAlbumes!=NULL && limAlbumes>0 && aArtistas!=NULL && limArtistas>0 && aGeneros!=NULL && limGeneros>0 &&
			aTiposArtistas!=NULL && limTiposArtistas>0 && aTiposAlbumes!=NULL && limTiposAlbumes>0 &&
			!ingresarEntero(&anioBuscado, mensajeAnio, MSJ_ERROR_OPCION, ANIO_MIN, ANIO_ACTUAL, REINTENTOS)){
		printf("\n\n¡lbumes del aÒo %d:\n|%-11s|%-31s|%-21s|%-16s|%-21s|%-21s|%-21s|%-21s|\n",
				anioBuscado, "CÛdigo:", "TÌtulo:", "Fecha:", "Importe:", "Artista:", "Genero:", "Tipo de Artista:", "Tipo de ¡lbum:");
		for(i=0;i<limAlbumes;i++){
			if(aAlbumes[i].isEmpty==FALSE &&
					aAlbumes[i].fechaPublicacion.anio==anioBuscado &&
					!album_coincidirAlbumConArtista(aAlbumes[i], aArtistas, limArtistas, &auxArtista) &&
					!album_coincidirAlbumConGenero(aAlbumes[i], aGeneros, limGeneros, &auxGenero) &&
					!album_coincidirAlbumConTipoArtista(aAlbumes[i], aTiposArtistas, limTiposArtistas, &auxTipoArtista) &&
					!album_coincidirAlbumConTipoAlbum(aAlbumes[i], aTiposAlbumes, limTiposAlbumes, &auxTipoAlbum))
			{
				totalAlbumesEncontrados++;
				album_imprimirUnAlbumPorParametros(&aAlbumes[i], &auxArtista, &auxGenero, &auxTipoArtista, &auxTipoAlbum);
			}
		}
		retorno=0;
	}
	if(totalAlbumesEncontrados==0){
		puts("\nNo hay ·lbumes que cumplan con las caracterÌsticas pedidas.\n\n");
	}
	return retorno;
}

//	10)
int album_listarAlbumesMasCaros(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
										eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes){
	int retorno=-1;
	int i;
	float importeMaximo;
	eArtista auxArtista;
	eGenero auxGenero;
	eTipoArtista auxTipoArtista;
	eTipoAlbum auxTipoAlbum;
	if(aAlbumes!=NULL && limAlbumes>0 && aArtistas!=NULL && limArtistas>0 && aGeneros!=NULL && limGeneros>0 &&
			aTiposArtistas!=NULL && limTiposArtistas>0 && aTiposAlbumes!=NULL && limTiposAlbumes>0 &&
			!album_calcularImporteMaximo(aAlbumes, limAlbumes, &importeMaximo)){
		printf("\n\nEl importe mas alto es: %.2f\n\nLos ·lbumes mas caros son:\n|%-11s|%-31s|%-21s|%-16s|%-21s|%-21s|%-21s|%-21s|\n",
					importeMaximo, "CÛdigo:", "TÌtulo:", "Fecha:", "Importe:", "Artista:", "Genero:", "Tipo de Artista:", "Tipo de ¡lbum:");
		for(i=0;i<limAlbumes;i++){
			if(aAlbumes[i].isEmpty==FALSE &&
					aAlbumes[i].importe==importeMaximo &&
					!album_coincidirAlbumConTipoAlbum(aAlbumes[i], aTiposAlbumes, limTiposAlbumes, &auxTipoAlbum) &&
					!album_coincidirAlbumConArtista(aAlbumes[i], aArtistas, limArtistas, &auxArtista) &&
					!album_coincidirAlbumConGenero(aAlbumes[i], aGeneros, limGeneros, &auxGenero) &&
					!album_coincidirAlbumConTipoArtista(aAlbumes[i], aTiposArtistas, limTiposArtistas, &auxTipoArtista))
			{
				album_imprimirUnAlbumPorParametros(&aAlbumes[i], &auxArtista, &auxGenero, &auxTipoArtista, &auxTipoAlbum);
			}
		}
		retorno=0;
	}
	return retorno;
}


//	11)
int tipoAlbum_imprimirListaTiposAlbumes(eTipoAlbum* aTiposAlbumes, int limTiposAlbumes){
	int retorno=-1;
	int i;
	if(aTiposAlbumes!=NULL && limTiposAlbumes>0){
		printf("\n\nListado de Tipos de ¡lbumes:\n|%-16s|%-21s|\n", "Id Tipo ¡lbum:", "Tipos ¡lbumes:");
		for(i=0;i<limTiposAlbumes;i++){
			printf("|%16d|%21s|\n", aTiposAlbumes[i].idTipoAlbum, aTiposAlbumes[i].descripcion);
		}
		retorno=0;
	}
	return retorno;
}

//	12)
int album_listarAlbumesNoSonVinilos(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
											eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes){
	int retorno=-1;
	int i;
	int totalAlbumesEncontrados=0;
	eArtista auxArtista;
	eGenero auxGenero;
	eTipoArtista auxTipoArtista;
	eTipoAlbum auxTipoAlbum;
	if(aAlbumes!=NULL && limAlbumes>0 && aArtistas!=NULL && limArtistas>0 && aGeneros!=NULL && limGeneros>0 &&
			aTiposArtistas!=NULL && limTiposArtistas>0 && aTiposAlbumes!=NULL && limTiposAlbumes>0){
		printf("\n\n¡lbumes que no son de vinilo:\n|%-11s|%-31s|%-21s|%-16s|%-21s|%-21s|%-21s|%-21s|\n",
					"CÛdigo:", "TÌtulo:", "Fecha:", "Importe:", "Artista:", "Genero:", "Tipo de Artista:", "Tipo de ¡lbum:");
		for(i=0;i<limAlbumes;i++){
			if(aAlbumes[i].isEmpty==FALSE &&
					!album_coincidirAlbumConTipoAlbum(aAlbumes[i], aTiposAlbumes, limTiposAlbumes, &auxTipoAlbum) &&
					auxTipoAlbum.idTipoAlbum!=1 &&
					!album_coincidirAlbumConArtista(aAlbumes[i], aArtistas, limArtistas, &auxArtista) &&
					!album_coincidirAlbumConGenero(aAlbumes[i], aGeneros, limGeneros, &auxGenero) &&
					!album_coincidirAlbumConTipoArtista(aAlbumes[i], aTiposArtistas, limTiposArtistas, &auxTipoArtista))
			{
				totalAlbumesEncontrados++;
				album_imprimirUnAlbumPorParametros(&aAlbumes[i], &auxArtista, &auxGenero, &auxTipoArtista, &auxTipoAlbum);
			}
		}
		retorno=0;
	}
	if(totalAlbumesEncontrados==0){
		puts("\nNo hay ·lbumes que cumplan con las caracterÌsticas pedidas.\n\n");
	}
	return retorno;
}


//	13)
int album_listarAlbumesVinilosArtistaDeterminado(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
														eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes){
	int retorno=-1;
	int idArtistaBuscado;
	char nombreArtista[LARGO_TEXTO];
	int i;
	int totalAlbumesEncontrados=0;
	eArtista auxArtista;
	eGenero auxGenero;
	eTipoArtista auxTipoArtista;
	eTipoAlbum auxTipoAlbum;
	if(aAlbumes!=NULL && limAlbumes>0 && aArtistas!=NULL && limArtistas>0 && aGeneros!=NULL && limGeneros>0 &&
			aTiposArtistas!=NULL && limTiposArtistas>0 && aTiposAlbumes!=NULL && limTiposAlbumes>0 &&
			!artista_imprimirListaArtistas(aArtistas, limArtistas) &&
			!ingresarEntero(&idArtistaBuscado, "\nIngrese el Id del artista que quiere encontrar:\n", MSJ_ERROR_OPCION, 1, 5, REINTENTOS) &&
			!artista_conseguirNombre(aArtistas, limArtistas, nombreArtista, idArtistaBuscado)){
		printf("\n\n¡lbumes de vinilo de %s:\n|%-11s|%-31s|%-21s|%-16s|%-21s|%-21s|%-21s|%-21s|\n",
				nombreArtista, "CÛdigo:", "TÌtulo:", "Fecha:", "Importe:", "Artista:", "Genero:", "Tipo de Artista:", "Tipo de ¡lbum:");
		for(i=0;i<limAlbumes;i++){
			if(aAlbumes[i].isEmpty==FALSE &&
					!album_coincidirAlbumConArtista(aAlbumes[i], aArtistas, limArtistas, &auxArtista) &&
					auxArtista.idArtista==idArtistaBuscado &&
					!album_coincidirAlbumConTipoAlbum(aAlbumes[i], aTiposAlbumes, limTiposAlbumes, &auxTipoAlbum) &&
					auxTipoAlbum.idTipoAlbum==1 &&
					!album_coincidirAlbumConGenero(aAlbumes[i], aGeneros, limGeneros, &auxGenero) &&
					!album_coincidirAlbumConTipoArtista(aAlbumes[i], aTiposArtistas, limTiposArtistas, &auxTipoArtista))
			{
				totalAlbumesEncontrados++;
				album_imprimirUnAlbumPorParametros(&aAlbumes[i], &auxArtista, &auxGenero, &auxTipoArtista, &auxTipoAlbum);
			}
		}
		retorno=0;
	}
	if(totalAlbumesEncontrados==0){
		puts("\nNo hay ·lbumes que cumplan con las caracterÌsticas pedidas.\n\n");
	}
	return retorno;
}

// 14)
int album_listarAlbumesGeneroYTipoAlbumDeterminados(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
														eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes){
	int retorno=-1;
	int idGeneroBuscado;
	char descripcionGenero[LARGO_TEXTO];
	int idTipoAlbumBuscado;
	char descripcionTipoAlbum[LARGO_TEXTO];
	int totalAlbumesEncontrados=0;
	int i;
	eArtista auxArtista;
	eGenero auxGenero;
	eTipoArtista auxTipoArtista;
	eTipoAlbum auxTipoAlbum;
	if(aAlbumes!=NULL && limAlbumes>0 && aArtistas!=NULL && limArtistas>0 && aGeneros!=NULL && limGeneros>0 &&
			aTiposArtistas!=NULL && limTiposArtistas>0 && aTiposAlbumes!=NULL && limTiposAlbumes>0 &&
			!genero_imprimirListaGeneros(aGeneros, limGeneros) &&
			!ingresarEntero(&idGeneroBuscado, "\nIngrese el id del gÈnero del ·lbum:\n", MSJ_ERROR_OPCION, 1, 5, REINTENTOS) &&
			!tipoAlbum_imprimirListaTiposAlbumes(aTiposAlbumes, limTiposAlbumes) &&
			!ingresarEntero(&idTipoAlbumBuscado, "\nIngrese el id del tipo de ·lbum:\n", MSJ_ERROR_OPCION, 1, 3, REINTENTOS) &&
			!genero_conseguirDescipcion(aGeneros, limGeneros, descripcionGenero, idGeneroBuscado) &&
			!tipoAlbum_conseguirDescipcion(aTiposAlbumes, limTiposAlbumes, descripcionTipoAlbum, idTipoAlbumBuscado)){
		printf("\n\n¡lbumes del genero %s y con tipo de album %s:\n|%-11s|%-31s|%-21s|%-16s|%-21s|%-21s|%-21s|%-21s|\n",
				descripcionGenero, descripcionTipoAlbum, "CÛdigo:", "TÌtulo:", "Fecha:", "Importe:", "Artista:", "Genero:", "Tipo de Artista:", "Tipo de ¡lbum:");
		for(i=0;i<limAlbumes;i++){
			if(aAlbumes[i].isEmpty==FALSE &&
					!album_coincidirAlbumConTipoAlbum(aAlbumes[i], aTiposAlbumes, limTiposAlbumes, &auxTipoAlbum) &&
					auxTipoAlbum.idTipoAlbum==idTipoAlbumBuscado &&
					!album_coincidirAlbumConGenero(aAlbumes[i], aGeneros, limGeneros, &auxGenero) &&
					auxGenero.idGenero==idGeneroBuscado &&
					!album_coincidirAlbumConArtista(aAlbumes[i], aArtistas, limArtistas, &auxArtista) &&
					!album_coincidirAlbumConTipoArtista(aAlbumes[i], aTiposArtistas, limTiposArtistas, &auxTipoArtista))
			{
				totalAlbumesEncontrados++;
				album_imprimirUnAlbumPorParametros(&aAlbumes[i], &auxArtista, &auxGenero, &auxTipoArtista, &auxTipoAlbum);
			}
		}
		retorno=0;
	}
	if(totalAlbumesEncontrados==0){
		puts("\nNo hay ·lbumes que cumplan con las caracterÌsticas pedidas.\n\n");
	}
	return retorno;
}



// 15)
int album_listarAlbumesArtistaYTipoAlbumDeterminados(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
														eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes){
	int retorno=-1;
	int idArtistaBuscado;
	char nombreArtista[LARGO_TEXTO];
	int idTipoAlbumBuscado;
	char descripcionTipoAlbum[LARGO_TEXTO];
	int totalAlbumesEncontrados=0;
	int i;
	eArtista auxArtista;
	eGenero auxGenero;
	eTipoArtista auxTipoArtista;
	eTipoAlbum auxTipoAlbum;
	if(aAlbumes!=NULL && limAlbumes>0 && aArtistas!=NULL && limArtistas>0 && aGeneros!=NULL && limGeneros>0 &&
			aTiposArtistas!=NULL && limTiposArtistas>0 && aTiposAlbumes!=NULL && limTiposAlbumes>0 &&
			!artista_imprimirListaArtistas(aArtistas, limArtistas) &&
			!ingresarEntero(&idArtistaBuscado, "\nIngrese el id del artista del ·lbum:\n", MSJ_ERROR_OPCION, 1, 5, REINTENTOS) &&
			!tipoAlbum_imprimirListaTiposAlbumes(aTiposAlbumes, limTiposAlbumes) &&
			!ingresarEntero(&idTipoAlbumBuscado, "\nIngrese el id del tipo de ·lbum:\n", MSJ_ERROR_OPCION, 1, 3, REINTENTOS) &&
			!artista_conseguirNombre(aArtistas, limArtistas, nombreArtista, idArtistaBuscado)&&
			!tipoAlbum_conseguirDescipcion(aTiposAlbumes, limTiposAlbumes, descripcionTipoAlbum, idTipoAlbumBuscado)){
		printf("\n\n¡lbumes del artista %s y con tipo de album %s:\n|%-11s|%-31s|%-21s|%-16s|%-21s|%-21s|%-21s|%-21s|\n",
				nombreArtista, descripcionTipoAlbum, "CÛdigo:", "TÌtulo:", "Fecha:", "Importe:", "Artista:", "Genero:", "Tipo de Artista:", "Tipo de ¡lbum:");
		for(i=0;i<limAlbumes;i++){
			if(aAlbumes[i].isEmpty==FALSE &&
					!album_coincidirAlbumConTipoAlbum(aAlbumes[i], aTiposAlbumes, limTiposAlbumes, &auxTipoAlbum) &&
					auxTipoAlbum.idTipoAlbum==idTipoAlbumBuscado &&
					!album_coincidirAlbumConArtista(aAlbumes[i], aArtistas, limArtistas, &auxArtista) &&
					auxArtista.idArtista==idArtistaBuscado &&
					!album_coincidirAlbumConGenero(aAlbumes[i], aGeneros, limGeneros, &auxGenero) &&
					!album_coincidirAlbumConTipoArtista(aAlbumes[i], aTiposArtistas, limTiposArtistas, &auxTipoArtista))
			{
				totalAlbumesEncontrados++;
				album_imprimirUnAlbumPorParametros(&aAlbumes[i], &auxArtista, &auxGenero, &auxTipoArtista, &auxTipoAlbum);
			}
		}
		retorno=0;
	}
	if(totalAlbumesEncontrados==0){
		puts("\nNo hay ·lbumes que cumplan con las caracterÌsticas pedidas.\n\n");
	}
	return retorno;
}




















int album_coincidirAlbumConArtista(eAlbum unAlbum, eArtista* aArtistas, int limArtistas, eArtista* auxArtista){
	int retorno=-1;
	int i;
	if(aArtistas!=NULL && limArtistas>0 && auxArtista!=NULL){
		for(i=0;i<limArtistas;i++){
			if(aArtistas[i].idArtista==unAlbum.idArtista){
				*auxArtista=aArtistas[i];
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int album_coincidirAlbumConGenero(eAlbum unAlbum, eGenero* aGeneros, int limGeneros, eGenero* auxGenero){
	int retorno=-1;
	int i;
	if(aGeneros!=NULL && limGeneros>0 && auxGenero!=NULL){
		for(i=0;i<limGeneros;i++){
			if(aGeneros[i].idGenero==unAlbum.idGenero){
				*auxGenero=aGeneros[i];
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int album_coincidirAlbumConTipoArtista(eAlbum unAlbum, eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoArtista* auxTipoArtista){
	int retorno=-1;
	int i;
	if(aTiposArtistas!=NULL && limTiposArtistas>0 && auxTipoArtista!=NULL){
		for(i=0;i<limTiposArtistas;i++){
			if(aTiposArtistas[i].idTipoArtista==unAlbum.idTipoArtista){
				*auxTipoArtista=aTiposArtistas[i];
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int album_coincidirAlbumConTipoAlbum(eAlbum unAlbum, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes, eTipoAlbum* auxTipoAlbum){
	int retorno=-1;
	int i;
	if(aTiposAlbumes!=NULL && limTiposAlbumes>0 && auxTipoAlbum!=NULL){
		for(i=0;i<limTiposAlbumes;i++){
			if(aTiposAlbumes[i].idTipoAlbum==unAlbum.idTipoAlbum){
				*auxTipoAlbum=aTiposAlbumes[i];
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}


int album_calcularImporteMaximo(eAlbum* aAlbumes, int limAlbumes, float* importeMaximo){
	int retorno=-1;
	int i;
	int flagMax=1;
	float auxImporteMaximo;
	if(aAlbumes!=NULL && limAlbumes>0 && importeMaximo!=NULL){
		for(i=0;i<limAlbumes;i++){
			if(aAlbumes[i].isEmpty==FALSE){
				if(flagMax || (aAlbumes[i].importe>auxImporteMaximo)){
					auxImporteMaximo=aAlbumes[i].importe;
					flagMax=0;
				}
			}
		}
		*importeMaximo=auxImporteMaximo;
		retorno=0;
	}
	return retorno;
}


int artista_conseguirNombre(eArtista* aArtistas, int limArtistas, char* nombreArtista, int idArtistaBuscado){
	int retorno=-1;
	int i;
	if(aArtistas!=NULL && limArtistas>0 && nombreArtista!=NULL && idArtistaBuscado>0){
		for(i=0;i<limArtistas;i++){
			if(aArtistas[i].idArtista==idArtistaBuscado){
				strncpy(nombreArtista, aArtistas[i].nombre, LARGO_TEXTO);
				break;
			}
		}
		retorno=0;
	}
	return retorno;
}

int genero_conseguirDescipcion(eGenero* aGeneros, int limGeneros, char* descripcionGenero, int idGeneroBuscado){
	int retorno=-1;
	int i;
	if(aGeneros!=NULL && limGeneros>0 && descripcionGenero!=NULL && idGeneroBuscado>0){
		for(i=0;i<limGeneros;i++){
			if(aGeneros[i].idGenero==idGeneroBuscado){
				strncpy(descripcionGenero, aGeneros[i].descripcion, LARGO_TEXTO);
				break;
			}
		}
		retorno=0;
	}
	return retorno;
}

int tipoAlbum_conseguirDescipcion(eTipoAlbum* aTiposAlbumes, int limTiposAlbumes, char* descripcionTipoAlbum, int idTipoAlbumBuscado){
	int retorno=-1;
	int i;
	if(aTiposAlbumes!=NULL && limTiposAlbumes>0 && descripcionTipoAlbum!=NULL && idTipoAlbumBuscado>0){
		for(i=0;i<limTiposAlbumes;i++){
			if(aTiposAlbumes[i].idTipoAlbum==idTipoAlbumBuscado){
				strncpy(descripcionTipoAlbum, aTiposAlbumes[i].descripcion, LARGO_TEXTO);
				break;
			}
		}
		retorno=0;
	}
	return retorno;
}

int tipoArtista_conseguirDescipcion(eTipoArtista* aTiposArtistas, int limTiposArtistas, char* descripcionTipoArtista, int idTipoArtistaBuscado){
	int retorno=-1;
	int i;
	if(aTiposArtistas!=NULL && limTiposArtistas>0 && descripcionTipoArtista!=NULL && idTipoArtistaBuscado>0){
		for(i=0;i<limTiposArtistas;i++){
			if(aTiposArtistas[i].idTipoArtista==idTipoArtistaBuscado){
				strncpy(descripcionTipoArtista, aTiposArtistas[i].descripcion, LARGO_TEXTO);
				break;
			}
		}
		retorno=0;
	}
	return retorno;
}

