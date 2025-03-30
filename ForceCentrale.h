#include <iostream>
#include "ChampForces.h"
#include "ObjetPhysique.h"
#include "vecteur.h"

class ForceCentrale : public ChampForces {
	private:
	
	const ObjetPhysique &pt_central;
	double prec;
	
	protected:
	
	Vecteur quadratique_inverse(const ObjetPhysique &autre_p) const;
	
	public:
	
	ForceCentrale(Vecteur intensite, const ObjetPhysique &p);
};
			

