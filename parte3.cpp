#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main (int argc, char *argv[])
{
	char peticion[100];
	strcpy (peticion, "3/Miguel/47/1.78");
	
	int codigo;
	char nombre[20];
	int edad; 
	float altura; 
	
	char *p = strtok (peticion, "/");
	codigo = atoi (p);
	p = strtok (NULL, "/");
	strcpy (nombre, p);
	p = strtok (NULL, "/");
	edad= atoi (p);
	p = strtok (NULL, "/");
	altura= atof (p);
	
	printf("Codigo: %d, nombre: %s, edad: %d, altura: %f\n", codigo, nombre, edad, altura);
	
	
	char respuesta[100];
	if (edad >18)
		sprintf (respuesta, "%s es mayor de edad tiene %d a�os", nombre ,edad);
	else
		sprintf (respuesta, "%s no es mayor de edad", nombre);
	
	printf("Respuestas: %s\n", respuesta);
	
}

