CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++17
CXXFLAGS += -pedantic -Wall 

# Règles pour générer les exécutables
all: testvecteurs testPointMateriel testIntegrateur1 testSysteme

# Compilation des exécutables
testSysteme: testSysteme.o Systeme.o ObjetPhysique.o Contraintes.o ChampForces.o \
            ChampNewtonien.o ForceCentrale.o ForceUniforme.o GravitationConstante.o \
            IntegrateurEulerCromer.o ObjetMobile.o PointMateriel.o vecteur.o Libre.o

testvecteurs: testvecteurs.o vecteur.o

testPointMateriel: testPointMateriel.o PointMateriel.o vecteur.o ObjetMobile.o \
                 ObjetPhysique.o Contraintes.o ChampForces.o GravitationConstante.o \
                 Libre.o ForceUniforme.o

testIntegrateur1: testIntegrateur1.o IntegrateurEulerCromer.o ObjetMobile.o \
                PointMateriel.o ObjetPhysique.o Contraintes.o ChampForces.o \
                GravitationConstante.o Libre.o vecteur.o ForceUniforme.o

# Règles pour les fichiers objets
ChampForces.o: ChampForces.cc ChampForces.h vecteur.h ObjetPhysique.h ObjetMobile.h Contraintes.h

ChampNewtonien.o: ChampNewtonien.cc ChampNewtonien.h ForceCentrale.h ChampForces.h vecteur.h \
                ObjetPhysique.h ObjetMobile.h Contraintes.h constantes.h

Contraintes.o: Contraintes.cc Contraintes.h vecteur.h

ForceCentrale.o: ForceCentrale.cc ForceCentrale.h ChampForces.h vecteur.h \
               ObjetPhysique.h ObjetMobile.h Contraintes.h

ForceUniforme.o: ForceUniforme.cc ForceUniforme.h ChampForces.h vecteur.h \
               ObjetPhysique.h ObjetMobile.h Contraintes.h

GravitationConstante.o: GravitationConstante.cc GravitationConstante.h ForceUniforme.h \
                      ChampForces.h vecteur.h ObjetPhysique.h ObjetMobile.h Contraintes.h \
                      constantes.h

IntegrateurEulerCromer.o: IntegrateurEulerCromer.cc IntegrateurEulerCromer.h Integrateur.h \
                         ObjetMobile.h vecteur.h

Libre.o: Libre.cc Libre.h Contraintes.h vecteur.h ObjetPhysique.h ObjetMobile.h ChampForces.h

ObjetMobile.o: ObjetMobile.cc ObjetMobile.h vecteur.h

ObjetPhysique.o: ObjetPhysique.cc ObjetPhysique.h ObjetMobile.h vecteur.h \
               Contraintes.h ChampForces.h

PointMateriel.o: PointMateriel.cc PointMateriel.h ObjetPhysique.h ObjetMobile.h \
               vecteur.h Contraintes.h ChampForces.h Dessinable.h SupportADessin.h

Systeme.o: Systeme.cc Systeme.h ObjetPhysique.h ObjetMobile.h vecteur.h \
          Contraintes.h ChampForces.h Integrateur.h 

testIntegrateur1.o: testIntegrateur1.cc IntegrateurEulerCromer.h Integrateur.h \
                  ObjetMobile.h vecteur.h PointMateriel.h ObjetPhysique.h \
                  Contraintes.h ChampForces.h Dessinable.h SupportADessin.h \
                  GravitationConstante.h ForceUniforme.h Libre.h

testPointMateriel.o: testPointMateriel.cc vecteur.h \
                   GravitationConstante.h ForceUniforme.h ChampForces.h ObjetPhysique.h \
                   ObjetMobile.h Contraintes.h Libre.h PointMateriel.h Dessinable.h \
                   SupportADessin.h

testSysteme.o: testSysteme.cc Systeme.h ObjetPhysique.h ObjetMobile.h \
             vecteur.h Contraintes.h ChampForces.h Integrateur.h Libre.h \
             ChampNewtonien.h ForceCentrale.h PointMateriel.h Dessinable.h \
             SupportADessin.h IntegrateurEulerCromer.h

testvecteurs.o: testvecteurs.cc vecteur.h

vecteur.o: vecteur.cc vecteur.h

# Nettoyage des fichiers intermédiaires
clean:
	rm -f *.o testvecteurs testIntegrateur1 testPointMateriel testSysteme
