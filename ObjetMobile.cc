#include "ObjetMobile.h"

using namespace std;

//constructeurs
ObjetMobile::ObjetMobile(const Vecteur& e, const Vecteur& e_prime) 
            : E(e), E_prime(e_prime) {}
 
ObjetMobile::ObjetMobile(unsigned int dim)
            : E(dim), E_prime(dim) {}

//méthodes
ostream& ObjetMobile::affiche(ostream& sortie) const {
	sortie << E << " # paramètre" << endl << E_prime << "# vitesse" << endl;
	sortie << "=========================" << endl << endl;
	return sortie;
}

//methodes pas ouf mais je vois pas comment faire sinon dans les integrateurs
Vecteur  ObjetMobile::get_E() const {return E;}
Vecteur ObjetMobile::get_E_prime() const {return E_prime;}
void ObjetMobile::set_E(const Vecteur& v) {E = v;}
void ObjetMobile::set_E_prime(const Vecteur& v) {E_prime = v;}

//opérateurs
ostream& operator<<(ostream& sortie, const ObjetMobile& o) {
	return o.affiche(sortie);
}
