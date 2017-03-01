#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define RCVSIZE 1024

int main (int argc, char *argv[]) {
  if(argc == 2){	
	  struct sockaddr_in adresse, client;
	  int port= atoi(argv[1]);
	  int valid= 1;
	  socklen_t alen= sizeof(client);
	  char buffer[RCVSIZE];
	
	  //create socket
	  int desc= socket(AF_INET, SOCK_STREAM, 0);
	
	  // handle error
	  if (desc < 0) {
	    perror("cannot create socket\n");
	    return -1;
	  }
	
	  setsockopt(desc, SOL_SOCKET, SO_REUSEADDR, &valid, sizeof(int));
	
	  adresse.sin_family= AF_INET;
	  adresse.sin_port= htons(port);
	  adresse.sin_addr.s_addr= htonl(INADDR_ANY);
	
	  if (bind(desc, (struct sockaddr*) &adresse, sizeof(adresse)) == -1) {
	    perror("Bind fail\n");
	    close(desc);
	    return -1;
	  }
	
	
	  if (listen(desc, 5) < 0) {
	    printf("Listen failed\n");
	    return -1;
	  }
	
	  while (1) {
	
	    int rqst= accept(desc, (struct sockaddr*)&client, &alen);
		int pid = fork();
		
		switch (pid){
			case -1 : printf("Erreur de création de fils\n");
			case 0 : //Fils
				while(1){
					int msgSize= recv(rqst,buffer,RCVSIZE,0);
					printf("Sock wait : %d Sock accept : %d\n", desc, rqst);
				    while (msgSize > 0) {
				      send(rqst,buffer,msgSize,0);
				      printf("%s",buffer);
				      memset(buffer,0,RCVSIZE);
				      msgSize= recv(rqst,buffer,RCVSIZE,0);
						}
					close(rqst);
					exit(0);
					}
				
			default : 
				printf("PID : %d\n", pid);
				close(rqst);
			}
	
	  }
	
	close(desc);
	}else{
		printf("Usage : ./Serveur <Port>\n");
	}
return 0;
}

