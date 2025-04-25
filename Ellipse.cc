#pragma once
#include <iostream>
#include "cmath"
#include "Ellipse.h"
#include "ObjetPhysique.h"

using namespace std;

//methodes publiques
Vecteur Ellipse::applique_force(const ObjetPhysique &p, const Vecteur &force, double t) const {
	if (p.get_m() == 0) {
		return force;
	} else {
		return (1/p.get_m())*force;
	}
}
Vecteur Ellipse::position(const ObjetPhysique &obj) const {
	Vecteur e1({1, 0});
	Vecteur e2({0, 1});
	double r = obj.get_E()*e1;
	double teta = obj.get_E()*e2;
	double x = r*cos(teta);
	double y = r*sin(teta);
	Vecteur pos({x, y});
	return pos;
}
Vecteur Ellipse::vitesse(const ObjetPhysique &obj) const {
	Vecteur e1({1, 0}); 
	Vecteur e2({0, 1});
	double r = obj.get_E()*e1;
	double teta = obj.get_E()*e2;
	double r_prime = obj.get_E_prime()*e1;
	double teta_prime = obj.get_E_prime()*e2;
	double vx = r_prime*cos(teta)-r*teta_prime*sin(teta);
	double vy = r_prime*sin(teta)+r*teta_prime*cos(teta);
	Vecteur vit({vx, vy});
	return vit;
}
ostream& Ellipse::affiche(ostream& sortie) const {
	sortie << "contrainte, mouvement elliptique";
	return sortie;
}
unique_ptr<Contrainte> Ellipse::copie() const {
	return unique_ptr<Ellipse>(new Ellipse(*this));
}
	
	
	
