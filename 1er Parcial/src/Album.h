#ifndef ALBUM_H_
#define ALBUM_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Reports.h"
#include "Listings.h"
#include "Input.h"
#include "Validations.h"

#define CANT_ALBUMES 50
#define CANT_ARTISTAS 5
#define CANT_GENEROS 5
#define CANT_TIPOS_ARTISTAS 2
#define CANT_TIPOS_ALBUMES 3

#define REINTENTOS 50
#define TRUE 1
#define FALSE 0
#define LARGO_DESCRIPCION 50
#define LARGO_MENSAJE_CORTO 150
#define LARGO_MENSAJE_LARGO 550
#define LARGO_MENSAJE_LISTADO 2250

#define ANIO_MIN 1890
#define ANIO_ACTUAL 2022
#define MES_ANTERIOR 7
#define IMPORTE_MIN 1
#define IMPORTE_MAX 200000

#define MSJ_MENU_PRINCIPAL "Seleccione una opcion\n1. Agregar �lbum\n2. Modificar �lbum\n3. Eliminar �lbum\n4. Informes\n5. Listados\n6. Salir\n\n"
#define MSJ_MENU_MODIFICAR "�Qu� desea modificar?\n  1- T�tulo\n  2- Fecha de publicaci�n\n  3- Importe\n  4- Tipo de �lbum\n  5- Finalizar cambios\n\n"
#define MSJ_MENU_INFORME "�Qu� desea informar?\n  1- Total y promedio de los importes, y cu�ntos �lbumes superan ese promedio.\n  2- Cantidad de �lbumes cuya fecha de publicaci�n es anterior a 1/1/2000.\n  3- Informar la cantidad de solistas de un a�o determinado.\n  4- Informar la cantidad de �lbumes de bandas de un g�nero determinado.\n\n"
#define MSJ_MENU_LISTADO_01_05 "�Qu� listado desea ver?\n  1- Todos los g�neros.\n  2- Todos los tipos de artistas musicales.\n  3- Todos los artistas.\n  4- Todos los �lbumes.\n  5- Realizar un solo listado de los �lbumes ordenados por los siguientes criterios:\n\tImporte (descendentemente) y T�tulo (ascendentemente)\n"
#define MSJ_MENU_LISTADO_06_10 "  6- Todos los �lbumes cuya fecha de publicaci�n es menor a 1/1/2000.\n  7- Todos los �lbumes que superan el promedio de los importes.\n  8- Todos los �lbumes de cada artista.\n  9- Todos los �lbumes de un a�o determinado.\n  10- El �lbum o los �lbumes m�s caros.\n"
#define MSJ_MENU_LISTADO_12_15 "  11- Listar todos los tipos de �lbumes.\n  12- Listar todos los �lbumes que no sean de vinilo.\n  13- Listar todos los �lbumes de vinilo que correspondan a un artista determinado.\n  14- Realizar un solo listado de todos los �lbumes de un tipo de �lbum determinado y de un g�nero determinado.\n  15- Realizar un solo listado de todos los �lbumes de un artista determinado y de un tipo de �lbum determinado.\n"

#define MSJ_CODIGO_MODIFICAR "Ingrese el c�digo del �lbum que desea modificar:"
#define MSJ_CODIGO_ELIMINAR "Ingrese el c�digo del �lbum que desea eliminar:"
#define MSJ_ERROR_OPCION  "No es una opci�n v�lida."
#define MSJ_ERROR_CODIGO "No es un c�digo v�lido."
#define MSJ_CONFIRMAR_AGREGADO "�Est� seguro/a de quiere agregar este �lbum?\n  1- Si\n  0- No\n\n"
#define MSJ_CONFIRMAR_MODIFICACION "�Est� seguro/a de quiere realizar las modificaciones?\n  1- Si\n  0- No\n\n"
#define MSJ_CONFIRMAR_ELIMINADO "�Est� seguro/a de quiere eliminar este �lbum?\n  1- Si\n  0- No\n\n"
#define MSJ_INGRESO_ANIO "Ingrese el a�o: (entre %d y %d)."
#define MSJ_INGRESO_MES_ANTERIOR "Ingrese el mes: (del 1 al %d)"
#define MSJ_VISTA_NUEVO "Vista previa del �lbum ingresado: 	(Tiene c�digo 0 (cero). Se le asignar� su c�digo correspondiente una vez que se agregue definitivamente a la lista)."
#define MSJ_VISTA_MODIFICADO "Vista previa de los cambios realizados:"
#define MSJ_VISTA_ENCONTRADO "Se encontr� el siguiente �lbum con el c�digo ingresado:"


typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;


typedef struct{
	int idTipoAlbum;
	char descripcion[LARGO_DESCRIPCION];
}eTipoAlbum;


typedef struct{
	int idTipoArtista;
	char descripcion[LARGO_DESCRIPCION];
}eTipoArtista;


typedef struct{
	int idGenero;
	char descripcion[LARGO_DESCRIPCION];
}eGenero;


typedef struct{
	int idArtista;
	char nombre[LARGO_DESCRIPCION];
}eArtista;


typedef struct{
	int codigo;
	char titulo[LARGO_DESCRIPCION];
	eFecha fechaPublicacion;
	float importe;
	int idArtista;
	int idTipoArtista;
	int idGenero;
	int idTipoAlbum;
	int isEmpty;
}eAlbum;




/// @brief Es el menu de opcines pricipal de la funcion, se usa un ABM
/// @return Retorna 0 (EXITO) si logro finalizar la operatoria, -1 (ERROR) si no se consigui�
int album_menuPrincipal(void);

/// @brief Inicializa todas la posiciones de la lista de �lbumes como vac�as
/// @param aAlbumes Es la lista de �lbumes, a la cual se le inicializaran las todas las posiones como vacias
/// @param limAlbumes Define el tama�o de la lista
/// @return Retorna 0 (EXITO) si se lograron inicializar todas las posiciones del vector, -1 (ERROR) si no se consigui�
int album_inicializarLista(eAlbum* aAlbumes, int limTiposAlbumes);

/// @brief Busca la proxima posicion que se encuentre vacia, dentro del vector
/// @param aAlbumes Es la lista de �lbumes en el que se buscara la posicion vacia
/// @param limAlbumes Define el tama�o de la lista
/// @return Retorna 0 (EXITO) si se logr� encontrar alguna posicion vacia, -1 (ERROR) si no se consigui�
int album_buscarIndiceVacio(eAlbum* aAlbumes, int limAlbumes);

/// @brief Busca la posicion de un album dentro de la lista, segun el codigo ingresado
/// @param aAlbumes Es la lista de �lbumes en el que se buscara la posicion con el codigo
/// @param limAlbumes Define el tama�o de la lista
/// @param codigo Es el codigo del �lbum a ser buscado
/// @return Retorna 0 (EXITO) si se logr� encontrar el �lbum con el codigo ingresado, -1 (ERROR) si no se consigui�
int album_buscarPorCodigo(eAlbum* aAlbumes, int limAlbumes, int codigo);


/// @brief Hardcodea los datos de un �lbum y lo agrega a la lista
/// @param aAlbumes Es la lista de �lbumes donde se agregar� el album hardcodeado
/// @param limAlbumes Define el tama�o de la lista de �lbumes
/// @param indiceLibre Es la posici�n en el vector donde se agregar� el album
/// @param codigo Es el c�digo hardcodeado que se le asignar� al album
/// @param titulo Es el t�tulo hardcodeado que se le asignar� al album
/// @param dia Es el d�a de publicaci�n hardcodeado que se le asignar� al album
/// @param mes Es el mes de publicaci�n  hardcodeado que se le asignar� al album
/// @param anio Es el a�o de publicaci�n hardcodeado que se le asignar� al album
/// @param importe Es el importe hardcodeado que se le asignar� al album
/// @param idArtista Es el id del artista hardcodeado que se le asignar� al album
/// @param idTipoArtista Es el id del tipo de artista hardcodeado que se le asignar� al album
/// @param idGenero Es el id del genero hardcodeado que se le asignar� al album
/// @param idTipoAlbum Es el id del tipo de album hardcodeado que se le asignar� al album
/// @return Retorna 0 (EXITO) si se logr� agregar el �lbum hardcodeado a la lista, -1 (ERROR) si no se consigui�
int album_agregarAlbumForzado(eAlbum* aAlbumes, int limAlbumes, int indiceLibre, int codigo, char* titulo, int dia, int mes, int anio,
								float importe, int idArtista, int idGenero, int idTipoArtista, int idTipoAlbum);

