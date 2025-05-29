#include "ForceUniforme.h"

using namespace std;

//constructeur
ForceUniforme::ForceUniforme(const Vecteur &intensite)
:intensite(intensite)
{}

//méthodes publiques
Vecteur ForceUniforme::force(const ObjetPhysique &p, double t) const {
	return p.get_m()*intensite; //vecteur de la force de gravitation (uniforme) exercée par pt_central sur p
}
