#include "Systeme.h"

using namespace std;

//constructeurs
Systeme::Systeme() : temps(0) {}

Systeme::Systeme(double t, vector<unique_ptr<ObjetPhysique>> obj,
	                       vector<shared_ptr<Contrainte>> cont,
	                       vector<shared_ptr<ChampForces>> champ, 
	                       unique_ptr<Integrateur> integ) : temps(t), objet(std::move(obj)), contrainte(std::move(cont)), champforce(std::move(champ)), integrateur(std::move(integ)) {}
	                       
//Manipulateurs
void Systeme::ajouter_objet(std::unique_ptr<ObjetPhysique> obj) 
     {objet.push_back(std::move(obj));}
     
void Systeme::ajouter_contrainte(std::shared_ptr<Contrainte> cont)
     {contrainte.push_back(cont);}

void Systeme::ajouter_ChampForces(std::shared_ptr<ChampForces> champ)
     {champforce.push_back(champ);}

void Systeme::changer_integrateur(std::unique_ptr<Integrateur> integ)
     {integrateur = std::move(integ);}

//Méthode qui crée la sortie
ostream& Systeme::affiche(ostream& sortie) const {
	sortie << "Systeme : à t = " << temps << " :" << endl;
	for (size_t i(0); i < objet.size(); ++i) {
		sortie << "Objet no " << i+1 << " : ";
		sortie << *objet[i] << endl;
	}
	sortie << endl;
	for (size_t i(0); i < champforce.size(); ++i) {
		sortie << "Champ no " << i+1 <<  " : " << *champforce[i] << endl;
	}
	sortie << endl;
	for (size_t i(0); i < contrainte.size(); ++i) {
		sortie << "Contrainte no " << i+1 << " : " << *contrainte[i] << endl;
	}
	return sortie;
}

void Systeme::ajout_contrainte_objet(size_t indice_objet, size_t indice_contrainte) {
	if ((contrainte.size()-1 >= indice_contrainte) and ( objet.size() -1 >= indice_objet)){
		objet[indice_objet]->set_contrainte(contrainte[indice_contrainte]);
	} else {
		cerr << "ERREUR : indice hors limite, la contrainte n'a pas pu etre ajouter" << endl;
	}
}

void Systeme::ajout_champs_objet(size_t indice_objet, size_t indice_champ) {
	if ((champforce.size()-1 >= indice_champ) and (objet.size() -1 >= indice_objet)){
		objet[indice_objet]->set_champ(champforce[indice_champ]);
	} else {
		cerr << "ERREUR : indice hors limite, le champ n'a pas pu etre ajouter" << endl;
	}
}




//Surcharge de <<
ostream& operator<<(ostream& sortie, const Systeme& systeme){
	return systeme.affiche(sortie);
}

	
	

