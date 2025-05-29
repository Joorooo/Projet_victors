#include "ObjetPhysique.h"

using namespace std;

//constructeur
ObjetPhysique::ObjetPhysique(const Vecteur &e, const Vecteur &e_prime, Contrainte* c, ChampForces* champ_f, 
double m, double dim)
: ObjetMobile(e, e_prime), contrainte(c), champ_f(champ_f), m(m), dim(dim)
{}
ObjetPhysique::ObjetPhysique(const Vecteur &e, const Vecteur &e_prime, double m, double dim)
: ObjetPhysique(e, e_prime, nullptr, nullptr, m, dim) //initialise les attributs contrainte et champ_f à nullptr
{}

//méthodes publiques
Vecteur ObjetPhysique::force(double t) const {return champ_f->force(*this, t);} //retourne force exercée par le champ de force sur l'objet
Vecteur ObjetPhysique::position() const {return contrainte->position(*this);} //retourne position de l'objet dans système coordonnées carthésiennes calculée par la contrainte 
Vecteur ObjetPhysique::vitesse() const {return contrainte->vitesse(*this);} //retourne vitesse de l'objet dans système coordonnées carthésiennes calculée par la contrainte 
Vecteur ObjetPhysique::evolution(double t) const {return contrainte->applique_force(*this, force(t));} //retourne accélérations de l'objet subissant le champ de force sous la contrainte 
double ObjetPhysique::distance(const ObjetPhysique &autre_p) const {
	return (position()-autre_p.position()).norme(); //calcule distance entre l'objet et autre_p
}
double ObjetPhysique::distance2(const ObjetPhysique &autre_p) const {
	return (position()-autre_p.position()).norme2(); //distance au carré
}

//modificateurs
void ObjetPhysique::mod_contrainte(Contrainte* cont) {contrainte = cont;}
void ObjetPhysique::mod_champ(ChampForces* champ) {champ_f = champ;}

//reféfinition des méthodes affiche et affiche_primaire dans sous-classe ObjetPhysique
ostream& ObjetPhysique::affiche_primaire(ostream& sortie) const {
	ObjetMobile::affiche_primaire(sortie);
	sortie << position() << " # position physique" << endl;
	sortie << vitesse() << " # vitesse physique" << endl;
	return sortie;
}
ostream& ObjetPhysique::affiche(ostream& sortie) const {
	affiche_primaire(sortie);
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
