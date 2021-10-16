#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Input.h"
#include "ArrayEmployees.h"
#define TRUE 0
int initEmployees(Employee* list, int lenght){
	int i;

	if (list != NULL && lenght > 0) {
		for (i = 0; i < lenght; i++) {
			list[i].isEmpty = TRUE;
		}
	}
	return 0;
}

int addEmployee(Employee* list, int lenght, int id, char name[],char lastName[],float salary,int sector){
	if (list != NULL && lenght > 0 && name != NULL && lastName != NULL){

	}

	return 1;
}

/*int findEmployeeById(Employee* list, int len,int id){

}

int removeEmployee(Employee* list, int len, int id){

}

int sortEmployees(Employee* list, int len, int order){

}

int printEmployees(Employee* list, int length){

}
*/
