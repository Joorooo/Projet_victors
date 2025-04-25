#include <iostream>
#include "ChampNewtonien.h"
#include "constantes.h"

using namespace std;

//methode publique
Vecteur ChampNewtonien::force(const ObjetPhysique &p, double t) const {
	return pt_central.get_m() * Constantes::G * p.get_m()*quadratique_inverse(p);
}

ostream& ChampNewtonien::affiche(ostream& sortie) const {
	sortie << "champ newtonien, centre : " << pt_central.get_E() << ", masse : " << pt_central.get_m();
	return sortie;
}
unique_ptr<ChampForces> ChampNewtonien::copie() const {
	return make_unique<ChampNewtonien>(*this);
}
//constructeur
ChampNewtonien::ChampNewtonien(const ObjetPhysique &p, double prec)
:ForceCentrale(p, prec)
{}
