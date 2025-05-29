#pragma once
#include <iostream>
#include "PointMateriel.h"

class PointMaterielAngles : public PointMateriel {
	public:
	
	//utilise les contructeurs de PointMateriel
	using PointMateriel::PointMateriel;
	
	//méthodes publiques
	virtual std::ostream& affiche(std::ostream& sortie) const override;
	virtual void set_E(const Vecteur &v) override;
	
	private:
	
	//methode privée
	double remise_angle(double angle) const; //prend un angle en radian en paramêtre et le remet dans l'interval [0, 2pi[
};
