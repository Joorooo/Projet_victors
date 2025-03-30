#include <iostream>
#include "ChampForces.h"
#include "ObjetPhysique.h"
#include "vecteur.h"

class ForceCentrale : public ChampForces {
	private:
	
	const ObjetPhysique &pt_central; //point central 
	double prec; //precision
	
	protected:
	
	//methode protected
	Vecteur quadratique_inverse(const ObjetPhysique &autre_p) const;
	
	public:
	
	//constructeur
	ForceCentrale(Vecteur intensite, const ObjetPhysique &p);
};
			

