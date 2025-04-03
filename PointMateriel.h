#pragma once
#include <iostream>
#include "ObjetPhysique.h"
#include "Contraintes.h"
#include "ChampForces.h"
#include "vecteur.h"

class PointMateriel : public ObjetPhysique {
	public:
	
	//constucteur
	PointMateriel (const Vecteur &e, const Vecteur &e_prime, Contrainte& c, ChampForces &champ_f, 
	double m, double charge = 0, double dim = 3);
	
	//methodes publiques 
	double virtual E_cin() const override;
	virtual std::ostream& affiche(std::ostream& sortie) const override;
};
	
	
	
	
