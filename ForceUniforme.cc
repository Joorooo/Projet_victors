#include <iostream>
#include "ForceUniforme.h"
#include "ObjetPhysique.h"

using namespace std;

//constructeur
ForceUniforme::ForceUniforme(const Vecteur &intensite)
:intensite(intensite)
{}

//méthodes publiques
Vecteur ForceUniforme::force(const ObjetPhysique &p, double t) const {
	return p.get_m()*intensite;
}

//accesseur
Vecteur ForceUniforme::get_intensite() const {return intensite;}
