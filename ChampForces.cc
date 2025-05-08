#include <iostream>
#include "ChampForces.h"

using namespace std;

//destructeur
ChampForces::~ChampForces() {}

//operateur d'affichage
std::ostream& operator<<(std::ostream& sortie, const ChampForces &champ_f) {
	return champ_f.affiche(sortie);
}
