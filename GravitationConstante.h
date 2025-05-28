#pragma once
#include <iostream>
#include "ForceUniforme.h"

class GravitationConstante : public ForceUniforme {
	public:
	
	//constructeur par défaut
	GravitationConstante();
	
	//méthode publique
	virtual std::ostream& affiche(std::ostream& sortie) const override;
};
