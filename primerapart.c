#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int sock_conn, sock_listen, ret;
	struct sockaddr_in serv_adr;
	char buff[512];
	char buff2[512];
	char respuesta[512];
	// INICIALITZACIONS
	// Obrim el socket
	if ((sock_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		printf("Error creant socket");
	// Fem el bind al port
	// ES UN SOCKET DE ESCUCHA 
	
	// PROTOCOLOS QUE TILIZA 
	memset(&serv_adr, 0, sizeof(serv_adr));// inicialitza a zero serv_addr
	serv_adr.sin_family = AF_INET;
	
	// asocia el socket a cualquiera de las IP de la m?quina. 
	//htonl formatea el numero que recibe al formato necesario
	
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	// escucharemos en el port 9050
	serv_adr.sin_port = htons(9050);
	//asociar al socket 
	if (bind(sock_listen, (struct sockaddr *) &serv_adr, sizeof(serv_adr)) < 0)
		printf ("Error al bind");
	//La cola de peticiones pendientes no podr? ser superior a 4
	
	//indicamos que es un socket pasivo
	if (listen(sock_listen, 2) < 0)
		printf("Error en el Listen");
	
	int i;
	// Atenderemos solo 7 peticione se puede poner más 
	for(i=0;i<7;i++){
		printf ("Escuchando\n");
		// acepta la peticion de escucha 
		sock_conn = accept(sock_listen, NULL, NULL);
		// una vez se conecta el sistema nos da un soscket distinto para 
		//comunicarnos con el servido
		printf ("He recibido conexi?n\n");
		//sock_conn es el socket que usaremos para este cliente
		
		// Ahora recibimos su nombre, que dejamos en buff
		// indica el tamaño de lapeticion mensaje
		ret=read(sock_conn,buff, sizeof(buff));
		printf ("Recibido\n");
		
		// Tenemos que a?adirle la marca de fin de string 
		// para que no escriba lo que hay despues en el buffer
		buff[ret]='\0';
		
		//Escribimos el nombre en la consola
		
		printf ("Se ha conectado: %s\n",buff);
		
		
		char *p = strtok( buff, "/");
		int codigo =  atoi (p);
		p = strtok( NULL, "/");
		char nombre[20];
		strcpy (nombre, p);
		printf ("Codigo: %d, Nombre: %s\n", codigo, nombre);
		
		if (codigo ==1) //piden la longitd del nombre
			sprintf (buff2,"%d,",strlen (nombre));
		else if (codigo ==2)
			// quieren saber si el nombre es bonito
				if((nombre[0]=='M') || (nombre[0]=='S'))
			strcpy (buff2,"SI,");
				else
				strcpy (buff2,"NO,");
			else //indicar altura
				{
					p = strtok( NULL, "/");
					float altura =  atof (p);
					if (altura > 1.70)
						sprintf (respuesta," %s: eres alto",nombre);
					else
						sprintf (respuesta, "%s: eres bajo",nombre);
			}
			printf ("%s\n", buff2);
			// Y lo enviamos
			write (sock_conn,buff2, strlen(buff2));
			
			// Se acabo el servicio para este cliente
			close(sock_conn); 
	}
}

