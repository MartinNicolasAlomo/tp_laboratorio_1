#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

/// @brief verifica si el numero ingresado es positivo, negativo o neutro
/// @param numeroIngresado es el numero que ingreso el usuario.
/// @return devuelve 0 si el numero ingresado fue 0, 1 si el numero ingresado fue positivo y -1 si el numero ingresado fue negativo.
int VerificarSigno(int numeroIngresado);

/// @brief Verifica si el numero es un entero
/// @param numeroIngresado es el numero ingresado por el usuario
/// @return devuelve 1 si es entero o 0 si es flotante
int VerificarEntero(float numeroIngresado);

#endif /* VALIDACIONES_H_ */
