#pragma once
#include <iostream>
#include "ChampForces.h"
#include "ObjetPhysique.h"
#include "vecteur.h"

class Vide : public ChampForces {
	public:
	 
	//méthodes publiques
	virtual Vecteur force(const ObjetPhysique &p, double t = 0) const override;
	virtual std::ostream& affiche(std::ostream& sortie) const override;
};
