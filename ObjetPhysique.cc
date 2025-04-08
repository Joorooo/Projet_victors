#include "ObjetPhysique.h"

using namespace std;

//constructeur
ObjetPhysique::ObjetPhysique(const Vecteur &e, const Vecteur &e_prime, const vector<shared_ptr<Contrainte>>& c, const vector<shared_ptr<ChampForces>>& champ_f, double m, double charge, double dim)
: ObjetMobile(e, e_prime), m(m), charge(charge), dim(dim)
{
	//initialisation des tableaux de contraintes et champs de forces 
	for (const auto& contrainte : c) {
		if (!contrainte) {
			cerr << "ERREUR: le shared ptr de contrainte doit etre initialisé" << endl;
		} else {
			tab_contrainte.push_back(contrainte);
		}
    }
    
    for (const auto& champ : champ_f) {
        if (!champ) {
			cerr << "ERREUR: le shared ptr de champ de force doit etre initialisé " << endl;
		} else {
			tab_champ_f.push_back(champ);
		}

		
    }
}

ObjetPhysique::ObjetPhysique(const ObjetPhysique& obj) // constructeur de copie profonde
  : ObjetMobile(obj), m(obj.m), charge(obj.charge), dim(obj.dim) { 
	  for (const auto& c : obj.tab_contrainte) {
		  if (c!=nullptr) {
			  tab_contrainte.push_back(std::shared_ptr<Contrainte>(c->clone()));
		  }
	  }
	  for (const auto& c : obj.tab_champ_f) {
		  if (c!=nullptr) {
			  tab_champ_f.push_back(std::shared_ptr<ChampForces>(c->clone()));
		  }
	  }
  }

//methodes publiques
Vecteur ObjetPhysique::force(double t) const {
	if (tab_champ_f.empty()) { 
		Vecteur nul(3);
		return nul;
	}
	Vecteur force{tab_champ_f[0]->force(*this)};
	for (size_t i(1); i < tab_champ_f.size(); ++i) {
		force += tab_champ_f[i]->force(*this);
	}
	return force;
	
}

Vecteur ObjetPhysique::position() const {
	if (tab_contrainte.empty()) { 
		Vecteur nul(3);
		return nul;
	}
	Vecteur position_avec_contrainte{tab_contrainte[0]->position(*this)};
	for (size_t i(1); i < tab_contrainte.size(); ++i) {
		ObjetPhysique obj(*this);
	    obj.E = position_avec_contrainte;
		position_avec_contrainte = tab_contrainte[i]->position(obj);      //On compose les differentes contraintes s'appliquant à notre objet
	}
	return position_avec_contrainte;
}

Vecteur ObjetPhysique::vitesse() const {
	if (tab_contrainte.empty()) { 
		Vecteur nul(3);
		return nul;
	}
	Vecteur vitesse_avec_contrainte{tab_contrainte[0]->vitesse(*this)};
	for (size_t i(1); i < tab_contrainte.size(); ++i) {
		ObjetPhysique obj(*this);
	    obj.E_prime = vitesse_avec_contrainte;
		vitesse_avec_contrainte = tab_contrainte[i]->vitesse(obj);      //On compose les differentes contraintes s'appliquant à notre objet
	}
	return vitesse_avec_contrainte;
}

Vecteur ObjetPhysique::evolution(double t) const {
    if (tab_contrainte.empty()) {
        return force(t)*(1/m); // Si aucune contrainte, retourne F = ma
    }

    Vecteur force_courante = force(t);
    Vecteur acceleration;

    for (const auto& c : tab_contrainte) {
        if (c) {
            ObjetPhysique tmp(*this);
            tmp.E = this->position();    // Position avec contraintes précédentes
            tmp.E_prime = this->vitesse(); // Vitesse avec contraintes précédentes

            acceleration = c->applique_force(tmp, force_courante, t);
            force_courante = acceleration * m;
            }
    }
    return acceleration;
}
	
	
	
double ObjetPhysique::distance(const ObjetPhysique &autre_p) const {
	return (E-autre_p.get_E()).norme();
}
double ObjetPhysique::distance2(const ObjetPhysique &autre_p) const {
	return (E-autre_p.get_E()).norme2();
}

void ObjetPhysique::set_contrainte(const std::shared_ptr<Contrainte>& c){
	tab_contrainte.push_back(c);
}

void ObjetPhysique::set_champ(const std::shared_ptr<ChampForces>& c){
	tab_champ_f.push_back(c);
}

int ObjetPhysique::nb_contrante() {return tab_contrainte.size();}

int ObjetPhysique::nb_champforce() {return tab_champ_f.size();}

//redefinition de la methode affiche dans la sous-classe ObjetPhysique
ostream& ObjetPhysique::affiche(ostream& sortie) const {
	sortie << E << " # parametre" << endl;
	sortie << E_prime << " # vitesse" << endl;
	sortie << position() << " # position physique" << endl;
	sortie << vitesse() << " # vitesse physique" << endl;
	sortie << m << " # masse" << endl;
	sortie << "contraintes : ";
	for (const auto& c : tab_contrainte) {
		sortie << *c;
	}
	sortie << endl;
	return sortie;
}


//accesseurs
double ObjetPhysique::get_m() const {return m;}
double ObjetPhysique::get_charge() const {return charge;}       
