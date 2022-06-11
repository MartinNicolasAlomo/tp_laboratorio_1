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


int controller_editPassenger(LinkedList* pArrayListPassenger);

/** \brief - Baja de pasajero. Elimina un pasajero del sistema
 * \param pArrayListPassenger LinkedList* - Puntero al vector de pasajeros
 * \return int - Retorna 0 (EXITO) - Si se pudo eliminar el pasajero del sistema correctamente
 * 						-1 (ERROR) - El puntero a LinkedList es NULL
 * 						-2 (ERROR) - No se ingresó ningun ID para eliminar
 * 						-3 (ERROR) - No se pudo encontrar el ID buscado
 * 						-4 (ERROR) - No se pudo obtener el pasajero
 * 						-5 (ERROR) - No se obtuvo ninguna confirmación. Volvió al menú principal
 * 						-6 (ERROR) - Se canceló la operación. No se eliminó el pasajero
 * 						-7 (ERROR) - Se eliminó el pasajero de memoria pero no se pudo eliminar de la lista
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

/** \brief - Busca en el array el maximo id ya cargado.
 * \param pArrayListPassenger LinkedList* - Puntero al vector de pasajeros
 * \return int - Retorna 0 (EXITO) - Si se pudo encontrar el id mas grande dentro de la lista
 * 						-1 (ERROR) - El puntero a LinkedList es NULL, la lista está vacia,
 * 									 no se pudo obtener el pasajero o no se pudo obtener el ID del pasajero
 */
int Controller_encontrarIdMaximo(LinkedList* pArrayListPassenger);

/** \brief - Busca el id maximo hasta el momento y luego genera un nuevo id para un el nuevo pasajero ingresado a partir del id maximo encontrado
 * \param pArrayListPassenger LinkedList* - Puntero al vector de pasajeros
 * \return int - Retorna 0 (EXITO) - Si se pudo generar un nuevo id mayor al encontrado en la lista
 * 						-1 (ERROR) - El puntero a LinkedList es NULL o la lista está vacia
 */
int Controller_generarIdNuevo(LinkedList* pArrayListPassenger);




#endif /* CONTROLLER_H_ */
