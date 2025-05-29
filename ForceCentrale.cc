#include "ForceCentrale.h"

using namespace std;

//méthode protégée
Vecteur ForceCentrale::quadratique_inverse(const ObjetPhysique &autre_p) const {
	if (pt_central.distance(autre_p) <= prec) {
		return Vecteur(pt_central.get_dim()); //cf constructeurs de classe Vecteur
	} else {
		double l(1/(pt_central.distance2(autre_p)));
		Vecteur v(pt_central.position()-autre_p.position()); //vecteur dans la direction de droite passant par les deux objets physiques (pt_central et autre_p)
		return ~v*l; //vecteur unitaire de v multiplié par vecteur l
	}
}

//constructeur
ForceCentrale::ForceCentrale(ObjetPhysique& p, double prec)
:pt_central(p), prec(prec)
{}

