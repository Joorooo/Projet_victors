#pragma once
#include <iostream>
#include "ObjetPhysique.h"

class PointMateriel : public ObjetPhysique {
	public:
	
	//constucteur
	using ObjetPhysique::ObjetPhysique;
	
	//methode publique
	virtual std::ostream& affiche(std::ostream& sortie) const override;
};
	
	
	
	
