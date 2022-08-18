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

#define MSJ_MENU_PRINCIPAL "Seleccione una opcion\n1. Agregar álbum\n2. Modificar álbum\n3. Eliminar álbum\n4. Informes\n5. Listados\n6. Salir\n\n"
#define MSJ_MENU_MODIFICAR "¿Qué desea modificar?\n  1- Título\n  2- Fecha de publicación\n  3- Importe\n  4- Tipo de álbum\n  5- Finalizar cambios\n\n"
#define MSJ_MENU_INFORME "¿Qué desea informar?\n  1- Total y promedio de los importes, y cuántos álbumes superan ese promedio.\n  2- Cantidad de álbumes cuya fecha de publicación es anterior a 1/1/2000.\n  3- Informar la cantidad de solistas de un año determinado.\n  4- Informar la cantidad de álbumes de bandas de un género determinado.\n\n"
#define MSJ_MENU_LISTADO_01_05 "¿Qué listado desea ver?\n  1- Todos los géneros.\n  2- Todos los tipos de artistas musicales.\n  3- Todos los artistas.\n  4- Todos los álbumes.\n  5- Realizar un solo listado de los álbumes ordenados por los siguientes criterios:\n\tImporte (descendentemente) y Título (ascendentemente)\n"
#define MSJ_MENU_LISTADO_06_10 "  6- Todos los álbumes cuya fecha de publicación es menor a 1/1/2000.\n  7- Todos los álbumes que superan el promedio de los importes.\n  8- Todos los álbumes de cada artista.\n  9- Todos los álbumes de un año determinado.\n  10- El álbum o los álbumes más caros.\n"
#define MSJ_MENU_LISTADO_12_15 "  11- Listar todos los tipos de álbumes.\n  12- Listar todos los álbumes que no sean de vinilo.\n  13- Listar todos los álbumes de vinilo que correspondan a un artista determinado.\n  14- Realizar un solo listado de todos los álbumes de un tipo de álbum determinado y de un género determinado.\n  15- Realizar un solo listado de todos los álbumes de un artista determinado y de un tipo de álbum determinado.\n"

#define MSJ_CODIGO_MODIFICAR "Ingrese el código del álbum que desea modificar:"
#define MSJ_CODIGO_ELIMINAR "Ingrese el código del álbum que desea eliminar:"
#define MSJ_ERROR_OPCION  "No es una opción válida."
#define MSJ_ERROR_CODIGO "No es un código válido."
#define MSJ_CONFIRMAR_AGREGADO "¿Está seguro/a de quiere agregar este álbum?\n  1- Si\n  0- No\n\n"
#define MSJ_CONFIRMAR_MODIFICACION "¿Está seguro/a de quiere realizar las modificaciones?\n  1- Si\n  0- No\n\n"
#define MSJ_CONFIRMAR_ELIMINADO "¿Está seguro/a de quiere eliminar este álbum?\n  1- Si\n  0- No\n\n"
#define MSJ_INGRESO_ANIO "Ingrese el año: (entre %d y %d)."
#define MSJ_INGRESO_MES_ANTERIOR "Ingrese el mes: (del 1 al %d)"
#define MSJ_VISTA_NUEVO "Vista previa del álbum ingresado: 	(Tiene código 0 (cero). Se le asignará su código correspondiente una vez que se agregue definitivamente a la lista)."
#define MSJ_VISTA_MODIFICADO "Vista previa de los cambios realizados:"
#define MSJ_VISTA_ENCONTRADO "Se encontró el siguiente álbum con el código ingresado:"


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
/// @return Retorna 0 (EXITO) si logro finalizar la operatoria, -1 (ERROR) si no se consiguió
int album_menuPrincipal(void);

/// @brief Inicializa todas la posiciones de la lista de álbumes como vacías
/// @param aAlbumes Es la lista de álbumes, a la cual se le inicializaran las todas las posiones como vacias
/// @param limAlbumes Define el tamaño de la lista
/// @return Retorna 0 (EXITO) si se lograron inicializar todas las posiciones del vector, -1 (ERROR) si no se consiguió
int album_inicializarLista(eAlbum* aAlbumes, int limTiposAlbumes);

