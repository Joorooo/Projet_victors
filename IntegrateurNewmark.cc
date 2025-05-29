#include "IntegrateurNewmark.h"
#include "vecteur.h"

//constructeur
IntegrateurNewmark::IntegrateurNewmark(double eps) : epsilon(eps) {}

//méthode publique
void IntegrateurNewmark::integre(ObjetMobile& obj, double t, double dt) {
	Vecteur s = obj.evolution(t);
	Vecteur q;
	Vecteur r;
	Vecteur p;
	Vecteur condition;
	do {
		q = obj.get_E();
		p = obj.get_E_prime();
		r = obj.evolution(t+dt);
		obj.set_E_prime(p + (dt/2.0)*(r+s));
		obj.set_E(obj.get_E() + dt*p + ((dt*dt)/3.0)*((1/2.0)*r + s));
		condition = obj.get_E()-q;
	} while(condition.norme() >= epsilon); //cf complément mathématique
}
		
	
	
	
	
	
