#include "ForceCentrale.h"

using namespace std;

//méthode protégée
Vecteur ForceCentrale::quadratique_inverse(const ObjetPhysique &autre_p) const {
	if (pt_central.distance(autre_p) <= prec) {
		Vecteur v_nul(pt_central.get_dim());
		return v_nul;
	} else {
		double l(1/(pt_central.distance2(autre_p)));
		Vecteur v(pt_central.position()-autre_p.position());
		return ~v*l;
	}
}

//constructeur
ForceCentrale::ForceCentrale(ObjetPhysique& p, double prec)
:pt_central(p), prec(prec)
{}

