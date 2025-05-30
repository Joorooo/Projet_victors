#include <iostream>
#include "Systeme.h"
#include "PointMateriel.h"
#include "Libre.h"
#include "GravitationConstante.h"
#include "IntegrateurEulerCromer.h"
#include "IntegrateurNewmark.h"
#include "IntegrateurRungeKutta.h"
#include "vecteur.h"
#include "constantes.h"
#include "TextViewer.h"

using namespace std;

int main() {
	TextViewer ecran(cout);
	
	//création du système
	Systeme systeme(0, new IntegrateurRungeKutta);
                     //new (IntegrateurEulerCromer)
	
	Vecteur E({0, 0, 1.0}); //vecteur position initiale de l'objet
	Vecteur E_prime({0, 1.0, 2.0}); //vecteur vitesse initial de l'objet
	double m(0.127); //masse 
	
	systeme.ajouter_objet(new PointMateriel(E, E_prime, m)); //création du point matériel et ajout au système
	systeme.ajouter_contrainte(new Libre); //création de la contrainte libre et ajout au système
	systeme.ajouter_champ(new GravitationConstante); //création du champ de gravitation de la Terre(uniforme)
	
	//ajout de la contrainte et du champ de force au point matériel
	systeme.ajout_contrainte_objet(0, 0);
	systeme.ajout_champs_objet(0, 0);
	
	unsigned int n(100);
	double dt(0.01); //pas de calcul
	
	cout << systeme;
	systeme.evolue(dt);
	for (size_t i(1); i <= n; i++) {
		systeme.dessine_sur(ecran);
		systeme.evolue(dt);
	}
	
	return 0;
}
