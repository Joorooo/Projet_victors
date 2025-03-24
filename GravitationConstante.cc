#include <iostream>
#include "GravitationConstante.h"
#include "PointMateriel.h"
#include "constantes.h"

using namespace std;


//constructeur par defaut
GravitationConstante::GravitationConstante()
: intensite(Constantes::g)
{}

//methodes
Vecteur GravitationConstante::force(const PointMateriel &p, double t) const {
	if (p.get_m() <= 0) {
		cerr << "La masse ne peut pas être inférieure ou égale à 0" << endl; 
		Vecteur v_nul(0, 0, 0);
		return v_nul;
	} else {
		return p.get_m()*intensite;
	}
}
Vecteur GravitationConstante::get_intensite() const {return intensite;}

//operateurs externes 
std::ostream& operator<<(std::ostream& sortie, const GravitationConstante &champ_g) {
	sortie << champ_g.get_intensite();
	return sortie;
}


