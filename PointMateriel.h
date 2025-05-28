#pragma once
#include <iostream>
#include "vecteur.h"
#include "GravitationConstante.h"

class PointMateriel {
	private:
	
	Vecteur E;
	Vecteur E_prime;
	double  m; //masse m
	GravitationConstante champ_f;
	
	public:
	
	//constucteurs
	PointMateriel(const Vecteur&e, const Vecteur &e_prime, double m);
	PointMateriel(double m);
	
	//methodes publiques
	virtual Vecteur position() const;
	virtual Vecteur vitesse() const;
	virtual Vecteur evolution(double t) const;
	virtual std::ostream& affiche(std::ostream& sortie) const;
	virtual std::ostream& affiche(std::ostream& sortie, double t) const;
	
	//accesseurs
	double get_m() const;
	
	//modificateurs
	void mod_pos(double a, double b, double c);
	void mod_v(double a, double b, double c);
};

//operateurs externes 
std::ostream& operator<<(std::ostream& sortie, const PointMateriel &p); //affiche les attributs un à un du PointMateriel p

	
	
	
	
