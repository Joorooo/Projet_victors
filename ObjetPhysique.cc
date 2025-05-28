#include <iostream>
#include "ObjetPhysique.h"

using namespace std;

//constructeur
ObjetPhysique::ObjetPhysique(const Vecteur &e, const Vecteur &e_prime, Contrainte* c, ChampForces* champ_f, 
double m, double dim)
: ObjetMobile(e, e_prime), contrainte(c), champ_f(champ_f), m(m), dim(dim)
{}
ObjetPhysique::ObjetPhysique(const Vecteur &e, const Vecteur &e_prime, double m, double dim)
: ObjetPhysique(e, e_prime, nullptr, nullptr, m, dim)
{}

//méthodes publiques
Vecteur ObjetPhysique::force(double t) const {return champ_f->force(*this, t);}
Vecteur ObjetPhysique::position() const {return contrainte->position(*this);}
Vecteur ObjetPhysique::vitesse() const {return contrainte->vitesse(*this);}
Vecteur ObjetPhysique::evolution(double t) const {return contrainte->applique_force(*this, force(t));}
double ObjetPhysique::distance(const ObjetPhysique &autre_p) const {
	return (position()-autre_p.position()).norme();
}
double ObjetPhysique::distance2(const ObjetPhysique &autre_p) const {
	return (position()-autre_p.position()).norme2();
}

//modificateurs
void ObjetPhysique::mod_contrainte(Contrainte* cont) {contrainte = cont;}
void ObjetPhysique::mod_champ(ChampForces* champ) {champ_f = champ;}

//redéfinition de la méthode affiche dans la sous-classe ObjetPhysique
ostream& ObjetPhysique::affiche(ostream& sortie) const {
	sortie << E << " # parametre" << endl;
	sortie << E_prime << " # vitesse" << endl;
	sortie << position() << " # position physique" << endl;
	sortie << vitesse() << " # vitesse physique" << endl;
	sortie << m << " # masse" << endl;
	sortie << "contrainte : ";
	if (contrainte == nullptr) {
		sortie << "aucune contrainte (mais pas une contrainte libre)";
	} else {
		sortie << *contrainte;
	}
	return sortie;
}

//accesseurs
double ObjetPhysique::get_m() const {return m;}
double ObjetPhysique::get_charge() const {return charge;}     
double ObjetPhysique::get_dim() const {return dim;}  
