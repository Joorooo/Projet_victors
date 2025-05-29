#include <cmath>
#include "PointMaterielAngles.h"

using namespace std;

//redéfinition de méthode affiche
ostream& PointMaterielAngles::affiche(ostream& sortie) const {
	sortie << "Point Materiel à vecteur d'état angulaire périodique: " << endl;
	PointMateriel::affiche(sortie);
	return sortie;
}

//redéfinition du modificateur du vecteur d'état E
void PointMaterielAngles::set_E(const Vecteur &v) {
	double nouveau_teta = remise_angle(v.getcoord(0));
	double nouveau_phi = remise_angle(v.getcoord(1));
	E = Vecteur({nouveau_teta, nouveau_phi}); //modifie le vecteur d'état E pour les angles soient toujours dans l'interval [0, 2pi[
}

//méthode privée
double PointMaterielAngles::remise_angle(double angle) const {
	angle = fmod(angle, 2*M_PI);
	if (angle < 0) {
        angle += 2 * M_PI;
	}
	return angle;
}
		
		
