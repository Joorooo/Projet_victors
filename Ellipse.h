#pragma once
#include <iostream>
#include "Contraintes.h"
#include "vecteur.h"

class ObjetPhysique;

class Ellipse : public Contrainte {
	public:
	
	//methodes publiques
	Vecteur applique_force(const ObjetPhysique &p, const Vecteur &force, double t = 0) const;
	virtual Vecteur position(const ObjetPhysique &obj) const override;
	virtual Vecteur vitesse(const ObjetPhysique &obj) const override;
	virtual std::ostream& affiche(std::ostream& sortie) const override;
	virtual std::unique_ptr<Contrainte> copie() const override;
};
