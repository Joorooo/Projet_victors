#include <iostream>
#include "Vide.h"

using namespace std;

//destructeur
Vide::~Vide() {}

//methodes publiques
Vecteur Vide::force(const ObjetPhysique &p, double t) const {
	Vecteur nul(p.get_E().dim());
	return nul;
}
ostream& Vide::affiche(ostream& sortie) const {
	sortie << "aucun champ de force (champ vide)";
	return sortie;
}
unique_ptr<ChampForces> Vide::copie() const {
	return make_unique<Vide>(*this);
}

