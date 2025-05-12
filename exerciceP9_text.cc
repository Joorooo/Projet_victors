#include <iostream>
#include "memory"
#include "Systeme.h"
#include "PointMateriel.h"
#include "Vide.h"
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
	Systeme systeme(0, make_unique<IntegrateurEulerCromer>());
	
	//création d'une pointeur à la C sur une contrainte libre
	Libre* l(new Libre);
	
	Vide* champ_vide(new Vide); //pointeur à la C sur un champ de force vide (ne fait rien), ce sera le champ de force agissant sur la Terre
	
	double prec(0.1);
	double m_pomme(0.1); //masse de la pomme en kg
	double M(Constantes::m_terre);
	
	Vecteur nul({0});
	Vecteur E_T({-Constantes::r_terre}); //vecteur d'une dimension representant la position sur droite vertical passant par la pomme et le centre de la Terre
	Vecteur E_P({10.0});
	
	//création des objets du système
	PointMateriel Terre(E_T, nul, M); //la Terre (représenté par un PointMateriel)
	PointMateriel Pomme(E_P, nul, m_pomme); //une Pomme (représentée par un PointMateriel)
	
	ChampNewtonien* champN_Terre(new ChampNewtonien(Terre, prec)); //création du champ de force Newtonien de la Terre
	
	//ajout des objets, de la contrainte et des champs de force au système
	systeme.ajouter_objet(make_unique<PointMateriel>(Terre));
	systeme.ajouter_objet(make_unique<PointMateriel>(Pomme));
	
	systeme.ajouter_contrainte(l);
	
	systeme.ajouter_champ(champ_vide);
	systeme.ajouter_champ(champN_Terre);
	
	//ajout de la contrainte et des champs de force au objets du systeme
	systeme.ajout_contrainte_objet(0, 0);
	systeme.ajout_contrainte_objet(1, 0);
	
	systeme.ajout_champs_objet(0, 0);
	systeme.ajout_champs_objet(1, 1);
	
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
