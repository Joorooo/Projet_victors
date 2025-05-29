#pragma once
#include <iostream>
#include "ObjetPhysique.h"

class PointMateriel : public ObjetPhysique {
	public:
	
	//utilise les contructeurs de ObjetPhysique
	using ObjetPhysique::ObjetPhysique;
	
	//méthodes publiques
	virtual std::ostream& affiche(std::ostream& sortie) const override;
	virtual void dessine_sur(SupportADessin& support) const override;
};
	
	
	
	
