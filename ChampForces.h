#pragma once
#include <iostream>
#include "vecteur.h"

class ObjetPhysique;

class ChampForces {
	public:
	
	//methodes publiques
	virtual Vecteur force(const ObjetPhysique &p, double t = 0) const = 0;
	virtual std::ostream& affiche(std::ostream& sortie) const = 0;
	
	//destructeur
	virtual ~ChampForces();
};

//operateur d'affichage
std::ostream& operator<<(std::ostream& sortie, const ChampForces &champ_f);
