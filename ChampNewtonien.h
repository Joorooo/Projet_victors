#pragma once
#include "ForceCentrale.h"

class ChampNewtonien : public ForceCentrale {
	public:
	
	//methode publique
	virtual Vecteur force(const ObjetPhysique &p, double t = 0) const;
	std::unique_ptr<ChampForces> copie() const override;
	virtual std::ostream& affiche(std::ostream& sortie) const override;
	
	//constructeur
	ChampNewtonien(const ObjetPhysique &p, double prec);
	ChampNewtonien(const ChampNewtonien &champ_n) = default;
};
