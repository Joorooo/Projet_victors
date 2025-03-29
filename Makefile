CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++11 
CXXFLAGS += -pedantic -Wall 

# Règles pour générer les exécutables
all: testvecteurs testPointMateriel

# Compilation des exécutables
testvecteurs: testvecteurs.o vecteur.o
	$(CXX) testvecteurs.o vecteur.o -o testvecteurs

testPointMateriel: testPointMateriel.o PointMateriel.o vecteur.o ObjetMobile.o ObjetsPhysiques.o Contraintes.o ChampForces.o GravitationConstante.o Libre.o
	$(CXX) testPointMateriel.o PointMateriel.o vecteur.o ObjetMobile.o ObjetsPhysiques.o Contraintes.o ChampForces.o GravitationConstante.o Libre.o -o testPointMateriel

# Compilation des fichiers objets
ChampForces.o: ChampForces.cc ChampForces.h vecteur.h ObjetsPhysiques.h ObjetMobile.h Contraintes.h
Contraintes.o: Contraintes.cc Contraintes.h vecteur.h
GravitationConstante.o: GravitationConstante.cc GravitationConstante.h ChampForces.h vecteur.h constantes.h
Libre.o: Libre.cc Libre.h Contraintes.h
ObjetMobile.o: ObjetMobile.cc ObjetMobile.h vecteur.h
ObjetsPhysiques.o: ObjetsPhysiques.cc ObjetsPhysiques.h ObjetMobile.h vecteur.h Contraintes.h ChampForces.h
PointMateriel.o: PointMateriel.cc PointMateriel.h ObjetsPhysiques.h ObjetMobile.h vecteur.h Contraintes.h ChampForces.h
testPointMateriel.o: testPointMateriel.cc vecteur.h GravitationConstante.h ChampForces.h Libre.h Contraintes.h ObjetsPhysiques.h ObjetMobile.h PointMateriel.h
testvecteurs.o: testvecteurs.cc vecteur.h
vecteur.o: vecteur.cc vecteur.h

# Nettoyage des fichiers intermédiaires
clean:
	rm -f *.o testvecteurs testPointMateriel
