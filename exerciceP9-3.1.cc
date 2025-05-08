#include <iostream>
#include <memory>
#include "Systeme.h"
#include "PointMateriel.h"
#include "GravitationConstante.h"
#include "Libre.h"
#include "IntegrateurEulerCromer.h"
#include "vecteur.h"
#include "constantes.h"

using namespace std;

int main() {
	//création du système
	Systeme systeme(0, make_unique<IntegrateurEulerCromer>());
	
	//création d'un pointeur à la C sur une contrainte libre
	Libre* l(new Libre);
	
	//création du champ de gravitation de la Terre(uniforme), et d'un pointeur à la C sur ce champ
	GravitationConstante* champ_g(new GravitationConstante);
	
	//paramètres donnés dans l'énoncé
	double H(8);
	double L(5);
	double v0(5);
	double m_pierre(1); //masse de la pierre et du fromage en kg
	double m_fromage(1);
	double prec(0.1);
	
	Vecteur nul({0, 0, 0});
	Vecteur E_fromage({0, L, H}); //vecteur position initiale du fromage
	Vecteur E_prime_pierre((~E_fromage)*v0); //vecteur vitesse intitiale de la pierre
	
	//cŕeation des objets
	PointMateriel Pierre(nul, E_prime_pierre, m_pierre);
	PointMateriel Fromage(E_fromage, nul, m_fromage);
	
	//ajout des objets, de la contrainte et du champ de force au système
	systeme.ajouter_objet(make_unique<PointMateriel>(Pierre));
	systeme.ajouter_objet(make_unique<PointMateriel>(Fromage));
	
	systeme.ajouter_contrainte(l);
	systeme.ajouter_champ(champ_g);
	
	//ajout de la contrainte de du champ de force aux objets du système
	systeme.ajout_contrainte_objet(0, 0);
	systeme.ajout_contrainte_objet(1, 0);
	
	systeme.ajout_champs_objet(0, 0);
	systeme.ajout_champs_objet(1, 0);
	
	size_t n(2000);
	double dt(1E-3); //pas de calcul
	
	for (size_t i(0); i <= n; i++) {
		if (i%100 == 0) { //affichage tous les 100 pas de calcul 
			if (systeme.proche(0, 1, prec)) {
				cout << "La pierre et le fromage rentrent en colision !" << endl;
				cout << "----------------------------------------------" << endl;
				cout << endl;
			}
			cout << systeme << endl;
		}
		systeme.evolue(dt);
	}
	
	return 0;
};
	
	
	
