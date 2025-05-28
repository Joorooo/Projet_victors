#include <array>
#include "PointMateriel.h"

using namespace std;

//constructeurs
PointMateriel::PointMateriel(const Vecteur&e, const Vecteur &e_prime, double m)
: E(e), E_prime(e_prime), m(m)
{}
PointMateriel::PointMateriel(double m) 
: E(3), E_prime(3), m(m)
{}

//methodes publiques
Vecteur PointMateriel::position() const {return E;}
Vecteur PointMateriel::vitesse() const {return E_prime;}
Vecteur PointMateriel::evolution(double t) const {
	if (m <= 0) {
		cerr << "La masse ne peut pas être inférieure ou égale à 0" << endl;
		return Vecteur(3);
	} else {
		return (1/m)*champ_f.get_intensite();
	}
}
ostream& PointMateriel::affiche(ostream& sortie) const {
	sortie << m << " # masse" << endl;
	sortie << position() << " # position" << endl;
	sortie << vitesse() << " # vitesse" << endl;
	return sortie;
}
ostream& PointMateriel::affiche(ostream& sortie, double t) const {
	affiche(sortie);
	sortie << champ_f.force(*this, t) << " #force" << endl;
	return sortie;
}

//accesseurs
double PointMateriel::get_m() const {return m;};

//modificateurs
void PointMateriel::mod_pos(double a, double b, double c) {
	E.augmente(a);
	E.augmente(b);
	E.augmente(c);
}
void PointMateriel::mod_v(double a, double b, double c) {
	E_prime.augmente(a);
	E_prime.augmente(b);
	E_prime.augmente(c);
}

//operateurs externes 
std::ostream& operator<<(std::ostream& sortie, const PointMateriel &p) {
	return p.affiche(sortie);
}
