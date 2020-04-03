#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main (int argc, char *argv[])
{
	char peticion[100];
	char respuesta[100];
	strcpy (peticion, "Miguel/47/Maria/17/Cristina/22/Manuel/27/Juan/25/");
	
	char nombre[20];
	int edad; 
	
	char *p = strtok (peticion, "/");
	while (p!=NULL)
	{
		strcpy (nombre, p);
		p = strtok (NULL, "/");
		edad= atoi (p);
		
		if (edad >18)
			sprintf (respuesta, "%s%s*%d-", respuesta, nombre ,edad);
		else
			sprintf (respuesta, "%s no es mayor de edad\n", nombre);
		
		p = strtok (NULL, "/");
	}

	respuesta [strlen (respuesta)-1] = '\0';
	printf("Resultado: %s\n", respuesta);
	
	
}

