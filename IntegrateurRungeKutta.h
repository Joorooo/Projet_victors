#pragma once
#include "Integrateur.h"

class IntegrateurRungeKutta : public Integrateur {
	public:
	void integre(ObjetMobile& obj, double t, double dt) override;
};
