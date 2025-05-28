#pragma once
#include <iostream>
#include "vecteur.h"

class ObjetPhysique;

class ChampForces {
	public:
	
	//méthodes virtuelles pures
	virtual Vecteur force(const ObjetPhysique &p, double t = 0) const = 0;
	virtual std::ostream& affiche(std::ostream& sortie) const = 0;
	
	//destructeur par défaut
	virtual ~ChampForces() = default;
};

//opérateur d'affichage
std::ostream& operator<<(std::ostream& sortie, const ChampForces &champ_f);
