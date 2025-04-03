#include <iostream>
#include "GravitationConstante.h"
#include "constantes.h"

using namespace std;


//constructeur par defaut
GravitationConstante::GravitationConstante()
: ForceUniforme(Constantes::g)
{}

ostream& GravitationConstante::affiche(ostream& sortie) const {
	sortie << "champ de gravitation constante, intensite : " << intensite << endl;
	return sortie;
}
