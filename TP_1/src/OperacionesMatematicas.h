#ifndef OPERACIONESMATEMATICAS_H_
#define OPERACIONESMATEMATICAS_H_

/// @brief realiza la suma de los dos numeros ingresados.
/// @param operandoUno es el primer numero ingresado.
/// @param operandoDos es el segundo numero ingresado.
/// @return devuelve el resultado de la sumatoria.
float Sumar(float operandoUno, float operandoDos);

/// @brief realiza la resta de los dos numeros ingresados.
/// @param operandoUno es el primer numero ingresado.
/// @param operandoDos es el segundo numero ingresado.
/// @return devuelve el resultado de la resta.
float Restar(float operandoUno, float operandoDos);

/// @brief realiza la multiplicacion de los dos numeros ingresados.
/// @param operandoUno es el primer numero ingresado.
/// @param operandoDos es el segundo numero ingresado.
/// @return devuelve el producto de la multiplicacion.
float Multriplicar(float operandoUno, float operandoDos);

/// @brief realiza la division de los dos numeros ingresados..
/// @param operandoUno es el primer numero ingresado.
/// @param operandoDos es el segundo numero ingresado.
/// @param dirResultadoDivision es el puntero de la variable resultadoDivision en la funcion Main.
/// @return devuelve 0 si se intento dividir por 0 (error) y devuelve 1 si la division fue exitosa.
int Dividir(float operandoUno, float operandoDos, float *dirResultadoDivision);

/// @brief realiza el calculo para sacar el factorial (n!) del numero ingresado.
/// @param numeroIngresado es el numero ingresado, el cual yo quiero saber su factorial.
/// @return devuelve 1 si el numero ingresado fue 0, devuelve -1 si se ingreso un numero negativo, -2 si es un numero flotante y si se ingreso un numero positivo devuelve el factorial de dicho numero.
long int SacarFactorial(float numeroIngresado);

#endif /* OPERACIONESMATEMATICAS_H_ */
