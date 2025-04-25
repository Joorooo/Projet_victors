#include <iostream>
#include <memory>
#include <cmath>
#include "Systeme.h"
#include "PointMateriel.h"
#include "Vide.h"
#include "ChampNewtonien.h"
#include "Libre.h"
#include "IntegrateurEulerCromer.h"
#include "vecteur.h"
#include "constantes.h"

using namespace std;

int main() {
	unique_ptr<Integrateur> integrateur = make_unique<IntegrateurEulerCromer>();
	
	//création du système
	Systeme systeme(0, move(integrateur));
	
	//création des contraintes
	Libre l;
	
	double prec(0.1);
	double m_vaisseau(1);
	Vecteur nul({0, 0});
	
	Vecteur E_T({Constantes::ua, 0}); //position initiale de la Terre
	Vecteur E_M({-Constantes::d_MS, 0}); //position initiale de Mars
	
	Vecteur E_prime_T({0, 10.73E4/3.6}); //vitesse de la Terre
	Vecteur E_prime_M({0, -8.71E4/3.6}); //vitesse de Mars
	Vecteur E_prime_V({0, 11.79E4/3.6}); //vitesse initiale du vaisseau
	
	Vide champ_vide; //champ de force vide (ne fait rien), ce sera le champ de force agissant sur le Soleil
	PointMateriel Soleil(nul, nul, l, champ_vide, Constantes::m_soleil); //cŕeation du Soleil(représenté par un PointMateriel)
	
	ChampNewtonien champN_Soleil(Soleil, prec); //création du champ de force Newtonien du Soleil
	
	//création des autres objets
	PointMateriel Terre(E_T, E_prime_T, l, champN_Soleil, Constantes::m_terre); //planète Terre
	PointMateriel Mars(E_M, E_prime_M, l, champN_Soleil, Constantes::m_mars); //planète Mars
	PointMateriel Vaisseau(E_T, E_prime_V, l, champN_Soleil, m_vaisseau); //vaisseau
	
	//ajout de la contrainte, des champs et des objets au système
	systeme.ajouter_objet(make_unique<PointMateriel>(Soleil));
	systeme.ajouter_objet(make_unique<PointMateriel>(Terre));
	systeme.ajouter_objet(make_unique<PointMateriel>(Mars));
	systeme.ajouter_objet(make_unique<PointMateriel>(Vaisseau));
	
	systeme.ajouter_contrainte(l);
	
	systeme.ajouter_champ(champ_vide);
	systeme.ajouter_champ(champN_Soleil);
	
	size_t n(700); //2 années
	double dt(86400); //pas de calcul
	
	for (size_t i(0); i <= n; i++) {
		if (i == 365) {
			cout << "Au bout de 365 jours (Terriens), la Terre a retrouvée sa position initiale !" << endl;
			cout << systeme << endl;
		}
		if (i == 517) {
			cout << "Au bout de 517 jours (Terriens), le vaisseau a retrouvé sa position initiale !" << endl;
			cout << systeme << endl;
		}
		if (i%100 == 0) { //affichage du système tous des 10 jours 
			cout << systeme << endl;
		}
		systeme.evolue(dt);
	}
	
	return 0;
}
	
	
	 
