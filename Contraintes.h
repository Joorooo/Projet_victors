#pragma once
#include <iostream>
#include "vecteur.h"

class ObjetPhysique;

class Contrainte {
	public:
	
	//methodes à ce stade virtuelles pures
	virtual Vecteur applique_force(const ObjetPhysique &p, const Vecteur &force, double t = 0) const = 0;
	virtual Vecteur position(const ObjetPhysique &p) const  = 0;
	virtual Vecteur vitesse(const ObjetPhysique &p) const = 0;
	virtual std::ostream& affiche(std::ostream& sortie) const = 0;
};

//Opérateure externe
std::ostream& operator<<(std::ostream& sortie, const Contrainte &c);
