#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>

#include <string.h>
#include <netinet/in.h>

#include <arpa/inet.h>



int main(){
	
	int sock;
	int temp;
	int temp2;
	int conn;
	char *mess = "Coucou\0";
	
	struct sockaddr_in addr_srv;
	memset((char*)&addr_srv,0, sizeof(addr_srv));
	
	if((sock = socket(AF_INET, SOCK_STREAM, 0)) >= 0){
		printf("Socket Crée! \n");
	}else{
		printf("Echec de création du socket\n");
		exit(-1);
	}
	
	addr_srv.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr_srv.sin_port = htons(5050);
	addr_srv.sin_family = AF_INET;

	
	printf("Valeur de inet_aton client = %d\n", temp);
	printf("Valeur de sock client = %d\n", sock);
	
	conn = connect(sock, (struct sockaddr *) &addr_srv, sizeof(addr_srv));
	printf("Client connecté? : %d\n", conn);
	send(sock , mess, 150,0);
	sleep(5);
	

	return 0;
	
	
}
