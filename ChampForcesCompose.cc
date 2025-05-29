#include "ChampForcesCompose.h"

using namespace std;

//constructeur
ChampForcesCompose::ChampForcesCompose(const vector<ChampForces*> &autres_champs) {
	for (auto c : autres_champs) {
		champs.push_back(c); //ajoute en bout de liste
	}
}

//destructeur
ChampForcesCompose::~ChampForcesCompose() {
	for (auto c : champs) {
		delete c;
	}
}

//méthodes publiques
Vecteur ChampForcesCompose::force(const ObjetPhysique &p, double t) const {
	Vecteur resultat(p.get_dim()); //cf constructeurs de la classe Vecteur
	for (const auto& c : champs) {
		resultat += c->force(p, t); //fait la somme des forces associées aux différents champs de force
	}
	return resultat;
}
void ChampForcesCompose::ajout_champ(ChampForces* c) {
	champs.push_back(c); //ajoute en bout de liste un pointeur sur un champ de force à attribut champs
}

//Définition de la méthode affiche
ostream& ChampForcesCompose::affiche(ostream& sortie) const {
	for (const auto& c : champs) {
		 c->affiche(sortie); //appelle de manière polymorphique méthode affiche des champs de force 
		 sortie << " "; //espace entre chaque affichages
	}
	return sortie;
}
		
		
		
