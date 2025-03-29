#include <iostream>
#include <memory>
#include "vecteur.h"
#include "GravitationConstante.h"
#include "Libre.h"
#include "PointMateriel.h"
using namespace std;

int main() {
	GravitationConstante g;
	Libre* p = new Libre();
	
	Vecteur pos1(1.0, 2.0, 3.0); // creation des vecteurs vect_position et vect_vitesse de type Vecteur de la classe PointMateriel
	Vecteur v1(0.0, 0.1, 0.2);
	Vecteur pos2(-1.1, 1.2, 1.3);
	Vecteur v2(0.2, 0.1, 0.0);
	
	PointMateriel p1(pos1, v1, p, g, pos1, 0.1); //construction de PointMateriel p1 et p2
	PointMateriel p2(pos2, v2, p, g, pos2, 2.0);
	
	
	cout << "Nous avons :" << endl;
	cout << "Un champ de force :" << endl;
	cout << g << " # intensité" << endl << endl;
	
	cout << "un point matériel :" << endl;
	cout << p1.position();
	cout << g.force(p1) << " # force" << endl << endl;
	
	cout << "et un autre point matériel :" << endl;
	cout << p2;
	cout << g.force(p2) << " # force" << endl;
	cout << p->position(p1);
	return 0;
}
