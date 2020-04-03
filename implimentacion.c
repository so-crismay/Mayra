#include <stdio.h>
#include <string.h>

int main ()
{
	
	char nombre[20];
	int a,b;
	int Palindromo = 1;
	printf("Escribir nombre\n");
	fflush (stdout);
	gets (nombre);
	b=strlen(nombre-1);
	
	for (a=0; a<strlen(nombre)/2; a++, b--)
	{
		if (*(nombre +a)!=*(nombre+b))
		{
			
			Palindromo = 0;
			break;
		}
	}
	if (Palindromo)
		printf("Tu nombre SI es Palindromo.\n");
	else
		printf("NO es un nombre Palindromo");
	return (0);
}

	


