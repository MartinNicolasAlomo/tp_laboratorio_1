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


/// @brief muestra un menu de opciones para que el usuario decida que hacer
/// @param lista vector de empleados
/// @param limite tamaño del vector
/// @return 0 si falla, 1 si resolvio la funcion
int MenuEmpleados(Employee lista[], int limite);

/// @brief Indican que todas las posiciones del vectorn the array estan vacias (TRUE = 1)
/// @param list vector de empleados
/// @param lenght tamaño del vector
/// @return 0 si falla, 1 si resolvio la funcion
int initEmployees(Employee* list, int lenght);

/// @brief Busca el primer espacio libre
/// @param lista vector de empleados
/// @param cantidadElementos el numero de elementos del vector
/// @return	0 si falla, 1 si resolvio la funcion
int BuscarPrimerOcurrenciaEmpleados(Employee lista[], int cantidadElementos);

/// @brief carga los datos ingresados del empleado
/// @param list vector de empleados
/// @param lenght tamaño del vector
/// @param id identificacion del empleado
/// @param name nombre del empleado
/// @param lastName apellido del empleado
/// @param salary salario del empleado
/// @param sector secor donde trabaja el empleado
/// @return 0 si falla, 1 si resolvio la funcion
int addEmployee(Employee* list, int lenght, int id, char name[],char lastName[],float salary,int sector);

/// @brief ecuentra un empleado segun su ID
/// @param list vector de empleados
/// @param lenght tamaño del vector
/// @param id identificacion del empleado
/// @return 0 si falla, 1 si resolvio la funcion
int findEmployeeById(Employee* list, int lenght,int id);

/// @brief Elimina un empleado del sistema
/// @param list vector de empleados
/// @param lenght tamaño del vector
/// @param id identificacion del empleado
/// @return 0 si falla, 1 si resolvio la funcion
int removeEmployee(Employee* list, int lenght, int id);

/// @brief Ordena el vector de empleados ascendente o descendente
/// @param list vector de empleados
/// @param lenght tamaño del vector
/// @param order Orden en el cual se ordenara el vector
/// @return 0 si falla, 1 si resolvio la funcion
int sortEmployees(Employee* list, int lenght, int order);

/// @brief  Imprime los resultados por pantalla
/// @param list vector de empleados
/// @param length tamaño del vector
/// @return 0 si falla, 1 si resolvio la funcion
int printEmployees(Employee* list, int length);

/// @brief calcula el promedio y cuantos empleados lo superan. Luego imprime los resultados
/// @param lista vector de empleados
/// @param limite tamaño del vector
/// @param totalSalarios la suma de todos los salarios
/// @param cantidadSalarios la cantidad de salarios ingresados
/// @return 0 si falla, 1 si resolvio la funcion
int CalcularYMostrarSalarios(Employee* lista,int limite,float totalSalarios,int cantidadSalarios);


#endif
