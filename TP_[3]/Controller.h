#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Input.h"
#include "parser.h"
#include "Validations.h"


/** \brief - Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 * \param path char* - Ruta del archivo a cargar
 * \param pArrayListPassenger LinkedList* - Puntero al vector de pasajeros
 * \return int - Retorna 0 (EXITO) - Si se pudieron cargar los datos desde el archivo
 * 						-1 (ERROR) - La ruta del Archivo no es valida
 * 						-2 (ERROR) - El puntero a LinkedList es NULL
 * 						-3 (ERROR) - No se pudo abrir el Archivo
 * 						-4 (ERROR) - No se pudieron parsear los Datos del Archivo
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);

/** \brief - Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 * \param path char* - Ruta del archivo a cargar
 * \param pArrayListPassenger LinkedList* - Puntero al vector de pasajeros
 * \return int - Retorna 0 (EXITO) - Si se pudieron cargar los datos desde el archivo
 * 						-1 (ERROR) - La ruta del Archivo no es valida
 * 						-2 (ERROR) - El puntero a LinkedList es NULL
 * 						-3 (ERROR) - No se pudo abrir el Archivo
 * 						-4 (ERROR) - No se pudieron parsear los Datos del Archivo
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);

/** \brief - Alta de pasajero. Solicita los datos al usuario y agrega el pasajero al vector
 * \param pArrayListPassenger LinkedList* - Puntero al vector de pasajeros
 * \return int - Retorna 0 (EXITO) - Si se pudieron cargar los datos y se pudo agregar el pasajero a la lista
 * 						-1 (ERROR) - El puntero a LinkedList es NULL
 * 						-2 (ERROR) - No se pudo crear el Pasajero
 * 						-3 (ERROR) - Falló la carga de datos
 * 						-4 (ERROR) - No se obtuvo confirmación. Volvió al menú principal
 * 						-5 (ERROR) - Se canceló la operación. No se agregó el pasajero
 * 						-6 (ERROR) - No se pudieron setear los datos correctamente
 * 						-7 (ERROR) - Se generó un ID invalido
 * 						-8 (ERROR) - No se pudo agregar el pasajero a la lista
 */
int controller_addPassenger(LinkedList* pArrayListPassenger);

/** \brief - Modificar datos de pasajero. Modifica los datos de un pasajero dentro de la lista
 * \param pArrayListPassenger LinkedList* - Puntero al vector de pasajeros
 * \return int - Retorna 0 (EXITO) - Si se pudieron modificar los datos del Pasajero
 * 						-1 (ERROR) - El puntero a LinkedList es NULL
 * 						-2 (ERROR) - No se ingresó ningun ID para modificar
 * 						-3 (ERROR) - No se pudo encontrar el ID buscado
 * 						-4 (ERROR) - No se pudo obtener el pasajero
 * 						-5 (ERROR) - No se pudieron obtener los datos del pasajero
 * 						-6 (ERROR) - No se ingresó una opcion correcta para modificar
 * 						-7 (ERROR) - No se realizó ningun cambio en los datos del pasajero
 * 						-8 (ERROR) - No se obtuvo ninguna confirmación. Volvió al menú principal
 * 						-9 (ERROR) - Se canceló la operación. No se modificaron los datos del pasajero
 * 						-10 (ERROR) - No se pudieron setear los datos correctamente
 */
int controller_editPassenger(LinkedList* pArrayListPassenger);

/** \brief - Baja de pasajero. Elimina un pasajero del sistema
 * \param pArrayListPassenger LinkedList* - Puntero al vector de pasajeros
 * \return int - Retorna 0 (EXITO) - Si se pudo eliminar el pasajero del sistema correctamente
 * 						 1 (EXITO) - Si se pudo eliminar la lista completa del sistema correctamente
 * 						-1 (ERROR) - El puntero a LinkedList es NULL
 * 						-2 (ERROR) - No se encontró un ID correcto en la lista
 * 						-3 (ERROR) - Falló la impresión, no se pudo mostrar la lista
 * 						-4 (ERROR) - No se ingresó una opcion de eliminado correcta
 * 						-5 (ERROR) - No se ingresó ningun ID para eliminar
 * 						-6 (ERROR) - No se pudo encontrar el ID buscado
 * 						-7 (ERROR) - No se pudo obtener el pasajero
 * 						-8 (ERROR) - No se obtuvo ninguna confirmación. Volvió al menú principal
 * 						-9 (ERROR) - Se canceló la operación. No se eliminó el pasajero
 * 						-10 (ERROR) - Se eliminó el pasajero de memoria pero no se pudo eliminar de la lista
 * 						-11 (ERROR) - Se canceló la operación. No se eliminó la lista
 * 						-12 (ERROR) - No se pudo eliminar la lista
 * 						-13 (ERROR) - Se eliminó de memoria pero no se pudo eliminar la lista
 */
