#include <iostream>
#include "Systeme.h"
#include "PointMateriel.h"
#include "ChampNewtonien.h"
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
	
	Vecteur nul({0});
	Vecteur E_T({-Constantes::r_terre}); //vecteur d'une dimension représentant la position sur droite vertical passant par la pomme et le centre de la Terre
	Vecteur E_P({10.0});
	
	double prec(0.1);
	double m_pomme(0.1); //masse de la pomme en kg
	double M(Constantes::m_terre);
	
	//création des objets et ajout de ces objets au système
	systeme.ajouter_objet(new PointMateriel(E_T, nul, M)); //la Terre (représentée par un PointMateriel)
	systeme.ajouter_objet(new PointMateriel(E_P, nul, m_pomme)); //une pomme (représentée par un PointMateriel)
	
	systeme.ajouter_contrainte(new Libre); //création de la contrainte libre et ajout au système
	
	systeme.ajouter_champ(new ChampNewtonien(*systeme.get_objet(0), prec)); //création du champ de force Newtonien de la Terre sur la pomme
	systeme.ajouter_champ(new ChampNewtonien(*systeme.get_objet(1), prec)); //création du champ de force Newtonien de la pomme sur la Terre
	
	//ajout de la contrainte et des champs de force aux objets du systeme
	systeme.ajout_contrainte_objet(0, 0);
	systeme.ajout_contrainte_objet(1, 0);
	
	systeme.ajout_champs_objet(0, 1);
	systeme.ajout_champs_objet(1, 0);
	
	size_t n(1500);
	double dt(1E-3); //pas de calcul
	
	for (size_t i(0); i <= n; i++) {
		if (i%100 == 0) { //affichage tous les 100 pas de calcul
			systeme.dessine_sur(ecran);
		}
		systeme.evolue(dt);
	}
	
	return 0;
}
