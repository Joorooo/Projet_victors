#include "ChampForces.h"

using namespace std;

//opérateur d'affichage externe
std::ostream& operator<<(std::ostream& sortie, const ChampForces &champ_f) {
	return champ_f.affiche(sortie);
}
