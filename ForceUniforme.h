#pragma once
#include <iostream>
#include "ChampForces.h"
#include "ObjetPhysique.h"
#include "vecteur.h"

class ForceUniforme : public ChampForces {
	protected:
	
	Vecteur intensite; //intensité du champ de force
	
	public:
	
	//constructeur
	ForceUniforme(const Vecteur &intensite);
	
	//méthode publique
	virtual Vecteur force(const ObjetPhysique &p, double t = 0) const;
};
