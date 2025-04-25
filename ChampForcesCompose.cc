#include <iostream>
#include "ChampForcesCompose.h"
#include "ObjetPhysique.h"

using namespace std;

//constructeur
ChampForcesCompose::ChampForcesCompose(const vector<unique_ptr<ChampForces>> &autres_champs) {
	for (auto& c : autres_champs) {
		champs.push_back(c->copie());
	}
}
ChampForcesCompose::ChampForcesCompose(const ChampForcesCompose &autre_cfc)
: ChampForcesCompose(autre_cfc.champs)
{}

//destructeur
ChampForcesCompose::~ChampForcesCompose() {}

//methodes publiques
Vecteur ChampForcesCompose::force(const ObjetPhysique &p, double t) const {
	unsigned int dimension(p.get_E().dim());
	Vecteur resultat(dimension);
	for (const auto& c : champs) {
		resultat += c->force(p, t);
	}
	return resultat;
}
void ChampForcesCompose::ajout_champ(const ChampForces &c) {
	champs.push_back(c.copie());
}
unique_ptr<ChampForces> ChampForcesCompose::copie() const {
	return make_unique<ChampForcesCompose>(*this);
}
ostream& ChampForcesCompose::affiche(ostream& sortie) const {
	for (const auto& c : champs) {
		 c->affiche(sortie);
	}
	return sortie;
}
		
		
		
