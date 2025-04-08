#pragma once
#include <iostream>
#include "Contraintes.h"
#include "vecteur.h"

class ObjetPhysique;

class Libre : public Contrainte {
	public:
	//Constructeur
	Libre() = default;
	
	//Destructeur
	~Libre() = default;
	
	//methodes publiques
	Vecteur applique_force(const ObjetPhysique &p, const Vecteur &force, double t = 0) const override;
	Vecteur position(const ObjetPhysique &p) const override;
	Vecteur vitesse(const ObjetPhysique &p) const override;
	std::ostream& affiche(std::ostream& sortie) const override;
    std::unique_ptr<Contrainte> clone() const override;

};
	