int controller_removePassenger(LinkedList* pArrayListPassenger);

/** \brief - Listar pasajeros. Imprime todos los pasajeros de la lista
 * \param pArrayListPassenger LinkedList* - Puntero al vector de pasajeros
 * \return int - Retorna 0 (EXITO) - Si se pudo listar los pasajeros correctamente
 * 						 -1 (ERROR) - El puntero a LinkedList es NULL
 * 						 -2 (ERROR) - La lista está vacia, no hay pasajeros
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger);

/** \brief - Listar pasajeros. Imprime los datos del listado de pasajeros
 * \param pArrayListPassenger LinkedList* - Puntero al vector de pasajeros
 * \param indice int - Indice del pasajero
 * \return int - Retorna 0 (EXITO) - Si se pudo listar al pasajero correctamente
 * 						 -1 (ERROR) - Si: El puntero a LinkedList es NULL, el indice es incorrecto,
 * 										  no se pudo obtener el pasajero o no se pudo obtener los datos del pasajero correctamente
 */
int Controller_imprimirElemento(LinkedList* pArrayListPassenger,int indice);

/** \brief - Ordenar pasajeros. Ordena la lista de pasajero segun el criterio y el orden que elija el usuario
 * \param pArrayListPassenger LinkedList* - Puntero al vector de pasajeros
 * \return int - Retorna 0 (EXITO) - Si se pudo ordenar la lista de pasajeros correctamente
 * 						-1 (ERROR) - El puntero a LinkedList es NULL
 * 						-2 (ERROR) - No se ingresó un criterio por el cual ordenar la lista
 * 						-3 (ERROR) - Volvió al menú principal
 * 						-4 (ERROR) - No se ingresó el orden para ordenar la lista
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger);

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 * \param path char* - Ruta del archivo a cargar
 * \param pArrayListPassenger LinkedList* - Puntero al vector de pasajeros
 * \return int - Retorna 0 (EXITO) - Si se pudieron cargar los datos desde el archivo
 * 						-1 (ERROR) - La ruta del Archivo no es valida
 * 						-2 (ERROR) - El puntero a LinkedList es NULL
 * 						-3 (ERROR) - No se pudo abrir el Archivo
 * 						-4 (ERROR) - La lista está vacia, no hay pasajeros
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);

/** \brief Guarda los datos de los pasajeros en el archivo data.bin (modo binario).
 * \param path char* - Ruta del archivo a cargar
 * \param pArrayListPassenger LinkedList* - Puntero al vector de pasajeros
 * \return int - Retorna 0 (EXITO) - Si se pudieron cargar los datos desde el archivo
 * 						-1 (ERROR) - La ruta del Archivo no es valida
 * 						-2 (ERROR) - El puntero a LinkedList es NULL
 * 						-3 (ERROR) - No se pudo abrir el Archivo
 * 						-4 (ERROR) - La lista está vacia, no hay pasajeros
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);

/** \brief - Busca un pasajero por id
 * \param pArrayListPassenger LinkedList* - Puntero al vector de pasajeros
 * \param id int - El id del pasajero que se intenta encontrar
 * \return int - Retorna 0 (EXITO) - Si se pudo encontrar el pasajero en la lista
 * 						-1 (ERROR) - El puntero a LinkedList es NULL, no se pudo obtener el pasajero,
 * 									 no se pudo obtener el ID del pasajero o no se encontró ninguna coincidencia
 */
int Controller_buscarPorId(LinkedList* pArrayListPassenger,int id);

/** \brief - Busca el maximo id guardado previamente en el archivo id.txt y lo asigna como un idGlobal
 * \return int - Retorna 0 (EXITO) - Si se cargar y asignar el ultimo id maximo guardado
 * 						-1 (ERROR) - La ruta del Archivo no es valida
 * 						-2 (ERROR) - Falló la lectura del archivo
 */
int Controller_cargarUltimoId();

/** \brief - Guarda en el archivo id.txt el ultimo id maximo ingresado en el sistema
 * \return int - Retorna 0 (EXITO) - Si se pudo guardar el ultimo id maximo asignado
 * 						-1 (ERROR) - Falló la lectura del archivo
 */
int Controller_guardarUltimoId();

#endif /* CONTROLLER_H_ */
