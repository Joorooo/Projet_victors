CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++17
CXXFLAGS += -pedantic -Wall 

# Règles pour générer les exécutables
all: exerciceP9 exerciceP9-3.1 exerciceP9-7.3

# Compilation des exécutables
exerciceP9: exerciceP9.o Systeme.o PointMateriel.o ObjetPhysique.o ObjetMobile.o \
ChampForces.o ForceCentrale.o ChampNewtonien.o  ChampForces.o\
Vide.o Contraintes.o Libre.o IntegrateurEulerCromer.o vecteur.o constantes.h 
exerciceP9-3.1: exerciceP9-3.1.o Systeme.o PointMateriel.o ObjetPhysique.o ObjetMobile.o \
ChampForces.o ForceUniforme.o GravitationConstante.o Contraintes.o Libre.o IntegrateurEulerCromer.o \
vecteur.o constantes.h
exerciceP9-7.3 : exerciceP9-7.3.o Systeme.o PointMateriel.o ObjetPhysique.o ObjetMobile.o \
ChampForces.o Vide.o ForceCentrale.o ChampNewtonien.o Contraintes.o Libre.o IntegrateurEulerCromer.o \
vecteur.o constantes.h

# Compilation des fichiers objets
ChampForces.o: ChampForces.cc ChampForces.h vecteur.h ObjetPhysique.h \
 ObjetMobile.h Contraintes.h
ChampForcesCompose.o: ChampForcesCompose.cc ChampForcesCompose.h \
 ChampForces.h vecteur.h ObjetPhysique.h ObjetMobile.h Contraintes.h
Vide.o: Vide.cc Vide.h ChampForces.h vecteur.h ObjetPhysique.h \
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
ContrainteCompose.o: ContrainteCompose.cc ContrainteCompose.h \
 Contraintes.h vecteur.h ObjetPhysique.h ObjetMobile.h ChampForces.h
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
TextViewer.o: TextViewer.cc TextViewer.h SupportADessin.h PointMateriel.h \
 ObjetPhysique.h ObjetMobile.h vecteur.h Contraintes.h ChampForces.h \
 Systeme.h Integrateur.h
exerciceP9.o: exerciceP9.cc Systeme.h ObjetPhysique.h ObjetMobile.h \
 vecteur.h Contraintes.h ChampForces.h Integrateur.h PointMateriel.h \
 Vide.h ChampNewtonien.h ForceCentrale.h \
 ContrainteCompose.h Libre.h IntegrateurEulerCromer.h constantes.h
exerciceP9-3.1.o: exerciceP9-3.1.cc Systeme.h ObjetPhysique.h ObjetMobile.h \
 vecteur.h Contraintes.h ChampForces.h Integrateur.h PointMateriel.h ForceUniforme.h \
 GravitationConstante.h Libre.h
exerciceP9-7.3.o: exerciceP9-7.3.cc Systeme.h ObjetPhysique.h ObjetMobile.h \
 vecteur.h Contraintes.h ChampForces.h Integrateur.h PointMateriel.h \
 ChampNewtonien.h ForceCentrale.h Libre.h IntegrateurEulerCromer.h \
 Vide.h constantes.h
vecteur.o: vecteur.cc vecteur.h

# Nettoyage des fichiers intermédiaires
clean:
	rm -f *.o exerciceP9 exerciceP9-3.1 exerciceP9-7.3
