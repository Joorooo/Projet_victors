#include <iostream>
#include "Systeme.h"
#include "PointMateriel.h"
#include "ChampNewtonien.h"
#include "Libre.h"
#include "IntegrateurEulerCromer.h"
#include "vecteur.h"
#include "constantes.h"

using namespace std;

int main() {
	//création du système
	Systeme systeme(0, new IntegrateurEulerCromer);
	
	Vecteur nul(3);
	Vecteur E2({6.37101E6, 0, 0});
	
	double prec(0.1);
	double m1(5.972E24); //masse de l'objet 1
	double m2(0.1); //masse de l'objet 2
	
	//création des objets et ajout de ces objets au système
	systeme.ajouter_objet(new PointMateriel(nul, nul, m1)); //objet numero 1
	systeme.ajouter_objet(new PointMateriel(E2, nul, m2)); //objet numero 2
	
	systeme.ajouter_contrainte(new Libre); //création de la contrainte libre et ajout au système
	
	systeme.ajouter_champ(new ChampNewtonien(*systeme.get_objet(0), prec)); //création du champ de force Newtonien de l'objet 1 sur le second
	systeme.ajouter_champ(new ChampNewtonien(*systeme.get_objet(1), prec)); //création du champ de force Newtonien de l'objet 2 sur le premier
	
	//ajout de la contrainte et des champs de force aux objets du système
	systeme.ajout_contrainte_objet(0, 0);
	systeme.ajout_contrainte_objet(1, 0);
	
	systeme.ajout_champs_objet(0, 1);
	systeme.ajout_champs_objet(1, 0);
	
	cout << systeme;
	
	return 0;
}
	
	
	
	