/// @brief Busca la proxima posicion que se encuentre vacia, dentro del vector
/// @param aAlbumes Es la lista de álbumes en el que se buscara la posicion vacia
/// @param limAlbumes Define el tamaño de la lista
/// @return Retorna 0 (EXITO) si se logró encontrar alguna posicion vacia, -1 (ERROR) si no se consiguió
int album_buscarIndiceVacio(eAlbum* aAlbumes, int limAlbumes);

/// @brief Busca la posicion de un album dentro de la lista, segun el codigo ingresado
/// @param aAlbumes Es la lista de álbumes en el que se buscara la posicion con el codigo
/// @param limAlbumes Define el tamaño de la lista
/// @param codigo Es el codigo del álbum a ser buscado
/// @return Retorna 0 (EXITO) si se logró encontrar el álbum con el codigo ingresado, -1 (ERROR) si no se consiguió
int album_buscarPorCodigo(eAlbum* aAlbumes, int limAlbumes, int codigo);


/// @brief Hardcodea los datos de un álbum y lo agrega a la lista
/// @param aAlbumes Es la lista de álbumes donde se agregará el album hardcodeado
/// @param limAlbumes Define el tamaño de la lista de álbumes
/// @param indiceLibre Es la posición en el vector donde se agregará el album
/// @param codigo Es el código hardcodeado que se le asignará al album
/// @param titulo Es el título hardcodeado que se le asignará al album
/// @param dia Es el día de publicación hardcodeado que se le asignará al album
/// @param mes Es el mes de publicación  hardcodeado que se le asignará al album
/// @param anio Es el año de publicación hardcodeado que se le asignará al album
/// @param importe Es el importe hardcodeado que se le asignará al album
/// @param idArtista Es el id del artista hardcodeado que se le asignará al album
/// @param idTipoArtista Es el id del tipo de artista hardcodeado que se le asignará al album
/// @param idGenero Es el id del genero hardcodeado que se le asignará al album
/// @param idTipoAlbum Es el id del tipo de album hardcodeado que se le asignará al album
/// @return Retorna 0 (EXITO) si se logró agregar el álbum hardcodeado a la lista, -1 (ERROR) si no se consiguió
int album_agregarAlbumForzado(eAlbum* aAlbumes, int limAlbumes, int indiceLibre, int codigo, char* titulo, int dia, int mes, int anio,
								float importe, int idArtista, int idGenero, int idTipoArtista, int idTipoAlbum);

/// @brief Agrega un album nuevo a la lista
/// @param aAlbumes Es la lista de álbumes donde se agregará el nuevo álbum agregado
/// @param limAlbumes Define el tamaño de la lista
/// @param indiceNuevo Puntero al espacio de memoria donde se guardará el indice que ocupará el album
/// @param aArtistas Es la lista de artistas
/// @param limArtistas Define el tamaño de la lista de artistas
/// @param aGeneros Es la lista de generos
/// @param limGeneros Define el tamaño de la lista de generos
/// @param aTiposArtistas Es la lista de tipos de artistas
/// @param limTiposArtistas Define el tamaño de la lista de tipos de artistas
/// @param aTiposAlbumes Es la lista de tipos de álbumes
/// @param limTiposAlbumes Define el tamaño de la lista de tipos de álbumes
/// @return Retorna 0 (EXITO) si se logró agregar el album a la lista, -1 (ERROR) si no se consiguió
int album_agregarAlbum(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
							eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes, float* totalImportes, int* totalAlbumes);
/// @brief Solicita los datos al usuario y los carga dentro de un álbum auxiliar, para luego cargarlos al nuevo álbum
/// @param pElemento Puntero al espacio de memoria donde se cargarán los datos ingresados
/// @param aAlbumes Es la lista de álbumes
/// @param limAlbumes Define el tamaño de la lista
/// @param aArtistas Es la lista de artistas
/// @param limArtistas Define el tamaño de la lista de artistas
/// @param aGeneros Es la lista de generos
/// @param limGeneros Define el tamaño de la lista de generos
/// @param aTiposArtistas Es la lista de tipos de artistas
/// @param limTiposArtistas Define el tamaño de la lista de tipos de artistas
/// @param aTiposAlbumes Es la lista de tipos de álbumes
/// @param limTiposAlbumes Define el tamaño de la lista de tipos de álbumes
/// @return Retorna 0 (EXITO) si se lograron cargar todos los datos ingresados en el auxiliar, -1 (ERROR) si no se consiguió
int album_cargarDatos(eAlbum* pElemento, eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
							eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes);

