#pragma once
#include <iostream>
#include <memory>
#include "vecteur.h"

class ObjetPhysique;

class ChampForces {
	public:
	
	//methode publique
	virtual Vecteur force(const ObjetPhysique &p, double t = 0) const = 0;
	virtual std::ostream& affiche(std::ostream& sortie) const = 0;
	virtual std::unique_ptr<ChampForces> clone() const = 0;  //permet la copie profonde
	
	//destructeur
	virtual ~ChampForces() = default;
};

//Operateur d'affichage
std::ostream& operator<<(std::ostream& sortie, const ChampForces &champ_f);
