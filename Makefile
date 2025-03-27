CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++11 
CXXFLAGS += -pedantic -Wall 

# Règles pour générer les exécutables
all: testvecteurs testPointMateriel

# Compilation des exécutables
testvecteurs: testvecteurs.o vecteur.o

testPointMateriel: testPointMateriel.o PointMateriel.o constantes.o vecteur.o

# Compilation des fichiers objets
PointMateriel.o: PointMateriel.cc PointMateriel.h vecteur.h constantes.h

constantes.o: constantes.cc constantes.h vecteur.h PointMateriel.h

testPointMateriel.o: testPointMateriel.cc vecteur.h constantes.h PointMateriel.h

testvecteurs.o: testvecteurs.cc vecteur.h

vecteur.o: vecteur.cc vecteur.h

# Nettoyage des fichiers intermédiaires
clean:
	rm -f *.o testvecteurs testPointMateriel
