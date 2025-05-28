CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++17
CXXFLAGS += -pedantic -Wall 
CXXFLAGS += -g

# Règles pour générer les exécutables
all: testIntegrateurs

# Compilation des exécutables
testIntegrateurs: testIntegrateurs.o Systeme.o ObjetMobile.o ObjetPhysique.o PointMateriel.o \
ChampForces.o ForceUniforme.o GravitationConstante.o Contraintes.o Libre.o \
IntegrateurEulerCromer.o IntegrateurNewmark.o IntegrateurRungeKutta.o vecteur.o constantes.h \
TextViewer.o

# Compilation des fichiers objets
ChampForces.o: ChampForces.cc ChampForces.h vecteur.h ObjetPhysique.h \
 ObjetMobile.h Contraintes.h
ForceUniforme.o: ForceUniforme.cc ForceUniforme.h ChampForces.h vecteur.h \
 ObjetPhysique.h ObjetMobile.h Contraintes.h
GravitationConstante.o: GravitationConstante.cc GravitationConstante.h \
 ForceUniforme.h ChampForces.h vecteur.h ObjetPhysique.h ObjetMobile.h \
 Contraintes.h constantes.h
Contraintes.o: Contraintes.cc Contraintes.h vecteur.h
IntegrateurEulerCromer.o: IntegrateurEulerCromer.cc \
 IntegrateurEulerCromer.h Integrateur.h ObjetMobile.h vecteur.h
IntegrateurNewmark.o: IntegrateurNewmark.cc IntegrateurNewmark.h \
 Integrateur.h ObjetMobile.h vecteur.h
IntegrateurRungeKutta.o: IntegrateurRungeKutta.cc IntegrateurRungeKutta.h \
 Integrateur.h ObjetMobile.h vecteur.h
ObjetMobile.o: ObjetMobile.cc ObjetMobile.h vecteur.h
ObjetPhysique.o: ObjetPhysique.cc ObjetPhysique.h ObjetMobile.h vecteur.h \
 Contraintes.h ChampForces.h
PointMateriel.o: PointMateriel.cc PointMateriel.h ObjetPhysique.h \
 ObjetMobile.h vecteur.h Contraintes.h ChampForces.h
Systeme.o: Systeme.cc Systeme.h ObjetPhysique.h ObjetMobile.h vecteur.h \
 Contraintes.h ChampForces.h Integrateur.h
TextViewer.o: TextViewer.cc TextViewer.h SupportADessin.h PointMateriel.h \
 ObjetPhysique.h ObjetMobile.h vecteur.h Contraintes.h ChampForces.h \
 Systeme.h Integrateur.h
testIntegrateurs.o: testIntegrateurs.cc Systeme.h ObjetMobile.h ObjetPhysique.h \
 PointMateriel.h Contraintes.h Libre.h ChampForces.h ForceUniforme.h GravitationConstante.h \
 IntegrateurEulerCromer.h  IntegrateurNewmark.h IntegrateurRungeKutta.h Integrateur.h \
 vecteur.h constantes.h SupportADessin.h TextViewer.h
vecteur.o: vecteur.cc vecteur.h

# Nettoyage des fichiers intermédiaires
clean:
	rm -f *.o testIntegrateurs
