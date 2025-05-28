#pragma once
#include <iostream>
#include "Contraintes.h"
#include "ObjetPhysique.h"

class Libre : public Contrainte {
	public:
	
	//méthodes publiques
	Vecteur applique_force(const ObjetPhysique &p, const Vecteur &force, double t = 0) const;
	Vecteur position(const ObjetPhysique &p) const;
	Vecteur vitesse(const ObjetPhysique &p) const;
	virtual std::ostream& affiche(std::ostream& sortie) const override;
};
	
