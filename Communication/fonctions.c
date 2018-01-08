#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#define TAILLEBUF 20


int envoi(
	/*identifiant de la machine serveur*/struct hostent *serveur_host,
	/* chaine à envoyer */char *msg,
	/* id du serveur */ char *id_serveur,
	/* numéro de port*/ int port) {
			
	static struct sockaddr_in addr_serveur; // adresse de la socket coté serveur
		
	socklen_t lg; // taille de l'addresse socket
		
	int sock; // descripteur de la socket locale
		
	char buffer[TAILLEBUF]; // buffer de réception
		
	/* En option*/ // char *reponse; // chaine reçue en réponse
		
	int nb_octets; // nombre d'octets lus ou envoyés
	
	sock = socket(AF_INET, SOCK_DGRAM, 0); // création d'une socket UDP
	
	if (sock == -1) { // Test création socket
		perror("erreur création socket");
		exit(1);
	}
		
	serveur_host = gethostbyname(id_serveur); // récupération identifiant du serveur
	if (serveur_host==NULL) { //Vérification du serveur
		perror("erreur adresse serveur");
		exit(1);
	}
	
	bzero(&addr_serveur, sizeof(struct sockaddr_in)); // création adresse socket destinatrice
	addr_serveur.sin_family = AF_INET;
	addr_serveur.sin_port = htons(port);
	memcpy(&addr_serveur.sin_addr.s_addr,serveur_host -> h_addr, serveur_host -> h_length);
		// on envoie le message	au serveur
	lg = sizeof(struct sockaddr_in);
	nb_octets = sendto(sock, msg, strlen(msg)+1, 0,
	(struct sockaddr*)&addr_serveur, lg);
	if (nb_octets == -1) {
		perror("erreur envoi message");
		exit(1); 
	}
	//printf("paquet envoyé, nb_octets = %d\n",nb_octets);
		// on attend la réponse du serveur
	/* En option 
	/*
	nb_octets = recvfrom(sock, buffer, TAILLEBUF, 0,(struct sockaddr*)&addr_serveur, &lg);
	if (nb_octets == -1) {
		perror("erreur réponse serveur");
		exit(1);
	}
	reponse = (char *)malloc(nb_octets * sizeof(char));
	memcpy(reponse, buffer, nb_octets);
	printf("reponse recue du serveur : %s\n",reponse);
	*/
	close(sock);	// on ferme la socket
}

int reception(
	/* identifiant du client */ struct hostent *host_client,
	/* numéro de port*/ int port,
	/* timeout */  int timeout) {

	static struct sockaddr_in addr_local; 	// adresse de la socket locale

	static struct sockaddr_in addr_client; 	// adresse de la socket coté serveur

	socklen_t lg; 	// taille de l'addresse socket

	int sock; 	// descripteur de la socket locale
	
	/* En option */ //char *reponse = "bien recu"; // chaine à envoyer en réponse
	
	char buffer[TAILLEBUF]; // buffer de réception

	char *chaine; 	// chaine reçue
	
	int nb_octets; // nombre d'octets lus ou envoyés
 
	sock = socket(AF_INET, SOCK_DGRAM, 0); 	// création de la socket
	if (sock == -1) { // test création
		perror("erreur création socket");
		exit(1);
	}
		// liaison de la socket sur le port passé en paramètre
	bzero(&addr_local, sizeof(struct sockaddr_in));
	addr_local.sin_family = AF_INET;
	addr_local.sin_port = htons(port);
	addr_local.sin_addr.s_addr=htonl(INADDR_ANY);
	if( bind(sock, (struct sockaddr*)&addr_local,sizeof(addr_local))== -1 ) {
		perror("erreur bind");
		exit(1);
	}
		// attente de données venant d'un client
	lg = sizeof(struct sockaddr_in);
	nb_octets = recvfrom(sock, buffer, TAILLEBUF, 0,(struct sockaddr *)&addr_client, &lg);
	if (nb_octets == -1) {
		perror("erreur réception paquet");
		exit(1);
	}
	/* Option */
	// récupère nom de la machine émettrice des données
	/*
	host_client = gethostbyaddr(&(addr_client.sin_addr),
	sizeof(long), AF_INET);
	if (host_client == NULL) {
		perror("erreur gethostbyaddr");
		exit(1);
	}
	*
		// affichage message reçu et coordonnées émetteur
	chaine = (char *)malloc(nb_octets * sizeof(char));
	memcpy(chaine, buffer, nb_octets);
	printf("recu message %s de la part de %s sur le port %d\n", chaine, host_client->h_name,ntohs(addr_client.sin_port));
		// envoi de la réponse à l'émetteur
	nb_octets = sendto(sock, reponse, strlen(reponse)+1,0,(struct sockaddr*)&addr_client, lg);
	if (nb_octets == -1) {
		perror("erreur envoi réponse");
		exit(1);
	}
	*/

	close(sock); 	// fermeture la socket
}