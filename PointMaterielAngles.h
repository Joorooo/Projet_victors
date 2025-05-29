#pragma once
#include <iostream>
#include "PointMateriel.h"

class PointMaterielAngles : public PointMateriel {
	public:
	
	//utilise les contructeurs de PointMateriel
	using PointMateriel::PointMateriel;
	
	//méthode publique
	virtual std::ostream& affiche(std::ostream& sortie) const override;
	
	//redéfinition du modificateur du vecteur d'état E
	virtual void set_E(const Vecteur &v) override;
	
	private:
	
	//methode privée
	double remise_angle(double angle) const;
};
