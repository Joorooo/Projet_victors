#pragma once
#include <iostream>
#include "vector"
#include "memory"
#include "ChampForces.h"

class ChampForcesCompose : public ChampForces {
	private:
	
	std::vector<std::unique_ptr<ChampForces>> champs; //tableau de unique pointeurs sur des champs de forces
	
	public:
	
	//constructeur
	ChampForcesCompose(const std::vector<std::unique_ptr<ChampForces>> &autres_champs);
	ChampForcesCompose(const ChampForcesCompose &autre_cfc);
	ChampForcesCompose() = default;
	
	//destructeur
	virtual ~ChampForcesCompose();

	//methodes publiques
	virtual Vecteur force(const ObjetPhysique &p, double t = 0) const override;
	virtual std::unique_ptr<ChampForces> copie() const override;
	void ajout_champ(const ChampForces &c);
	virtual std::ostream& affiche(std::ostream& sortie) const override;
	
};
	
	
