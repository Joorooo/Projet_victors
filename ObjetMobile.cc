#include "ObjetMobile.h"

using namespace std;

//constructeurs
ObjetMobile::ObjetMobile(const Vecteur& e, const Vecteur& e_prime) 
: E(e), E_prime(e_prime) {}
 
ObjetMobile::ObjetMobile(unsigned int dim)
: E(dim), E_prime(dim) {}

//méthodes publiques
ostream& ObjetMobile::affiche_primaire(ostream& sortie) const {
	sortie << E << " # paramètre" << endl;
	sortie << E_prime << " # vitesse" << endl;
	return sortie;
}
ostream& ObjetMobile::affiche(ostream& sortie) const {return affiche_primaire(sortie);}

Vecteur  ObjetMobile::get_E() const {return E;}
Vecteur ObjetMobile::get_E_prime() const {return E_prime;}
void ObjetMobile::set_E(const Vecteur& v) {E = v;}
void ObjetMobile::set_E_prime(const Vecteur& v) {E_prime = v;}

//opérateur d'affichage
ostream& operator<<(ostream& sortie, const ObjetMobile& obj) {
	return obj.affiche(sortie);
}
