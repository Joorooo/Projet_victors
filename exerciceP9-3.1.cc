#include <iostream>
#include <memory>
#include "Systeme.h"
#include "PointMateriel.h"
#include "ChampForcesCompose.h"
#include "GravitationConstante.h"
#include "Libre.h"
#include "IntegrateurEulerCromer.h"
#include "vecteur.h"
#include "constantes.h"

using namespace std;

int main() {
	unique_ptr<Integrateur> integrateur = make_unique<IntegrateurEulerCromer>();
	
	//création du système
	Systeme systeme(0, move(integrateur));
	
	//création d'une contrainte libre
	Libre l;
	
	//création du champ de gravitation de la Terre(uniforme)
	GravitationConstante champ_g;
	
	//paramètres donnés dans l'énoncé
	double H(8);
	double L(5);
	double v0(5);
	double m_pierre(1);
	double m_fromage(1);
	double prec(0.1);
	
	Vecteur nul({0, 0, 0});
	Vecteur E_fromage({0, L, H}); //vecteur position initiale du fromage
	Vecteur E_prime_pierre((~E_fromage)*v0); //vecteur vitesse intitiale de la pierre
	
	//cŕeation des objets
	PointMateriel Pierre(nul, E_prime_pierre, l, champ_g, m_pierre);
	PointMateriel Fromage(E_fromage, nul, l, champ_g, m_fromage);
	
	//ajout de la contrainte, des champs et des objets au système
	systeme.ajouter_objet(make_unique<PointMateriel>(Pierre));
	systeme.ajouter_objet(make_unique<PointMateriel>(Fromage));
	
	systeme.ajouter_contrainte(l);
	systeme.ajouter_champ(champ_g);
	
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
	
	
	
