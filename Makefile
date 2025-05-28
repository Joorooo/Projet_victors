CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++17
CXXFLAGS += -pedantic -Wall

# Règles pour générer les exécutables
all: testSystem

# Compilation des exécutables
testSystem: testSystem.o Systeme.o PointMateriel.o ObjetPhysique.o ObjetMobile.o ForceCentrale.o \
ChampNewtonien.o ChampForces.o Contraintes.o Libre.o IntegrateurEulerCromer.o vecteur.o constantes.h \

# Compilation des fichiers objets
ChampForces.o: ChampForces.cc ChampForces.h vecteur.h ObjetPhysique.h \
 ObjetMobile.h Contraintes.h
ForceCentrale.o: ForceCentrale.cc ForceCentrale.h ChampForces.h vecteur.h \
 ObjetPhysique.h ObjetMobile.h Contraintes.h
ChampNewtonien.o: ChampNewtonien.cc ChampNewtonien.h ForceCentrale.h \
 ChampForces.h vecteur.h ObjetPhysique.h ObjetMobile.h Contraintes.h \
 constantes.h
Contraintes.o: Contraintes.cc Contraintes.h vecteur.h
Libre.o: Libre.cc Libre.h Contraintes.h vecteur.h ObjetPhysique.h \
 ObjetMobile.h ChampForces.h
IntegrateurEulerCromer.o: IntegrateurEulerCromer.cc \
 IntegrateurEulerCromer.h Integrateur.h ObjetMobile.h vecteur.h
ObjetMobile.o: ObjetMobile.cc ObjetMobile.h vecteur.h
ObjetPhysique.o: ObjetPhysique.cc ObjetPhysique.h ObjetMobile.h vecteur.h \
 Contraintes.h ChampForces.h
PointMateriel.o: PointMateriel.cc PointMateriel.h ObjetPhysique.h \
 ObjetMobile.h vecteur.h Contraintes.h ChampForces.h
Systeme.o: Systeme.cc Systeme.h ObjetPhysique.h ObjetMobile.h vecteur.h \
 Contraintes.h ChampForces.h Integrateur.h
testSystem.o: testSystem.cc Systeme.h ObjetPhysique.h ObjetMobile.h \
 vecteur.h Contraintes.h ChampForces.h Integrateur.h PointMateriel.h \
 ChampNewtonien.h ForceCentrale.h Libre.h IntegrateurEulerCromer.h constantes.h
vecteur.o: vecteur.cc vecteur.h

# Nettoyage des fichiers intermédiaires
clean:
	rm -f *.o testSystem
