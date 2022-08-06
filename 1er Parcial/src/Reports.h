#ifndef REPORTS_H_
#define REPORTS_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Album.h"
#include "Input.h"
#include "Validations.h"
#include "Listings.h"

/// @brief Es el menú de opciones de informes
/// @param aAlbumes Es la lista de álbumes
/// @param limAlbumes Define el tamaño de la lista de álbumes
/// @param aArtistas Es la lista de artistas
/// @param limArtistas Define el tamaño de la lista de artistas
/// @param aGeneros Es la lista de generos
/// @param limGeneros Define el tamaño de la lista de generos
/// @param aTiposArtistas Es la lista de tipos de artistas
/// @param limTiposArtistas Define el tamaño de la lista de tipos de artistas
/// @param aTiposAlbumes Es la lista de tipos de álbumes
/// @param limTiposAlbumes Define el tamaño de la lista de tipos de álbumes
/// @param totalImportes Es el total de importes ingresados
/// @param totalAlbumes Es el total de álbumes ingresados
/// @return Retorna 0 (EXITO) si se logró mostrar el informe seleccionado correctamente, -1 (ERROR) si no se consiguió
int album_menuInformes(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
							eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes, float totalImportes, int totalAlbumes);

/// @brief Calcula el importe promedio de los importes ingresados
/// @param pResultado Puntero al espacio de memoria donde se guardará el resultado del promedio de importes
/// @param importeTotal Es el total de importes ingresados
/// @param cantidadTotal Es el total de álbumes ingresados
/// @return Retorna 0 (EXITO) si se logró calcular el promedio, -1 (ERROR) si no se consiguió
int album_calcularImportePromedio(float* pResultado, float totalImportes, float totalAlbumes);

/// @brief Busca cuántos álbumes superan el importe promedio
/// @param aAlbumes Es la lista de álbumes
/// @param limAlbumes Define el tamaño de la lista de álbumes
/// @param pResultado Puntero al espacio de memoria donde se guardará el resultado del total de álbumes que superan el importe promedio
/// @param importePromedio Es el importe promedio de los importes ingresados
/// @return Retorna 0 (EXITO) si se logró contar el total de albumes que superan el importe promedio, -1 (ERROR) si no se consiguió
int album_contarAlbumesSuperanImportePromedio(eAlbum* aAlbumes, int limTiposAlbumes, int* pResultado, float importePromedio);

/// @brief Busca cuántos albumes fueron publicados antes de un año determinado
/// @param aAlbumes Es la lista de álbumes
/// @param limAlbumes Define el tamaño de la lista de álbumes
/// @param anioBuscado Puntero al espacio de memoria donde se guardará el año ingresado
/// @return Retorna 0 (EXITO) si se logrò encontrar el total de álbumes que se publicaton antes del año ingresado, -1 (ERROR) si no se consiguió
int album_contarAlbumesAnterioresAnio(eAlbum* aAlbumes, int limTiposAlbumes, int* pResultado, int* anioBuscado);

/// @brief Busca cuántos albumes pertenecen a un solista y se hayan publicado en un año determinado
/// @param aAlbumes Es la lista de álbumes
/// @param limAlbumes Define el tamaño de la lista de álbumes
/// @param aTiposArtistas Es la lista de tipos de artistas
/// @param limTiposArtistas Define el tamaño de la lista de tipos de artistas
/// @param pResultado Puntero al espacio de memoria donde se guardará el total de albumes que sean de un solista y se hayan publicado en el año ingresado
/// @param anioBuscado Puntero al espacio de memoria donde se guardará el año ingresado
/// @return Retorna 0 (EXITO) si se logrò encontrar el total de álbumes que sean de solistas y se hayan publicado en el año ingresado, -1 (ERROR) si no se consiguió
int album_contarSolistasAnioDeterminado(eAlbum* aAlbumes, int limAlbumes, eTipoArtista* aTiposArtistas, int limTiposArtistas, int* pResultado, int* anioBuscado);


int album_contarBandasGeneroDeterminado(eAlbum* aAlbumes, int limAlbumes, eGenero* aGeneros, int limGeneros,
											eTipoArtista* aTiposArtistas, int limTiposArtistas, int* pResultado, char* descripcionGenero);



#endif /* REPORTS_H_ */
