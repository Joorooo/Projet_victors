#pragma once
#include <iostream>
#include <vector>


class Vecteur {
private:
    //attributs
    std::vector<double> vect;
    
    //méthode privée
    bool dim(const Vecteur& V) const; //vérifie si le vecteur de l'instance courante et V ont la même dimension

public:
    //constructeurs
    Vecteur(unsigned int dimension); //crée le vecteur nul dans espace-vectoriel de dimension dimension
    Vecteur(double a, double b, double c); //crée un vecteur dans R^3
    Vecteur(std::initializer_list<double> liste); //crée un vecteur de dimension quelconque 

    //méthodes publiques
    Vecteur() = default; // ?
    void augmente(double val);
    double getcoord(size_t indice) const; //retourne la coordonnée d'indice indice du vecteur (instance courante)
    void set_coord(size_t indice, double valeur); //change la valeur de la coordonnée du vecteur (instance courante) pour la valeur valeur
    double norme2() const; //norme au carré du vecteur (instance courante)
    double norme() const;
    unsigned int dim() const; //retourne la dimension du vecteur (instance courante)
    std::ostream& affiche(std::ostream& sortie) const;
    
    //opérateur interne
    Vecteur& operator+=(const Vecteur& v);
    Vecteur& operator-=(const Vecteur& v);
    Vecteur operator-() const;                    //opposé
    Vecteur& operator^=(const Vecteur& v2);
    Vecteur& operator*=(double a);          
    double operator*(const Vecteur& v) const; //produit scalaire
    bool operator==(const Vecteur& v2) const; //compare
    Vecteur operator~() const;    //unitaire


};

//opérateur externe
const Vecteur operator+(Vecteur v1, const Vecteur& v2);//remplace addition
const Vecteur operator-(Vecteur v1, const Vecteur& v2);//remplace soustraction
std::ostream& operator<<(std::ostream& sortie, const Vecteur& v);//remplace affiche
const Vecteur operator^(Vecteur v1, const Vecteur& v2);//remplace prod_vect
const Vecteur operator*(double a, Vecteur v); //multiplication
const Vecteur operator*(Vecteur v, double a); // multiplication

