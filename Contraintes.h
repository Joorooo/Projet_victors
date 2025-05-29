#pragma once
#include <iostream>
#include "vecteur.h"

class ObjetPhysique; //pré-déclaration de la classe ObjetPhysique

class Contrainte {
	protected:
	
	static constexpr double limite = 1E-9; //variable de classe représentant la masse minimale que peut avoir un objet subissant une contrainte
	
	public:
	
	//destruteur
	virtual ~Contrainte() = default;
	
	//méthodes virtuelles pures
	virtual Vecteur applique_force(const ObjetPhysique &p, const Vecteur &force, double t = 0) const = 0;
	virtual Vecteur position(const ObjetPhysique &p) const  = 0;
	virtual Vecteur vitesse(const ObjetPhysique &p) const = 0;
	virtual std::ostream& affiche(std::ostream& sortie) const = 0;
};

//opérateur d'affichage externe
std::ostream& operator<<(std::ostream& sortie, const Contrainte &c);
