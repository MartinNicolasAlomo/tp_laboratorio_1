#include "Listings.h"


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
				if(!album_listadoAlbumesAnteriorAFecha(aAlbumes, limAlbumes, aArtistas, limArtistas, aGeneros, limGeneros,
						aTiposArtistas, limTiposArtistas, aTiposAlbumes, limTiposAlbumes)){
					retorno=0;
				}
				else{
					puts("ERROR\n");
				}
				break;
			case 7:
				if(!album_calcularImportePromedio(&importePromedio, totalImportes, totalAlbumes) &&
						!album_listadoSuperanImportePromedio(aAlbumes, limAlbumes, aArtistas, limArtistas, aGeneros, limGeneros,
								aTiposArtistas, limTiposArtistas, aTiposAlbumes, limTiposAlbumes, importePromedio)){
					retorno=0;
				}
				else{
					puts("ERROR\n");
				}
				break;
			case 8:
				if(!album_listadoAlbumesCadaArtista(aAlbumes, limAlbumes, aArtistas, limArtistas, aGeneros, limGeneros,
						aTiposArtistas, limTiposArtistas, aTiposAlbumes, limTiposAlbumes)){
					retorno=0;
				}
				else{
					puts("ERROR\n");
				}
				break;
			case 9:
				if(!album_listadoAlbumesAnioDeterminado(aAlbumes, limAlbumes, aArtistas, limArtistas, aGeneros, limGeneros,
						aTiposArtistas, limTiposArtistas, aTiposAlbumes, limTiposAlbumes)){
					retorno=0;
				}
				else{
					puts("ERROR\n");
				}
				break;
			case 10:
				if(!album_listadoAlbumesMasCaros(aAlbumes, limAlbumes, aArtistas, limArtistas, aGeneros, limGeneros,
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
				if(!album_listadoAlbumesNoSonVinilos(aAlbumes, limAlbumes, aArtistas, limArtistas, aGeneros, limGeneros,
						aTiposArtistas, limTiposArtistas, aTiposAlbumes, limTiposAlbumes)){
					retorno=0;
				}
				else{
					puts("ERROR\n");
				}
				break;
			case 13:
				if(!album_listadoAlbumesVinilosArtistaDeterminado(aAlbumes, limAlbumes, aArtistas, limArtistas, aGeneros, limGeneros,
						aTiposArtistas, limTiposArtistas, aTiposAlbumes, limTiposAlbumes)){
					retorno=0;
				}
				else{
					puts("ERROR\n");
				}
				break;
			case 14:
				if(!album_listadoAlbumesGeneroYTipoAlbumDeterminados(aAlbumes, limAlbumes, aArtistas, limArtistas, aGeneros, limGeneros,
						aTiposArtistas, limTiposArtistas, aTiposAlbumes, limTiposAlbumes)){
					retorno=0;
				}
				else{
					puts("ERROR\n");
				}
				break;
			case 15:
				if(!album_listadoAlbumesArtistaYTipoAlbumDeterminados(aAlbumes, limAlbumes, aArtistas, limArtistas, aGeneros, limGeneros,
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

//	5)		Funciones:	album_ordenarPorImporteYTitulo  +  album_imprimirListaAlbumes

//	6)
int album_listadoAlbumesAnteriorAFecha(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
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
					!album_coincidirAlbumConArtista(&aAlbumes[i], aArtistas, limArtistas, &auxArtista) &&
					!album_coincidirAlbumConGenero(&aAlbumes[i], aGeneros, limGeneros, &auxGenero) &&
					!album_coincidirAlbumConTipoArtista(&aAlbumes[i], aTiposArtistas, limTiposArtistas, &auxTipoArtista) &&
					!album_coincidirAlbumConTipoAlbum(&aAlbumes[i], aTiposAlbumes, limTiposAlbumes, &auxTipoAlbum))
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
int album_listadoSuperanImportePromedio(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
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
					!album_coincidirAlbumConArtista(&aAlbumes[i], aArtistas, limArtistas, &auxArtista) &&
					!album_coincidirAlbumConGenero(&aAlbumes[i], aGeneros, limGeneros, &auxGenero) &&
					!album_coincidirAlbumConTipoArtista(&aAlbumes[i], aTiposArtistas, limTiposArtistas, &auxTipoArtista) &&
					!album_coincidirAlbumConTipoAlbum(&aAlbumes[i], aTiposAlbumes, limTiposAlbumes, &auxTipoAlbum))
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
int album_listadoAlbumesCadaArtista(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
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
						!album_coincidirAlbumConGenero(&aAlbumes[k], aGeneros, limGeneros, &auxGenero) &&
						!album_coincidirAlbumConTipoArtista(&aAlbumes[k], aTiposArtistas, limTiposArtistas, &auxTipoArtista) &&
						!album_coincidirAlbumConTipoAlbum(&aAlbumes[k], aTiposAlbumes, limTiposAlbumes, &auxTipoAlbum))
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
int album_listadoAlbumesAnioDeterminado(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
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
					!album_coincidirAlbumConArtista(&aAlbumes[i], aArtistas, limArtistas, &auxArtista) &&
					!album_coincidirAlbumConGenero(&aAlbumes[i], aGeneros, limGeneros, &auxGenero) &&
					!album_coincidirAlbumConTipoArtista(&aAlbumes[i], aTiposArtistas, limTiposArtistas, &auxTipoArtista) &&
					!album_coincidirAlbumConTipoAlbum(&aAlbumes[i], aTiposAlbumes, limTiposAlbumes, &auxTipoAlbum))
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
int album_listadoAlbumesMasCaros(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
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
					!album_coincidirAlbumConTipoAlbum(&aAlbumes[i], aTiposAlbumes, limTiposAlbumes, &auxTipoAlbum) &&
					!album_coincidirAlbumConArtista(&aAlbumes[i], aArtistas, limArtistas, &auxArtista) &&
					!album_coincidirAlbumConGenero(&aAlbumes[i], aGeneros, limGeneros, &auxGenero) &&
					!album_coincidirAlbumConTipoArtista(&aAlbumes[i], aTiposArtistas, limTiposArtistas, &auxTipoArtista))
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
int album_listadoAlbumesNoSonVinilos(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
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
					!album_coincidirAlbumConTipoAlbum(&aAlbumes[i], aTiposAlbumes, limTiposAlbumes, &auxTipoAlbum) &&
					auxTipoAlbum.idTipoAlbum!=1 &&
					!album_coincidirAlbumConArtista(&aAlbumes[i], aArtistas, limArtistas, &auxArtista) &&
					!album_coincidirAlbumConGenero(&aAlbumes[i], aGeneros, limGeneros, &auxGenero) &&
					!album_coincidirAlbumConTipoArtista(&aAlbumes[i], aTiposArtistas, limTiposArtistas, &auxTipoArtista))
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
int album_listadoAlbumesVinilosArtistaDeterminado(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
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
					!album_coincidirAlbumConArtista(&aAlbumes[i], aArtistas, limArtistas, &auxArtista) &&
					auxArtista.idArtista==idArtistaBuscado &&
					!album_coincidirAlbumConTipoAlbum(&aAlbumes[i], aTiposAlbumes, limTiposAlbumes, &auxTipoAlbum) &&
					auxTipoAlbum.idTipoAlbum==1 &&
					!album_coincidirAlbumConGenero(&aAlbumes[i], aGeneros, limGeneros, &auxGenero) &&
					!album_coincidirAlbumConTipoArtista(&aAlbumes[i], aTiposArtistas, limTiposArtistas, &auxTipoArtista))
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
int album_listadoAlbumesGeneroYTipoAlbumDeterminados(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
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
					!album_coincidirAlbumConTipoAlbum(&aAlbumes[i], aTiposAlbumes, limTiposAlbumes, &auxTipoAlbum) &&
					auxTipoAlbum.idTipoAlbum==idTipoAlbumBuscado &&
					!album_coincidirAlbumConGenero(&aAlbumes[i], aGeneros, limGeneros, &auxGenero) &&
					auxGenero.idGenero==idGeneroBuscado &&
					!album_coincidirAlbumConArtista(&aAlbumes[i], aArtistas, limArtistas, &auxArtista) &&
					!album_coincidirAlbumConTipoArtista(&aAlbumes[i], aTiposArtistas, limTiposArtistas, &auxTipoArtista))
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
int album_listadoAlbumesArtistaYTipoAlbumDeterminados(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
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
					!album_coincidirAlbumConArtista(&aAlbumes[i], aArtistas, limArtistas, &auxArtista) &&
					auxArtista.idArtista==idArtistaBuscado &&
					!album_coincidirAlbumConTipoAlbum(&aAlbumes[i], aTiposAlbumes, limTiposAlbumes, &auxTipoAlbum) &&
					auxTipoAlbum.idTipoAlbum==idTipoAlbumBuscado &&
					!album_coincidirAlbumConGenero(&aAlbumes[i], aGeneros, limGeneros, &auxGenero) &&
					!album_coincidirAlbumConTipoArtista(&aAlbumes[i], aTiposArtistas, limTiposArtistas, &auxTipoArtista))
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

