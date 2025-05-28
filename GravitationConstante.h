#pragma once
#include <iostream>
#include "vecteur.h"

class PointMateriel;

class GravitationConstante {
	private:
	
	Vecteur intensite; //intensité du champ
	
	public:
	
	//constructeur par défaut
	GravitationConstante();
	
	//méthodes publiques
	Vecteur force(const PointMateriel &p, double t = 0) const;
	Vecteur get_intensite() const;
};

//opérateur d'affichage
std::ostream& operator<<(std::ostream& sortie, const GravitationConstante &champ_g); //affiche l'attribut intensité
