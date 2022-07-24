#ifndef VALIDATIONS_H_
#define VALIDATIONS_H_
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

/// @brief Verifica si la cadena contiene solo n�meros
/// @param cadena Cadena de caracteres a ser analizada
/// @param limite Define el tama�o de la cadena
/// @return Retorna 1 (VERDADERO) si la cadena es un n�mero entero, 0 (FALSO) si no lo es, y -1 (ERROR) en hubo un error
int esEntero(char* cadena, int limite);

/// @brief Valida que el n�mero entero ingresado este dentro el rango establecido
/// @param numero Es el n�mero entero a analizar
/// @param minimo Es el n�mero m�nimo a ser aceptado
/// @param maximo Es el n�mero m�ximo a ser aceptado
/// @return Retorna 1 (VERDADERO) si el n�mero ingresado esta dentro del rango establecido, y 0 (FALSO) si no lo est�
int validarRangoEntero(int numero, int minimo, int maximo);

/// @brief Verifica si la cadena contiene solo n�meros y un solo punto decimal
/// @param cadena Cadena de caracteres a ser analizada
/// @param limite Define el tama�o de la cadena
/// @return Retorna 1 (VERDADERO) si la cadena es un n�mero con decimales, 0 (FALSO) si no lo es, y -1 (ERROR) en hubo un error
int esFlotante(char* cadena, int limite);

/// @brief Valida que el n�mero con decimales ingresado este dentro el rango establecido
/// @param numero Es el n�mero con decimales a analizar
/// @param minimo Es el n�mero m�nimo a ser aceptado
/// @param maximo Es el n�mero m�ximo a ser aceptado
/// @return Retorna 1 (VERDADERO) si el n�mero ingresado esta dentro del rango establecido, y 0 (FALSO) si no lo est�
int validarRangoFlotante(float numero, float minimo, float maximo);

/// @brief Verifica si la cadena contiene letras. Tambien acepta espacios en blanco y guiones para nombres compuestos
/// @param cadena Cadena de caracteres a ser analizada
/// @param limite Define el tama�o de la cadena
/// @return Retorna 1 (VERDADERO) si la cadena es un nombre v�lido, 0 (FALSO) si no lo es, y -1 (ERROR) en hubo un error
int esNombre(char* cadena, int limite);

/// @brief Verifica si la cadena contiene letras, n�meros y otros caracteres espec�ficos
/// @param cadena Cadena de caracteres a ser analizada
/// @param limite Define el tama�o de la cadena
/// @return Retorna 1 (VERDADERO) si la cadena es una descripci�n v�lida, 0 (FALSO) si no lo es, y -1 (ERROR) en hubo un error
int esDescripcion(char* cadena, int limite);

/// @brief Verifica si la cadena contiene letras, n�meros o espacios en blanco
/// @param cadena Cadena de caracteres a ser analizada
/// @param limite Define el tama�o de la cadena
/// @return Retorna 1 (VERDADERO) si la cadena es un alfanum�rico v�lido, 0 (FALSO) si no lo es, y -1 (ERROR) en hubo un error
int esAlfanumerico(char* cadena, int limite);

/// @brief Verifica si el a�o ingresado es bisiesto
/// @param anio Es el a�o a ser analizado
/// @return Retorna 1 (VERDADERO) si el a�o es bisiesto, 0 (FALSO) si no lo es, y -1 (ERROR) en hubo un error
int esAnioBisiesto(int anio);

int esArchivo(char* cadena, int limite);
int esArchivoCSV(char* cadena, int limite);





#endif /* VALIDATIONS_H_ */
