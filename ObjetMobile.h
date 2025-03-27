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
	  virtual Vecteur evolution(double temps) = 0;
	  virtual std::ostream& affiche(std::ostream& sortie) const;
	  Vecteur get_E() const;
	  Vecteur get_E_prime() const;
	  void set_E(const Vecteur& v);
	  void set_E_prime(const Vecteur& v);

	  //destructeur
	  virtual ~ObjetMobile();
	          
};

//Opérateure externe
std::ostream& operator<<(std::ostream& sortie, const ObjetMobile& o);
