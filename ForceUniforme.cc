#include <iostream>
#include "ForceUniforme.h"

using namespace std;

//constructeur
ForceUniforme::ForceUniforme(const Vecteur &intensite)
:intensite(intensite)
{}

//destructeur
ForceUniforme::~ForceUniforme() {}

//methode publiques
Vecteur ForceUniforme::force(const ObjetPhysique &p, double t) const {
	if (p.get_m() == 0) {
		cerr << "La masse ne peut pas être nulle" << endl; 
		Vecteur v_nul(0, 0, 0);
		return v_nul;
	} else {
		return p.get_m()*intensite;
	}
}
ostream& ForceUniforme::affiche(ostream& sortie) const {
	sortie << intensite << " # intensite du champ de force" << endl;
	return sortie;
}

//accesseur
Vecteur ForceUniforme::get_intensite() const {return intensite;}

//surcharge operateur d'affichage
std::ostream& operator<<(std::ostream& sortie, const ForceUniforme &force_u) {
	return force_u.affiche(sortie);
}
