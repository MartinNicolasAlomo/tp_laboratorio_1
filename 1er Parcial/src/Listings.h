#ifndef LISTINGS_H_
#define LISTINGS_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Album.h"
#include "Input.h"
#include "Validations.h"
#include "Reports.h"

/// @brief Es el men� de opciones de listados
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
/// @return Retorna 0 (EXITO) si se logr� mostrar el listado seleccionado correctamente, -1 (ERROR) si no se consigui�
int album_menuListado(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
					eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes, float totalImportes, int totalAlbumes);

/// @brief Imprime la lista de todos los generos que hay
/// @param aGeneros Es la lista de generos
/// @param limGeneros Define el tama�o de la lista de generos
/// @return Retorna 0 (EXITO) si se logr� imprimir la lista completa de generos, -1 (ERROR) si no se consigui�
int genero_imprimirListaGeneros(eGenero* aGeneros, int limGeneros);

/// @brief Imprime la lista de todos los tipos de artistas que hay
/// @param aTiposArtistas Es la lista de tipos de artistas
/// @param limTiposArtistas Define el tama�o de la lista de tipos de artistas
/// @return Retorna 0 (EXITO) si se logr� imprimir la lista completa de tipos de artistas, -1 (ERROR) si no se consigui�
int tipoArtista_imprimirListaTiposArtistas(eTipoArtista* aTiposArtistas, int limTiposArtistas);

/// @brief Imprime la lista de todos los artistas que hay
/// @param aArtistas Es la lista de artistas
/// @param limArtistas Define el tama�o de la lista de artistas
/// @return Retorna 0 (EXITO) si se logr� imprimir la lista completa de artistas, -1 (ERROR) si no se consigui�
int artista_imprimirListaArtistas(eArtista* aArtistas, int limArtistas);

/// @brief Imprime un listado solo con los �lbumes que se hayan publicado antes del a�o ingresado
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
/// @return Retorna 0 (EXITO) si se logr� imprimir el listado correctamente, -1 (ERROR) si no se consigui�
int album_listadoAlbumesAnteriorAFecha(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
											eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes);

/// @brief Imprime un listado solo con los �lbumes que superen el importe promedio
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
/// @param importePromedio Es el importe promedio de todos los importes ingresados
/// @return Retorna 0 (EXITO) si se logr� imprimir el listado correctamente, -1 (ERROR) si no se consigui�
int album_listadoSuperanImportePromedio(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
												eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes, float importePromedio);

/// @brief Imprime un listado con todos los �lbumes de cada artista
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
/// @return Retorna 0 (EXITO) si se logr� imprimir el listado correctamente, -1 (ERROR) si no se consigui�
int album_listadoAlbumesCadaArtista(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
											eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes);

/// @brief Imprime un listado con todos los �lbumes que se hayan publicado en un a�o determinado
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
/// @return Retorna 0 (EXITO) si se logr� imprimir el listado correctamente, -1 (ERROR) si no se consigui�
int album_listadoAlbumesAnioDeterminado(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
											eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes);

/// @brief Imprime un listado con todos los �lbumes cuyo importe coincida con el importe m�s alto de la lista
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
/// @return Retorna 0 (EXITO) si se logr� imprimir el listado correctamente, -1 (ERROR) si no se consigui�
int album_listadoAlbumesMasCaros(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
										eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes);


/// @brief Imprime la lista de todos los tipos de �lbumes que hay
/// @param aTiposAlbumes Es la lista de tipos de �lbumes
/// @param limTiposAlbumes Define el tama�o de la lista de tipos de �lbumes
/// @return Retorna 0 (EXITO) si se logr� imprimir la lista completa de tipos de �lbumes, -1 (ERROR) si no se consigui�
int tipoAlbum_imprimirListaTiposAlbumes(eTipoAlbum* aTiposAlbumes, int limTiposAlbumes);

/// @brief Imprime un listado con todos los �lbumes que no sean de vinilo
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
/// @return Retorna 0 (EXITO) si se logr� imprimir el listado correctamente, -1 (ERROR) si no se consigui�
int album_listadoAlbumesNoSonVinilos(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
											eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes);

/// @brief Imprime un listado con todos los �lbumes de un artista determinado y que a la vez sean de vinilo
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
/// @return Retorna 0 (EXITO) si se logr� imprimir el listado correctamente, -1 (ERROR) si no se consigui�
int album_listadoAlbumesVinilosArtistaDeterminado(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
														eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes);

/// @brief Imprime un listado con todos los �lbumes que sean de un genero determinado y un tipo de �lbum determinado
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
/// @return Retorna 0 (EXITO) si se logr� imprimir el listado correctamente, -1 (ERROR) si no se consigui�
int album_listadoAlbumesGeneroYTipoAlbumDeterminados(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
														eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes);

/// @brief Imprime un listado con todos los �lbumes que sean de un artista determinado y un tipo de �lbum determinado
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
/// @return Retorna 0 (EXITO) si se logr� imprimir el listado correctamente, -1 (ERROR) si no se consigui�
int album_listadoAlbumesArtistaYTipoAlbumDeterminados(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
														eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes);






#endif /* LISTINGS_H_ */
