#include <iostream>
#include "ForceCentrale.h"

using namespace std;

//methode protected
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
ForceCentrale::ForceCentrale(const ObjetPhysique &p, double prec)
:pt_central(p), prec(prec)
{}

//destructeur
ForceCentrale::~ForceCentrale() {}

//methode publique
ostream& ForceCentrale::affiche(ostream& sortie) const {
	sortie << pt_central << " # point central du champ de force" << endl;
	sortie << prec << " # precision" << endl;
	return sortie;
} 

//surcharge operateur d'affichage
std::ostream& operator<<(std::ostream& sortie, const ForceCentrale &force_c) {
	return force_c.affiche(sortie);
}