/// @brief Agrega un album nuevo a la lista
/// @param aAlbumes Es la lista de �lbumes donde se agregar� el nuevo �lbum agregado
/// @param limAlbumes Define el tama�o de la lista
/// @param indiceNuevo Puntero al espacio de memoria donde se guardar� el indice que ocupar� el album
/// @param aArtistas Es la lista de artistas
/// @param limArtistas Define el tama�o de la lista de artistas
/// @param aGeneros Es la lista de generos
/// @param limGeneros Define el tama�o de la lista de generos
/// @param aTiposArtistas Es la lista de tipos de artistas
/// @param limTiposArtistas Define el tama�o de la lista de tipos de artistas
/// @param aTiposAlbumes Es la lista de tipos de �lbumes
/// @param limTiposAlbumes Define el tama�o de la lista de tipos de �lbumes
/// @return Retorna 0 (EXITO) si se logr� agregar el album a la lista, -1 (ERROR) si no se consigui�
int album_agregarAlbum(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
							eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes, float* totalImportes, int* totalAlbumes);
/// @brief Solicita los datos al usuario y los carga dentro de un �lbum auxiliar, para luego cargarlos al nuevo �lbum
/// @param pElemento Puntero al espacio de memoria donde se cargar�n los datos ingresados
/// @param aAlbumes Es la lista de �lbumes
/// @param limAlbumes Define el tama�o de la lista
/// @param aArtistas Es la lista de artistas
/// @param limArtistas Define el tama�o de la lista de artistas
/// @param aGeneros Es la lista de generos
/// @param limGeneros Define el tama�o de la lista de generos
/// @param aTiposArtistas Es la lista de tipos de artistas
/// @param limTiposArtistas Define el tama�o de la lista de tipos de artistas
/// @param aTiposAlbumes Es la lista de tipos de �lbumes
/// @param limTiposAlbumes Define el tama�o de la lista de tipos de �lbumes
/// @return Retorna 0 (EXITO) si se lograron cargar todos los datos ingresados en el auxiliar, -1 (ERROR) si no se consigui�
int album_cargarDatos(eAlbum* pElemento, eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
							eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes);

int album_cargarTitulo(eAlbum* auxiliar, int largoTitulo, eAlbum* aAlbumes, int limAlbumes, char* mensaje, char* mensajeError, char* mensajeYaExistente, int reintentos);

/// @brief Verifica si el titulo ingresado es igual a un titulo previamente ingresado en la lista
/// @param aAlbumes Es la lista de �lbumes
/// @param limAlbumes Define el tama�o de la lista de �lbumes
/// @param titulo Es el t�tulo ingresado a ser comparado
/// @param mensajeYaExistente Puntero al espacio de memoria donde se guardar� el mensaje de error en caso de que ya exista un �lbum
/// 			con el mismo titulo que el ingresado por el usuario
/// @return Retorna 1 (VERDADERO) si el titulo ingresado ya existe dentro de la lista, 0 (FALSO) si no estaba registrado, y -1 (ERROR) si hubo un error
int album_esAlbumExistente(eAlbum* aAlbumes, int limAlbumes, char* titulo, char* mensajeYaExistente);

/// @brief Solicita el a�o, el mes y el d�a al usuario, y luego de verificar los datos, los carga en un auxiliar
/// @param auxiliar Puntero al espacio de memoria donde se cargar� la fecha ingresada
/// @param mensaje Es el mensaje de pedido de ingreso de fecha a ser mostrado
/// @param anioMinimo Es el a�o minimo aceptado
/// @param anioMaximo es el a�o maximo aceptado
/// @return Retorna 0 (EXITO) si se logr� cargar una fecha v�lida en el auxiliar, -1 (ERROR) si no se consigui�
int album_cargarFecha(eAlbum* auxiliar, char* mensaje, int anioMinimo, int anioMaximo);

/// @brief Modifica los datos de un �lbum dentro de la lista a elecci�n
/// @param aAlbumes Es la lista de �lbumes donde se encuentra el �lbum a modificar
/// @param limAlbumes Define el tama�o de la lista
/// @param indiceBuscado Puntero al espacio de memoria donde se guardar� el indice del �lbum seleccionado para modificar
/// @param importePrevio Puntero al espacio de memoria donde se guardar� el importe del �lbum previo a su modificaci�n
/// @param aArtistas Es la lista de artistas
/// @param limArtistas Define el tama�o de la lista de artistas
/// @param aGeneros Es la lista de generos
/// @param limGeneros Define el tama�o de la lista de generos
/// @param aTiposArtistas Es la lista de tipos de artistas
/// @param limTiposArtistas Define el tama�o de la lista de tipos de artistas
/// @param aTiposAlbumes Es la lista de tipos de �lbumes
/// @param limTiposAlbumes Define el tama�o de la lista de tipos de �lbumes
/// @return Retorna 0 (EXITO) si se lograron modificar los datos el �lbum seleccionado, -1 (ERROR) si no se consigui�
int album_modificarAlbum(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
							eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes, float* totalImportes);

