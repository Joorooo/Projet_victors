#pragma once
#include "Integrateur.h"

class IntegrateurEulerCromer : public Integrateur {
	public:
	  void integre(ObjetMobile& obj, double t, double dt) override;
};
