#include <iostream>
#include "GravitationConstante.h"
#include "constantes.h"

using namespace std;

//constructeur par défaut
GravitationConstante::GravitationConstante()
: ForceUniforme(Constantes::g)
{}

ostream& GravitationConstante::affiche(ostream& sortie) const {
	sortie << "champ de gravitation constante, intensite : " << intensite;
	return sortie;
}
