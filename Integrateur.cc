#include "Integrateur.h"

void IntegrateurEulerCromer::integre(ObjetMobile& obj, double t, double dt) {
	if (not(obj.get_E().norme() > 1e-10)) {
		obj.set_E_prime(obj.get_E_prime() + dt*obj.evolution(t));
	}
	
	obj.set_E(obj.get_E() + dt*obj.get_E_prime());
}
