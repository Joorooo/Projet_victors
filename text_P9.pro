QMAKE_CXXFLAGS += -std=c++17

CONFIG += console

TARGET = exerciceP9_text

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general

SOURCES += \
    exerciceP9_text.cc \
    TextViewer.cc

HEADERS += \
    ../general/ChampForces.h \
    ../general/ChampForcesCompose.h \
    ../general/ChampNewtonien.h \
    ../general/constantes.h \
    ../general/Contraintes.h \
    ../general/ForceCentrale.h \
    ../general/ForceUniforme.h \
    ../general/GravitationConstante.h \
    ../general/Integrateur.h \
    ../general/IntegrateurEulerCromer.h \
    ../general/ObjetMobile.h \
    ../general/ObjetPhysique.h \
    ../general/PointMateriel.h \
    ../general/Systeme.h \
    ../general/vecteur.h \
    ../general/Vide.h \
    ../general/Libre.h \
    TextViewer.h \
    ../general/Dessinable.h \
    ../general/SupportADessin.h 
    
