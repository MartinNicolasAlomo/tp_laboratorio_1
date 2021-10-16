#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}Employee;

int MenuEmpleados(Employee lista[], int limite);

/// @brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array.
/// @param list Pointer to array of employees.
/// @param lenght length of the array.
/// @return
int initEmployees(Employee* list, int lenght);

int BuscarPrimerOcurrenciaEmpleados(Employee lista[], int cantidadElementos);

int addEmployee(Employee* list, int lenght, int id, char name[],char lastName[],float salary,int sector);

int findEmployeeById(Employee* list, int lenght,int id);

int removeEmployee(Employee* list, int lenght, int id);

int sortEmployees(Employee* list, int lenght, int order);

int printEmployees(Employee* list, int length);

int CalcularYMostrarSalarios(Employee* lista,int limite,float totalSalarios,int cantidadSalarios);


#endif
