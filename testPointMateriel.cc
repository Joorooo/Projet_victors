#include <iostream>
#include <memory>
#include "vecteur.h"
#include "GravitationConstante.h"
#include "Libre.h"
#include "PointMateriel.h"

using namespace std;

int main() {
	Vecteur pos1(1.0, 2.0, 3.0); //creation des vecteurs vect_position et vect_vitesse de type Vecteur de la classe PointMateriel
	Vecteur v1(0.0, 0.1, 0.2);
	Vecteur pos2(-1.1, 1.2, 1.3);
	Vecteur v2(0.2, 0.1, 0.0);
	
	//construction de PointMateriel p1 et p2
	PointMateriel p1(pos1, v1, vector<shared_ptr<Contrainte>>{make_shared<Libre>()}, 
		          vector<shared_ptr<ChampForces>>{make_shared<GravitationConstante>()}, 0.1); 
		          
    PointMateriel p2(pos2, v2, vector<shared_ptr<Contrainte>>{make_shared<Libre>()}, 
		          vector<shared_ptr<ChampForces>>{make_shared<GravitationConstante>()}, 2.0);
	
	
	cout << "Point materiel 1 : " << endl << p1 << endl << endl;
	cout << "Point materiel 2 : " << endl << p2 << endl << endl;
	
	
	
	return 0;
}