int album_cargarTitulo(eAlbum* auxiliar, int largoTitulo, eAlbum* aAlbumes, int limAlbumes, char* mensaje, char* mensajeError, char* mensajeYaExistente, int reintentos);

/// @brief Verifica si el titulo ingresado es igual a un titulo previamente ingresado en la lista
/// @param aAlbumes Es la lista de álbumes
/// @param limAlbumes Define el tamaño de la lista de álbumes
/// @param titulo Es el título ingresado a ser comparado
/// @param mensajeYaExistente Puntero al espacio de memoria donde se guardará el mensaje de error en caso de que ya exista un álbum
/// 			con el mismo titulo que el ingresado por el usuario
/// @return Retorna 1 (VERDADERO) si el titulo ingresado ya existe dentro de la lista, 0 (FALSO) si no estaba registrado, y -1 (ERROR) si hubo un error
int album_esAlbumExistente(eAlbum* aAlbumes, int limAlbumes, char* titulo, char* mensajeYaExistente);

/// @brief Solicita el año, el mes y el día al usuario, y luego de verificar los datos, los carga en un auxiliar
/// @param auxiliar Puntero al espacio de memoria donde se cargará la fecha ingresada
/// @param mensaje Es el mensaje de pedido de ingreso de fecha a ser mostrado
/// @param anioMinimo Es el año minimo aceptado
/// @param anioMaximo es el año maximo aceptado
/// @return Retorna 0 (EXITO) si se logró cargar una fecha válida en el auxiliar, -1 (ERROR) si no se consiguió
int album_cargarFecha(eAlbum* auxiliar, char* mensaje, int anioMinimo, int anioMaximo);

/// @brief Modifica los datos de un álbum dentro de la lista a elección
/// @param aAlbumes Es la lista de álbumes donde se encuentra el álbum a modificar
/// @param limAlbumes Define el tamaño de la lista
/// @param indiceBuscado Puntero al espacio de memoria donde se guardará el indice del álbum seleccionado para modificar
/// @param importePrevio Puntero al espacio de memoria donde se guardará el importe del álbum previo a su modificación
/// @param aArtistas Es la lista de artistas
/// @param limArtistas Define el tamaño de la lista de artistas
/// @param aGeneros Es la lista de generos
/// @param limGeneros Define el tamaño de la lista de generos
/// @param aTiposArtistas Es la lista de tipos de artistas
/// @param limTiposArtistas Define el tamaño de la lista de tipos de artistas
/// @param aTiposAlbumes Es la lista de tipos de álbumes
/// @param limTiposAlbumes Define el tamaño de la lista de tipos de álbumes
/// @return Retorna 0 (EXITO) si se lograron modificar los datos el álbum seleccionado, -1 (ERROR) si no se consiguió
int album_modificarAlbum(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
							eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes, float* totalImportes);

/// @brief Es el menú de opciones para modificar los datos del álbum seleccionado
/// @param pElemento Puntero al espacio de memoria donde se cargarán los nuevos datos modificados
/// @param cambio Puntero al espacio de memoria donde se determinara si se realizaron cambios en los datos del álbum o no
/// @param aTiposAlbumes Es la lista de tipos de álbumes
/// @param limTiposAlbumes Define el tamaño de la lista de tipos de álbumes
/// @return Retorna 0 (EXITO) si se lograron cargar todos los datos modificados en el auxiliar o si no hubo cambios, -1 (ERROR) si no se consiguió cargar los datos
int album_modificarDatos(eAlbum* pElemento, int* cambios, eAlbum* aAlbumes, int limAlbumes, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes);

