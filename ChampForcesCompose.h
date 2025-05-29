#pragma once
#include <iostream>
#include <vector>
#include "ChampForces.h"
#include "ObjetPhysique.h"

class ChampForcesCompose : public ChampForces {
	private:
	
	std::vector<ChampForces*> champs; //tableau dynamique de pointeurs à la C sur des champs de forces
	
	public:
	
	//constructeur
	ChampForcesCompose(const std::vector<ChampForces*> &autres_champs);
	
	//destructeur
	virtual ~ChampForcesCompose();

	//méthodes publiques
	virtual Vecteur force(const ObjetPhysique &p, double t = 0) const override;
	void ajout_champ(ChampForces* c);
	virtual std::ostream& affiche(std::ostream& sortie) const override;
};
	
	
