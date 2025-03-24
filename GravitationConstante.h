#pragma once
#include <iostream>
#include "vecteur.h"

class PointMateriel;

class GravitationConstante {
	private:
	
	Vecteur intensite;
	
	public:
	
	//constructeur par defaut
	GravitationConstante();
	
	//methodes publiques
	Vecteur force(const PointMateriel &p, double t = 0) const;
	Vecteur get_intensite() const;
};

//operateurs externes 
std::ostream& operator<<(std::ostream& sortie, const GravitationConstante &champ_g); //affiche attribut intensité
