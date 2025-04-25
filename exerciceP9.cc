#include <iostream>
#include <memory>
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
	
	//création d'une contrainte libre
	Libre l;
	
	double prec(0.1);
	double m_pomme(0.1); //masse de la pomme
	double M(Constantes::m_terre);
	
	Vecteur nul({0});
	Vecteur E_T({-Constantes::r_terre}); //vecteur d'une dimension representant la position sur droite vertical passant par la pomme et le centre de la Terre
	Vecteur E_P({10.0});
	
	Vide champ_vide; //champ de force vide (ne fait rien), ce sera le champ de force agissant sur la Terre
	PointMateriel Terre(E_T, nul, l, champ_vide, M); //cŕeation de la Terre (représenté par un PointMateriel)
	
	ChampNewtonien champN_Terre(Terre, prec); //création du champ de force Newtonien de la Terre
	
	//création d'une Pomme (représentée par un PointMateriel)
	PointMateriel Pomme(E_P, nul, l, champN_Terre, m_pomme);
	
	//ajout de la contrainte, des champs et des objets au système
	systeme.ajouter_objet(make_unique<PointMateriel>(Terre));
	systeme.ajouter_objet(make_unique<PointMateriel>(Pomme));
	
	systeme.ajouter_contrainte(l);
	
	systeme.ajouter_champ(champ_vide);
	systeme.ajouter_champ(champN_Terre);
	
	size_t n(1500);
	double dt(1E-3); //pas de calcul
	
	for (size_t i(0); i <= n; i++) {
		if (i%100 == 0) { //affichage tous les 100 pas de calcul
			cout << systeme << endl;
		}
		systeme.evolue(dt);
	}
	
	return 0;
}
