#include <iostream>
#include "ForceCentrale.h"

using namespace std;

//methodes protected
Vecteur ForceCentrale::quadratique_inverse(const ObjetPhysique &autre_p) const {
	if (pt_central.distance(autre_p) <= prec) {
		Vecteur v_nul(0, 0, 0);
		return v_nul;
	} else {
		double l(1/(pt_central.distance2(autre_p)));
		Vecteur v(pt_central.get_E()-autre_p.get_E());
		return ~v*l;
	}
}

//constructeur
ForceCentrale::ForceCentrale(Vecteur intensite, const ObjetPhysique &p)
	: ChampForces(intensite), pt_central(p)
	{}
