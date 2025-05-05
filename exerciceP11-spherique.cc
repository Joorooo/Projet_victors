#include <iostream>
#include <memory>
#include "Systeme.h"
#include "PointMaterielAngles.h"
#include "GravitationConstante.h"
#include "Spherique.h"
#include "IntegrateurEulerCromer.h"
#include "vecteur.h"
#include "constantes.h"

using namespace std;

int main() {
	//création du système
	Systeme systeme(0, make_unique<IntegrateurEulerCromer>());
	
	//paramètres données dans l'énoncé
	
	double m(0.1); //masse du pendule en kg
	double L(2.2); //longueur du pendule en m
	
	Vecteur E_masse({Constantes::pi/6, 0}); //vecteur position initiale de la masse dans les coordonnées sphériques
	Vecteur E_prime_masse({0, 1}); //vecteur vitesse initiale de la masse
	
	//création d'un pointeur à la C sur une contrainte sphérique
	Spherique* s(new Spherique(L));
	
	//création du champ de gravitation de la Terre(uniforme), et d'un pointeur à la C sur ce champ
	GravitationConstante* champ_g(new GravitationConstante);
	
	//création du pendule
	PointMaterielAngles masse(E_masse, E_prime_masse, m);
	
	//ajout de la masse, de la contrainte et du champ de force au système
	systeme.ajouter_objet(make_unique<PointMaterielAngles>(masse));
	
	systeme.ajouter_contrainte(s);
	
	systeme.ajouter_champ(champ_g);
	
	//ajout de la contrainte et du champ de force à la masse
	systeme.ajout_contrainte_objet(0, 0);
	systeme.ajout_champs_objet(0, 0);
	
	size_t n(10);
	double dt(0.01); //pas de calcul
	
	for (size_t i(0); i <= n; i++) {
		cout << systeme << endl;
		systeme.evolue(dt);
	}
	
	return 0;
}
	
	
