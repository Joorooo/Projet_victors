#pragma once
#include <iostream>
#include "vecteur.h"
#include "GravitationConstante.h"

class PointMateriel {
	private:
	
	Vecteur vect_position;
	Vecteur vect_vitesse;
	double  m; //masse m
	GravitationConstante sm_forces;
	
	public:
	
	//constucteurs
	PointMateriel (Vecteur vect_position, Vecteur vect_vitesse, double m);
	PointMateriel (double m);
	
	//methodes publiques
	Vecteur position() const;
	Vecteur vitesse() const;
	Vecteur evolution(double t) const;
	
	//accesseurs
	double get_m() const;
	
	//modificateurs
	void mod_pos(double a, double b, double c);
	void mod_v(double a, double b, double c);
};

//operateurs externes 
std::ostream& operator<<(std::ostream& sortie, const PointMateriel &p); //affiche les attributs un à un du PointMateriel p

	
	
	
	
