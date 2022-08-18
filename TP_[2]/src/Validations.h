#ifndef VALIDATIONS_H_
#define VALIDATIONS_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "Input.h"

/// @brief Verifica si la cadena contiene solo números
/// @param cadena Cadena de caracteres a ser analizada
/// @param limite Define el tamaño de la cadena
/// @param mensajeFallo Puntero al espacio de memoria donde, en caso de haber un error, se guardará la descripción del error
/// @return Retorna 1 (VERDADERO) si la cadena es un número entero, 0 (FALSO) si no lo es, y -1 (ERROR) si hubo un error
int esEntero(char* cadena, int limite, char* mensajeFallo);

/// @brief Valida que el número entero ingresado este dentro el rango establecido
/// @param numero Es el número entero a analizar
/// @param minimo Es el número mínimo a ser aceptado
/// @param maximo Es el número máximo a ser aceptado
/// @param mensajeFallo Puntero al espacio de memoria donde, en caso de haber un error, se guardará la descripción del error
/// @return Retorna 1 (VERDADERO) si el número ingresado esta dentro del rango establecido, y 0 (FALSO) si no lo está
int validarRangoEntero(int numero, int minimo, int maximo, char* mensajeFallo);

/// @brief Verifica si la cadena contiene solo números y un solo punto decimal
/// @param cadena Cadena de caracteres a ser analizada
/// @param limite Define el tamaño de la cadena
/// @param mensajeFallo Puntero al espacio de memoria donde, en caso de haber un error, se guardará la descripción del error
/// @return Retorna 1 (VERDADERO) si la cadena es un número con decimales, 0 (FALSO) si no lo es, y -1 (ERROR) si hubo un error
int esFlotante(char* cadena, int limite, char* mensajeFallo);

/// @brief Valida que el número con decimales ingresado este dentro el rango establecido
/// @param numero Es el número con decimales a analizar
/// @param minimo Es el número mínimo a ser aceptado
/// @param maximo Es el número máximo a ser aceptado
/// @param mensajeFallo Puntero al espacio de memoria donde, en caso de haber un error, se guardará la descripción del error
/// @return Retorna 1 (VERDADERO) si el número ingresado esta dentro del rango establecido, y 0 (FALSO) si no lo está
int validarRangoFlotante(float numero, float minimo, float maximo, char* mensajeFallo);

/// @brief Verifica si la cadena contiene letras. Tambien acepta espacios en blanco y guiones para nombres compuestos
/// @param cadena Cadena de caracteres a ser analizada
/// @param limite Define el tamaño de la cadena
/// @param mensajeFallo Puntero al espacio de memoria donde, en caso de haber un error, se guardará la descripción del error
/// @return Retorna 1 (VERDADERO) si la cadena es un nombre válido, 0 (FALSO) si no lo es, y -1 (ERROR) si hubo un error
int esNombre(char* cadena, int limite, char* mensajeFallo);

/// @brief Verifica si el carácter ingresado es un carácter válido para un nombre
/// @param caracter Carácter a ser analizado
/// @return Retorna 1 (VERDADERO) si el carácter ingresado es válido para un nombre, 0 (FALSO) si no lo es
int esCaracterValidoNombre(char caracter);

/// @brief Verifica si la cadena contiene letras, números y otros caracteres específicos
/// @param cadena Cadena de caracteres a ser analizada
/// @param limite Define el tamaño de la cadena
/// @param mensajeFallo Puntero al espacio de memoria donde, en caso de haber un error, se guardará la descripción del error
/// @return Retorna 1 (VERDADERO) si la cadena es una descripción válida, 0 (FALSO) si no lo es, y -1 (ERROR) en hubo un error
int esDescripcion(char* cadena, int limite, char* mensajeFallo);

/// @brief Verifica si el carácter ingresado es un carácter válido para una descripción
/// @param caracter Carácter a ser analizado
/// @return Retorna 1 (VERDADERO) si el carácter ingresado es válido para una descripción, 0 (FALSO) si no lo es
int esCaracterValidoDescripcion(char caracter);

/// @brief Verifica si la cadena contiene letras, números o espacios en blanco
/// @param cadena Cadena de caracteres a ser analizada
/// @param limite Define el tamaño de la cadena
/// @param mensajeFallo Puntero al espacio de memoria donde, en caso de haber un error, se guardará la descripción del error
/// @return Retorna 1 (VERDADERO) si la cadena es un alfanumérico válido, 0 (FALSO) si no lo es, y -1 (ERROR) si hubo un error
int esAlfanumerico(char* cadena, int limite, char* mensajeFallo);

/// @brief Verifica si el carácter ingresado es un carácter válido para un alfanumérico
/// @param caracter Carácter a ser analizado
/// @return Retorna 1 (VERDADERO) si el carácter ingresado es válido para un alfanumérico, 0 (FALSO) si no lo es
int esCaracterValidoAlfanumerico(char caracter);

/// @brief Verifica si el año ingresado es bisiesto
/// @param anio Es el año a ser analizado
/// @return Retorna 1 (VERDADERO) si el año es bisiesto, 0 (FALSO) si no lo es, y -1 (ERROR) si hubo un error
int esAnioBisiesto(int anio);





#endif /* VALIDATIONS_H_ */
