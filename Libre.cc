#pragma once
#include <iostream>
#include "Libre.h"
#include "ObjetPhysique.h"

using namespace std;

//methodes publiques
Vecteur Libre::applique_force(const ObjetPhysique &p, const Vecteur &force, double t) const {
	if (p.get_m() == 0) {
		return force;
	} else {
		return (1/p.get_m())*force;
	}
}
Vecteur Libre::position(const ObjetPhysique &p) const {return p.get_E();}
Vecteur Libre::vitesse(const ObjetPhysique &p) const {return p.get_E_prime();}
	
