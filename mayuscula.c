#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main ()
{
	
	char nombre[20];
	int a,b,i;
	int Palindromo = 1;
	
	printf("Escribir nombre\n");
	fflush (stdout);
	gets (nombre);
	b=strlen(nombre-1);
	
	for (a=0; a<strlen(nombre)/2; a++, b--)
	{
		if (*(nombre +a)!=*(nombre-b))
		{
			
			Palindromo = 0;
			break;
		}
	}
	if (Palindromo)
		printf("Tu nombre SI es Palindromo.\n");
	else
		printf("NO es un nombre Palindromo");
	for (i = 0; nombre[i] !='\0'; i++)
		nombre[i] = toupper(nombre[i]);
	printf(" %s \n", nombre);
	return (0);
}

