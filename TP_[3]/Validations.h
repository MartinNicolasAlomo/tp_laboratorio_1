#ifndef VALIDATIONS_H_
#define VALIDATIONS_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Input.h"

/// @brief Verifica si la cadena contiene solo numeros
/// @param cadena cadena de caracteres a ser analizada
/// @param limite Define el tamaño de la cadena
/// @return Retorna 1 (VERDADERO) si la cadena es numerica, 0(FALSO) si no lo es, y -1 en caso de ERROR
int esEntero(char cadena[], int limite);

/// @brief Valida que el numero entero recibido este en el rango pedido
/// @param numeroIngresado Es el numero entero a evaluar si esta dentro del rango
/// @param minimo Es el numero minimo a ser aceptado
/// @param maximo Es el numero maximo a ser aceptado
/// @return Retorna 1 (VERDADERO) si esta dentro del rango, y 0 (FALSO) si no lo esta
int validarRangoEntero(int numeroIngresado, int minimo, int maximo);

/// @brief Verifica si la cadena contiene solo numeros y un solo punto decimal
/// @param cadena Cadena de caracteres a ser analizada
/// @param limite Define el tamaño de la cadena
/// @return Retorna 1 (VERDADERO) si la cadena es un numero flotante, 0 (FALSO) si no lo es, y -1 en caso de ERROR
int esFlotante(char cadena[],int limite);

/// @brief Valida que el numero con decimal recibido este en el rango pedido
/// @param numeroFlotante Es el numero con decimal a evaluar si esta dentro del rango
/// @param minimo Es el numero minimo a ser aceptado
/// @param maximo Es el numero maximo a ser aceptado
/// @return Retorna 1 (VERDADERO) si esta dentro del rango, y 0 (FALSO) si no lo esta.
int validarRangoFlotante(float numeroFlotante, float minimo, float maximo);

/// @brief Verifica si la cadena contiene letras, tambien acepta espacios en blanco
/// @param cadena Cadena de caracteres a ser analizada
/// @param limite Define el tamaño de la cadena
/// @return Retorna 1 (VERDADERO) si la cadena contiene letras o tambien contiene espacios en blanco, 0 (FALSO) si no lo es, y -1 en caso de ERROR
int esNombre(char cadena[], int limite);

/// @brief Verifica si la cadena contiene los caracteres especificados para una descripcion
/// @param cadena Cadena de caracteres a ser analizada
/// @param limite Define el tamaño de la cadena
/// @return Retorna 1 (VERDADERO) si la cadena contiene los caracteres especificados, 0 (FALSO) si no los tiene, y -1 en caso de ERROR
int esDescripcion(char cadena[], int limite);

/// @brief Verifica si la cadena contiene letras, numeros o espacios en blanco
/// @param cadena Cadena de caracteres a ser analizada
/// @param limite Define el tamaño de la cadena
/// @return Retorna 1 (VERDADERO) si la cadena contiene letras, numeros o espacios en blanco, 0 (FALSO) si no lo es, y -1 en caso de ERROR
int esAlfanumerico(char cadena[], int limite);


#endif /* VALIDATIONS_H_ */
