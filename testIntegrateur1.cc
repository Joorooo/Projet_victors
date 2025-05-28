#include <iostream>
#include "PointMateriel.h"
#include "GravitationConstante.h"
#include "Libre.h"
#include "IntegrateurEulerCromer.h"
#include "vecteur.h"
#include "constantes.h"

using namespace std;

int main() {
	IntegrateurEulerCromer integrateur;
	Libre l;
	GravitationConstante champ;
	
	Vecteur E({0, 0, 1.0}); //vecteur position initiale de l'objet
	Vecteur E_prime({0, 1.0, 2.0}); //vecteur vitesse initial de l'objet
	double m(0.127); //masse 
	
	PointMateriel point(E, E_prime, &l, &champ, m); //point matériel
	
	unsigned int n(100);
	double dt(0.01); //pas de calcul
	double t(0); //temps
	
	for(size_t i(0); i <= n; i++) {
		cout << t << " #temps" << endl;
		cout << point;
		integrateur.integre(point, t, dt);
		t += dt;
		cout << "=====================" << endl;
	}
	return 0;
}
	
