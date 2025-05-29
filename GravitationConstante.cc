#include "GravitationConstante.h"
#include "constantes.h"

using namespace std;

//constructeur par defaut
GravitationConstante::GravitationConstante()
: ForceUniforme(Constantes::g)
{}

//redéfinition de la méthode affiche
ostream& GravitationConstante::affiche(ostream& sortie) const {
	sortie << "champ de gravitation constante, intensite : " << intensite;
	return sortie;
}
