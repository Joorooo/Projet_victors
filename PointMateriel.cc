#include "PointMateriel.h"

using namespace std;

//redéfinition de méthode affiche
ostream& PointMateriel::affiche(ostream& sortie) const {
	sortie << "Point Materiel : " << endl;
	ObjetPhysique::affiche(sortie);
	return sortie;
}
void PointMateriel::dessine_sur(SupportADessin& support) const {support.dessine(*this);} 
