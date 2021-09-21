/*=================================================================================================================================================

										 	  	 	 Trabajo Practico 1

											Martín Nicolás Alomo   -   División E

 ================================================================================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "OperacionesMatematicas.h"
#include "Ingresos.h"
#include "Validaciones.h"


int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	float numeroA;
	float numeroB;
	int flagA;
	int flagB;
	int flagOperaciones;
	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicacion;
	int errorDivision;
	float resultadoDivision;
	long int factorialA;
	long int factorialB;
	flagA = 0;
	flagB = 0;
	flagOperaciones = 0;

	do{
		if(PedirOpcion(&opcion,"Seleccione una opcion: \n\n1-Ingresar primer operando\n2-Ingresar segundo operando\n3-Calcular todas las operaciones\n4-Informar resultados\n5-Salir","No es una opcion valida, reintentelo de nuevo\n",1,5,3) == 0){

		switch(opcion){
		case 1:
			numeroA = PedirNumero("Ingrese un numero: \n");
			printf("El primer numero ingresado fue %f\n\n", numeroA);
			flagA = 1;
			break;
		case 2:
			numeroB = PedirNumero("Ingrese otro numero: \n");
			printf("El segundo numero ingresado fue %f\n\n", numeroB);
			flagB = 1;
			break;
		case 3:
			if(flagA == 1 && flagB == 1){
				puts("Se realizaron las operaciones\n");
				resultadoSuma = Sumar(numeroA, numeroB);
				resultadoResta = Restar(numeroA, numeroB);
				resultadoMultiplicacion = Multriplicar(numeroA, numeroB);
				errorDivision = Dividir(numeroA, numeroB, &resultadoDivision);
				factorialA = SacarFactorial(numeroA);
				factorialB = SacarFactorial(numeroB);
				flagOperaciones = 1;
			}
			else{
				puts("No se ingresaron los operandos suficientes para realizar alguna operación \n");
			}
			break;
		case 4:
			if(flagOperaciones == 1){
			printf("El resultado de la suma entre %f y %f es: %f\n", numeroA, numeroB, resultadoSuma);
			printf("El resultado de la resta entre %f y %f es: %f\n", numeroA, numeroB, resultadoResta);
			printf("El resultado de la multiplicación entre %f y %f es: %f\n", numeroA, numeroB, resultadoMultiplicacion);
			if (errorDivision == 0) {
				printf("No se puede dividir por cero. \n");
			}
			else {
				printf("El resultado de la división entre %f y %f es: %f\n", numeroA, numeroB, resultadoDivision);
			}
			if(factorialA == -1){
				printf("No se puede sacar el factorial del primer numero ya que es un numero negativo \n");
			}
			else{
				printf("El factorial de %f es: %ld\n", numeroA, factorialA);
			}
			if(factorialB == -1){
				printf("No se puede sacar el factorial del segundo numero ya que es un numero negativo \n\n");
			}
			else{
				printf("El factorial de %f es: %ld\n\n", numeroB, factorialB);
			}
			break;
		}
			else{
				puts("Aun no se realizo ninguna operacion \n");
			}
		}
		}
	}while(opcion != 5);

	return EXIT_SUCCESS;
}
