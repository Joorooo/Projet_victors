CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++11 
CXXFLAGS += -pedantic -Wall 

# Règles pour générer les exécutables
all: testPointMateriel

# Compilation des exécutables
testPointMateriel: testPointMateriel.o PointMateriel.o GravitationConstante.o vecteur.o

# Compilation des fichiers objets
GravitationConstante.o: GravitationConstante.cc GravitationConstante.h \
 vecteur.h PointMateriel.h constantes.h
PointMateriel.o: PointMateriel.cc PointMateriel.h vecteur.h \
 GravitationConstante.h
testPointMateriel.o: testPointMateriel.cc vecteur.h \
 GravitationConstante.h PointMateriel.h
vecteur.o: vecteur.cc vecteur.h

# Nettoyage des fichiers intermédiaires
clean:
	rm -f *.o testPointMateriel
