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

/// @brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array.
/// @param list Pointer to array of employees.
/// @param lenght length of the array.
/// @return
int initEmployees(Employee* list, int lenght);

int addEmployee(Employee* list, int lenght, int id, char name[],char lastName[],float salary,int sector);

int findEmployeeById(Employee* list, int len,int id);

int removeEmployee(Employee* list, int len, int id);

int sortEmployees(Employee* list, int len, int order);

int printEmployees(Employee* list, int length);





#endif
