#include "Album.h"

//	https://onlinegdb.com/pyXJISMgW

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
	int i;
	int opcion=0;
	int indiceNuevo;
	int indiceBuscado;
	float importePrevio;
	float totalImportes=0;
	int totalAlbumes=0;

	if(!album_inicializarLista(aAlbumes, CANT_ALBUMES)){
		puts("Se inicializó el programa correctamente.\n\n");
	}
	else{
		puts("Falló la inicialización del programa.\n\n\n");
	}
	if(		!album_agregarAlbumForzado(aAlbumes, CANT_ALBUMES, 0, 1, "Signos",					5, 3, 1986, 9000, 1, 1, 2, 3) &&
			!album_agregarAlbumForzado(aAlbumes, CANT_ALBUMES, 1, 2, "Canción Animal", 			28, 1, 1990, 10000, 1, 1, 2, 1) &&
			!album_agregarAlbumForzado(aAlbumes, CANT_ALBUMES, 2, 3, "Nada Personal", 			28, 1, 1985, 10000, 1, 1, 2, 1) &&
			!album_agregarAlbumForzado(aAlbumes, CANT_ALBUMES, 3, 4, "Como Un Pájaro Libre", 	22, 10, 1983, 500, 5, 5, 1, 2) &&
			!album_agregarAlbumForzado(aAlbumes, CANT_ALBUMES, 4, 5, "La Negra", 				8, 8, 1988, 10000, 5, 5, 1, 1) &&
			!album_agregarAlbumForzado(aAlbumes, CANT_ALBUMES, 5, 6, "Solo Para Entendidos", 	11, 11, 2006, 500, 3, 3, 2, 3) &&
			!album_agregarAlbumForzado(aAlbumes, CANT_ALBUMES, 6, 7, "Esquivando El Éxito", 	18, 3, 2011, 500, 3, 3, 2, 3) &&
			!album_agregarAlbumForzado(aAlbumes, CANT_ALBUMES, 7, 8, "100% Negro Cumbiero", 	5, 9, 2004, 9000, 3, 3, 2, 1) &&
			!album_agregarAlbumForzado(aAlbumes, CANT_ALBUMES, 8, 9, "Libertango", 				31, 4, 1983, 32000, 4, 4, 1, 2)	&&
			!album_agregarAlbumForzado(aAlbumes, CANT_ALBUMES, 9, 10, "Sin Restricciones", 		17, 8, 2004, 500, 2, 2, 2, 1) &&
			!album_agregarAlbumForzado(aAlbumes, CANT_ALBUMES, 10, 11, "El Disco De Tu Corazón", 1, 4, 2007, 9000, 2, 2, 2, 3) &&
			!album_agregarAlbumForzado(aAlbumes, CANT_ALBUMES, 11, 12, "Es Imposible!", 		24, 8, 2009, 9000, 2, 2, 2, 3)	){
		for(i=0;i<CANT_ALBUMES;i++){
			if(aAlbumes[i].isEmpty==FALSE){
				totalImportes=totalImportes+aAlbumes[i].importe;
			}
		}
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
					printf("\nSe agregó el nuevo álbum al final de la lista. Código N°: %d.\n\n\n\n", aAlbumes[indiceNuevo].codigo);
				}
				break;
			case 2:
				if(totalAlbumes==0){
					puts("No hay álbumes en el sistema.\n\n\n");
				}
				else{
					if(!album_modificarAlbum(aAlbumes, CANT_ALBUMES, &indiceBuscado, &importePrevio, aArtistas, CANT_ARTISTAS, aGeneros, CANT_GENEROS,
								aTiposArtistas, CANT_TIPOS_ARTISTAS, aTiposAlbumes, CANT_TIPOS_ALBUMES)	){
						totalImportes=totalImportes-importePrevio;
						totalImportes=totalImportes+aAlbumes[indiceBuscado].importe;
						album_imprimirListaAlbumes(aAlbumes, CANT_ALBUMES, aArtistas, CANT_ARTISTAS, aGeneros, CANT_GENEROS,
														aTiposArtistas, CANT_TIPOS_ARTISTAS, aTiposAlbumes, CANT_TIPOS_ALBUMES);
						printf("\nSe modificaron los datos del álbum con el código: %d.\n\n\n\n", aAlbumes[indiceBuscado].codigo);
					}
				}
				break;
			case 3:
				if(totalAlbumes==0){
					puts("No hay álbumes en el sistema.\n\n\n");
				}
				else{
					if(!album_eliminarAlbum(aAlbumes, CANT_ALBUMES, &indiceBuscado, aArtistas, CANT_ARTISTAS, aGeneros, CANT_GENEROS,
							aTiposArtistas, CANT_TIPOS_ARTISTAS, aTiposAlbumes, CANT_TIPOS_ALBUMES) ){
						totalImportes=totalImportes-aAlbumes[indiceBuscado].importe;
						totalAlbumes--;
						album_imprimirListaAlbumes(aAlbumes, CANT_ALBUMES, aArtistas, CANT_ARTISTAS, aGeneros, CANT_GENEROS,
														aTiposArtistas, CANT_TIPOS_ARTISTAS, aTiposAlbumes, CANT_TIPOS_ALBUMES);
						printf("\nSe eliminaron los datos del álbum con el código: %d.\n\n\n\n", aAlbumes[indiceBuscado].codigo);
					}
				}
				break;
			case 4:
				if(totalAlbumes==0){
					puts("No hay álbumes en el sistema.\n\n\n");
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
					puts("No hay álbumes en el sistema.\n\n\n");
				}
				else{
					if(!album_menuListado(aAlbumes, CANT_ALBUMES, aArtistas, CANT_ARTISTAS, aGeneros, CANT_GENEROS,
							aTiposArtistas, CANT_TIPOS_ARTISTAS, aTiposAlbumes, CANT_TIPOS_ALBUMES, totalImportes, totalAlbumes)){
						puts("\n\nListado finalizado.\n\n\n");
					}
				}
				break;
			case 6:
				puts("Seleccionó la opción SALIR.\n\n");
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
			puts("No hay mas espacio para agregar álbumes.\n\n\n");
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
		!album_cargarTitulo(&auxiliar, LARGO_TEXTO, aAlbumes, limAlbumes, "Ingrese el título:", "No es un título válido.", mensajeYaExistente, REINTENTOS) &&
		!album_cargarFecha(&auxiliar, MSJ_INGRESO_ANIO, ANIO_MIN, ANIO_ACTUAL) &&
		!ingresarFlotante(&auxiliar.importe, "Ingrese el importe del álbum:", "No es un importe válido.", IMPORTE_MIN, IMPORTE_MAX, REINTENTOS) &&
		!artista_imprimirListaArtistas(aArtistas, limArtistas) &&
		!ingresarEntero(&auxiliar.idArtista, "Ingrese el ID del artista del álbum:", "No es un artista válido.", 1, 5, REINTENTOS) &&
		!genero_imprimirListaGeneros(aGeneros, limGeneros) &&
		!ingresarEntero(&auxiliar.idGenero, "Ingrese el ID del género del álbum:", "No es un género válido.", 1, 5, REINTENTOS) &&
		!tipoArtista_imprimirListaTiposArtistas(aTiposArtistas, limTiposArtistas) &&
		!ingresarEntero(&auxiliar.idTipoArtista, "Ingrese el ID del tipo de artista del álbum::", "No es un tipo de artista válido.", 1, 2, REINTENTOS) &&
		!tipoAlbum_imprimirListaTiposAlbumes(aTiposAlbumes, limTiposAlbumes) &&
		!ingresarEntero(&auxiliar.idTipoAlbum, "Ingrese el ID del tipo de album del álbum:", "No es un tipo de artista válido.", 1, 3, REINTENTOS)	){
		retorno=0;
		*pElemento=auxiliar;
	}
	else{
		//printf("%s", mensajeYaExistente);
	}
	return retorno;
}


