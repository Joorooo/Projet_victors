#pragma once
#include <iostream>
#include "Contraintes.h"
#include "ObjetPhysique.h"

class Spherique : public Contrainte {
	private:
	
	double r; //rayon de la contrainte
	
	//accesseurs des angles et dérivées angulaires
	double get_teta(const ObjetPhysique &p) const;
	double get_phi(const ObjetPhysique &p) const;
	double get_teta_prime(const ObjetPhysique &p) const;
	double get_phi_prime(const ObjetPhysique &p) const;
	
	public:
	
	//constructeur
	Spherique(double r);
	
	//méthodes publiques
	virtual Vecteur applique_force(const ObjetPhysique &p, const Vecteur &force, double t = 0) const override; //retourne doubles dérivées des angles teta et phi 
	virtual Vecteur position(const ObjetPhysique &p) const override; //retourne position de l'objet p dans système de coordonnées carthésiennes
	virtual Vecteur vitesse(const ObjetPhysique &p) const override; //retourne vitesse de l'objet p dans système de coordonnées carthésiennes
	virtual std::ostream& affiche(std::ostream& sortie) const override;
};
