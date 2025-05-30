#pragma once
#include "Integrateur.h"

class IntegrateurNewmark : public Integrateur {
	private:
	
	double epsilon; //précision, utilisée dans le méthode integre
	
	public:
	
	//constructeur
	IntegrateurNewmark(double eps);
	
	//méthode publique
	void integre(ObjetMobile& obj, double t, double dt) override;
};
