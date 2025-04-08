#include "IntegrateurEulerCromer.h"

void IntegrateurEulerCromer::integre(ObjetMobile& obj, double t, double dt) {
	
	obj.set_E_prime(obj.get_E_prime() + dt*obj.evolution(t));
	obj.set_E(obj.get_E() + dt*obj.get_E_prime());
}
