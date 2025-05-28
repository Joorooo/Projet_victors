#include "PointMateriel.h"

using namespace std;

//méthodes publiques
ostream& PointMateriel::affiche(ostream& sortie) const {
	sortie << "Point Materiel : " << endl;
	ObjetPhysique::affiche(sortie);
	return sortie;
}
