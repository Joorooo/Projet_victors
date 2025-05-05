#include <iostream>
#include "cmath"
#include "PointMaterielAngles.h"
#include "constantes.h"

using namespace std;

//methode publique
ostream& PointMaterielAngles::affiche(ostream& sortie) const {
	sortie << "Point Materiel à vecteur d'état angulaire périodique: " << endl;
	ObjetPhysique::affiche(sortie);
	return sortie;
}

//redéfinition du modificateur du vecteur d'état E
void PointMaterielAngles::set_E(const Vecteur &v) {
	E = v;
	Vecteur e1({1, 0});
	Vecteur e2({0, 1});
	double nouveau_teta = remise_angle(E*e1);
	double nouveau_phi = remise_angle(E*e2);
	Vecteur nouveau_E({nouveau_teta, nouveau_phi});
	E = nouveau_E;
}

//methode privée
double PointMaterielAngles::remise_angle(double angle) const {
	angle = fmod(angle, 2*Constantes::pi);
	return angle;
}
		
		
