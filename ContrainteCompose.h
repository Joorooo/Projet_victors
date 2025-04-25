#pragma once
#include <iostream>
#include "vector"
#include "memory"
#include "Contraintes.h"


class ContrainteCompose : public Contrainte {
	private:
	
	std::vector<std::unique_ptr<Contrainte>> contraintes; //tableau de unique pointeurs sur des contraintes
	
	public:
	
	//constructeur
	ContrainteCompose(const std::vector<std::unique_ptr<Contrainte>> &contr);
	ContrainteCompose(const ContrainteCompose &autre_cc);
	ContrainteCompose() = default;
	
	//destructeur
	virtual ~ContrainteCompose();
	
	//methodes publiques
	virtual Vecteur applique_force(const ObjetPhysique &p, const Vecteur &force, double t = 0) const override;
	virtual Vecteur position(const ObjetPhysique &p) const override;
	virtual Vecteur vitesse(const ObjetPhysique &p) const override;
	virtual std::ostream& affiche(std::ostream& sortie) const override;
	void ajout_contr(const Contrainte &c);
	virtual std::unique_ptr<Contrainte> copie() const override;
};
