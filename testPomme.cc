#include <iostream>
#include "PointMateriel.h"
#include "ChampNewtonien.h"
#include "Libre.h"
#include "IntegrateurEulerCromer.h"
#include "vecteur.h"
#include "constantes.h"

using namespace std;

int main() {
	IntegrateurEulerCromer integrateur;
	Libre l;
	
	Vecteur nul(1); //cf constructeurs de classe Vecteur
	Vecteur E_T({-Constantes::r_terre}); //vecteur d'une dimension représentant la position sur droite vertical passant par la pomme et le centre de la Terre
	Vecteur E_P({10.0});
	
	double prec(0.1); //précision pour le champ de force Newtonien
	double m_pomme(0.1); //masse de la pomme en kg
	double M(Constantes::m_terre);
	
	PointMateriel Terre(E_T, nul, &l, nullptr, M); //la Terre (représentée par un PointMateriel)
	PointMateriel Pomme(E_P, nul, &l, nullptr, m_pomme); //une pomme (représentée par un PointMateriel)
	
	ChampNewtonien champ_T(Terre, prec); //création du champ de force Newtonien de la Terre sur la pomme
	ChampNewtonien champ_P(Pomme, prec); //création du champ de force Newtonien de la pomme sur la Terre
	
	//ajout des champs de force aux objets(la Terre et la Pomme)
	Terre.mod_champ(&champ_P);
	Pomme.mod_champ(&champ_T);
	
	
	unsigned int n(1500);
	double dt(1E-3); //pas de calcul
	double t(0); //temps
	
	for (size_t i(0); i <= n; i++) {
		if (i%100 == 0) { //affichage tous les 100 pas de calcul
			cout << t << " # temps" << endl;
			cout << Pomme;
		}
		integrateur.integre(Terre, t, dt);
		integrateur.integre(Pomme, t, dt);
		t += dt;
	}
	return 0;
}


	

