#include <iostream>
#include "ObjetPhysique.h"

using namespace std;

//constructeur
ObjetPhysique::ObjetPhysique(const Vecteur &e, const Vecteur &e_prime,Contrainte* c, const ChampForces &champ_f, double m, double charge, double dim)
: ObjetMobile(e, e_prime), contrainte(c), champ_f(champ_f), m(m), charge(charge), dim(dim)
{}

//methodes publiques
Vecteur ObjetPhysique::force(double t) const {return champ_f.force(*this, t);}
Vecteur ObjetPhysique::position() const {return contrainte->position(*this);}
Vecteur ObjetPhysique::vitesse() const {return contrainte->vitesse(*this);}

//redefinition de la methode affiche dans la sous-classe ObjetPhysique
ostream& ObjetPhysique::affiche(ostream& sortie) const {
	sortie << m << " # masse" << endl;
	sortie << charge << " # charge" << endl;
	sortie << position() << " # position" << endl;
	sortie << vitesse() << " # vitesse" << endl;
	return sortie;
}


//accesseurs
double ObjetPhysique::get_m() const {return m;}
double ObjetPhysique::get_charge() const {return charge;}       