/// @brief Es el men� de opciones para modificar los datos del �lbum seleccionado
/// @param pElemento Puntero al espacio de memoria donde se cargar�n los nuevos datos modificados
/// @param cambio Puntero al espacio de memoria donde se determinara si se realizaron cambios en los datos del �lbum o no
/// @param aTiposAlbumes Es la lista de tipos de �lbumes
/// @param limTiposAlbumes Define el tama�o de la lista de tipos de �lbumes
/// @return Retorna 0 (EXITO) si se lograron cargar todos los datos modificados en el auxiliar o si no hubo cambios, -1 (ERROR) si no se consigui� cargar los datos
int album_modificarDatos(eAlbum* pElemento, int* cambios, eAlbum* aAlbumes, int limAlbumes, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes);

/// @brief Elimina un album a elecci�n (baja logica)
/// @param aAlbumes Es la lista de �lbumes donde se encuentra el �lbum a eliminar
/// @param limAlbumes Define el tama�o de la lista
/// @param indiceBuscado Puntero al espacio de memoria donde se guardar� el indice del �lbum seleccionado para eliminar
/// @param aArtistas Es la lista de artistas
/// @param limArtistas Define el tama�o de la lista de artistas
/// @param aGeneros Es la lista de generos
/// @param limGeneros Define el tama�o de la lista de generos
/// @param aTiposArtistas Es la lista de tipos de artistas
/// @param limTiposArtistas Define el tama�o de la lista de tipos de artistas
/// @param aTiposAlbumes Es la lista de tipos de �lbumes
/// @param limTiposAlbumes Define el tama�o de la lista de tipos de �lbumes
/// @return Retorna 0 (EXITO) si se logr� eliminar el album seleccionado, -1 (ERROR) si no se consiguio
int album_eliminarAlbum(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
							eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes, float* totalImportes, int* totalAlbumes);

/// @brief Imprime un solo �lbum de la lista (recibiendo los punteros de los elementos especificados)
/// @param album Puntero a un solo �lbum, que contiene los datos especificados
/// @param artista Puntero a un solo artista, que contiene los datos especificados
/// @param genero Puntero a un solo genero, que contiene los datos especificados
/// @param tipoArtista Puntero a un solo tipo de artista, que contiene los datos especificados
/// @param tipoAlbum Puntero a un solo tipo de �lbum, que contiene los datos especificados
/// @return Retorna 0 (EXITO) si se logr� imprimir el �lbum elegido correctamente, -1 (ERROR) si no se consigui�
int album_imprimirUnAlbumPorParametros(eAlbum* album, eArtista* artista, eGenero* genero, eTipoArtista* tipoArtista, eTipoAlbum* tipoAlbum);

/// @brief Imprime por pantalla los datos de un �lbum para saber si el usuario desea confirmar la acci�n (agregarlo, modificarlo o eliminarlo)
/// @param pElemento Puntero del elemento con los datos que se van a imprimir
/// @param mensajePrevio Mensaje que indica si se ingres�, encontr� o modific� el �lbum en cuesti�n
/// @param aArtistas Es la lista de artistas
/// @param limArtistas Define el tama�o de la lista de artistas
/// @param aGeneros Es la lista de generos
/// @param limGeneros Define el tama�o de la lista de generos
/// @param aTiposArtistas Es la lista de tipos de artistas
/// @param limTiposArtistas Define el tama�o de la lista de tipos de artistas
/// @param aTiposAlbumes Es la lista de tipos de �lbumes
/// @param limTiposAlbumes Define el tama�o de la lista de tipos de �lbumes
/// @return Retorna 0 (EXITO) si se lograron imprimir los datos del �lbum, -1 (ERROR) si no se consigui�
int album_vistaPrevia(eAlbum* pElemento, char* mensajePrevio, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
									eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes);

/// @brief Imprime toda la lista de �lbumes
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
/// @return Retorna 0 (EXITO) si se lograron imprimir todos los �lbumes de la lista correctamente, -1 (ERROR) si no se consigui�
int album_imprimirListaAlbumes(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
									eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes);



/// @brief Ordena la lista de �lbumes por c�digo de manera descendente
/// @param aAlbumes Es la lista de �lbumes
/// @param limAlbumes Define el tama�o de la lista de �lbumes
/// @return Retorna 0 (EXITO) si se logr� ordenar la lista, -1 (ERROR) si no se consigui�
int album_ordenarPorCodigo(eAlbum* aAlbumes, int limAlbumes);

