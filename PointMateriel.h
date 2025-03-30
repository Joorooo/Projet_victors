#pragma once
#include <iostream>
#include "ObjetPhysique.h"
#include "Contraintes.h"
#include "ChampForces.h"
#include "vecteur.h"

class PointMateriel : public ObjetPhysique {
	private:
	
	Vecteur pos3D; //vecteur position dans le repère tridimentionnel carthésien
	
	public:
	
	//constucteur
	PointMateriel (const Vecteur &e, const Vecteur &e_prime, Contrainte& c, const ChampForces &champ_f, const Vecteur &pos3D, 
	double m, double charge = 0, double dim = 3);
	
	//methodes publiques 
	double E_cin() const;
	void mod_pos3D(double a, double b, double c);
	virtual Vecteur evolution(double temps) const override;
};
	
	
	
	
