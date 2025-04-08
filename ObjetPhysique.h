#pragma once
#include <memory>
#include <iostream>
#include "ObjetMobile.h"
#include "Contraintes.h"
#include "ChampForces.h"
#include "vecteur.h"

class ObjetPhysique : public ObjetMobile {
	protected:
	
	
	std::vector<std::shared_ptr<Contrainte>> tab_contrainte; //tableau de pointeurs partagés sur des contraintes
	std::vector<std::shared_ptr<ChampForces>> tab_champ_f;       //tableau de pointeurs partagés sur des champForces
	double m;
	double charge;
	double dim;
	
	public:
	
	//constructeur
	ObjetPhysique(const Vecteur &e, const Vecteur &e_prime, const std::vector<std::shared_ptr<Contrainte>>& c, const std::vector<std::shared_ptr<ChampForces>>& champ_f, double m, double charge = 0, double dim = 3);
	ObjetPhysique(const ObjetPhysique& obj);
	
	//methodes publiques
	Vecteur force(double t = 0) const;
	Vecteur position() const;
	Vecteur vitesse() const;
	virtual Vecteur evolution(double t = 0) const override;
	virtual std::ostream& affiche(std::ostream& sortie) const override;
	//virtual double E_cin() const = 0;
	virtual double distance(const ObjetPhysique &autre_p) const;
	virtual double distance2(const ObjetPhysique &autre_p) const;
	
	//Manipulateur
	void set_contrainte(const std::shared_ptr<Contrainte>& c);
	void set_champ(const std::shared_ptr<ChampForces>& c);
	int nb_contrante();
	int nb_champforce();
	
	//accesseurs 
	double get_m() const;
	double get_charge() const;
	

};
