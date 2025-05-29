#pragma once
#include <iostream>
#include "ForceCentrale.h"
#include "constantes.h"

class ChampNewtonien : public ForceCentrale {
	public:
	
	//on utilise le constructeur de Forcecentrale
	using ForceCentrale::ForceCentrale;
	
	//méthode publique
	virtual Vecteur force(const ObjetPhysique &p, double t = 0) const;
	virtual std::ostream& affiche(std::ostream& sortie) const override;
};
