#pragma once
#include <iostream>
#include "vecteur.h"

class ObjetMobile {
	
	protected:
	Vecteur E;
	Vecteur E_prime;
	
	public:
	
	//constructeurs
        ObjetMobile(const Vecteur& e, const Vecteur& e_prime);
	ObjetMobile(unsigned int dim);
	  
	//méthodes publiques
	virtual Vecteur evolution(double t = 0) const = 0;
	virtual std::ostream& affiche(std::ostream& sortie) const;
	virtual std::ostream& affiche_primaire(std::ostream& sortie) const; //retourne pour l'instant la même chose que méthode affiche
	
	//accesseurs
	virtual Vecteur get_E() const;
	virtual Vecteur get_E_prime() const;
	
	//manipulateurs
	virtual void set_E(const Vecteur& v);
	virtual void set_E_prime(const Vecteur& v);

	//destructeur
	virtual ~ObjetMobile() = default;          
};

//opérateur d'affichage externe
std::ostream& operator<<(std::ostream& sortie, const ObjetMobile& obj);
