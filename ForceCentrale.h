#pragma once
#include <iostream>
#include "ChampForces.h"
#include "ObjetPhysique.h"
#include "vecteur.h"

class ForceCentrale : public ChampForces {
	protected:
	
	//attribut protégé
	ObjetPhysique& pt_central; //point central (référence)
	
	//méthode protégée
	Vecteur quadratique_inverse(const ObjetPhysique &autre_p) const;
	
	private:
	
	double prec; //précision
	
	public:
	
	//constructeur
	ForceCentrale(ObjetPhysique& p, double prec);
};

			

