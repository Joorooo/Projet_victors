#include <iostream>
#include "PointMateriel.h"

using namespace std;

//methode publique
ostream& PointMateriel::affiche(ostream& sortie) const {
	sortie << "Point Materiel : " << endl;
	ObjetPhysique::affiche(sortie);
	return sortie;
}
