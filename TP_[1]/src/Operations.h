#ifndef OPERATIONS_H_
#define OPERATIONS_H_

/// @brief Es el menu interactivo del programa
/// @return Retorna 0 (EXITO) si se pudo finalizar el menu interactivo, y -1 (ERROR) si hubo un fallo en el programa
int menuOpcionesEmpresas(void);

/// @brief Divide dos numeros flotantes
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param operandoUno Es el numero flotante a ser dividido
/// @param operandoDos Es el numero divisor
/// @return Retorna 0 (EXITO) si se pudo realizar la division, y -1 si no se pudo
int dividir(float* pResultado,float operandoUno,float operandoDos);

/// @brief Aplica el descuento y calcula el precio final
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param precio Es el precio inicial al que se le aplicara el descuento
/// @param descuento Es el descuento a aplicar
/// @return Retorna 0 (EXITO) si se logra aplicar el descuento, -1 si hubo ERROR y -2 si el descuento es cero y no hubo cambios en el precio
int calcularDescuento(float* pResultado,float precio,float descuento);

/// @brief Aplica el interes y calcula el precio final
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param precio Es el precio inicial al que se le aplicara el interes
/// @param interes Es el interes a aplicar
/// @return Retorna 0 (EXITO) si se logra aplicar el interes, -1 si hubo ERROR y -2 si el interes es cero y no hubo cambios en el precio
int calcularInteres(float* pResultado,float precio,float interes);

/// @brief Determina si un precio es mayor al otro y saca la diferencia restanndole el menor al del mayor
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param precioUno Es el primer precio que se paso.
/// @param precioDos Es el segundo precio que se paso.
/// @return Retorna 1 si encontro que uno es mayor al otro y se realizo la resta, 0 si ambos precios son iguales, -1 si hubo ERROR
int calcularDiferenciaPrecios(float* pResultado,float precioUno,float precioDos);

#endif /* OPERATIONS_H_ */
