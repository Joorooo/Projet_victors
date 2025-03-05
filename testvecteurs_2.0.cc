#include "vecteur.h"
#include <iostream>

using namespace std;


void test_addition(const Vecteur& v1, const Vecteur& v2) {
	v1.voir(); cout << "+"; v2.voir(); cout << "="; v1.addition(v2).voir(); cout << endl;
	v2.voir(); cout << "+"; v1.voir(); cout << "="; v2.addition(v1).voir(); cout << endl;
	cout << "Testons l'addition d'un vecteur quelquonque au vecteur nul : " << endl;
	Vecteur v_nul;
	v_nul.augmente(0.0);
	v1.voir(); cout << "+"; v_nul.voir(); cout << "="; v1.addition(v_nul).voir(); cout << endl;
}

void test_soustraction(const Vecteur& v1, const Vecteur& v2) {
	v1.voir(); cout << "-"; v2.voir(); cout << "="; v1.soustraction(v2).voir(); cout << endl;
	v2.voir(); cout << "-"; v1.voir(); cout << "="; v2.soustraction(v1).voir(); cout << endl;
	cout << "Testons la soustration d'un vecteur quelquonque au vecteur nul : " << endl;
	Vecteur v_nul;
	v_nul.augmente(0.0);
	v1.voir(); cout << "-"; v_nul.voir(); cout << "="; v1.soustraction(v_nul).voir(); cout << endl;
}
	
void test_mult(const Vecteur& v1, double x) {
	cout << x << "*"; v1.voir(); cout << "="; v1.mult(x).voir(); cout << endl;
}

void test_normes(const Vecteur& v1) {
	cout << "||"; v1.voir(); cout << "||" << "=" ; cout << v1.norme() << endl;
	cout << "||"; v1.voir(); cout << "||^2" << "="; cout << v1.norme2() << endl;
}

void test_prod_scal(const Vecteur& v1, const Vecteur& v2) {
	v1.voir(); cout << "*"; v2.voir(); cout << "="; cout << v1.prod_scal(v2) << endl;
}


void test_prod_vect(const Vecteur& v1, const Vecteur& v2) {
	try {
		Vecteur prod = v1.prod_vect(v2);
		v1.voir(); cout << "^"; v2.voir(); cout << "="; prod.voir(); cout << endl;
	} catch (const invalid_argument& err) {
		cout << "Exeption attrapée (prod_vect) : " << err.what() << endl;
	}
	
}

void test_unitaire(const Vecteur& v1) {
    try {
        Vecteur v_unit = v1.unitaire();
        v1.voir(); cout << " normalisé devient : "; v_unit.voir(); cout << endl;
        cout << "Nous avons bien : " << endl; 
        test_normes(v_unit);
    } catch (const runtime_error& err) {
        cout << "Exception attrapée (unitaire) : " << err.what() << endl;
    }
}

void grand_test(const Vecteur& v1, const Vecteur &v2, const Vecteur &v3) {
	vector <Vecteur> ens = {v1, v2, v3};
	for (size_t i(0); i < 2; i++) {
		test_addition(ens[i], ens[i+1]);
		cout << endl;
		test_soustraction(ens[i], ens[i+1]);
		cout << endl;
		test_mult(ens[i], 3.0);
		test_mult(ens[i], 0);
		cout << endl;
		test_prod_scal(ens[i], ens[i+1]);
		cout << endl;
		test_prod_vect(ens[i], ens[i+1]);
		cout << endl;
		test_normes(ens[i]);
		cout << endl;
		test_unitaire(ens[i]);
		cout << endl;
	}
}

int main() {
	Vecteur v1;
	Vecteur v2;
	Vecteur v3;
	
	v1.augmente(1.0); v1.augmente(-2.0); v1.augmente(-0.1);
	v2.augmente(2.6); v2.augmente(3.5); v2.augmente(4.1);
	v3.augmente(9.78); v3.augmente(-7.4);
	
	grand_test(v1, v2, v3);
	
	return 0;
}

