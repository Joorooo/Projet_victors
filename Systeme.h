#pragma once
#include <vector>
#include "ObjetPhysique.h"
#include "Contraintes.h"
#include "ChampForces.h"
#include "Integrateur.h"
#include "Dessinable.h"
#include "IntegrateurEulerCromer.h"

class Systeme : public Dessinable {
	
	private:
	  
	double temps;
	std::vector<ObjetPhysique*> objets;  //collection hétérogène d'objets
	std::vector <Contrainte*> contraintes; //collection hétérogène de contraintes
	std::vector <ChampForces*> champsforces; //collection hétérogène de champs de forces
	Integrateur* integrateur; //pointeur à la C sur un integrateur
	  
	public:
	
	//constructeur
	Systeme();
	Systeme(double t, Integrateur* integ);
	Systeme(double t);
	  
	//manipulateurs
	void ajouter_objet(ObjetPhysique* obj);
	void ajouter_contrainte(Contrainte* cont);
	void ajouter_champ(ChampForces* champ);
	void changer_integrateur(Integrateur* integ);
	void ajout_contrainte_objet(size_t indice_objet, size_t indice_contrainte);
	void ajout_champs_objet(size_t indice_objet, size_t indice_champ);
	
	//accesseur
	ObjetPhysique* get_objet(size_t indice_objet) const;
	double get_temps() const;
	size_t taille_objets() const;
	
	//méthode publique
	void evolue(double dt);
	bool proche(size_t indice1, size_t indice2, double prec);
	std::ostream& affiche(std::ostream& sortie) const;
	virtual void dessine_sur(SupportADessin& support) const override
	  { support.dessine(*this); }
	//destructeur
	virtual ~Systeme();
	  
	//on ne copie pas un système
	Systeme(Systeme const&) = delete;
        Systeme& operator=(Systeme const&) = delete;
};

//opérateur d'affichage pour un système
std::ostream& operator<<(std::ostream& sortie, const Systeme& systeme);
