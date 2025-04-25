#pragma once
#include <iostream>
#include "ChampForces.h"
#include "ObjetPhysique.h"
#include "vecteur.h"

class ForceUniforme : public ChampForces {
	protected:
	
	Vecteur intensite; //intensite du champ
	
	public:
	
	//constructeur
	ForceUniforme(const Vecteur &intensite);
	ForceUniforme(const ForceUniforme &autre_f);
	
	//destructeur
	virtual ~ForceUniforme();
	
	//methode publique
	virtual Vecteur force(const ObjetPhysique &p, double t = 0) const;
	virtual std::unique_ptr<ChampForces> copie() const override;
	virtual std::ostream& affiche(std::ostream& sortie) const override;
	
	//accesseur
	Vecteur get_intensite() const;
	
};
