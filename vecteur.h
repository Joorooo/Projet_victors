#pragma once

#include <vector>
#include <iostream>
using namespace std;


class Vecteur {
private:
    vector<double> vect;
    bool dim(const Vecteur& V) const;

public:
    void augmente(double val);
    void set_coord(size_t indice, double valeur);
    void affiche() const;
    bool compare(const Vecteur& v) const;
    Vecteur addition(const Vecteur& v2) const;
    Vecteur oppose() const;
    Vecteur soustraction(const Vecteur& v2) const;
    Vecteur mult(double x) const;
    double prod_scal(const Vecteur& v2) const;
    double norme2() const;
    double norme() const;
    Vecteur unitaire() const;
    Vecteur prod_vect(const Vecteur& v) const;


};

