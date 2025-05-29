#include "GravitationConstante.h"
#include "constantes.h"

using namespace std;

//constructeur par defaut
GravitationConstante::GravitationConstante()
: ForceUniforme(Constantes::g)
{}

Vecteur GravitationConstante::force(const ObjetPhysique &p, double t) const {
	return p.get_m()*intensite;
}

//définition de la méthode affiche
ostream& GravitationConstante::affiche(ostream& sortie) const {
	sortie << "champ de gravitation constante, intensite : " << intensite;
	return sortie;
}
