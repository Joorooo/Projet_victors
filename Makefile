CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++11 
# Partie commentée : choisissez les options que vous voulez avoir
# en décommentant la/les lignes correspondantes
#
CXXFLAGS += -pedantic -Wall # CXXFLAGS += -g # CXXFLAGS += -O2
# pour debugger
# pour optimiser la vitesse
all: testVecteur
Vecteur.o: Vecteur.cc Vecteur.h
testVecteur.o: testVecteur.cc Vecteur.h
testVecteur: testVecteur.o Vecteur.o
# Nettoyage des fichiers intermédiaires
clean:
	rm -f *.o testvecteur
