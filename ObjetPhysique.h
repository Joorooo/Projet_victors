#pragma once
#include <iostream>
#include "ObjetMobile.h"
#include "Contraintes.h"
#include "ChampForces.h"
#include "vecteur.h"

class ObjetPhysique : public ObjetMobile {
	protected:
	
	Contrainte* contrainte; // pointeur à la C sur un objet de type Contrainte
	ChampForces* champ_f;
	double m;
	double charge;
	double dim;
	
	public:
	
	//constructeur
	ObjetPhysique(const Vecteur &e, const Vecteur &e_prime, Contrainte* c, ChampForces* champ_f, 
	double m, double charge = 0, double dim = 3);
	ObjetPhysique(const Vecteur &e, const Vecteur &e_prime, double m, double charge = 0, double dim = 3);
    
	//destructeur
	virtual ~ObjetPhysique();
	
	//methodes publiques
	Vecteur force(double t = 0) const;
	Vecteur position() const;
	Vecteur vitesse() const;
	virtual Vecteur evolution(double t = 0) const override;
	virtual std::ostream& affiche(std::ostream& sortie) const override;
	virtual double distance(const ObjetPhysique &autre_p) const;
	virtual double distance2(const ObjetPhysique &autre_p) const;
	
	//modificateurs
	void mod_contrainte(Contrainte* cont);
	void mod_champ(ChampForces* champ);
	
	//accesseurs 
	double get_m() const;
	double get_charge() const;
	

};
