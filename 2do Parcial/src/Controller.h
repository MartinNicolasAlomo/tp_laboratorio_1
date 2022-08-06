#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Computer.h"
#include "Controller.h"
#include "Input.h"
#include "LinkedList.h"
#include "Parser.h"
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
int controller_loadFromText(char* path , LinkedList* pArraList);


/** \brief - Ordenar pasajeros. Ordena la lista de pasajero segun el criterio y el orden que elija el usuario
 * \param pArrayListPassenger LinkedList* - Puntero al vector de pasajeros
 * \return int - Retorna 0 (EXITO) - Si se pudo ordenar la lista de pasajeros correctamente
 * 						-1 (ERROR) - El puntero a LinkedList es NULL
 * 						-2 (ERROR) - No se ingresó un criterio por el cual ordenar la lista
 * 						-3 (ERROR) - Volvió al menú principal
 * 						-4 (ERROR) - No se ingresó el orden para ordenar la lista
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger);

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



/// @brief Analiza un vector y segun la funcion
/// @param pArrayList Vector de donde se sacaran los datos
/// @return - Retorna 0 (EXITO) - Si se pudo ajustar los preicios de la computadoras
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL
int controller_map(LinkedList* pArrayList);




#endif /* CONTROLLER_H_ */