/// @brief Elimina un album a elección (baja logica)
/// @param aAlbumes Es la lista de álbumes donde se encuentra el álbum a eliminar
/// @param limAlbumes Define el tamaño de la lista
/// @param indiceBuscado Puntero al espacio de memoria donde se guardará el indice del álbum seleccionado para eliminar
/// @param aArtistas Es la lista de artistas
/// @param limArtistas Define el tamaño de la lista de artistas
/// @param aGeneros Es la lista de generos
/// @param limGeneros Define el tamaño de la lista de generos
/// @param aTiposArtistas Es la lista de tipos de artistas
/// @param limTiposArtistas Define el tamaño de la lista de tipos de artistas
/// @param aTiposAlbumes Es la lista de tipos de álbumes
/// @param limTiposAlbumes Define el tamaño de la lista de tipos de álbumes
/// @return Retorna 0 (EXITO) si se logró eliminar el album seleccionado, -1 (ERROR) si no se consiguio
int album_eliminarAlbum(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
							eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes, float* totalImportes, int* totalAlbumes);

/// @brief Imprime un solo álbum de la lista (recibiendo los punteros de los elementos especificados)
/// @param album Puntero a un solo álbum, que contiene los datos especificados
/// @param artista Puntero a un solo artista, que contiene los datos especificados
/// @param genero Puntero a un solo genero, que contiene los datos especificados
/// @param tipoArtista Puntero a un solo tipo de artista, que contiene los datos especificados
/// @param tipoAlbum Puntero a un solo tipo de álbum, que contiene los datos especificados
/// @return Retorna 0 (EXITO) si se logró imprimir el álbum elegido correctamente, -1 (ERROR) si no se consiguió
int album_imprimirUnAlbumPorParametros(eAlbum* album, eArtista* artista, eGenero* genero, eTipoArtista* tipoArtista, eTipoAlbum* tipoAlbum);

/// @brief Imprime por pantalla los datos de un álbum para saber si el usuario desea confirmar la acción (agregarlo, modificarlo o eliminarlo)
/// @param pElemento Puntero del elemento con los datos que se van a imprimir
/// @param mensajePrevio Mensaje que indica si se ingresó, encontró o modificó el álbum en cuestión
/// @param aArtistas Es la lista de artistas
/// @param limArtistas Define el tamaño de la lista de artistas
/// @param aGeneros Es la lista de generos
/// @param limGeneros Define el tamaño de la lista de generos
/// @param aTiposArtistas Es la lista de tipos de artistas
/// @param limTiposArtistas Define el tamaño de la lista de tipos de artistas
/// @param aTiposAlbumes Es la lista de tipos de álbumes
/// @param limTiposAlbumes Define el tamaño de la lista de tipos de álbumes
/// @return Retorna 0 (EXITO) si se lograron imprimir los datos del álbum, -1 (ERROR) si no se consiguió
int album_vistaPrevia(eAlbum* pElemento, char* mensajePrevio, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
									eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes);

/// @brief Imprime toda la lista de álbumes
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
/// @return Retorna 0 (EXITO) si se lograron imprimir todos los álbumes de la lista correctamente, -1 (ERROR) si no se consiguió
int album_imprimirListaAlbumes(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
									eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes);



/// @brief Ordena la lista de álbumes por código de manera descendente
/// @param aAlbumes Es la lista de álbumes
/// @param limAlbumes Define el tamaño de la lista de álbumes
/// @return Retorna 0 (EXITO) si se logró ordenar la lista, -1 (ERROR) si no se consiguió
int album_ordenarPorCodigo(eAlbum* aAlbumes, int limAlbumes);

/// @brief Ordena la lista de álbumes por importe (descendente) y por título (ascendente)
/// @param aAlbumes Es la lista de álbumes
/// @param limAlbumes Define el tamaño de la lista de álbumes
/// @return Retorna 0 (EXITO) si se logró ordenar la lista, -1 (ERROR) si no se consiguió
int album_ordenarPorImporteYTitulo(eAlbum* aAlbumes, int limTiposAlbumes);

/// @brief Ordena la lista de álbumes por genero (ascendente) y por título (ascendente)
/// @param aAlbumes Es la lista de álbumes
/// @param limAlbumes Define el tamaño de la lista de álbumes
/// @return Retorna 0 (EXITO) si se logró ordenar la lista, -1 (ERROR) si no se consiguió
int album_ordenarPorGeneroYTitulo(eAlbum* aAlbumes, int limite);

