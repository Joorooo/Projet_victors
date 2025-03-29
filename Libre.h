#pragma once
#include <iostream>
#include "Contraintes.h"
#include "vecteur.h"

class ObjetPhysique;

class Libre : public Contrainte {
	public:
	
	//methodes publiques
	Vecteur applique_force(const ObjetPhysique &p, const Vecteur &force, double t = 0) const;
	Vecteur position(const ObjetPhysique &p) const;
	Vecteur vitesse(const ObjetPhysique &p) const;
};
	
