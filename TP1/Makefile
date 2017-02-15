CC = gcc
CFLAGS = -Wall

serveur : serveur.o
	$(CC) $(CFLAGS) serveur.o -o Serveur
	
client : client.o
	$(CC) $(CFLAGS) client.o -o Client 
	
client.o: client.c
	$(CC) $(CFLAGS) -c client.c -o client.o
	
serveur.o: serveur.c
	$(CC) $(CFLAGS) -c serveur.c -o serveur.o
	
clean: 
	rm -rf *.o Client Serveur
