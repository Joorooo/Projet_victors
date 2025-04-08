#pragma once
#include <iostream>
#include "ChampForces.h"
#include "ObjetPhysique.h"
#include "vecteur.h"

class ObjetPhysique;

class ForceCentrale : public ChampForces {
	protected:
	
	//attribut protegé
	const ObjetPhysique &pt_central; //point central 
	
	//methode protégé
	Vecteur quadratique_inverse(const ObjetPhysique &autre_p) const;
	
	private:
	
	double prec; //precision
	
	
	public:
	
	//constructeur
	ForceCentrale(const ObjetPhysique &p, double prec);
	
	//destructeur
	virtual ~ForceCentrale() = default;
	
	//methode publique
	virtual std::ostream& affiche(std::ostream& sortie) const override;
};

			

