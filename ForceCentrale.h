#pragma once
#include <iostream>
#include "ChampForces.h"
#include "ObjetPhysique.h"
#include "vecteur.h"

class ForceCentrale : public ChampForces {
	protected:
	
	//attribut protegé
	ObjetPhysique& pt_central; //point central 
	
	//methode protégé
	Vecteur quadratique_inverse(const ObjetPhysique &autre_p) const;
	
	private:
	
	double prec; //precision
	
	public:
	
	//constructeur
	ForceCentrale(ObjetPhysique& p, double prec);
	
	//destructeur
	virtual ~ForceCentrale();
	
	//methode publique
	virtual Vecteur force(const ObjetPhysique &p, double t = 0) const = 0;
	virtual std::ostream& affiche(std::ostream& sortie) const override;
};

			

