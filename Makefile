CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++17
CXXFLAGS += -pedantic -Wall 

# Règles pour générer les exécutables
all: exerciceP11-spherique

# Compilation des exécutables
exerciceP11-spherique: exerciceP11-spherique.o Systeme.o PointMaterielAngles.o PointMateriel.o ObjetPhysique.o \
ObjetMobile.o ChampForces.o ForceUniforme.o GravitationConstante.o Contraintes.o Spherique.o \
IntegrateurEulerCromer.o vecteur.o constantes.h TextViewer.o

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
ObjetMobile.o: ObjetMobile.cc ObjetMobile.h vecteur.h
ObjetPhysique.o: ObjetPhysique.cc ObjetPhysique.h ObjetMobile.h vecteur.h \
 Contraintes.h ChampForces.h
PointMateriel.o: PointMateriel.cc PointMateriel.h ObjetPhysique.h \
 ObjetMobile.h vecteur.h Contraintes.h ChampForces.h
PointMaterielAngles.o: PointMaterielAngles.cc PointMaterielAngles.h \
 ObjetPhysique.h ObjetMobile.h Contraintes.h ChampForces.h
Systeme.o: Systeme.cc Systeme.h ObjetPhysique.h ObjetMobile.h vecteur.h \
 Contraintes.h ChampForces.h Integrateur.h
TextViewer.o: TextViewer.cc TextViewer.h SupportADessin.h PointMateriel.h \
 ObjetPhysique.h ObjetMobile.h vecteur.h Contraintes.h ChampForces.h \
 Systeme.h Integrateur.h
exerciceP11-spherique.o: exerciceP11-spherique.cc Systeme.h ObjetPhysique.h ObjetMobile.h \
 PointMateriel.h PointMaterielAngles.h Contraintes.h Spherique.h ChampForces.h ForceUniforme.h \
 GravitationConstante.h IntegrateurEulerCromer.h Integrateur.h vecteur.h constantes.h \
 SupportADessin.h TextViewer.h
vecteur.o: vecteur.cc vecteur.h

# Nettoyage des fichiers intermédiaires
clean:
	rm -f *.o exerciceP11-spherique
