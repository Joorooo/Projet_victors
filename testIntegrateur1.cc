#include "IntegrateurEulerCromer.h"
#include "PointMateriel.h"
#include "GravitationConstante.h"
#include "Libre.h"
using namespace std;

int main () {
	
	Vecteur position_init({0, 0, 1.0});
	Vecteur vitesse_init({0, 1.0, 2.0});
	GravitationConstante g;
	Libre l;
	double m(0.127);
	PointMateriel point(position_init, vitesse_init, l, g, m, 0.0, 2.0);
	
	cout << point <<endl;
	
	IntegrateurEulerCromer integrateur;
	double dt(0.01);
	double t(0.01);
	
	unsigned int nb_pas(100);
	
	for (int i(0); i < nb_pas -1; ++i){
		cout << "t = " << t << endl;
		integrateur.integre(point, t, dt);
		cout << point << endl;
		t += dt;
		cout << "=====================" << endl << endl;
	}
	
	return 0;
}
