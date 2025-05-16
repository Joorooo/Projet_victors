#include <iostream>
#include <cmath>
#include "Systeme.h"
#include "PointMaterielAngles.h"
#include "Spherique.h"
#include "GravitationConstante.h"
#include "IntegrateurEulerCromer.h"
#include "vecteur.h"
#include "constantes.h"
#include "TextViewer.h"

using namespace std;

int main() {
	TextViewer ecran(cout);
	
	//création du système
	Systeme systeme(0, new IntegrateurEulerCromer);
	
	double m(0.1); //masse du pendule en kg
	double L(2.2); //longueur du pendule en m
	
	Vecteur E_masse({M_PI/6, 0}); //vecteur position initiale de la masse dans les coordonnées sphériques
	Vecteur E_prime_masse({0, 1}); //vecteur vitesse initiale de la masse
	
	//création du pendule et ajout au système
	systeme.ajouter_objet(new PointMaterielAngles(E_masse, E_prime_masse, m));
	
	systeme.ajouter_contrainte(new Spherique(L)); //création de la contrainte sphérique et ajout au système
	
	systeme.ajouter_champ(new GravitationConstante); //création du champ de gravitation de la Terre(uniforme)
	
	//ajout de la contrainte et du champ de force à la masse
	systeme.ajout_contrainte_objet(0, 0);
	systeme.ajout_champs_objet(0, 0);
	
	size_t n(10);
	double dt(0.01); //pas de calcul
	
	for (size_t i(0); i <= n; i++) {
		systeme.dessine_sur(ecran);
		systeme.evolue(dt);
	}
	
	return 0;
}
	
	
