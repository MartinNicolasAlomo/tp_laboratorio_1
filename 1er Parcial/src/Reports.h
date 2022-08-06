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

/// @brief Es el men� de opciones de informes
/// @param aAlbumes Es la lista de �lbumes
/// @param limAlbumes Define el tama�o de la lista de �lbumes
/// @param aArtistas Es la lista de artistas
/// @param limArtistas Define el tama�o de la lista de artistas
/// @param aGeneros Es la lista de generos
/// @param limGeneros Define el tama�o de la lista de generos
/// @param aTiposArtistas Es la lista de tipos de artistas
/// @param limTiposArtistas Define el tama�o de la lista de tipos de artistas
/// @param aTiposAlbumes Es la lista de tipos de �lbumes
/// @param limTiposAlbumes Define el tama�o de la lista de tipos de �lbumes
/// @param totalImportes Es el total de importes ingresados
/// @param totalAlbumes Es el total de �lbumes ingresados
/// @return Retorna 0 (EXITO) si se logr� mostrar el informe seleccionado correctamente, -1 (ERROR) si no se consigui�
int album_menuInformes(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
							eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes, float totalImportes, int totalAlbumes);

/// @brief Calcula el importe promedio de los importes ingresados
/// @param pResultado Puntero al espacio de memoria donde se guardar� el resultado del promedio de importes
/// @param importeTotal Es el total de importes ingresados
/// @param cantidadTotal Es el total de �lbumes ingresados
/// @return Retorna 0 (EXITO) si se logr� calcular el promedio, -1 (ERROR) si no se consigui�
int album_calcularImportePromedio(float* pResultado, float totalImportes, float totalAlbumes);

/// @brief Busca cu�ntos �lbumes superan el importe promedio
/// @param aAlbumes Es la lista de �lbumes
/// @param limAlbumes Define el tama�o de la lista de �lbumes
/// @param pResultado Puntero al espacio de memoria donde se guardar� el resultado del total de �lbumes que superan el importe promedio
/// @param importePromedio Es el importe promedio de los importes ingresados
/// @return Retorna 0 (EXITO) si se logr� contar el total de albumes que superan el importe promedio, -1 (ERROR) si no se consigui�
int album_contarAlbumesSuperanImportePromedio(eAlbum* aAlbumes, int limTiposAlbumes, int* pResultado, float importePromedio);

/// @brief Busca cu�ntos albumes fueron publicados antes de un a�o determinado
/// @param aAlbumes Es la lista de �lbumes
/// @param limAlbumes Define el tama�o de la lista de �lbumes
/// @param anioBuscado Puntero al espacio de memoria donde se guardar� el a�o ingresado
/// @return Retorna 0 (EXITO) si se logr� encontrar el total de �lbumes que se publicaton antes del a�o ingresado, -1 (ERROR) si no se consigui�
int album_contarAlbumesAnterioresAnio(eAlbum* aAlbumes, int limTiposAlbumes, int* pResultado, int* anioBuscado);

/// @brief Busca cu�ntos albumes pertenecen a un solista y se hayan publicado en un a�o determinado
/// @param aAlbumes Es la lista de �lbumes
/// @param limAlbumes Define el tama�o de la lista de �lbumes
/// @param aTiposArtistas Es la lista de tipos de artistas
/// @param limTiposArtistas Define el tama�o de la lista de tipos de artistas
/// @param pResultado Puntero al espacio de memoria donde se guardar� el total de albumes que sean de un solista y se hayan publicado en el a�o ingresado
/// @param anioBuscado Puntero al espacio de memoria donde se guardar� el a�o ingresado
/// @return Retorna 0 (EXITO) si se logr� encontrar el total de �lbumes que sean de solistas y se hayan publicado en el a�o ingresado, -1 (ERROR) si no se consigui�
int album_contarSolistasAnioDeterminado(eAlbum* aAlbumes, int limAlbumes, eTipoArtista* aTiposArtistas, int limTiposArtistas, int* pResultado, int* anioBuscado);


int album_contarBandasGeneroDeterminado(eAlbum* aAlbumes, int limAlbumes, eGenero* aGeneros, int limGeneros,
											eTipoArtista* aTiposArtistas, int limTiposArtistas, int* pResultado, char* descripcionGenero);



#endif /* REPORTS_H_ */
