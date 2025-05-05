#pragma once
#include "Contraintes.h"

class PointMaterielAngles;

class Spherique : public Contrainte {
	private:
	
	double r; //rayon
	
	//methodes privées
	double get_teta(const ObjetPhysique &p) const;
	double get_phi(const ObjetPhysique &p) const;
	double get_teta_prime(const ObjetPhysique &p) const;
	double get_phi_prime(const ObjetPhysique &p) const;
	
	public:
	
	//constructeur
	Spherique(double r);
	
	//methodes publiques
	virtual Vecteur applique_force(const ObjetPhysique &p, const Vecteur &force, double t = 0) const override;
	virtual Vecteur position(const ObjetPhysique &p) const override;
	virtual Vecteur vitesse(const ObjetPhysique &p) const override;
	virtual std::ostream& affiche(std::ostream& sortie) const override;
};
