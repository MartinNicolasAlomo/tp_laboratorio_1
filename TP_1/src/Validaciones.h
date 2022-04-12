#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_


/// @brief Verifica si la cadena contiene solo numeros
/// @param cadena cadena de caracteres a ser analizada
/// @param limite Define el tamaño de la cadena
/// @return Retorna 1 (VERDADERO) si la cadena es numerica, 0(FALSO) si no lo es, y -1 en caso de ERROR
int esNumerica(char cadena[], int limite);


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


#endif /* VALIDACIONES_H_ */
