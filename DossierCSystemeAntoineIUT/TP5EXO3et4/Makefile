# BIB peut prendre l'une des deux valeurs : dijkstra ou  semposix
# elle correspond à la bibliothèque qu'on souhaite utiliser 

BIB=dijkstra

ALL: init voiture camion clear

dijkstra.o: dijkstra.c dijkstra.h
	cc -c dijkstra.c
semposix.o: semposix.c semposix.h
	cc -c semposix.c

init: init.c $(BIB).o
	cc -o init init.c $(BIB).o -pthread -Wall

voiture: voiture.c $(BIB).o
	cc -o voiture voiture.c $(BIB).o -pthread -Wall
camion: camion.c $(BIB).o
	cc -o camion camion.c $(BIB).o -pthread -Wall
clear: clear.c $(BIB).o
	cc -o clear clear.c $(BIB).o -pthread -Wall
clean:
	rm *.o
	rm init clear camion voiture
