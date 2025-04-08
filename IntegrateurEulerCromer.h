#pragma once
#include "Integrateur.h"

class IntegrateurEulerCromer : public Integrateur {
	public:
	  //méthode integre
	  void integre(ObjetMobile& obj, double t, double dt) override;
	  
	  //constructeur
	  IntegrateurEulerCromer() = default;
	  
	  //destructeur
	  ~IntegrateurEulerCromer() = default;
};
