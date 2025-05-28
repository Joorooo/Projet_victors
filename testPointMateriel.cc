#include <iostream>
#include "vecteur.h"
#include "GravitationConstante.h"
#include "PointMateriel.h"
using namespace std;

int main() {
	GravitationConstante g;
	
	double m1(0.1); //masses des points matériels 
	double m2(2.0);
	
	Vecteur pos1(1.0, 2.0, 3.0); // création des vecteurs d'état E et E_prime de type Vecteur de la classe PointMateriel
	Vecteur v1(0.0, 0.1, 0.2);
	Vecteur pos2(-1.1, 1.2, 1.3);
	Vecteur v2(0.2, 0.1, 0.0);
	
	PointMateriel p1(pos1, v1, m1); //construction des points matériels p1 et p2
	PointMateriel p2(pos2, v2, m2);
	
	cout << "Nous avons :" << endl;
	cout << "Un champ de force :" << endl;
	cout << g << " # intensité" << endl << endl;
	
	cout << "un point matériel :" << endl;
	p1.affiche(cout, 0);
	
	cout << endl;
	cout << "et un autre point matériel :" << endl;
	p2.affiche(cout, 0);
	
	return 0;
}
