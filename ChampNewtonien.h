#pragma once
#include "ForceCentrale.h"

class ChampNewtonien : public ForceCentrale {
	public:
	
	//methode publique
	virtual Vecteur force(const ObjetPhysique &p, double t = 0) const;
	virtual std::ostream& affiche(std::ostream& sortie) const override;
	
	//constructeur
	ChampNewtonien(const ObjetPhysique &p, double prec);
};
