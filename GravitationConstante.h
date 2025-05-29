#pragma once
#include <iostream>
#include "ForceUniforme.h"

class GravitationConstante : public ForceUniforme {
	public:
	
	//constructeur par défaut
	GravitationConstante();
	
	//méthodes publiques
        virtual Vecteur force(const ObjetPhysique &p, double t = 0) const;
	virtual std::ostream& affiche(std::ostream& sortie) const override;
};
