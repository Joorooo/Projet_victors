#pragma once
#include "ObjetMobile.h"

class Integrateur {
	public:
	  virtual void integre(ObjetMobile& obj, double t, double dt) = 0;  
	  virtual ~Integrateur();
};

class IntegrateurEulerCromer : public Integrateur {
	public:
	  void integre(ObjetMobile& obj, double t, double dt) override;
};
