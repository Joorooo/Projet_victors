#include <cmath>
#include "PointMaterielAngles.h"

using namespace std;

//méthode publique
ostream& PointMaterielAngles::affiche(ostream& sortie) const {
	sortie << "Point Materiel à vecteur d'état angulaire périodique: " << endl;
	ObjetPhysique::affiche(sortie);
	return sortie;
}

//redéfinition du modificateur du vecteur d'état E
void PointMaterielAngles::set_E(const Vecteur &v) {
	Vecteur e1({1, 0});
	Vecteur e2({0, 1});
	double nouveau_teta = remise_angle(v*e1);
	double nouveau_phi = remise_angle(v*e2);
	Vecteur nouveau_E({nouveau_teta, nouveau_phi});
	E = nouveau_E;
}

//méthode privée
double PointMaterielAngles::remise_angle(double angle) const {
	angle = fmod(angle, 2*M_PI);
	return angle;
}
		
		
