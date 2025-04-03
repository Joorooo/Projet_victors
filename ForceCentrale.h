#pragma once
#include <iostream>
#include "ChampForces.h"
#include "ObjetPhysique.h"
#include "vecteur.h"

class ObjetPhysique;

class ForceCentrale : public ChampForces {
	private:
	
	double prec; //precision
	
	protected:
	
	//attribut protegé
	const ObjetPhysique &pt_central; //point central 
	
	//methode protégé
	Vecteur quadratique_inverse(const ObjetPhysique &autre_p) const;
	
	
	public:
	
	//constructeur
	ForceCentrale(const ObjetPhysique &p, double prec);
	
	//destructeur
	virtual ~ForceCentrale();
	
	//methode publique
	virtual Vecteur force(const ObjetPhysique &p, double t = 0) const = 0;
	virtual std::ostream& affiche(std::ostream& sortie) const override;
};

			

