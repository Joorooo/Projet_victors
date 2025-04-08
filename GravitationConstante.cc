#include <iostream>
#include <memory>
#include "GravitationConstante.h"
#include "constantes.h"

using namespace std;


//constructeur par defaut
GravitationConstante::GravitationConstante()
: ForceUniforme(Constantes::g)
{}

//surcharge de <<
ostream& GravitationConstante::affiche(ostream& sortie) const {
	sortie << "champ de gravitation constante, intensite : " << intensite << endl;
	return sortie;
}

//methode publique
unique_ptr<ChampForces> GravitationConstante::clone() const {
	return std::make_unique<GravitationConstante>(*this);
}



