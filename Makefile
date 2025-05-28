CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++17
CXXFLAGS += -pedantic -Wall

# Règles pour générer les exécutables
all: testVecteur

# Compilation des exécutables
testVecteur: testVecteur.o vecteur.o

# Compilation des fichiers objets
testVecteur.o: testVecteur.cc vecteur.h
vecteur.o: vecteur.cc vecteur.h

# Nettoyage des fichiers intermédiaires
clean:
	rm -f *.o testVecteur

