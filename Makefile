CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++11 
CXXFLAGS += -pedantic -Wall 

# Règles pour générer les exécutables
all: testPointMateriel testIntegrateur1 testPomme

# Compilation des exécutables

testPointMateriel: testPointMateriel.o PointMateriel.o vecteur.o ObjetMobile.o ObjetPhysique.o Contraintes.o ChampForces.o GravitationConstante.o Libre.o ForceUniforme.o

testIntegrateur1: testIntegrateur1.o IntegrateurEulerCromer.o ObjetMobile.o PointMateriel.o ObjetPhysique.o Contraintes.o ChampForces.o GravitationConstante.o Libre.o vecteur.o ForceUniforme.o

testPomme: testPomme.o PointMateriel.o ObjetMobile.o  ObjetPhysique.o ChampNewtonien.o GravitationConstante.o Libre.o IntegrateurEulerCromer.o  vecteur.o constantes.h ForceCentrale.o ChampForces.o ForceUniforme.o

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
testPointMateriel.o: testPointMateriel.cc vecteur.h \
 GravitationConstante.h ForceUniforme.h ChampForces.h ObjetPhysique.h \
 ObjetMobile.h Contraintes.h Libre.h PointMateriel.h
testPomme.o: testPomme.cc PointMateriel.h ObjetPhysique.h ObjetMobile.h \
 vecteur.h Contraintes.h ChampForces.h ChampNewtonien.h ForceCentrale.h \
 GravitationConstante.h ForceUniforme.h Libre.h IntegrateurEulerCromer.h \
 Integrateur.h constantes.h
testvecteurs.o: testvecteurs.cc vecteur.h
vecteur.o: vecteur.cc vecteur.h


# Nettoyage des fichiers intermédiaires
clean:
	rm -f *.o testIntegrateur1 testPointMateriel testPomme
