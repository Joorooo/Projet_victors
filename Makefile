CXXFLAGS = -std=c++17
CXXFLAGS += -pedantic -Wall 

# Règles pour générer les exécutables
all: testvecteurs testPointMateriel testIntegrateur1

# Compilation des exécutables
testvecteurs: testvecteurs.o vecteur.o

testPointMateriel: testPointMateriel.o PointMateriel.o vecteur.o ObjetMobile.o ObjetPhysique.o Contraintes.o ChampForces.o GravitationConstante.o Libre.o

testIntegrateur1: testIntegrateur1.o IntegrateurEulerCromer.o ObjetMobile.o PointMateriel.o ObjetPhysique.o Contraintes.o ChampForces.o GravitationConstante.o Libre.o vecteur.o

# Compilation des fichiers objets
ChampForces.o: ChampForces.cc ChampForces.h vecteur.h ObjetPhysique.h \
  ObjetMobile.h Contraintes.h
Contraintes.o: Contraintes.cc
GravitationConstante.o: GravitationConstante.cc GravitationConstante.h \
  ChampForces.h vecteur.h constantes.h
IntegrateurEulerCromer.o: IntegrateurEulerCromer.cc Integrateur.h \
  ObjetMobile.h vecteur.h
Libre.o: Libre.cc Libre.h Contraintes.h vecteur.h ObjetPhysique.h \
  ObjetMobile.h ChampForces.h
ObjetMobile.o: ObjetMobile.cc ObjetMobile.h vecteur.h
ObjetPhysique.o: ObjetPhysique.cc ObjetPhysique.h ObjetMobile.h vecteur.h \
  Contraintes.h ChampForces.h
PointMateriel.o: PointMateriel.cc PointMateriel.h ObjetPhysique.h \
  ObjetMobile.h vecteur.h Contraintes.h ChampForces.h
testIntegrateur1.o: testIntegrateur1.cc IntegrateurEulerCromer.h \
  Integrateur.h ObjetMobile.h vecteur.h PointMateriel.h ObjetPhysique.h \
  Contraintes.h ChampForces.h GravitationConstante.h Libre.h
testPointMateriel.o: testPointMateriel.cc vecteur.h \
  GravitationConstante.h ChampForces.h Libre.h Contraintes.h \
  PointMateriel.h ObjetPhysique.h ObjetMobile.h
testvecteurs.o: testvecteurs.cc vecteur.h
vecteur.o: vecteur.cc vecteur.h
# Nettoyage des fichiers intermédiaires
clean:
	rm -f *.o testIntegrateur1 testvecteurs testPointMateriel
