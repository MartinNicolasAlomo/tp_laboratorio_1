#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Ingresos.h"
#include "Validaciones.h"
#include "Operaciones.h"
#define LONGMENSAJEMENU 500
#define LONGMENSAJES 100
#define REINTENTOS 3
#define DESCUENTO 10
#define INTERES 25


int menuOpcionesEmpresas(void){
	int retorno=-1;
	int opcion;
	char mensajeMenuIngreso[LONGMENSAJEMENU];
	char mensajeMenuError[LONGMENSAJES];
	char mensajeKmIngreso[LONGMENSAJES];
	char mensajeKmError[LONGMENSAJES];
	char mensajeAerolineasIngreso[LONGMENSAJES];
	char mensajeAerolineasError[LONGMENSAJES];
	char mensajeLatamIngreso[LONGMENSAJES];
	char mensajeLatamError[LONGMENSAJES];
	float kmMaximos=15000;
	float preciosMaximos=750000;
	float kilometrosIngresados=0;
	float precioLatamIngresado=0;
	float precioAerolineasIngresado=0;
	int flagKilometros=1;
	int flagLatam=1;
	int flagAerolineas=1;
	int flagCalculos=1;
	float bitcoinPrecio=4800000;
	float precioDescuentoLatam;
	float precioInteresLatam;
	float precioBitcoinLatam;
	float precioUnitarioLatam;
	float precioDescuentoAerolineas;
	float precioInteresAerolineas;
	float precioBitcoinAerolineas;
	float precioUnitarioAerolineas;
	float diferenciaPrecios;
	int respuestaDescuentoLatam;
	int respuestaInteresLatam;
	int respuestaBitcoinLatam;
	int respuestaUnitarioLatam;
	int respuestaDescuentoAerolineas;
	int respuestaInteresAerolineas;
	int respuestaBitcoinAerolineas;
	int respuestaUnitarioAerolineas;
	int respuestaDiferenciaPrecios;
	float kilometrosHardcodeado = 7090;
	float aerolineasHardcodeado = 162965;
	float latamHardcodeado = 159339;
	int respuestaDiferenciaPreciosHardcodeado;

	snprintf(mensajeMenuIngreso,sizeof(mensajeMenuIngreso),"Seleccione una opcion:\n\n1-Ingresar Kilómetros: (km = %.2f)\n2-Ingresar Precio de Vuelos: (Aerolíneas = $%.2f, Latam = $%.2f)\n3-Calcular todos los costos:\n4-Informar Resultados\n5-Carga forzada de datos\n6-Salir\n\n",kilometrosIngresados,precioAerolineasIngresado,precioLatamIngresado);
	strncpy(mensajeMenuError,"No es una opcion valida, reintentelo de nuevo.\n\n\n",sizeof(mensajeMenuError));
	snprintf(mensajeKmIngreso,sizeof(mensajeKmIngreso),"Ingrese los kilometros de vuelo (maximo %.2f km):\n",kmMaximos);
	strncpy(mensajeKmError,"\nError! No es un kilometro correcto.\n\n\n",sizeof(mensajeKmError));
	snprintf(mensajeAerolineasIngreso,sizeof(mensajeAerolineasIngreso),"Ingrese el precio para Aerolineas (maximo $%.2f):\n",preciosMaximos);
	strncpy(mensajeAerolineasError,"\nError! No es un precio correcto.\n\n\n",sizeof(mensajeAerolineasError));
	snprintf(mensajeLatamIngreso,sizeof(mensajeLatamIngreso),"Ingrese el precio para LATAM (maximo $%.2f):\n",preciosMaximos);
	strncpy(mensajeLatamError,"\nError! No es un precio correcto.\n\n\n",sizeof(mensajeLatamError));

	do{
		snprintf(mensajeMenuIngreso,sizeof(mensajeMenuIngreso),"Seleccione una opcion:\n\n1-Ingresar Kilómetros: (km = %.2f)\n2-Ingresar Precio de Vuelos: (Aerolíneas = $%.2f, Latam = $%.2f)\n3-Calcular todos los costos:\n4-Informar Resultados\n5-Carga forzada de datos\n6-Salir\n\n",kilometrosIngresados,precioAerolineasIngresado,precioLatamIngresado);
		if(!ingresarEntero(&opcion,mensajeMenuIngreso,mensajeMenuError,1,6,REINTENTOS)){
			printf("Usted eligió la opción %d.\n",opcion);
			switch(opcion){
			case 1:
				if(!ingresarFlotante(&kilometrosIngresados,mensajeKmIngreso,mensajeKmError, 1, kmMaximos, REINTENTOS)){
					printf("KM ingresados: %.2f km.\n\n\n", kilometrosIngresados);
					flagKilometros = 0;
				}
				else{
					puts("No se pudo ingresar los kilometros de vuelo.\n\n\n");
				}
				break;
			case 2:
				if(!flagKilometros){
					if(!ingresarFlotante(&precioAerolineasIngresado,mensajeAerolineasIngreso,mensajeAerolineasError, 1, preciosMaximos, REINTENTOS)){
						flagAerolineas = 0;
					}
					else{
						puts("No se pudo ingresar el precio para Aerolineas.\nPara poder ingresar el precio para LATAM, en necesario que primero se ingrese un precio para Aerolineas.\n\n\n");
					}
					if(!flagAerolineas){
						if(!ingresarFlotante(&precioLatamIngresado,mensajeLatamIngreso,mensajeLatamError, 1, preciosMaximos, REINTENTOS)){
							printf("\nEl precio de vuelo para LATAM es $%.2f.\n", precioLatamIngresado);
							printf("El precio de vuelo para Aerolineas es $%.2f.\n\n\n", precioAerolineasIngresado);
							flagLatam = 0;
						}
						else{
							puts("No se pudo ingresar el precio para LATAM.\n.Para poder ingresar el precio para LATAM, en necesario que primero se ingrese un precio para Aerolineas\n\n\n");
						}
					}
				}
				else{
					puts("Falta ingresar los kilometros de vuelo para realizar las operaciones.\n\n\n");
				}
				break;
			case 3:
				if(flagKilometros){
					puts("Falta ingresar los kilometros de vuelo para realizar las operaciones.\n\n\n");
				}
				else if(flagLatam){
					puts("No se ingresaron los precios de los vuelos para realizar las operaciones.\n\n\n");
				}
				else{
					flagCalculos = 0;
					puts("Se calcularon todos los costos.\n\n\n");
					respuestaDescuentoLatam = calcularDescuento(&precioDescuentoLatam, precioLatamIngresado, DESCUENTO);
					respuestaInteresLatam = calcularInteres(&precioInteresLatam, precioLatamIngresado, INTERES);
					respuestaBitcoinLatam = dividir(&precioBitcoinLatam, precioLatamIngresado, bitcoinPrecio);
					respuestaUnitarioLatam = dividir(&precioUnitarioLatam, precioLatamIngresado, kilometrosIngresados);
					respuestaDescuentoAerolineas = calcularDescuento(&precioDescuentoAerolineas, precioAerolineasIngresado, DESCUENTO);
					respuestaInteresAerolineas = calcularInteres(&precioInteresAerolineas, precioAerolineasIngresado, INTERES);
					respuestaBitcoinAerolineas = dividir(&precioBitcoinAerolineas, precioAerolineasIngresado, bitcoinPrecio);
					respuestaUnitarioAerolineas = dividir(&precioUnitarioAerolineas, precioAerolineasIngresado, kilometrosIngresados);
					respuestaDiferenciaPrecios = calcularDiferenciaPrecios(&diferenciaPrecios, precioLatamIngresado, precioAerolineasIngresado);
				}
				break;
			case 4:
				if(flagKilometros){
					puts("Falta ingresar los kilometros de vuelo para realizar las operaciones.\n\n\n");
				}
				else if(flagLatam){
					puts("No se ingresaron los precios de los vuelos para realizar las operaciones.\n\n\n");
				}
				else if(flagCalculos){
					puts("Aun no se realizó ninguna operacion.\n\n\n");
				}
				else{
					printf("\nKMs ingresados: %.2f\n\n",kilometrosIngresados);
					printf("Latam: %.2f\n",precioLatamIngresado);
					if(!respuestaDescuentoLatam){
						printf("a) Precio con tarjeta de débito: $%.2f\n", precioDescuentoLatam);
					}
					else{
						puts("No se pudo calcular el precio final con descuento para LATAM.\n");
					}
					if(!respuestaInteresLatam){
						printf("b) Precio con tarjeta de crédito: $%.2f\n", precioInteresLatam);
					}
					else{
						puts("No se pudo calcular el precio final con interes para LATAM.\n");
					}
					if(!respuestaBitcoinLatam){
						printf("c) Precio pagando con bitcoin: $%.2f\n", precioBitcoinLatam);
					}
					else{
						puts("No se pudo calcular el precio de LATAM pagando con bitcoin.\n");
					}
					if(!respuestaUnitarioLatam){
						printf("d) Precio unitario: $%.2f\n\n", precioUnitarioLatam);
					}
					else{
						puts("No se pudo calcular el precio unitario para LATAM.\n\n");
					}
					printf("Aerolineas: %.2f\n",precioAerolineasIngresado);
					if(!respuestaDescuentoAerolineas){
						printf("a) Precio con tarjeta de débito: $%.2f\n", precioDescuentoAerolineas);
					}
					else{
						puts("No se pudo calcular el precio final con descuento para Aerolineas.\n");
					}
					if(!respuestaInteresAerolineas){
						printf("b) Precio con tarjeta de crédito: $%.2f\n", precioInteresAerolineas);
					}
					else{
						 puts("No se pudo calcular el precio final con interes para Aerolineas.\n");
					}
					if(!respuestaBitcoinAerolineas){
						 printf("c) Precio pagando con bitcoin: $%.2f\n", precioBitcoinAerolineas);
					}
					else{
						 puts("No se pudo calcular el precio de Aerolineas pagando con bitcoin.\n");
					}
					if(!respuestaUnitarioAerolineas){
						 printf("d) Precio unitario: $%.2f\n\n", precioUnitarioAerolineas);
					}
					else{
						puts("No se pudo calcular el precio unitario para Aerolineas.\n");
					}
					if(respuestaDiferenciaPrecios==1){
						printf("La diferencia de precio es: $%.2f\n\n", diferenciaPrecios);
					}
					else if(respuestaDiferenciaPrecios){
						puts("Ambos precios son iguales.\n\n\n");
					}
					else {
						puts("No se pudo calcular la diferencia entre los precios ingresados.\n\n\n");
					}
					puts("Luego de mostrar los resultados se reiniciaran los todos los valores\n\n\n");
					kilometrosIngresados = 0;
					precioLatamIngresado = 0;
					precioDescuentoLatam = 0;
					precioInteresLatam = 0;
					precioBitcoinLatam = 0;
					precioUnitarioLatam = 0;
					precioAerolineasIngresado = 0;
					precioDescuentoAerolineas = 0;
					precioInteresAerolineas = 0;
					precioBitcoinAerolineas = 0;
					precioUnitarioAerolineas = 0;
					diferenciaPrecios = 0;
					flagKilometros=1;
					flagAerolineas=1;
					flagLatam=1;
					flagCalculos=1;
				}
				break;
			case 5:
				if(!flagKilometros){
					puts("Ya hay otra operatoria en proceso, espere a que termine para poder mostrar los datos hardcodeades:\n\n\n");
				}
				else{
					puts("Datos forzados:\n");
					printf("KMs ingresados: %.2f\n\n",kilometrosHardcodeado);
					printf("Latam: %.2f\n",latamHardcodeado);
					if(!calcularDescuento(&precioDescuentoLatam, latamHardcodeado, DESCUENTO)){
						printf("a) Precio con tarjeta de débito: $%.2f\n", precioDescuentoLatam);
					}
					else{
						puts("No se pudo calcular el precio final con descuento para LATAM.\n");
					}
					if(!calcularInteres(&precioInteresLatam, latamHardcodeado, INTERES)){
						printf("b) Precio con tarjeta de crédito: $%.2f\n", precioInteresLatam);
					}
					else{
						puts("No se pudo calcular el precio final con interes para LATAM.\n");
					}
					if(!dividir(&precioBitcoinLatam, latamHardcodeado, bitcoinPrecio)){
						printf("c) Precio pagando con bitcoin: $%.2f\n", precioBitcoinLatam);
					}
					else{
						puts("No se pudo calcular el precio de LATAM pagando con bitcoin.\n");
					}
					if(!dividir(&precioUnitarioLatam, latamHardcodeado, kilometrosHardcodeado)){
						printf("d) Precio unitario: $%.2f\n\n", precioUnitarioLatam);
					}
					else{
						puts("No se pudo calcular el precio unitario para LATAM.\n");
					}
					printf("Aerolineas: %.2f\n",aerolineasHardcodeado);
					if(!calcularDescuento(&precioDescuentoAerolineas, aerolineasHardcodeado, DESCUENTO)){
						printf("a) Precio con tarjeta de débito: $%.2f\n", precioDescuentoAerolineas);
					}
					else{
						puts("No se pudo calcular el precio final con descuento para Aerolineas.\n");
					}
					if(!calcularInteres(&precioInteresAerolineas, aerolineasHardcodeado, INTERES)){
						printf("b) Precio con tarjeta de crédito: $%.2f\n", precioInteresAerolineas);
					}
					else{
						puts("No se pudo calcular el precio final con interes para Aerolineas.\n");
					}
					if(!dividir(&precioBitcoinAerolineas, aerolineasHardcodeado, bitcoinPrecio)){
						printf("c) Precio pagando con bitcoin: $%.2f\n", precioBitcoinAerolineas);
					}
					else{
						puts("No se pudo calcular el precio de Aerolineas pagando con bitcoin.\n");
					}
					if(!dividir(&precioUnitarioAerolineas, aerolineasHardcodeado, kilometrosHardcodeado)){
						printf("d) Precio unitario: $%.2f\n\n", precioUnitarioAerolineas);
					}
					else{
						puts("No se pudo calcular el precio unitario para Aerolineas.\n\n");
					}
					respuestaDiferenciaPreciosHardcodeado = calcularDiferenciaPrecios(&diferenciaPrecios, latamHardcodeado, aerolineasHardcodeado);
					if(respuestaDiferenciaPreciosHardcodeado == 1){
						printf("La diferencia de precio es: $%.2f\n\n\n", diferenciaPrecios);
					}
					else if(respuestaDiferenciaPreciosHardcodeado == 0){
						puts("Ambos precios son iguales.\n\n\n");
					}
					else {
						puts("No se pudo calcular la diferencia entre los precios ingresados.\n\n\n");
					}
					precioDescuentoLatam = 0;
					precioInteresLatam = 0;
					precioBitcoinLatam = 0;
					precioUnitarioLatam = 0;
					precioDescuentoAerolineas = 0;
					precioInteresAerolineas = 0;
					precioBitcoinAerolineas = 0;
					precioUnitarioAerolineas = 0;
					diferenciaPrecios = 0;
				}
				break;
			case 6:
				puts("Usted finalizó la operación.\n");
				retorno=0;
				break;
			}
		}
	}while(opcion != 6);
	return retorno;
}


