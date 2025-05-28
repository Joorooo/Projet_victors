CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++17
CXXFLAGS += -pedantic -Wall 

# Règles pour générer les exécutables
all: testIntegrateur1 testPomme

# Compilation des exécutables

testIntegrateur1: testIntegrateur1.o IntegrateurEulerCromer.o ObjetMobile.o ObjetPhysique.o PointMateriel.o ChampForces.o ForceUniforme.o GravitationConstante.o Contraintes.o Libre.o vecteur.o
testPomme: testPomme.o IntegrateurEulerCromer.o ObjetMobile.o ObjetPhysique.o PointMateriel.o ChampForces.o ForceCentrale.o ChampNewtonien.o Contraintes.o Libre.o vecteur.o

# Compilation des fichiers objets
ChampForces.o: ChampForces.cc ChampForces.h vecteur.h ObjetPhysique.h \
 ObjetMobile.h Contraintes.h
ForceUniforme.o: ForceUniforme.cc ForceUniforme.h ChampForces.h vecteur.h \
 ObjetPhysique.h ObjetMobile.h Contraintes.h
GravitationConstante.o: GravitationConstante.cc GravitationConstante.h \
 ForceUniforme.h ChampForces.h vecteur.h ObjetPhysique.h ObjetMobile.h \
 Contraintes.h constantes.h
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
testIntegrateur1.o: testIntegrateur1.cc IntegrateurEulerCromer.h \
 Integrateur.h ObjetMobile.h vecteur.h PointMateriel.h ObjetPhysique.h \
 Contraintes.h ChampForces.h GravitationConstante.h ForceUniforme.h \
 Libre.h
testPomme.o: testPomme.cc PointMateriel.h ObjetPhysique.h ObjetMobile.h \
 vecteur.h Contraintes.h ChampForces.h ChampNewtonien.h ForceCentrale.h \
 Libre.h IntegrateurEulerCromer.h Integrateur.h constantes.h
vecteur.o: vecteur.cc vecteur.h

# Nettoyage des fichiers intermédiaires
clean:
	rm -f *.o testIntegrateur1 testPomme
