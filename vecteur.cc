#include "vecteur.h"
#include <cmath>
#include <string>

using namespace std;

//Constructeur

Vecteur::Vecteur(unsigned int dimension) : vect(dimension, 0) {}

Vecteur::Vecteur(double a, double b, double c) : vect({a,b,c}) {}

Vecteur::Vecteur(std::initializer_list<double> liste) : vect(liste) {}


//méthodes

bool Vecteur::dim(const Vecteur& V) const {
    return vect.size() == V.vect.size();
}

int Vecteur::dim() const {return vect.size();}

ostream& Vecteur::affiche(ostream& sortie) const {
	sortie << "(";
	for (size_t i = 0; i < dim(); ++i) {
		sortie << vect[i] << " ";
	}
	sortie << ")";
	return sortie;
}

void Vecteur::augmente(double x) {
    vect.push_back(x);
}

void Vecteur::set_coord(size_t indice, double valeur) {
    if (indice < vect.size()) {
        vect[indice] = valeur;
    } else {
        cerr << "ERREUR : indice hors limites!" << endl;
    }
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

//Operateur interne 

Vecteur& Vecteur::operator+=(const Vecteur& v) {
	for (size_t i(0); i < vect.size(); ++i){
		if (i < v.vect.size()){ 
			vect[i] += v.vect[i];
		}
	}
	return *this;
}

Vecteur& Vecteur::operator-=(const Vecteur& v) {
	for (size_t i(0); i < vect.size(); ++i){
		if (i < v.vect.size()){ 
			vect[i] -= v.vect[i];
		}
	}
	return *this;
}

Vecteur Vecteur::operator-() { // Remplace opposé
	if (vect.empty()) {
		return *this;
	}
	Vecteur v2(vect.size());   // On construis un vecteur nul de la meme taille que l'opérande
	for (size_t coord(0); coord < vect.size(); ++coord){
		v2.set_coord(coord,-vect[coord]);
	}

    return v2;
}

Vecteur& Vecteur::operator^=(const Vecteur& v2) {
	if (!dim(v2) or vect.size() != 3) {
				cerr << "ERREUR : Le produit vectoriel est défini pour des vecteurs de trois coordonnées !" << endl;
				return *this;
			}
			
	double x(vect[0]) ; double y(vect[1]); double z(vect[2]);
	vect[0] = y*v2.vect[2] - z*v2.vect[1];
	vect[1] = z*v2.vect[0] - x*v2.vect[2];
	vect[2] = x*v2.vect[1] - y*v2.vect[0];
	return *this;
}

Vecteur& Vecteur::operator*=(double a) {
	for (auto& coord : vect){
		coord *= a;
	}
	return *this;
}

double Vecteur::operator*(const Vecteur& v) const{
	 double scal = 0;
    for (size_t coord = 0; coord < vect.size(); ++coord) {
        if (coord < v.dim()) {
            scal += vect[coord] * v.vect[coord];
        } else {
            scal += vect[coord];
        }
    }
    return scal;
}

bool Vecteur::operator==(const Vecteur& v2) {
    if (!dim(v2)) {return false;}
    const double prec = 1e-10;
    for (size_t coord = 0; coord < vect.size(); ++coord) {
        if (abs(vect[coord] - v2.vect[coord]) > prec) return false;
    }
    return true;
}

Vecteur Vecteur::operator~() const{
    Vecteur v2(vect.size());
    if (norme() == 0) {
        cerr << "ERREUR : tentative de normalisation d'un vecteur nul!" << endl;
        return v2;
    }
    double mod = norme();
    for (size_t i(0); i < vect.size(); ++i) {
        v2.set_coord(i,vect[i]/mod);
    }
    return v2;
}


//Opérateur externe

const Vecteur operator+(Vecteur v1, const Vecteur& v2) { // remplace addition
    v1 += v2;
    return v1;
}

const Vecteur operator-(Vecteur v1, const Vecteur& v2) { // Remplace soustraction
	v1 -= v2;
	return v1;
}

ostream& operator<<(ostream& sortie, const Vecteur& v) { // Remplace affiche
    return v.affiche(sortie);
}

const Vecteur operator^(Vecteur v1, const Vecteur& v2) {// Remplace prod_vect
	v1 ^= v2;
	return v1;
}

const Vecteur operator*(Vecteur v, double a) {
	v *= a;
	return v;
}

const Vecteur operator*(double a, Vecteur v) {
	return v*a;
}


