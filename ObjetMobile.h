#pragma once
#include "vecteur.h"

class ObjetMobile {
	
	protected:
	  Vecteur E;
	  Vecteur E_prime;
	
	public:
	  //constructeurs
      ObjetMobile(const Vecteur& e, const Vecteur& e_prime);
	  ObjetMobile(unsigned int dim);
	  
	  //méthodes
	  virtual Vecteur evolution(double t = 0) const = 0;
	  virtual std::ostream& affiche(std::ostream& sortie) const;
	  virtual Vecteur get_E() const;
	  virtual Vecteur get_E_prime() const;
	  virtual void set_E(const Vecteur& v);
	  virtual void set_E_prime(const Vecteur& v);

	  //destructeur
	  virtual ~ObjetMobile();
	          
};

//Opérateure externe
std::ostream& operator<<(std::ostream& sortie, const ObjetMobile& o);
