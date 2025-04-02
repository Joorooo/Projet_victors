#pragma once
#include <iostream>
#include "ChampForces.h"
#include "ObjetPhysique.h"
#include "vecteur.h"

class ObjetPhysique;

class ForceCentrale : public ChampForces {
	private:
	
	const ObjetPhysique &pt_central; //point central 
	double prec; //precision
	
	protected:
	
	//methode protected
	Vecteur quadratique_inverse(const ObjetPhysique &autre_p) const;
	
	public:
	
	//constructeur
	ForceCentrale(const ObjetPhysique &p, double prec);
	
	//destructeur
	virtual ~ForceCentrale();
	
	//methode publique
	virtual Vecteur force(const ObjetPhysique &p, double t = 0) const = 0;
	virtual std::ostream& affiche(std::ostream& sortie) const;
};

//surcharge operateur d'affichage
std::ostream& operator<<(std::ostream& sortie, const ForceCentrale &force_c);
			

