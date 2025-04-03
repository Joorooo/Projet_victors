#include <iostream>
#include "ObjetPhysique.h"

using namespace std;

//constructeur
ObjetPhysique::ObjetPhysique(const Vecteur &e, const Vecteur &e_prime, Contrainte& c, ChampForces &champ_f, double m, double charge, double dim)
: ObjetMobile(e, e_prime), contrainte(c), champ_f(champ_f), m(m), charge(charge), dim(dim)
{}

//methodes publiques
Vecteur ObjetPhysique::force(double t) const {return champ_f.force(*this, t);}
Vecteur ObjetPhysique::position() const {return contrainte.position(*this);}
Vecteur ObjetPhysique::vitesse() const {return contrainte.vitesse(*this);}
Vecteur ObjetPhysique::evolution(double t) const {return contrainte.applique_force(*this,force(t));}
double ObjetPhysique::distance(const ObjetPhysique &autre_p) const {
	return (E-autre_p.get_E()).norme();
}
double ObjetPhysique::distance2(const ObjetPhysique &autre_p) const {
	return (E-autre_p.get_E()).norme2();
}

//redefinition de la methode affiche dans la sous-classe ObjetPhysique
ostream& ObjetPhysique::affiche(ostream& sortie) const {
	sortie << E << " parametre" << endl;
	sortie << E_prime << " vitesse" << endl;
	sortie << position() << " # position physique" << endl;
	sortie << vitesse() << " # vitesse physique" << endl;
	sortie << m << " # masse" << endl;
	sortie << "contraintes : ";
	for (auto c : contraintes) {
		sortie << c;
	}
	sortie << endl;
	return sortie;
}


//accesseurs
double ObjetPhysique::get_m() const {return m;}
double ObjetPhysique::get_charge() const {return charge;}       
