#include "Reports.h"






/*

int album_calcularImporteMinimo(eAlbum* aAlbumes, int limAlbumes, float* importeMinimo){
	int retorno=-1;
	int i;
	int flagMin=1;
	float importeMasBajo;
	if(aAlbumes!=NULL && limAlbumes>0 && importeMinimo!=NULL){
		for(i=0;i<limAlbumes;i++){
			if(aAlbumes[i].isEmpty==FALSE){
				if(flagMin || (aAlbumes[i].importe<importeMasBajo)){
					importeMasBajo=aAlbumes[i].importe;
					flagMin=0;
				}
			}
		}
		*importeMinimo=importeMasBajo;
		retorno=0;
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
						(aAlbumes[i].idGenero==aAlbumes[i+1].idGenero && strncmp(aAlbumes[i].titulo,aAlbumes[i+1].titulo,LARGO_DESCRIPCION)>0)){
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




//	6)
int Listado_albumesInferioresImportePromedio(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
												eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes,
												float totalImportes, int totalAlbumes){
	int retorno=-1;
	float importePromedio;
	int i;
	int albumesEncontrados=0;
	eArtista auxArtista;
	eGenero auxGenero;
	eTipoArtista auxTipoArtista;
	eTipoAlbum auxTipoAlbum;
	if(aAlbumes!=NULL && limAlbumes>0 && aArtistas!=NULL && limArtistas>0 && aGeneros!=NULL && limGeneros>0 &&
			aTiposArtistas!=NULL && limTiposArtistas>0 && aTiposAlbumes!=NULL && limTiposAlbumes>0
			&& !album_calcularImportePromedio(&importePromedio, totalImportes, totalAlbumes)){
		printf("\n\nEl promedio de los importes es: %.2f\n\n\nÁlbumes cuyo importe es inferior al importe promedio:\n|%-11s|%-31s|%-21s|%-16s|%-21s|%-21s|%-21s|%-21s|\n",
				importePromedio, "Código:", "Título:", "Fecha:", "Importe:", "Artista:", "Genero:", "Tipo de Artista:", "Tipo de Álbum:");
		for(i=0;i<limAlbumes;i++){
			if(aAlbumes[i].isEmpty==FALSE &&
					aAlbumes[i].importe<importePromedio &&
					!album_coincidirAlbumConArtista(&aAlbumes[i], aArtistas, limArtistas, &auxArtista) &&
					!album_coincidirAlbumConGenero(&aAlbumes[i], aGeneros, limGeneros, &auxGenero) &&
					!album_coincidirAlbumConTipoArtista(&aAlbumes[i], aTiposArtistas, limTiposArtistas, &auxTipoArtista) &&
					!album_coincidirAlbumConTipoAlbum(&aAlbumes[i], aTiposAlbumes, limTiposAlbumes, &auxTipoAlbum))
			{
				albumesEncontrados++;
				album_imprimirUnAlbumPorParametros(&aAlbumes[i], &auxArtista, &auxGenero, &auxTipoArtista, &auxTipoAlbum);
			}
		}
		retorno=0;
	}
	if(albumesEncontrados==0){
		puts("\nNo hay álbumes que cumplan con las características pedidas.\n\n");
	}
	return retorno;
}

//	9)
int Listado_albumesPosterioresAnioFijo(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
											eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes, int anioFijo){
	int retorno=-1;
	int i;
	int albumesEncontrados=0;
	eArtista auxArtista;
	eGenero auxGenero;
	eTipoArtista auxTipoArtista;
	eTipoAlbum auxTipoAlbum;
	if(aAlbumes!=NULL && limAlbumes>0 && aArtistas!=NULL && limArtistas>0 && aGeneros!=NULL && limGeneros>0 &&
			aTiposArtistas!=NULL && limTiposArtistas>0 && aTiposAlbumes!=NULL && limTiposAlbumes>0){
		printf("\n\nSe publicaron despues del año %d:\n|%-11s|%-31s|%-21s|%-16s|%-21s|%-21s|%-21s|%-21s|\n",
				anioFijo, "Código:", "Título:", "Fecha:", "Importe:", "Artista:", "Genero:", "Tipo de Artista:", "Tipo de Álbum:");
		for(i=0;i<limAlbumes;i++){
			if(aAlbumes[i].isEmpty==FALSE &&
					aAlbumes[i].fechaPublicacion.anio>=anioFijo &&
					!album_coincidirAlbumConArtista(&aAlbumes[i], aArtistas, limArtistas, &auxArtista) &&
					!album_coincidirAlbumConGenero(&aAlbumes[i], aGeneros, limGeneros, &auxGenero) &&
					!album_coincidirAlbumConTipoArtista(&aAlbumes[i], aTiposArtistas, limTiposArtistas, &auxTipoArtista) &&
					!album_coincidirAlbumConTipoAlbum(&aAlbumes[i], aTiposAlbumes, limTiposAlbumes, &auxTipoAlbum))
			{
				albumesEncontrados++;
				album_imprimirUnAlbumPorParametros(&aAlbumes[i], &auxArtista, &auxGenero, &auxTipoArtista, &auxTipoAlbum);
			}
		}
		retorno=0;
	}
	if(albumesEncontrados==0){
		puts("\nNo hay álbumes que cumplan con las características pedidas.\n\n");
	}
	return retorno;
}

//	10)
int Listado_albumesMasBaratos(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
										eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes){
	int retorno=-1;
	int i;
	float importeMinimo;
	eArtista auxArtista;
	eGenero auxGenero;
	eTipoArtista auxTipoArtista;
	eTipoAlbum auxTipoAlbum;
	if(aAlbumes!=NULL && limAlbumes>0 && aArtistas!=NULL && limArtistas>0 && aGeneros!=NULL && limGeneros>0 &&
			aTiposArtistas!=NULL && limTiposArtistas>0 && aTiposAlbumes!=NULL && limTiposAlbumes>0 &&
			!album_calcularImporteMinimo(aAlbumes, limAlbumes, &importeMinimo)){
		printf("\n\nEl importe mas bajo es: %.2f\n\nLos álbumes más baratos son:\n|%-11s|%-31s|%-21s|%-16s|%-21s|%-21s|%-21s|%-21s|\n",
					importeMinimo, "Código:", "Título:", "Fecha:", "Importe:", "Artista:", "Genero:", "Tipo de Artista:", "Tipo de Álbum:");
		for(i=0;i<limAlbumes;i++){
			if(aAlbumes[i].isEmpty==FALSE &&
					aAlbumes[i].importe==importeMinimo &&
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

//	13)
int Listado_albumesCadaGenero(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
											eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes){
	int retorno=-1;
	int i;
	int k;
	eArtista auxArtista;
	eTipoArtista auxTipoArtista;
	eTipoAlbum auxTipoAlbum;
	if(aAlbumes!=NULL && limAlbumes>0 && aArtistas!=NULL && limArtistas>0 && aGeneros!=NULL && limGeneros>0 &&
			aTiposArtistas!=NULL && limTiposArtistas>0 && aTiposAlbumes!=NULL && limTiposAlbumes>0){
		puts("Lista de Álbumes:");
		for(i=0;i<limGeneros;i++){
			printf("\n\nÁlbumes del genero %s:\n|%-11s|%-31s|%-21s|%-16s|%-21s|%-21s|%-21s|%-21s|\n",
					aGeneros[i].descripcion, "Código:", "Título:", "Fecha:", "Importe:", "Artista:", "Genero:", "Tipo de Artista:", "Tipo de Álbum:");
			for(k=0;k<limAlbumes;k++){
				if(aAlbumes[k].isEmpty==FALSE &&
						aAlbumes[k].idGenero==aGeneros[i].idGenero &&
						!album_coincidirAlbumConArtista(&aAlbumes[k], aArtistas, limArtistas, &auxArtista) &&
						!album_coincidirAlbumConTipoArtista(&aAlbumes[k], aTiposArtistas, limTiposArtistas, &auxTipoArtista) &&
						!album_coincidirAlbumConTipoAlbum(&aAlbumes[k], aTiposAlbumes, limTiposAlbumes, &auxTipoAlbum))
				{
					album_imprimirUnAlbumPorParametros(&aAlbumes[k], &auxArtista,&aGeneros[i], &auxTipoArtista, &auxTipoAlbum);
				}
			}
		}
		retorno=0;
	}
	return retorno;
}

//	14)
int Listado_albumesCadaTipoArtista(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
											eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes){
	int retorno=-1;
	int i;
	int k;
	eArtista auxArtista;
	eGenero auxGenero;
	eTipoAlbum auxTipoAlbum;
	if(aAlbumes!=NULL && limAlbumes>0 && aArtistas!=NULL && limArtistas>0 && aGeneros!=NULL && limGeneros>0 &&
			aTiposArtistas!=NULL && limTiposArtistas>0 && aTiposAlbumes!=NULL && limTiposAlbumes>0){
		puts("Lista de Álbumes:");
		for(i=0;i<limTiposArtistas;i++){
			printf("\n\nÁlbumes de tipo de artista %s:\n|%-11s|%-31s|%-21s|%-16s|%-21s|%-21s|%-21s|%-21s|\n",
					aTiposArtistas[i].descripcion, "Código:", "Título:", "Fecha:", "Importe:", "Artista:", "Genero:", "Tipo de Artista:", "Tipo de Álbum:");
			for(k=0;k<limAlbumes;k++){
				if(aAlbumes[k].isEmpty==FALSE &&
						aAlbumes[k].idTipoArtista==aTiposArtistas[i].idTipoArtista &&
						!album_coincidirAlbumConArtista(&aAlbumes[k], aArtistas, limArtistas, &auxArtista) &&
						!album_coincidirAlbumConGenero(&aAlbumes[k], aGeneros, limGeneros, &auxGenero) &&
						!album_coincidirAlbumConTipoAlbum(&aAlbumes[k], aTiposAlbumes, limTiposAlbumes, &auxTipoAlbum))
				{
					album_imprimirUnAlbumPorParametros(&aAlbumes[k], &auxArtista, &auxGenero, &aTiposArtistas[i], &auxTipoAlbum);
				}
			}
		}
		retorno=0;
	}
	return retorno;
}

//	15)
int Listado_albumesCadaTipoAlbum(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
											eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes){
	int retorno=-1;
	int i;
	int k;
	eArtista auxArtista;
	eGenero auxGenero;
	eTipoArtista auxTipoArtista;
	if(aAlbumes!=NULL && limAlbumes>0 && aArtistas!=NULL && limArtistas>0 && aGeneros!=NULL && limGeneros>0 &&
			aTiposArtistas!=NULL && limTiposArtistas>0 && aTiposAlbumes!=NULL && limTiposAlbumes>0){
		puts("Lista de Álbumes:");
		for(i=0;i<limTiposAlbumes;i++){
			printf("\n\nÁlbumes de tipo de álbum %s:\n|%-11s|%-31s|%-21s|%-16s|%-21s|%-21s|%-21s|%-21s|\n",
					aTiposAlbumes[i].descripcion, "Código:", "Título:", "Fecha:", "Importe:", "Artista:", "Genero:", "Tipo de Artista:", "Tipo de Álbum:");
			for(k=0;k<limAlbumes;k++){
				if(aAlbumes[k].isEmpty==FALSE &&
						aAlbumes[k].idTipoAlbum==aTiposAlbumes[i].idTipoAlbum &&
						!album_coincidirAlbumConArtista(&aAlbumes[k], aArtistas, limArtistas, &auxArtista) &&
						!album_coincidirAlbumConGenero(&aAlbumes[k], aGeneros, limGeneros, &auxGenero) &&
						!album_coincidirAlbumConTipoArtista(&aAlbumes[k], aTiposArtistas, limTiposArtistas, &auxTipoArtista))
				{
					album_imprimirUnAlbumPorParametros(&aAlbumes[k], &auxArtista, &auxGenero, &auxTipoArtista, &aTiposAlbumes[i]);
				}
			}
		}
		retorno=0;
	}
	return retorno;
}




















 * */

