# Variable pour MAP
MAP_FLAG =

# Règle par défaut : compiler le programme
main: main.o Trajet.o TrajetSimple.o Node.o L_trajet.o TrajetCompose.o Catalogue.o
	g++ -ansi -pedantic -Wall -std=c++11 -o trajets main.o Trajet.o TrajetSimple.o Node.o L_trajet.o TrajetCompose.o Catalogue.o

main.o: main.cpp Trajet.h
	g++ -ansi -pedantic -Wall -std=c++11 $(MAP_FLAG) -c main.cpp

Trajet.o: Trajet.cpp Trajet.h
	g++ -ansi -pedantic -Wall -std=c++11 $(MAP_FLAG) -c Trajet.cpp

TrajetSimple.o: TrajetSimple.cpp TrajetSimple.h
	g++ -ansi -pedantic -Wall -std=c++11 $(MAP_FLAG) -c TrajetSimple.cpp

Node.o: Node.cpp Node.h
	g++ -ansi -pedantic -Wall -std=c++11 $(MAP_FLAG) -c Node.cpp

L_trajet.o: L_trajet.cpp L_trajet.h
	g++ -ansi -pedantic -Wall -std=c++11 $(MAP_FLAG) -c L_trajet.cpp

TrajetCompose.o: TrajetCompose.cpp TrajetCompose.h
	g++ -ansi -pedantic -Wall -std=c++11 $(MAP_FLAG) -c TrajetCompose.cpp

Catalogue.o: Catalogue.cpp Catalogue.h
	g++ -ansi -pedantic -Wall -std=c++11 $(MAP_FLAG) -c Catalogue.cpp

# Nettoyage des fichiers générés
clean:
	rm -f main.o Trajet.o TrajetSimple.o Node.o L_trajet.o TrajetCompose.o Catalogue.o trajets

# Reconstruction complète
rebuild: clean main

# Compiler avec MAP
debug:
	$(MAKE) MAP_FLAG=-DMAP
