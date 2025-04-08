#include <iostream>
#include "ChampNewtonien.h"
#include "constantes.h"

using namespace std;

//methode publique
Vecteur ChampNewtonien::force(const ObjetPhysique &p, double t) const {
	return Constantes::m_terre * Constantes::G * p.get_m()*quadratique_inverse(p);
}

unique_ptr<ChampForces> ChampNewtonien::clone() const {
	return make_unique<ChampNewtonien>(*this);
}



//surcharge de <<
ostream& ChampNewtonien::affiche(ostream& sortie) const {
	sortie << "champ newtonien, centre : " << pt_central.position() << ", masse : " << pt_central.get_m() << endl;
	return sortie;
}

//constructeur
ChampNewtonien::ChampNewtonien(const ObjetPhysique &p, double prec)
:ForceCentrale(p, prec)
{}
