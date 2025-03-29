#include <iostream>
#include <array>
#include "PointMateriel.h"

using namespace std;

//constructeur
PointMateriel::PointMateriel(const Vecteur &e, const Vecteur &e_prime, Contrainte* c, const ChampForces &champ_f, const Vecteur &pos3D,
 double m, double charge, double dim)
: ObjetPhysique(e, e_prime, c , champ_f, m, charge, dim), pos3D(pos3D)
{}

//methodes publiques
double PointMateriel::E_cin() const {return 0.5*m*vitesse().norme2();}
Vecteur PointMateriel::evolution(double temps) const {
	if (m == 0) {
		cerr << "La masse ne peut pas être égale à 0" << endl;
		Vecteur v_nul(0, 0, 0);
		return v_nul;
	} else {
		return (1/m)*champ_f.get_intensite();
	}
}
//modificateurs
void PointMateriel::mod_pos3D(double a, double b, double c) {
	array <double, 3> tab = {a, b, c};
	for (auto coord : tab) {
		pos3D.augmente(coord);
	}
}
