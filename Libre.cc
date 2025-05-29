#include "Libre.h"
#include "ObjetPhysique.h"

using namespace std;

//méthodes publiques
Vecteur Libre::applique_force(const ObjetPhysique &p, const Vecteur &force, double t) const {
	if (p.get_m() <= limite) {
		cerr << "-->ERREUR : La masse est trop petite (<=" << limite << ")" << endl;
		return force;
	} else {
		return (1/p.get_m())*force; //cette contrainte ne modifie les accélérations de l'objet physique p
	}
}
Vecteur Libre::position(const ObjetPhysique &p) const {return p.get_E();}
Vecteur Libre::vitesse(const ObjetPhysique &p) const {return p.get_E_prime();}

//Définition de la méthode affiche
ostream& Libre::affiche(ostream& sortie) const {
	sortie << "contrainte Libre" << endl;
	return sortie;
}

