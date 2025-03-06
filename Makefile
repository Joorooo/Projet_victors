CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++11 
# Partie commentée : choisissez les options que vous voulez avoir
# en décommentant la/les lignes correspondantes
#
CXXFLAGS += -pedantic -Wall # CXXFLAGS += -g # CXXFLAGS += -O2
# pour debugger
# pour optimiser la vitesse
all: testvecteurs
vecteur.o: vecteur.cc vecteur.h
testvecteurs.o: testvecteurs.cc vecteur.h
testvecteurs: testvecteurs.o vecteur.o
# Nettoyage des fichiers intermédiaires
clean:
	rm -f *.o testvecteurs
