#include "vecteur.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <exception>

using namespace std;

bool Vecteur::dim(const Vecteur& V) const {
    return vect.size() == V.vect.size();
}

void Vecteur::augmente(double x) {
    vect.push_back(x);
}

void Vecteur::set_coord(size_t indice, double valeur) {
    if (indice < vect.size()) {
        vect[indice] = valeur;
    } else {
        throw out_of_range("indice hors limites!");
    }
}

void Vecteur::affiche() const {
    for (auto coord : vect) {
        cout << coord << " ";
    }
}

void Vecteur::voir() const {
    cout <<"(" ; affiche(); cout << ")";
}

bool Vecteur::compare(const Vecteur& v2) const {
    if (!dim(v2)) return false;
    const double prec = 1e-10;
    for (size_t coord = 0; coord < vect.size(); ++coord) {
        if (abs(vect[coord] - v2.vect[coord]) > prec) return false;
    }
    return true;
}

Vecteur Vecteur::addition(const Vecteur& v2) const {
    Vecteur somme;
    for (size_t coord = 0; coord < vect.size(); ++coord) {
        if (coord < v2.vect.size()) {
            somme.augmente(vect[coord] + v2.vect[coord]);
        } else {
            somme.augmente(vect[coord]);
        }
    }
    return somme;
}

Vecteur Vecteur::oppose() const {
    Vecteur v2;
    for (auto coord : vect) {
        v2.augmente(-coord);
    }
    return v2;
}

Vecteur Vecteur::soustraction(const Vecteur& v2) const {
    return addition(v2.oppose());
}

Vecteur Vecteur::mult(double x) const {
    Vecteur v2;
    for (auto coord : vect) {
        v2.augmente(x * coord);
    }
    return v2;
}

double Vecteur::prod_scal(const Vecteur& v2) const {
    double scal = 0;
    for (size_t coord = 0; coord < vect.size(); ++coord) {
        if (coord < v2.vect.size()) {
            scal += vect[coord] * v2.vect[coord];
        } else {
            scal += vect[coord];
        }
    }
    return scal;
}

double Vecteur::norme2() const {
    double calcul = 0;
    for (auto coord : vect) {
        calcul += coord * coord;
    }
    return calcul;
}

double Vecteur::norme() const {
    return sqrt(norme2());
}

Vecteur Vecteur::unitaire() const {
    Vecteur v2;
    double module = norme();
    if (module == 0) {
        throw runtime_error("tentative de normalisation d'un vecteur nul!");
    }
    for (auto coord : vect) {
        v2.augmente(coord / module);
    }
    return v2;
}

Vecteur Vecteur::prod_vect(const Vecteur& v) const {
	if (vect.size() ==  3 and dim(v)){
		Vecteur result;
		result.augmente(vect[1]*v.vect[2] - vect[2]*v.vect[1]);
		result.augmente(vect[2]*v.vect[0] - vect[0]*v.vect[2]);
		result.augmente(vect[0]*v.vect[1] - vect[1]*v.vect[0]);
		return result;
	} else {
		throw invalid_argument("Le produit vectoriel est défini pour des vecteurs de trois coordonnées !");
	}
}

	
