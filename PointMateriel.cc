#include <iostream>
#include <array>
#include "PointMateriel.h"

using namespace std;

//constructeurs
PointMateriel::PointMateriel(Vecteur vect_position, Vecteur vect_vitesse, double m)
: vect_position(vect_position), vect_vitesse(vect_vitesse), m(m)
{}
PointMateriel::PointMateriel(double m) 
: vect_position(3), vect_vitesse(3), m(m)
{}

//methodes publiques
Vecteur PointMateriel::position() const {return vect_position;}
Vecteur PointMateriel::vitesse() const {return vect_vitesse;}
Vecteur PointMateriel::evolution(double t) const {
	if (m <= 0) {
		cerr << "La masse ne peut pas être inférieure ou égale à 0" << endl;
		Vecteur v_nul(0, 0, 0);
		return v_nul;
	} else {
		return (1/m)*sm_forces.get_intensite();
	}
}

//accesseurs
double PointMateriel::get_m() const {return m;};

//modificateurs
void PointMateriel::mod_pos(double a, double b, double c) {
	array <double, 3> tab = {a, b, c};
	for (auto coord : tab) {
		vect_position.augmente(coord);
	}
}
void PointMateriel::mod_v(double a, double b, double c) {
	array <double, 3> tab = {a, b, c};
	for (auto coord : tab) {
		vect_vitesse.augmente(coord);
	}
}

//operateurs externes 
std::ostream& operator<<(std::ostream& sortie, const PointMateriel &p) {
	sortie << p.get_m() << " # masse" << endl;
	sortie << p.position() << " # position" << endl;
	sortie << p.vitesse() << " # vitesse" << endl;
	return sortie;
}
