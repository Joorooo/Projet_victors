#include <iostream>
#include "ChampForcesCompose.h"
#include "ObjetPhysique.h"

using namespace std;

//constructeur
ChampForcesCompose::ChampForcesCompose(const vector<ChampForces*> &autres_champs) {
	for (auto c : autres_champs) {
		champs.push_back(c);
	}
}

//destructeur
ChampForcesCompose::~ChampForcesCompose() {
	for (auto c : champs) {
		delete c;
	}
}

//methodes publiques
Vecteur ChampForcesCompose::force(const ObjetPhysique &p, double t) const {
	unsigned int dimension(p.get_E().dim());
	Vecteur resultat(dimension);
	for (auto c : champs) {
		resultat += c->force(p, t);
	}
	return resultat;
}
void ChampForcesCompose::ajout_champ(ChampForces* c) {
	champs.push_back(c);
}
ostream& ChampForcesCompose::affiche(ostream& sortie) const {
	for (const auto& c : champs) {
		 c->affiche(sortie);
	}
	return sortie;
}
		
		
		
