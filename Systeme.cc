#include "Systeme.h"

using namespace std;

//constructeurs
Systeme::Systeme() : temps(0) {}

Systeme::Systeme(double t, unique_ptr<Integrateur>&& integ) 
: temps(t), integrateur(move(integ))
{}

//manipulateurs
void Systeme::ajouter_objet(unique_ptr<ObjetPhysique>&& obj) 
     {objets.push_back(std::move(obj));}
     
void Systeme::ajouter_contrainte(Contrainte* cont)
     {contraintes.push_back(cont);}

void Systeme::ajouter_champ(ChampForces *champ)
     {champsforces.push_back(champ);}

void Systeme::changer_integrateur(std::unique_ptr<Integrateur>&& integ)
     {integrateur = std::move(integ);}

//méthode qui fait évoluer le système
void Systeme::evolue(double dt) {
	for (size_t i(0); i < objets.size(); i++) {
		integrateur->integre(*objets[i], temps, dt);
	}
	temps += dt;
}

//méthode qui dit si deux objets sont proches
bool Systeme::proche(size_t ind1, size_t ind2, double prec) {
	if ((ind1 > objets.size()) or (ind2 > objets.size())) {
		cerr << "ERREUR, indice(s) hors limite" << endl;
		return false;
	}
	else {
		if (objets[ind1]->distance(*objets[ind2]) <= prec) {
			return true;
		} else {
			return false;
		}
	}
}
void Systeme::ajout_contrainte_objet(size_t indice_objet, size_t indice_contrainte) {
	if ((contraintes.size()-1 >= indice_contrainte) and ( objets.size() -1 >= indice_objet)){
		objets[indice_objet]->mod_contrainte(contraintes[indice_contrainte]);
	} else {
		cerr << "ERREUR : indice hors limite, la contrainte n'a pas pu etre ajouter" << endl;
	}
}

void Systeme::ajout_champs_objet(size_t indice_objet, size_t indice_champ) {
	if ((champsforces.size()-1 >= indice_champ) and (objets.size() -1 >= indice_objet)){
		objets[indice_objet]->mod_champ(champsforces[indice_champ]);
	} else {
		cerr << "ERREUR : indice hors limite, le champ n'a pas pu etre ajouter" << endl;
	}
}


//méthode qui crée la sortie
ostream& Systeme::affiche(ostream& sortie) const {
	sortie << "Systeme : à t = " << temps << " :" << endl;
	for (size_t i(0); i < objets.size(); ++i) {
		sortie << "Objet no " << i+1 << " : ";
		sortie << *objets[i] << endl;
	}
	sortie << endl;
	for (size_t i(0); i < champsforces.size(); ++i) {
		sortie << "Champ no " << i+1 <<  " : " << *champsforces[i] << endl;
	}
	sortie << endl;
	for (size_t i(0); i < contraintes.size(); ++i) {
		sortie << "Contrainte no " << i+1 << " : " << *contraintes[i] << endl;
	}
	return sortie;
}

//surcharge de <<
ostream& operator<<(ostream& sortie, const Systeme& systeme){
	return systeme.affiche(sortie);
}

//destructeur
Systeme::~Systeme() {
	for (auto cont : contraintes) {
		delete cont;
	}
	for (auto champ : champsforces) {
		delete champ;
	}
}

	
	