int dividir(float* pResultado, float operandoUno, float operandoDos){
	int retorno = -1;
	float resultado;
	if(pResultado != NULL && operandoDos != 0){
		resultado = operandoUno / operandoDos;
		*pResultado = resultado;
		retorno = 0;
	}
	return retorno;
}


int calcularDescuento(float* pResultado, float precio, float descuento){
	int retorno = -1;
	float resultado;
	if(pResultado != NULL && descuento > 0){
		resultado = precio - (precio * descuento / 100);
		*pResultado = resultado;
		retorno = 0;
	}
	if(descuento == 0){
		retorno = -2;
	}
	return retorno;
}


int calcularInteres(float* pResultado, float precio, float interes){
	int retorno = -1;
	float resultado;
	if(pResultado != NULL && interes > 0){
		resultado = precio + (precio * interes / 100);
		*pResultado = resultado;
		retorno = 0;
	}
	if(interes == 0){
		retorno = -2;
	}
	return retorno;
}


int calcularDiferenciaPrecios(float* pResultado, float precioUno, float precioDos){
	int retorno = -1;
	float resultado;
	if(pResultado != NULL){
		if(precioUno == precioDos){
			retorno = 0;
		}
		else{
			retorno = 1;
			if(precioUno > precioDos){
				resultado = precioUno - precioDos;
				*pResultado = resultado;
			}
			else{
				resultado = precioDos - precioUno;
				*pResultado = resultado;;
			}
		}
	}
	return retorno;
}


