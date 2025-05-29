#include <iostream>
#include "ChampNewtonien.h"


using namespace std;

//méthode publique
Vecteur ChampNewtonien::force(const ObjetPhysique &p, double t) const {
	return Constantes::G * p.get_m() * pt_central.get_m() * quadratique_inverse(p);
}

ostream& ChampNewtonien::affiche(ostream& sortie) const {
	sortie << "champ newtonien, centre : " << pt_central.get_E() << ", masse : " << pt_central.get_m();
	return sortie;
}

