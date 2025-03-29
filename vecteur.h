#pragma once

#include <iostream>
#include <vector>


class Vecteur {
private:
    //attributs
    std::vector<double> vect;
    //méthodes privées 
    bool dim(const Vecteur& V) const;

public:
    //constructeurs
    Vecteur(unsigned int dimension);
    Vecteur(double a, double b, double c);
    Vecteur(std::initializer_list<double> liste);

    //méthodes publiques
    Vecteur() = default;
    void augmente(double val);
    void set_coord(size_t indice, double valeur);
    std::ostream& affiche(std::ostream& sortie) const;
    double norme2() const;
    double norme() const;
    int dim() const;

    //operateur interne
    Vecteur& operator+=(const Vecteur& v);
    Vecteur& operator-=(const Vecteur& v);
    Vecteur operator-();                    //opposé
    Vecteur& operator^=(const Vecteur& v2);
    Vecteur& operator*=(double a);          
    double operator*(const Vecteur& v) const; //produit scalaire
    bool operator==(const Vecteur& v2); //compare
    Vecteur operator~() const;    //unitaire


};

//operateur externe
const Vecteur operator+(Vecteur v1, const Vecteur& v2);//Remplace addition
const Vecteur operator-(Vecteur v1, const Vecteur& v2);// Remplace soustraction
std::ostream& operator<<(std::ostream& sortie, const Vecteur& v);//Remplace affiche
const Vecteur operator^(Vecteur v1, const Vecteur& v2);//Remplace prod_vect
const Vecteur operator*(double a, Vecteur v); //multiplication
const Vecteur operator*(Vecteur v, double a); // multiplication
