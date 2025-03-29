#include <iostream>
#include "ChampForces.h"
#include "ObjetPhysique.h"

using namespace std;

//constructeur
ChampForces::ChampForces(const Vecteur &intensite)
:intensite(intensite)
{}

//methode publiques
Vecteur ChampForces::force(const ObjetPhysique &p, double t) const {
	if (p.get_m() == 0) {
		cerr << "La masse ne peut pas être nulle" << endl; 
		Vecteur v_nul(0, 0, 0);
		return v_nul;
	} else {
		return p.get_m()*intensite;
	}
}

//accesseur
Vecteur ChampForces::get_intensite() const {return intensite;}

//surcharge operateur d'affichage
std::ostream& operator<<(std::ostream& sortie, const ChampForces &champ_f) {
	sortie << champ_f.get_intensite();
	return sortie;
}
