CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++11 
CXXFLAGS += -pedantic -Wall 

# Règles pour générer les exécutables
all: testvecteurs testPointMateriel

# Compilation des exécutables
testvecteurs: testvecteurs.o vecteur.o

testPointMateriel: testPointMateriel.o PointMateriel.o GravitationConstante.o vecteur.o

# Compilation des fichiers objets
GravitationConstante.o: GravitationConstante.cc GravitationConstante.h \
 vecteur.h PointMateriel.h constantes.h
PointMateriel.o: PointMateriel.cc PointMateriel.h vecteur.h \
 GravitationConstante.h
testPointMateriel.o: testPointMateriel.cc vecteur.h \
 GravitationConstante.h PointMateriel.h
testvecteurs.o: testvecteurs.cc vecteur.h
vecteur.o: vecteur.cc vecteur.h

# Nettoyage des fichiers intermédiaires
clean:
	rm -f *.o testvecteurs testPointMateriel