/// @brief Ordena la lista de �lbumes por importe (descendente) y por t�tulo (ascendente)
/// @param aAlbumes Es la lista de �lbumes
/// @param limAlbumes Define el tama�o de la lista de �lbumes
/// @return Retorna 0 (EXITO) si se logr� ordenar la lista, -1 (ERROR) si no se consigui�
int album_ordenarPorImporteYTitulo(eAlbum* aAlbumes, int limTiposAlbumes);

/// @brief Ordena la lista de �lbumes por genero (ascendente) y por t�tulo (ascendente)
/// @param aAlbumes Es la lista de �lbumes
/// @param limAlbumes Define el tama�o de la lista de �lbumes
/// @return Retorna 0 (EXITO) si se logr� ordenar la lista, -1 (ERROR) si no se consigui�
int album_ordenarPorGeneroYTitulo(eAlbum* aAlbumes, int limite);

/// @brief Ordena la lista de �lbumes por genero (ascendente) y por c�digo (ascendente)
/// @param aAlbumes Es la lista de �lbumes
/// @param limAlbumes Define el tama�o de la lista de �lbumes
/// @return Retorna 0 (EXITO) si se logr� ordenar la lista, -1 (ERROR) si no se consigui�
int album_ordenarPorGeneroYCodigo(eAlbum* aAlbumes, int limite);




/// @brief Busca una coincidencia con la lista de artistas seg�n su id, y devuelve los datos del artista encontrado
/// @param unAlbum Es el �lbum a ser comparado
/// @param aArtistas Es la lista de artistas
/// @param limArtistas Define el tama�o de la lista de artistas
/// @param auxiliar Puntero al espacio de memoria donde se guardar�n los datos del artista obtenido
/// @return Retorna 0 (EXITO) si se logr� encontrar una coincidencia y devolver el artista obtenido, -1 (ERROR) si no se consigui�
int album_coincidirAlbumConArtista(eAlbum* unAlbum, eArtista* aArtistas, int limArtistas, eArtista* auxiliar);

/// @brief Busca una coincidencia con la lista de generos seg�n su id, y devuelve los datos del genero encontrado
/// @param unAlbum Es el �lbum a ser comparado
/// @param aGeneros Es la lista de generos
/// @param limGeneros Define el tama�o de la lista de generos
/// @param auxiliar Puntero al espacio de memoria donde se guardar�n los datos del genero obtenido
/// @return Retorna 0 (EXITO) si se logr� encontrar una coincidencia y devolver el genero obtenido, -1 (ERROR) si no se consigui�
int album_coincidirAlbumConGenero(eAlbum* unAlbum, eGenero* aGeneros, int limGeneros, eGenero* auxiliar);

/// @brief Busca una coincidencia con la lista de tipos de artistas seg�n su id, y devuelve los datos del tipo de artista encontrado
/// @param unAlbum Es el �lbum a ser comparado
/// @param aTiposArtistas Es la lista de tipos de artistas
/// @param limTiposArtistas Define el tama�o de la lista de tipos de artistas
/// @param auxiliar Puntero al espacio de memoria donde se guardar�n los datos del tipo de artista obtenido
/// @return Retorna 0 (EXITO) si se logr� encontrar una coincidencia y devolver el tipo de artista obtenido, -1 (ERROR) si no se consigui�
int album_coincidirAlbumConTipoArtista(eAlbum* unAlbum, eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoArtista* auxiliar);

/// @brief Busca una coincidencia con la lista de tipos de �lbumes seg�n su id, y devuelve los datos del tipo de �lbum encontrado
/// @param unAlbum Es el �lbum a ser comparado
/// @param aTiposAlbumes Es la lista de tipos de �lbumes
/// @param limTiposAlbumes Define el tama�o de la lista de tipos de �lbumes
/// @param auxiliar Puntero al espacio de memoria donde se guardar�n los datos del tipo de �lbum obtenido
/// @return Retorna 0 (EXITO) si se logr� encontrar una coincidencia y devolver el tipo de �lbum obtenido, -1 (ERROR) si no se consigui�
int album_coincidirAlbumConTipoAlbum(eAlbum* unAlbum, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes, eTipoAlbum* auxiliar);



