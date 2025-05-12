TEMPLATE = lib

CONFIG = staticlib
QMAKE_CXXFLAGS += -std=c++17

SOURCES += \
    ChampForces.cc \
    ChampForcesCompose.cc \
    ChampNewtonien.cc \
    Contraintes.cc \
    ForceCentrale.cc \
    ForceUniforme.cc \
    GravitationConstante.cc \
    IntegrateurEulerCromer.cc \
    ObjetMobile.cc \
    ObjetPhysique.cc \
    PointMateriel.cc \
    Systeme.cc \
    vecteur.cc \
    Vide.cc \
    Libre.cc
    
        

HEADERS += \
    ChampForces.h \
    ChampForcesCompose.h \
    ChampNewtonien.h \
    constantes.h \
    Contraintes.h \
    Dessinable.h \
    ForceCentrale.h \
    ForceUniforme.h \
    GravitationConstante.h \
    Integrateur.h \
    IntegrateurEulerCromer.h \
    ObjetMobile.h \
    ObjetPhysique.h \
    PointMateriel.h \
    SupportADessin.h \
    Systeme.h \
    vecteur.h \
    Vide.h \
    Libre.h
    
