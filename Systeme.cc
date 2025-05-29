#include "Systeme.h"

using namespace std;

//constructeurs
Systeme::Systeme() : temps(0) {}
Systeme::Systeme(double t, Integrateur* integ) 
: temps(t), integrateur(integ)
{}
Systeme::Systeme(double t) : temps(t), 
integrateur(new IntegrateurEulerCromer) {} //l'intégrateur est un IntegrateurEulerCromer

//manipulateurs
void Systeme::ajouter_objet(ObjetPhysique* obj) 
     {objets.push_back(obj);}
     
void Systeme::ajouter_contrainte(Contrainte* cont)
     {contraintes.push_back(cont);}

void Systeme::ajouter_champ(ChampForces *champ)
     {champsforces.push_back(champ);}

void Systeme::changer_integrateur(Integrateur* integ)
     {integrateur = integ;}

//accesseur
ObjetPhysique* Systeme::get_objet(size_t indice_objet) const {
	if (indice_objet >= objets.size()) {
		cerr << "ERREUR, indice hors limite" << endl;
		return nullptr;
	} else {
		return objets[indice_objet];
	}
}

double Systeme::get_temps() const { return temps; }

size_t Systeme::taille_objets() const { return objets.size(); } 

//méthode qui fait évoluer le systeme
void Systeme::evolue(double dt) {
	for (auto & obj : objets) {
		integrateur->integre(*obj, temps, dt); //integre tous les objets du système un à un 
	}
	temps += dt;
}

//méthode qui dit si deux objets sont proches
bool Systeme::proche(size_t ind1, size_t ind2, double prec) {
	if ((ind1 >= objets.size()) or (ind2 >= objets.size())) {
		cerr << "ERREUR, indice(s) hors limite" << endl;
		return false;
	}
	else {
		return objets[ind1]->distance(*objets[ind2]) <= prec;
	}
}
void Systeme::ajout_contrainte_objet(size_t indice_objet, size_t indice_contrainte) {
	if ((contraintes.size() > indice_contrainte) and ( objets.size() > indice_objet)){
		objets[indice_objet]->mod_contrainte(contraintes[indice_contrainte]); //appelle mod_contrainte de la classe ObjetPhysique
	} else {
		cerr << "-->ERREUR : indice hors limite, la contrainte n'a pas pu être ajoutée" << endl;
	}
}

void Systeme::ajout_champs_objet(size_t indice_objet, size_t indice_champ) {
	if ((champsforces.size() > indice_champ) and (objets.size() > indice_objet)){
		objets[indice_objet]->mod_champ(champsforces[indice_champ]); //appelle mod_champ de la classe ObjetPhysique
	} else {
		cerr << "-->ERREUR : indice hors limite, le champ n'a pas pu etre ajouter" << endl;
	}
}                  

//méthode qui crée la sortie
ostream& Systeme::affiche(ostream& sortie) const {
	sortie << "Systeme : à t = " << temps << " :" << endl;
	if (!objets.empty()) { //on s'assure que objets ne soit pas vide
		for (size_t i(0); i < objets.size(); ++i) { //affiche un à un les objets physiques du système
			sortie << "Objet no " << i+1 << " : ";
			sortie << *objets[i] << endl;
		}
	}
	if (!champsforces.empty()) { //on s'assure que champsforces ne soit pas vide 
		for (size_t i(0); i < champsforces.size(); ++i) { //affiche un à un les champs de forces du système
			sortie << "Champ no " << i+1 <<  " : " << *champsforces[i] << endl; 
		}
		cout << endl;
	}
	if (!contraintes.empty()) { //on s'assure que contraintes ne soit pas vide
		for (size_t i(0); i < contraintes.size(); ++i) { //affiche un à un les contraintes du système
			sortie << "Contrainte no " << i+1 << " : " << *contraintes[i] << endl;
		}
	}
	return sortie;
}

//opérateur d'affichage pour un système
ostream& operator<<(ostream& sortie, const Systeme& systeme){
	return systeme.affiche(sortie);
}

//destructeur
Systeme::~Systeme() {
	//détruit un(e) à un(e) les variables pointées par les pointeurs à la C du système sur les contraintes, champs de forces et objets 
	for (auto cont : contraintes) {
		delete cont; 
	}
	for (auto champ : champsforces) {
		delete champ;
	}
	for (auto obj : objets) {
		delete obj;
	}
	delete integrateur; //détruit la variable pointée par integrateur
}

	
	

