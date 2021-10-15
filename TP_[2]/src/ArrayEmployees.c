#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Input.h>
#include <ArrayEmployees.h>

int initEmployees(Employee* list, int lenght){
	int i;

	if (list != NULL && cantidadElementos > 0) {
		for (i = 0; i < cantidadElementos; i++) {
			list[i].legajo = valorInicial;
		}
	}
	return 0;
}

int addEmployee(Employee* list, int lenght, int id, char name[],char, lastName[],float salary,int sector){

}

int findEmployeeById(Employee* list, int len,int id){

}

int removeEmployee(Employee* list, int len, int id){

}

int sortEmployees(Employee* list, int len, int order){

}

int printEmployees(Employee* list, int length){

}

