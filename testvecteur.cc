
#include "vecteur.h"
#include <iostream>

using namespace std;

void test_set_coord(Vecteur& v, size_t indice, double valeur);
void test_unitaire(const Vecteur& v);
void test_prod_vect(const Vecteur& v1, const Vecteur& v2);
void test_addition(const Vecteur& v1, const Vecteur& v2);
void test_soustraction(const Vecteur& v1, const Vecteur& v2);
void test_mult(double scalaire, const Vecteur& v);
void test_prod_scal(const Vecteur& v1, const Vecteur& v2);

int main() {
	
	Vecteur vect1;
	Vecteur vect2;
	Vecteur vect3;

		cout << "--- Initialisation de vect1 et vect2 ---" << endl;
    vect1.augmente(1.0); vect1.augmente(0.0); vect1.augmente(-0.1);
    vect1.affiche();
    vect2.augmente(2.6); vect2.augmente(3.5); vect2.augmente(4.1);


    cout << "--- Test set_coord ---" << endl;
    test_set_coord(vect1, 1, 2.0); // Modification valide
    test_set_coord(vect1, 5, 0.0); // Indice hors limites

    cout << "--- Test unitaire ---" << endl;
    test_unitaire(vect1);

    cout << "--- Initialisation de vect3 (vecteur nul) ---" << endl;
    vect3.augmente(0.0); vect3.augmente(0.0); vect3.augmente(0.0);
    vect3.affiche();
    
    cout << "--- Test unitaire sur un vecteur nul ---" << endl;
    test_unitaire(vect3);
    
    cout << "--- Test produit vectoriel ---" << endl;
    test_prod_vect(vect1,vect3);
    Vecteur v4;
    v4.augmente(1.0);
    test_prod_vect(vect1,v4);
    
    cout << "--- Test addition ---" << endl;
    test_addition(vect1,vect2);
    test_addition(vect1,vect3);
    
    cout << "--- Test soustraction ---" << endl;
    test_soustraction(vect1,vect2);
    test_soustraction(vect1,vect1);
    
    cout << "--- Test dimension ---" << endl;
    vect3.augmente(1.0);
    test_addition(vect1,vect3);
    test_addition(vect3,vect1);
    
    cout << "--- Test opposé ---" << endl;
    v4.set_coord(0,1.0); v4.set_coord(1,2.0); v4.set_coord(2,-0.1); 
    v4.oppose().affiche();
    test_addition(v4, vect1.oppose());
    test_soustraction(v4, vect1);
    
    cout << "--- Test multiplication par un scalaire ---" << endl;
    test_mult(3,v4);
    
    cout << "--- Test produit scalaire ---" << endl;
    test_prod_scal(vect1,vect2);
    



    




return 0;
}

void test_set_coord(Vecteur& v, size_t indice, double valeur) {
    try {
        v.set_coord(indice, valeur);
        cout << "Modification réussie : ";
        v.affiche();
    } catch (const out_of_range& err) {
        cout << "Exception attrapée (set_coord) : " << err.what() << endl;
    }
}

void test_unitaire(const Vecteur& v1) {
    try {
        Vecteur v_unit = v1.unitaire();
        cout << "Vecteur unitaire obtenu : ";
        v_unit.affiche();
    } catch (const runtime_error& err) {
        cout << "Exception attrapée (unitaire) : " << err.what() << endl;
    }
}

void test_prod_vect(const Vecteur& v1, const Vecteur& v2) {
	try {
		Vecteur prod = v1.prod_vect(v2);
		cout << "Le produit vectoriel des deux vecteurs est : ";
		prod.affiche();
	} catch (const invalid_argument& err) {
		cout << "Exeption attrapée (prod_vect) : " << err.what() << endl;
	}
}

void test_addition(const Vecteur& v1, const Vecteur& v2){
	Vecteur somme = v1.addition(v2);
	somme.affiche();
}

void test_soustraction(const Vecteur& v1, const Vecteur& v2){
	Vecteur diff = v1.soustraction(v2);
	diff.affiche();
}

void test_mult(double scalaire, const Vecteur& v) {
    Vecteur res = v.mult(scalaire);
    res.affiche();
}

void test_prod_scal(const Vecteur& v1, const Vecteur& v2) {
    cout << "Produit scalaire : " << v1.prod_scal(v2) << endl;
}
