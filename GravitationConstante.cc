#include "GravitationConstante.h"
#include "PointMateriel.h"
#include "constantes.h"

using namespace std;


//constructeur par défaut
GravitationConstante::GravitationConstante()
: intensite(Constantes::g)
{}

//méthodes publiques
Vecteur GravitationConstante::force(const PointMateriel &p, double t) const {
	return p.get_m()*intensite;
}
Vecteur GravitationConstante::get_intensite() const {return intensite;}

//opérateur d'affichage
std::ostream& operator<<(std::ostream& sortie, const GravitationConstante &champ_g) {
	sortie << champ_g.get_intensite();
	return sortie;
}


