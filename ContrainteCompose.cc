#include <iostream>
#include "ContrainteCompose.h"
#include "ObjetPhysique.h"

using namespace std;

//constructeur
ContrainteCompose::ContrainteCompose(const vector<unique_ptr<Contrainte>>& contr) {
	for (auto& c : contr) {
		contraintes.push_back(c->copie());
	}
}
ContrainteCompose::ContrainteCompose(const ContrainteCompose &autre_cc)
: ContrainteCompose(autre_cc.contraintes)
{}

//destructeur
ContrainteCompose::~ContrainteCompose() {}
		
//methodes publiques
Vecteur ContrainteCompose::applique_force(const ObjetPhysique &p, const Vecteur &force, double t) const {
	Vecteur nouv_force(force);
	for (auto& contr : contraintes) {
		nouv_force = p.get_m()*contr->applique_force(p, nouv_force, t);
	}
	return (1/p.get_m())*nouv_force;
}
Vecteur ContrainteCompose::position(const ObjetPhysique &p) const {
	if (contraintes.empty()) {
		Vecteur nul(3);
		return nul;
	} else {
		ObjetPhysique autre_p(p);
		for (unsigned int i(0); i < contraintes.size(); i++) {
			autre_p.set_E(contraintes[i]->position(autre_p));
		}
		return autre_p.get_E();
	}
}
Vecteur ContrainteCompose::vitesse(const ObjetPhysique &p) const {
	if (contraintes.empty()) {
		Vecteur nul(3);
		return nul;
	} else {
		ObjetPhysique autre_p(p);
		for (unsigned int i(0); i < contraintes.size(); i++) {
			autre_p.set_E_prime(contraintes[i]->vitesse(autre_p));
		}
		return autre_p.get_E_prime();
	}
}
ostream& ContrainteCompose::affiche(ostream& sortie) const {
	for (const auto& c : contraintes) {
		 c->affiche(sortie);
	 }
	 return sortie;
}
void ContrainteCompose::ajout_contr(const Contrainte &c) {
	contraintes.push_back(c.copie());
}
unique_ptr<Contrainte> ContrainteCompose::copie() const {
	return make_unique<ContrainteCompose>(*this);
}
	
	


			
		
