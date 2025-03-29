#pragma once
#include <iostream>
#include "vecteur.h"

class ObjetPhysique;

class ChampForces {
	protected:
	
	Vecteur intensite;
	
	public:
	
	//constructeur
	ChampForces(const Vecteur &intensite);
	
	//methode publique
	Vecteur force(const ObjetPhysique &p, double t = 0) const;
	
	//accesseur
	Vecteur get_intensite() const;
	
};

//surcharge operateur d'affichage
std::ostream& operator<<(std::ostream& sortie, const ChampForces &champ_f); 
