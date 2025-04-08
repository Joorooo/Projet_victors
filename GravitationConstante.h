#pragma once
#include <memory>
#include <iostream>
#include "ForceUniforme.h"

class PointMateriel;

class GravitationConstante : public ForceUniforme {
	public:
	
	//constructeur par defaut
	GravitationConstante();
	
	//methode publique
	virtual std::ostream& affiche(std::ostream& sortie) const override;
	virtual std::unique_ptr<ChampForces> clone() const override;



};