/// @brief Ordena la lista de álbumes por genero (ascendente) y por código (ascendente)
/// @param aAlbumes Es la lista de álbumes
/// @param limAlbumes Define el tamaño de la lista de álbumes
/// @return Retorna 0 (EXITO) si se logró ordenar la lista, -1 (ERROR) si no se consiguió
int album_ordenarPorGeneroYCodigo(eAlbum* aAlbumes, int limite);




/// @brief Busca una coincidencia con la lista de artistas según su id, y devuelve los datos del artista encontrado
/// @param unAlbum Es el álbum a ser comparado
/// @param aArtistas Es la lista de artistas
/// @param limArtistas Define el tamaño de la lista de artistas
/// @param auxiliar Puntero al espacio de memoria donde se guardarán los datos del artista obtenido
/// @return Retorna 0 (EXITO) si se logró encontrar una coincidencia y devolver el artista obtenido, -1 (ERROR) si no se consiguió
int album_coincidirAlbumConArtista(eAlbum* unAlbum, eArtista* aArtistas, int limArtistas, eArtista* auxiliar);

/// @brief Busca una coincidencia con la lista de generos según su id, y devuelve los datos del genero encontrado
/// @param unAlbum Es el álbum a ser comparado
/// @param aGeneros Es la lista de generos
/// @param limGeneros Define el tamaño de la lista de generos
/// @param auxiliar Puntero al espacio de memoria donde se guardarán los datos del genero obtenido
/// @return Retorna 0 (EXITO) si se logró encontrar una coincidencia y devolver el genero obtenido, -1 (ERROR) si no se consiguió
int album_coincidirAlbumConGenero(eAlbum* unAlbum, eGenero* aGeneros, int limGeneros, eGenero* auxiliar);

/// @brief Busca una coincidencia con la lista de tipos de artistas según su id, y devuelve los datos del tipo de artista encontrado
/// @param unAlbum Es el álbum a ser comparado
/// @param aTiposArtistas Es la lista de tipos de artistas
/// @param limTiposArtistas Define el tamaño de la lista de tipos de artistas
/// @param auxiliar Puntero al espacio de memoria donde se guardarán los datos del tipo de artista obtenido
/// @return Retorna 0 (EXITO) si se logró encontrar una coincidencia y devolver el tipo de artista obtenido, -1 (ERROR) si no se consiguió
int album_coincidirAlbumConTipoArtista(eAlbum* unAlbum, eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoArtista* auxiliar);

/// @brief Busca una coincidencia con la lista de tipos de álbumes según su id, y devuelve los datos del tipo de álbum encontrado
/// @param unAlbum Es el álbum a ser comparado
/// @param aTiposAlbumes Es la lista de tipos de álbumes
/// @param limTiposAlbumes Define el tamaño de la lista de tipos de álbumes
/// @param auxiliar Puntero al espacio de memoria donde se guardarán los datos del tipo de álbum obtenido
/// @return Retorna 0 (EXITO) si se logró encontrar una coincidencia y devolver el tipo de álbum obtenido, -1 (ERROR) si no se consiguió
int album_coincidirAlbumConTipoAlbum(eAlbum* unAlbum, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes, eTipoAlbum* auxiliar);



/// @brief Calcula cuál es el importe más alto dentro de la lista de álbumes
/// @param aAlbumes Es la lista de álbumes
/// @param limAlbumes Define el tamaño de la lista de álbumes
/// @param pResultado Puntero al espacio de memoria donde se guardará el importe más alto
/// @return Retorna 0 (EXITO) si se logró encontrar el precio más alto de la lista, -1 (ERROR) si no se consiguió
int album_calcularImporteMaximo(eAlbum* aAlbumes, int limAlbumes, float* pResultado);

int album_calcularImporteMinimo(eAlbum* aAlbumes, int limAlbumes, float* importeMinimo);

