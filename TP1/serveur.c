#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>

#include <string.h>
#include <netinet/in.h>

int main(){
	int sock;
	int acc = 0;
	char *mess = "";
	
	struct sockaddr_in my_addr;
	memset((char*)&my_addr,0, sizeof(my_addr));
	
	struct sockaddr_in addr_clt;
	socklen_t addr_clt_size = sizeof(addr_clt);
	
	if((sock = socket(AF_INET, SOCK_STREAM, 0)) >= 0){
		printf("Socket Crée! \n");
	}else{
		printf("Echec de création du socket\n");
		exit(-1);
	}
	
	my_addr.sin_addr.s_addr = INADDR_ANY;
	my_addr.sin_port = htons(5050);
	my_addr.sin_family = AF_INET;
	
	printf("Valeur de INADDR_ANY serveur = %d\n", INADDR_ANY);
	
	

	
	printf("Valeur de INADDR_ANY serveur = %d\n", INADDR_ANY);
	printf("Valeur de INADDR_LOOPBACK serveur = %d\n", INADDR_LOOPBACK);

	printf("Valeur de sock serveur = %d\n", sock);
	
	bind(sock, (struct sockaddr *) &my_addr, sizeof(struct sockaddr));
	listen(sock, 2);
	
	while(1){
		
		
		if(acc == 0){
			printf("Attente d'une connection\n");
			acc = accept(sock,(struct sockaddr *)&addr_clt , &addr_clt_size);
			printf("Valeur de accept serveur = %d\n", acc);
		}
		
		read(acc, mess, 20);
		sleep(5);
		printf("Message recu : %s\n", mess);
		
		
	}
		
		
		
		
	
	
	return 0;
}
