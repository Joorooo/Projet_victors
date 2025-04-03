#include <iostream>
#include "ChampForces.h"
#include "ObjetPhysique.h"

using namespace std;

ChampForces::~ChampForces() {}

//Operateur d'affichage
std::ostream& operator<<(std::ostream& sortie, const ChampForces &champ_f) {
	return champ_f.affiche(sortie);
}