/// @brief Obtiene el nombre del artista según su id
/// @param aArtistas Es la lista de artistas
/// @param limArtistas Define el tamaño de la lista de artistas
/// @param nombreArtistaBuscado Puntero al espacio de memoria donde se guardará el nombre obtenido del artista
/// @param idArtistaBuscado Es el id del artista del cual se buscará el nombre
/// @return Retorna 0 (EXITO) si se logró obtener el nombre del artista buscado, -1 (ERROR) si no se consiguió
int artista_conseguirNombre(eArtista* aArtistas, int limArtistas, char* nombreArtistaBuscado, int idArtistaBuscado);

/// @brief Obtiene la descripción del genero según su id
/// @param aGeneros Es la lista de generos
/// @param limGeneros Define el tamaño de la lista de generos
/// @param descripcionGenero Puntero al espacio de memoria donde se guardará la descripción obtenida del genero
/// @param idGeneroBuscado Es el id del genero del cual se buscará la descripción
/// @return Retorna 0 (EXITO) si se logró obtener la descripción del genero buscado, -1 (ERROR) si no se consiguió
int genero_conseguirDescipcion(eGenero* aGeneros, int limGeneros, char* descripcionGenero, int idGeneroBuscado);

/// @brief Obtiene la descripción del tipo de artista según su id
/// @param aTiposArtistas Es la lista de tipos de artistas
/// @param limTiposArtistas Define el tamaño de la lista de tipos de artistas
/// @param descripcionTipoArtista Puntero al espacio de memoria donde se guardará la descripción obtenida del tipo de artista
/// @param idTipoArtistaBuscado Es el id del tipo de artista del cual se buscará la descripción
/// @return Retorna 0 (EXITO) si se logró obtener la descripción del tipo de artista buscado, -1 (ERROR) si no se consiguió
int tipoArtista_conseguirDescipcion(eTipoArtista* aTiposArtistas, int limTiposArtistas, char* descripcionTipoArtista, int idTipoArtistaBuscado);

/// @brief Obtiene la descripción del tipo de álbum según su id
/// @param aTiposAlbumes Es la lista de tipos de álbumes
/// @param limTiposAlbumes Define el tamaño de la lista de tipos de álbumes
/// @param descripcionGenero Puntero al espacio de memoria donde se guardará la descripción obtenida del tipo de álbum
/// @param idGeneroBuscado Es el id del tipo de álbum del cual se buscará la descripción
/// @return Retorna 0 (EXITO) si se logró obtener la descripción del tipo de álbum buscado, -1 (ERROR) si no se consiguió
int tipoAlbum_conseguirDescipcion(eTipoAlbum* aTiposAlbumes, int limTiposAlbumes, char* descripcionTipoAlbum, int idTipoAlbumBuscado);




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


int album_contarAlbumesDeBandasGeneroDeterminado(eAlbum* aAlbumes, int limAlbumes, eGenero* aGeneros, int limGeneros,
											eTipoArtista* aTiposArtistas, int limTiposArtistas, int* pResultado, char* descripcionGenero);











/// @brief Es el menú de opciones de listados
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
/// @return Retorna 0 (EXITO) si se logró mostrar el listado seleccionado correctamente, -1 (ERROR) si no se consiguió
int album_menuListado(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
					eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes, float totalImportes, int totalAlbumes);

/// @brief Imprime la lista de todos los generos que hay
/// @param aGeneros Es la lista de generos
/// @param limGeneros Define el tamaño de la lista de generos
/// @return Retorna 0 (EXITO) si se logró imprimir la lista completa de generos, -1 (ERROR) si no se consiguió
int genero_imprimirListaGeneros(eGenero* aGeneros, int limGeneros);

/// @brief Imprime la lista de todos los tipos de artistas que hay
/// @param aTiposArtistas Es la lista de tipos de artistas
/// @param limTiposArtistas Define el tamaño de la lista de tipos de artistas
/// @return Retorna 0 (EXITO) si se logró imprimir la lista completa de tipos de artistas, -1 (ERROR) si no se consiguió
int tipoArtista_imprimirListaTiposArtistas(eTipoArtista* aTiposArtistas, int limTiposArtistas);

/// @brief Imprime la lista de todos los artistas que hay
/// @param aArtistas Es la lista de artistas
/// @param limArtistas Define el tamaño de la lista de artistas
/// @return Retorna 0 (EXITO) si se logró imprimir la lista completa de artistas, -1 (ERROR) si no se consiguió
int artista_imprimirListaArtistas(eArtista* aArtistas, int limArtistas);