/// @brief Calcula cu�l es el importe m�s alto dentro de la lista de �lbumes
/// @param aAlbumes Es la lista de �lbumes
/// @param limAlbumes Define el tama�o de la lista de �lbumes
/// @param pResultado Puntero al espacio de memoria donde se guardar� el importe m�s alto
/// @return Retorna 0 (EXITO) si se logr� encontrar el precio m�s alto de la lista, -1 (ERROR) si no se consigui�
int album_calcularImporteMaximo(eAlbum* aAlbumes, int limAlbumes, float* pResultado);

int album_calcularImporteMinimo(eAlbum* aAlbumes, int limAlbumes, float* importeMinimo);

/// @brief Obtiene el nombre del artista seg�n su id
/// @param aArtistas Es la lista de artistas
/// @param limArtistas Define el tama�o de la lista de artistas
/// @param nombreArtistaBuscado Puntero al espacio de memoria donde se guardar� el nombre obtenido del artista
/// @param idArtistaBuscado Es el id del artista del cual se buscar� el nombre
/// @return Retorna 0 (EXITO) si se logr� obtener el nombre del artista buscado, -1 (ERROR) si no se consigui�
int artista_conseguirNombre(eArtista* aArtistas, int limArtistas, char* nombreArtistaBuscado, int idArtistaBuscado);

/// @brief Obtiene la descripci�n del genero seg�n su id
/// @param aGeneros Es la lista de generos
/// @param limGeneros Define el tama�o de la lista de generos
/// @param descripcionGenero Puntero al espacio de memoria donde se guardar� la descripci�n obtenida del genero
/// @param idGeneroBuscado Es el id del genero del cual se buscar� la descripci�n
/// @return Retorna 0 (EXITO) si se logr� obtener la descripci�n del genero buscado, -1 (ERROR) si no se consigui�
int genero_conseguirDescipcion(eGenero* aGeneros, int limGeneros, char* descripcionGenero, int idGeneroBuscado);

/// @brief Obtiene la descripci�n del tipo de artista seg�n su id
/// @param aTiposArtistas Es la lista de tipos de artistas
/// @param limTiposArtistas Define el tama�o de la lista de tipos de artistas
/// @param descripcionTipoArtista Puntero al espacio de memoria donde se guardar� la descripci�n obtenida del tipo de artista
/// @param idTipoArtistaBuscado Es el id del tipo de artista del cual se buscar� la descripci�n
/// @return Retorna 0 (EXITO) si se logr� obtener la descripci�n del tipo de artista buscado, -1 (ERROR) si no se consigui�
int tipoArtista_conseguirDescipcion(eTipoArtista* aTiposArtistas, int limTiposArtistas, char* descripcionTipoArtista, int idTipoArtistaBuscado);

/// @brief Obtiene la descripci�n del tipo de �lbum seg�n su id
/// @param aTiposAlbumes Es la lista de tipos de �lbumes
/// @param limTiposAlbumes Define el tama�o de la lista de tipos de �lbumes
/// @param descripcionGenero Puntero al espacio de memoria donde se guardar� la descripci�n obtenida del tipo de �lbum
/// @param idGeneroBuscado Es el id del tipo de �lbum del cual se buscar� la descripci�n
/// @return Retorna 0 (EXITO) si se logr� obtener la descripci�n del tipo de �lbum buscado, -1 (ERROR) si no se consigui�
int tipoAlbum_conseguirDescipcion(eTipoAlbum* aTiposAlbumes, int limTiposAlbumes, char* descripcionTipoAlbum, int idTipoAlbumBuscado);




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


int album_contarAlbumesDeBandasGeneroDeterminado(eAlbum* aAlbumes, int limAlbumes, eGenero* aGeneros, int limGeneros,
											eTipoArtista* aTiposArtistas, int limTiposArtistas, int* pResultado, char* descripcionGenero);











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

int Listado_albumesAnterioresAnioFijo(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
											eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes, int anioFijo);

int Listado_albumesPosterioresAnioFijo(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
											eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes, int anioFijo);

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
int Listado_albumesSuperioresImportePromedio(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
												eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes,
												float totalImportes, int totalAlbumes);


int Listado_albumesInferioresImportePromedio(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
												eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes,
												float totalImportes, int totalAlbumes);

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
int Listado_albumesCadaArtista(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
											eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes);

int Listado_albumesCadaGenero(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
											eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes);

int Listado_albumesCadaTipoArtista(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
											eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes);

int Listado_albumesCadaTipoAlbum(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
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
int Listado_albumesMasCaros(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
										eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes);

int Listado_albumesMasBaratos(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
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







#endif /* ALBUM_H_ */
