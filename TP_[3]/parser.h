#ifndef PARSER_H_
#define PARSER_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Controller.h"
#include "Input.h"
#include "Validations.h"
#include "Zprueba.h"


/** \brief - Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 * \param pFile FILE* - Puntero al archivo a cargar
 * \param pArrayListPassenger LinkedList* - Puntero al vector de pasajeros
 * \return int - Retorna 0 (EXITO) - Si se pudieron parsear los datos desde el archivo correctamente
 * 						 -1 (ERROR) - Si: La ruta del Archivo no es valida, el puntero a LinkedList es NULL, no funcionó la Función de lectura FSCANF,
 * 										  no se pudo crear al Pasajero o no se pudo agregar el Pasajero a la Lista
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);


/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 * \param pFile FILE* - Puntero al archivo a cargar
 * \param pArrayListPassenger LinkedList* - Puntero al vector de pasajeros
* \return int - Retorna 0 (EXITO) - Si se pudieron parsear los datos desde el archivo correctamente
 * 						 -1 (ERROR) - Si: La ruta del Archivo no es valida, el puntero a LinkedList es NULL, no funcionó la Función de lectura FREAD,
 * 										  no se pudo crear al Pasajero o no se pudo agregar el Pasajero a la Lista
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);


#endif /* PARSER_H_ */