/// @brief Imprime un listado solo con los álbumes que se hayan publicado antes del año ingresado
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
/// @return Retorna 0 (EXITO) si se logró imprimir el listado correctamente, -1 (ERROR) si no se consiguió

int Listado_albumesAnterioresAnioFijo(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
											eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes, int anioFijo);

int Listado_albumesPosterioresAnioFijo(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
											eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes, int anioFijo);

/// @brief Imprime un listado solo con los álbumes que superen el importe promedio
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
/// @param importePromedio Es el importe promedio de todos los importes ingresados
/// @return Retorna 0 (EXITO) si se logró imprimir el listado correctamente, -1 (ERROR) si no se consiguió
int Listado_albumesSuperioresImportePromedio(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
												eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes,
												float totalImportes, int totalAlbumes);


int Listado_albumesInferioresImportePromedio(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
												eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes,
												float totalImportes, int totalAlbumes);

/// @brief Imprime un listado con todos los álbumes de cada artista
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
/// @return Retorna 0 (EXITO) si se logró imprimir el listado correctamente, -1 (ERROR) si no se consiguió
int Listado_albumesCadaArtista(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
											eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes);

int Listado_albumesCadaGenero(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
											eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes);

int Listado_albumesCadaTipoArtista(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
											eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes);

int Listado_albumesCadaTipoAlbum(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
											eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes);

/// @brief Imprime un listado con todos los álbumes que se hayan publicado en un año determinado
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
/// @return Retorna 0 (EXITO) si se logró imprimir el listado correctamente, -1 (ERROR) si no se consiguió
int album_listadoAlbumesAnioDeterminado(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
											eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes);

/// @brief Imprime un listado con todos los álbumes cuyo importe coincida con el importe más alto de la lista
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
/// @return Retorna 0 (EXITO) si se logró imprimir el listado correctamente, -1 (ERROR) si no se consiguió
int Listado_albumesMasCaros(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
										eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes);

int Listado_albumesMasBaratos(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
										eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes);

/// @brief Imprime la lista de todos los tipos de álbumes que hay
/// @param aTiposAlbumes Es la lista de tipos de álbumes
/// @param limTiposAlbumes Define el tamaño de la lista de tipos de álbumes
/// @return Retorna 0 (EXITO) si se logró imprimir la lista completa de tipos de álbumes, -1 (ERROR) si no se consiguió
int tipoAlbum_imprimirListaTiposAlbumes(eTipoAlbum* aTiposAlbumes, int limTiposAlbumes);

/// @brief Imprime un listado con todos los álbumes que no sean de vinilo
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
/// @return Retorna 0 (EXITO) si se logró imprimir el listado correctamente, -1 (ERROR) si no se consiguió
int album_listadoAlbumesNoSonVinilos(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
											eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes);

/// @brief Imprime un listado con todos los álbumes de un artista determinado y que a la vez sean de vinilo
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
/// @return Retorna 0 (EXITO) si se logró imprimir el listado correctamente, -1 (ERROR) si no se consiguió
int album_listadoAlbumesVinilosArtistaDeterminado(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
														eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes);

/// @brief Imprime un listado con todos los álbumes que sean de un genero determinado y un tipo de álbum determinado
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
/// @return Retorna 0 (EXITO) si se logró imprimir el listado correctamente, -1 (ERROR) si no se consiguió
int album_listadoAlbumesGeneroYTipoAlbumDeterminados(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
														eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes);

/// @brief Imprime un listado con todos los álbumes que sean de un artista determinado y un tipo de álbum determinado
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
/// @return Retorna 0 (EXITO) si se logró imprimir el listado correctamente, -1 (ERROR) si no se consiguió
int album_listadoAlbumesArtistaYTipoAlbumDeterminados(eAlbum* aAlbumes, int limAlbumes, eArtista* aArtistas, int limArtistas, eGenero* aGeneros, int limGeneros,
														eTipoArtista* aTiposArtistas, int limTiposArtistas, eTipoAlbum* aTiposAlbumes, int limTiposAlbumes);







#endif /* ALBUM_H_ */
