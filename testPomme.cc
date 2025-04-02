#include <iostream>
#include "PointMateriel.h"
#include "ChampNewtonien.h"
#include "GravitationConstante.h"
#include "Libre.h"
#include "IntegrateurEulerCromer.h"
#include "vecteur.h"
#include "constantes.h"

using namespace std;


int main() {
	Libre l;
	GravitationConstante g;
	
	double prec(0.1);
	double m_pomme(0.1); //masse de la pomme
	
	Vecteur E_T({-Constantes::r_terre}); //vecteur d'une dimension representant la position sur droite vertical passant par la pomme et le centre de la Terre
	Vecteur E_P({10.0});
	
	Vecteur Eprime_T({0.0}); //vecteur vitesse
	Vecteur Eprime_P({0.0});
	
	PointMateriel Terre(E_T, Eprime_T, l, g, Constantes::m_terre, 0.0, 1); //la Terre representee par un point materiel
	ChampNewtonien champ_T(Terre, prec);
	
	PointMateriel Pomme(E_P, Eprime_P, l, champ_T, m_pomme, 0.0, 1);
	
	IntegrateurEulerCromer EulerCromer;
	
	unsigned int n(1500);
	double dt(1E-3); //pas de calcul
	double t(0); //temps
	
	for (unsigned int i = 0; i <= n; i++) {
		if (i%100 == 0) { //affichage tous les 100 pas de calcul
			cout << t << " # temps" << endl;
			cout << Pomme << endl;
			
		}
		EulerCromer.integre(Pomme, t, dt);
		
		t += dt;
	}
	
}

	

