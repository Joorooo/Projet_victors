#pragma once
#include "ForceCentrale.h"

class ChampNewtonien : public ForceCentrale {
	public:
	
	//methode publique
	virtual Vecteur force(const ObjetPhysique &p, double t = 0) const;
	
	//constructeur
	ChampNewtonien(const ObjetPhysique &p, double prec);
};
