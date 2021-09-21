#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"

float Sumar(float operandoUno, float operandoDos) {
	float resultadoSuma;
	resultadoSuma = operandoUno + operandoDos;
	return resultadoSuma;
}

float Restar(float operandoUno, float operandoDos) {
	float resultadoResta;
	resultadoResta = operandoUno - operandoDos;
	return resultadoResta;
}

float Multriplicar(float operandoUno, float operandoDos) {
	float resultadoMultiplicacion;
	resultadoMultiplicacion = operandoUno * operandoDos;
	return resultadoMultiplicacion;
}

int Dividir(float operandoUno, float operandoDos, float *dirResultadoDivision) {
	float resultadoDivision;
	int errorNoDivision = 0;
	if (dirResultadoDivision != NULL && operandoDos != 0) {
		resultadoDivision = operandoUno / operandoDos;
		(*dirResultadoDivision) = resultadoDivision;
		errorNoDivision = 1;
	}
	return errorNoDivision;
}

long int SacarFactorial(float numeroIngresado){
	int signoPositividad;
	long int resultado;
	signoPositividad = VerificarSigno(numeroIngresado);

	if (signoPositividad == 0) {
		resultado = 1;
	}
	else if (signoPositividad == 1) {
		resultado = (int)numeroIngresado * SacarFactorial(numeroIngresado - 1);
	}
	else if(signoPositividad == -1){
		resultado = -1;
	}
	return resultado;
}
