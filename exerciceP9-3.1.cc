#include <iostream>
#include "Systeme.h"
#include "PointMateriel.h"
#include "GravitationConstante.h"
#include "Libre.h"
#include "IntegrateurEulerCromer.h"
#include "vecteur.h"
#include "constantes.h"
#include "TextViewer.h"

using namespace std;

int main() {
	TextViewer ecran(cout);
	
	//création du système
	Systeme systeme(0, new IntegrateurEulerCromer);
	
	//paramètres donnés dans l'énoncé
	double H(8);
	double L(5);
	double v0(5);
	double m_pierre(1); //masse de la pierre en kg
	double m_fromage(1);
	double prec(0.1);
	
	Vecteur nul(3);
	Vecteur E_fromage({0, L, H}); //vecteur position initiale du fromage
	Vecteur E_prime_pierre((~E_fromage)*v0); //vecteur vitesse intitiale de la pierre
	
	//création des objets et ajout de ces objets au système
	systeme.ajouter_objet(new PointMateriel(nul, E_prime_pierre, m_pierre)); //la pierre 
	systeme.ajouter_objet(new PointMateriel(E_fromage, nul, m_fromage)); //le fromage
	
	systeme.ajouter_contrainte(new Libre); //création de la contrainte libre et ajout au système
	
	systeme.ajouter_champ(new GravitationConstante); //création du champ de gravitation de la Terre(uniforme)
	
	//ajout de la contrainte et du champ de force aux objets du système
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
			systeme.dessine_sur(ecran);
		}
		systeme.evolue(dt);
	}
	
	return 0;
};
	
	
	