int album_cargarTitulo(eAlbum* auxiliar, int largoTitulo, eAlbum* aAlbumes, int limAlbumes, char* mensaje, char* mensajeError, char* mensajeYaExistente, int reintentos){
	int retorno=-1;
	int esExistente;
	int reiteraciones=2;
	if(auxiliar!=NULL && largoTitulo>0 && aAlbumes!=NULL && limAlbumes>0  && mensaje!=NULL  && mensajeError!=NULL &&
			!ingresarDescripcion(auxiliar->titulo, largoTitulo, mensaje, mensajeError, reintentos) &&
			!pasarInicialesMayusculas(auxiliar->titulo, largoTitulo)){
 		esExistente=album_esAlbumExistente(aAlbumes, limAlbumes, auxiliar->titulo, mensajeYaExistente);
		do{
			if(!esExistente){
				retorno=0;
				break;
			}
			else if(esExistente){
				printf("¡Error! ************************************ %s", mensajeYaExistente);
				if(!ingresarDescripcion(auxiliar->titulo, largoTitulo, mensaje, mensajeError, reintentos) &&
					!pasarInicialesMayusculas(auxiliar->titulo, largoTitulo)
					//&& !album_esAlbumExistente(aAlbumes, limAlbumes, auxiliar->titulo, mensajeYaExistente)
					){
			 		esExistente=album_esAlbumExistente(aAlbumes, limAlbumes, auxiliar->titulo, mensajeYaExistente);
				}
				reiteraciones--;
			}
			if(reiteraciones<0){
				break;
			}
		}while(reintentos>=0);
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
		strncpy(mensajeYaExistente, "Ya existe un álbum con este título.\n\n\n", LARGO_MENSAJE);
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
				printf("Actualmente estamos en el año %d. Solo se ingresaron álbumes hasta el 31/07/2022, inclusive.\n\n", anio);
				if(esBisiesto){
					printf("*El año %d es un año Bisiesto, tiene 366 dias, febrero tuvo 29 dias.\n\n", anio);
				}
				else{
					printf("*El año %d es un año Normal, tuvo 365 dias, febrero tuvo 28 dias.\n\n", anio);
				}
				if(!ingresarEntero(&mes, mensajeMesAnterior, MSJ_ERROR_OPCION, 1, MES_ANTERIOR, REINTENTOS) &&
						((mes==2 && esBisiesto && !ingresarEntero(&dia, "Ingrese el día: (del 1 al 29, ya que fue un año bisiesto)", MSJ_ERROR_OPCION, 1, 29, REINTENTOS)) ||
						(mes==2 && !esBisiesto && !ingresarEntero(&dia, "Ingrese el día: (del 1 al 28, fue un año normal)", MSJ_ERROR_OPCION, 1, 28, REINTENTOS)) ||
						((mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) && !ingresarEntero(&dia, "Ingrese el día: (del 1 al 31)", MSJ_ERROR_OPCION, 1, 31, REINTENTOS)) ||
						((mes==4 || mes==6 || mes==9 || mes==11) && !ingresarEntero(&dia, "Ingrese el día: (del 1 al 30)", MSJ_ERROR_OPCION, 1, 30, REINTENTOS))
				)){
					auxiliar->fechaPublicacion.anio=anio;
					auxiliar->fechaPublicacion.mes=mes;
					auxiliar->fechaPublicacion.dia=dia;
					retorno=0;
				}
			}
			else{
				if(esBisiesto){
					printf("*El año %d fue un año Bisiesto, tuvo 366 dias, febrero tuvo 29 dias.\n\n", anio);
				}
				else{
					printf("*El año %d fue un año Normal, tuvo 365 dias, febrero tuvo 28 dias.\n\n", anio);
				}
				if(!ingresarEntero(&mes, "Ingrese el mes: (del 1 al 12)", MSJ_ERROR_OPCION, 1, 12, REINTENTOS) &&
						((mes==2 && esBisiesto && !ingresarEntero(&dia, "Ingrese el día: (del 1 al 29, ya que fue un año bisiesto)", MSJ_ERROR_OPCION, 1, 29, REINTENTOS)) ||
						(mes==2 && !esBisiesto && !ingresarEntero(&dia, "Ingrese el día: (del 1 al 28, fue un año normal)", MSJ_ERROR_OPCION, 1, 28, REINTENTOS)) ||
						((mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) && !ingresarEntero(&dia, "Ingrese el día: (del 1 al 31)", MSJ_ERROR_OPCION, 1, 31, REINTENTOS)) ||
						((mes==4 || mes==6 || mes==9 || mes==11) && !ingresarEntero(&dia, "Ingrese el día: (del 1 al 30)", MSJ_ERROR_OPCION, 1, 30, REINTENTOS))
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
				puts("Se canceló la modificación del álbum.\n\n");
			}
		}
		else if(indiceCodigo<0 || aAlbumes[indiceCodigo].isEmpty==TRUE){
			puts("No existe ningún álbum con ese id.\n\n");
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
					if(!ingresarDescripcion(auxiliar.titulo, LARGO_TEXTO, "Nuevo título:", "No es un título válido.", REINTENTOS) &&
							!pasarInicialesMayusculas(auxiliar.titulo, LARGO_TEXTO)){
						flagExiste=album_esAlbumExistente(aAlbumes, limAlbumes, auxiliar.titulo, albumExistente);
						if(!flagExiste){
							puts("Título ingresado correctamente.\n\n");
							flagCambios=0;
						}
						else{
							printf("%s", albumExistente);
						}
					}
					else{
						puts("No se ingresó un título válido.\n\n");
					}
					break;
				case 2:
					if(!album_cargarFecha(&auxiliar, "Nuevo año: %d-%d", ANIO_MIN, ANIO_ACTUAL)){
						puts("Fecha ingresada correctamente.\n\n");
						flagCambios=0;
					}
					else{
						puts("No se ingresó un importe válido.\n\n");
					}
					break;
				case 3:
					if(!ingresarFlotante(&auxiliar.importe, "Nuevo importe:", "No es un importe válido.", IMPORTE_MIN, IMPORTE_MAX, REINTENTOS)){
						puts("Importe ingresado correctamente.\n\n");
						flagCambios=0;
					}
					else{
						puts("No se ingresó un importe válido.\n\n");
					}
					break;
				case 4:
					if(!tipoAlbum_imprimirListaTiposAlbumes(aTiposAlbumes, limTiposAlbumes) &&
							!ingresarEntero(&auxiliar.idTipoAlbum, "Nuevo tipo de album:", "No es un tipo de artista válido.", 1, 3, REINTENTOS)){
						puts("Tipo de álbum ingresado correctamente.\n\n");
						flagCambios=0;
					}
					else{
						puts("No se ingresó un tipo de álbum válido.\n\n");
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
				puts("No se pudo ingresar una opción.\n\n\n");
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
			printf("No existe ningún álbum con el id %d.\n\n", codigoEliminar);
		}
		else{
			puts("Hubo un error en la eliminacón del álbum.\n\n");
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
			!album_coincidirAlbumConArtista(pElemento, aArtistas, limArtistas, &auxArtista) &&
			!album_coincidirAlbumConGenero(pElemento, aGeneros, limGeneros, &auxGenero) &&
			!album_coincidirAlbumConTipoArtista(pElemento, aTiposArtistas, limTiposArtistas, &auxTipoArtista) &&
			!album_coincidirAlbumConTipoAlbum(pElemento, aTiposAlbumes, limTiposAlbumes, &auxTipoAlbum) ){
		printf("\n\n%s\n\n|%-11s|%-31s|%-21s|%-16s|%-21s|%-21s|%-21s|%-21s|\n", mensajePrevio,
				"Código:", "Título:","Fecha:","Importe:","Artista:","Genero:","Tipo de Artista:","Tipo de Álbum:");
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
		printf("\n\nLista de álbumes:\n|%-11s|%-31s|%-21s|%-16s|%-21s|%-21s|%-21s|%-21s|\n",
						"Código:", "Título:", "Fecha:", "Importe:", "Artista:", "Genero:", "Tipo de Artista:", "Tipo de Álbum:");
		for(i=0;i<limAlbumes;i++){
			if(aAlbumes[i].isEmpty==FALSE &&
					!album_coincidirAlbumConArtista(&aAlbumes[i], aArtistas, limArtistas, &auxArtista) &&
					!album_coincidirAlbumConGenero(&aAlbumes[i], aGeneros, limGeneros, &auxGenero) &&
					!album_coincidirAlbumConTipoArtista(&aAlbumes[i], aTiposArtistas, limTiposArtistas, &auxTipoArtista) &&
					!album_coincidirAlbumConTipoAlbum(&aAlbumes[i], aTiposAlbumes, limTiposAlbumes, &auxTipoAlbum))
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

int album_ordenarPorGeneroYTitulo(eAlbum* aAlbumes, int limite){
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
				if(aAlbumes[i].idGenero>aAlbumes[i+1].idGenero ||
						(aAlbumes[i].idGenero==aAlbumes[i+1].idGenero && strncmp(aAlbumes[i].titulo,aAlbumes[i+1].titulo,LARGO_TEXTO)>0)){
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

int album_ordenarPorGeneroYCodigo(eAlbum* aAlbumes, int limite){
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
				if(aAlbumes[i].idGenero>aAlbumes[i+1].idGenero ||
						(aAlbumes[i].idGenero==aAlbumes[i+1].idGenero && aAlbumes[i].codigo>aAlbumes[i+1].codigo)){
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






// 4)
int album_contarBandasGeneroDeterminado(eAlbum* aAlbumes, int limAlbumes, eGenero* aGeneros, int limGeneros,
											eTipoArtista* aTiposArtistas, int limTiposArtistas, int* pResultado, char* descripcionGenero){
	int retorno=-1;
	int idGeneroEncontrado;
	int totalAlbumes=0;
	int i;
	eGenero auxGenero;
	eTipoArtista auxTipoArtista;
	if(aAlbumes!=NULL && limAlbumes>0 && aTiposArtistas!=NULL && limTiposArtistas>0 && pResultado!=NULL){
		if(!genero_imprimirListaGeneros(aGeneros, limGeneros) &&
				!ingresarEntero(&idGeneroEncontrado, "\nIngrese el id del genero que desea buscar:\n", MSJ_ERROR_OPCION, 1, 5, REINTENTOS) &&
				!genero_conseguirDescipcion(aGeneros, limGeneros, descripcionGenero, idGeneroEncontrado)){
			for(i=0;i<limAlbumes;i++){
				if(aAlbumes[i].isEmpty==FALSE &&
						!album_coincidirAlbumConGenero(&aAlbumes[i], aGeneros, limGeneros, &auxGenero) &&
						auxGenero.idGenero==idGeneroEncontrado &&
						!album_coincidirAlbumConTipoArtista(&aAlbumes[i], aTiposArtistas, limTiposArtistas, &auxTipoArtista) &&
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








int album_coincidirAlbumConArtista22222(eAlbum* unAlbum, eArtista* aArtistas, int limArtistas, eArtista* auxArtista){
	int retorno=-1;
	int i;
	if(aArtistas!=NULL && limArtistas>0 && auxArtista!=NULL){
		for(i=0;i<limArtistas;i++){
			if(aArtistas[i].idArtista==unAlbum->idArtista){
				*auxArtista=aArtistas[i];
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}






int album_coincidirAlbumConArtista(eAlbum* unAlbum, eArtista* aArtistas, int limArtistas, eArtista* auxArtista){
	int retorno=-1;
	int i;
	if(aArtistas!=NULL && limArtistas>0 && auxArtista!=NULL){
		for(i=0;i<limArtistas;i++){
			if(aArtistas[i].idArtista==unAlbum->idArtista){
				*auxArtista=aArtistas[i];
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int album_coincidirAlbumConGenero(eAlbum* unAlbum, eGenero* aGeneros, int limGeneros, eGenero* auxGenero){
	int retorno=-1;
	int i;
	if(aGeneros!=NULL && limGeneros>0 && auxGenero!=NULL){
		for(i=0;i<limGeneros;i++){
			if(aGeneros[i].idGenero==unAlbum->idGenero){
				*auxGenero=aGeneros[i];
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int album_coincidirAlbumConTipoArtista(eAlbum* unAlbum, eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoArtista* auxTipoArtista){
	int retorno=-1;
	int i;
	if(aTiposArtistas!=NULL && limTiposArtistas>0 && auxTipoArtista!=NULL){
		for(i=0;i<limTiposArtistas;i++){
			if(aTiposArtistas[i].idTipoArtista==unAlbum->idTipoArtista){
				*auxTipoArtista=aTiposArtistas[i];
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int album_coincidirAlbumConTipoAlbum(eAlbum* unAlbum, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes, eTipoAlbum* auxTipoAlbum){
	int retorno=-1;
	int i;
	if(aTiposAlbumes!=NULL && limTiposAlbumes>0 && auxTipoAlbum!=NULL){
		for(i=0;i<limTiposAlbumes;i++){
			if(aTiposAlbumes[i].idTipoAlbum==unAlbum->idTipoAlbum){
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

