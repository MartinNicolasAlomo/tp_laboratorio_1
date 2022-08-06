#include "Reports.h"

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
					printf("El total de los importes es: %.2f\nEl promedio de los importes es: %.2f\nLa cantidad de álbumes que superan el importe promedio es: %d",
							totalImportes, importePromedio, totalMayoresPromedio);
					retorno=0;
				}
				break;
			case 2:
				if(!album_contarAlbumesAnterioresAnio(aAlbumes, limAlbumes, &totalAnterioresAnio, &anioBuscado)){
					printf("La cantidad de álbumes publicados antes del año %d es: %d", anioBuscado, totalAnterioresAnio);
					retorno=0;
				}
				else{
					puts("No se pudieron encontrar álbumes publicados antes del año 2000.\n\n\n");
				}
				break;
			case 3:
				if(!album_contarSolistasAnioDeterminado(aAlbumes, limAlbumes, aTiposArtistas, limTiposArtistas, &totalSolistasAnio, &anioBuscado)){
					printf("La cantidad de solistas del año %d es: %d", anioBuscado, totalSolistasAnio);
					retorno=0;
				}
				break;
			case 4:
				if(!album_contarBandasGeneroDeterminado(aAlbumes, limAlbumes, aGeneros, limGeneros, aTiposArtistas, limTiposArtistas, &totalBandasGenero, descripcionGenero)){
					printf("La cantidad de álbumes de banda del genero %s es: %d", descripcionGenero, totalBandasGenero);
					retorno=0;
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
						!album_coincidirAlbumConTipoArtista(&aAlbumes[i], aTiposArtistas, limTiposArtistas, &auxTipoArtista) &&
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


