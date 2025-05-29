#include "IntegrateurRungeKutta.h"
#include "vecteur.h"

void IntegrateurRungeKutta::integre(ObjetMobile &obj, double t, double dt) {
	Vecteur k0 = obj.get_E();
	Vecteur k1 = obj.get_E_prime();
	Vecteur k1_prime = obj.evolution(t);
	
	Vecteur k2 = k1 + (1/2.0)*dt*k1_prime;
	obj.set_E(k0 + (1/2.0)*dt*k1);
	obj.set_E_prime(k2);
	Vecteur k2_prime = obj.evolution(t+dt/2.0);
	
	Vecteur k3 = k1 + (1/2.0)*dt*k2_prime;
	obj.set_E(k0 + (1/2.0)*dt*k2);
	obj.set_E_prime(k3);
	Vecteur k3_prime = obj.evolution(t+dt/2);
	
	Vecteur k4 = k1 + dt*k3_prime;
	obj.set_E(k0 + dt*k3);
	obj.set_E_prime(k4);
	Vecteur k4_prime = obj.evolution(t+dt);
	
	obj.set_E(k0 + (1/6.0)*dt*(k1+2*k2+2*k3+k4));
	obj.set_E_prime(k1 + (1/6.0)*dt*(k1_prime+2*k2_prime+2*k3_prime+k4_prime));
}
	
	
	
