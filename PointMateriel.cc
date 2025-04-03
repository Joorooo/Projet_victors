#include <iostream>
#include <array>
#include "PointMateriel.h"

using namespace std;

//constructeur
PointMateriel::PointMateriel(const Vecteur &e, const Vecteur &e_prime, Contrainte& c, ChampForces &champ_f, 
double m, double charge, double dim)
: ObjetPhysique(e, e_prime, c , champ_f, m, charge, dim)
{}

//methodes publiques
double PointMateriel::E_cin() const {return 0.5*m*vitesse().norme2();}
ostream& PointMateriel::affiche(ostream& sortie) const {
	sortie << "Point Materiel : " << endl;
	ObjetPhysique::affiche(sortie);
	return sortie;
}
