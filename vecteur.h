#pragma once
#include <iostream>
#include <vector>


class Vecteur {
private:
    //attributs
    std::vector<double> vect;
    
    //méthode privée
    bool dim(const Vecteur& V) const;

public:
    //constructeurs
    Vecteur(unsigned int dimension);
    Vecteur(double a, double b, double c);
    Vecteur(std::initializer_list<double> liste);
    
    //constructeur de copie
    Vecteur(const Vecteur &autre_vecteur);

    //méthodes publiques
    Vecteur() = default;
    void augmente(double val);
    void set_coord(size_t indice, double valeur);
    std::ostream& affiche(std::ostream& sortie) const;
    double norme2() const;
    double norme() const;
    unsigned int dim() const;
    
    //opérateur interne
    Vecteur& operator+=(const Vecteur& v);
    Vecteur& operator-=(const Vecteur& v);
    Vecteur operator-();                    //opposé
    Vecteur& operator^=(const Vecteur& v2);
    Vecteur& operator*=(double a);          
    double operator*(const Vecteur& v) const; //produit scalaire
    bool operator==(const Vecteur& v2); //compare
    Vecteur operator~() const;    //unitaire


};

//opérateur externe
const Vecteur operator+(Vecteur v1, const Vecteur& v2);//remplace addition
const Vecteur operator-(Vecteur v1, const Vecteur& v2);//remplace soustraction
std::ostream& operator<<(std::ostream& sortie, const Vecteur& v);//remplace affiche
const Vecteur operator^(Vecteur v1, const Vecteur& v2);//remplace prod_vect
const Vecteur operator*(double a, Vecteur v); //multiplication
const Vecteur operator*(Vecteur v, double a); // multiplication

