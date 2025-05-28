#pragma once
#include <iostream>
#include "ObjetPhysique.h"

class PointMateriel : public ObjetPhysique {
	public:
	
	//constucteur
	using ObjetPhysique::ObjetPhysique;
	
	//méthodes publiques
	virtual std::ostream& affiche(std::ostream& sortie) const override;
};
	
	
	
	
