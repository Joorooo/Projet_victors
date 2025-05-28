#include <iostream>
#include "vecteur.h"

using namespace std;

void test_addition(const Vecteur& v1, const Vecteur& v2) {
	cout << v1 << "+" << v2 << "=" << v1+v2 << endl;
	cout << "Testons l'addition au vecteur nul : " << endl;
	Vecteur v_nul(3);
	cout << v1 << "+" << v_nul << "=" << v1+v_nul << endl;
	cout << v_nul << "+" << v1 << "=" << v_nul+v1 << endl;
}

void test_soustraction(const Vecteur& v1, const Vecteur& v2) {
	cout << v1 << "-" << v2 << "=" << v1-v2 << endl;
	cout << v1 << "-" << v1 << "=" << v1-v1 << endl;
}

void test_combine(const Vecteur& v1, const Vecteur& v2) {
	cout << "-" << v1 << "=" << (-v1) << endl;
	cout << "-" << v1 << "+" << v2 << "=" << (-v1)+v2 << endl;
}

void test_mult(const Vecteur& v1, double x) {
	cout << x << "*" << v1 << "=" << x*v1 << endl;
}

void test_normes(const Vecteur& v1) {
	cout << "||" << v1 << "||" << "=" << v1.norme() << endl;
	cout << "||" << v1 << "||^2" << "=" << v1.norme2() << endl;
}

void test_prod_scal(const Vecteur& v1, const Vecteur& v2) {
	cout << v1 << "*" << v2 << "=" << (v1*v2) << endl;
}

void test_prod_vect(const Vecteur& v1, const Vecteur& v2) {
	cout << v1 << "^" << v2 << "=" << (v1^v2) << endl;
}

void test_unitaire(const Vecteur& v1) {
	cout << v1 << " normalisé devient : " << ~v1 << endl;
	cout << "Nous avons bien : " << endl;
	cout << "||" << ~v1 << "||" << "=" << (~v1).norme() << endl;
}

void egal(const Vecteur& v1, const Vecteur&v2) {
	cout << "Les vecteurs " << v1 << " et " << v2 << " sont ";
	if (v1==v2) {
		cout << "égaux";
	} else {
		cout << "différents";
	}
	cout << endl;
}

void presentation(const vector<Vecteur>& ensemble ) {
	for (size_t i(0); i < ensemble.size(); i++) {
		cout << "Vecteur " << i+1 << " : " << ensemble[i];
		cout << endl;
	}
}

int main() {
	Vecteur v1;
	Vecteur v2;
	Vecteur v3;
	Vecteur v4;
	double x(3);
	
	v1.augmente(1.0); v1.augmente(-2.0); v1.augmente(-0.1);
	v2.augmente(2.6); v2.augmente(3.5); v2.augmente(4.1);
	v3.augmente(9.78); v3.augmente(-7.4);
	
	v4 = v2;
	
	presentation({v1, v2, v3, v4});
	cout << endl;
	egal(v1, v2); egal(v1, v3); egal(v2, v4);
	cout << endl;
	
	test_addition(v1, v2);  
	cout << "Et dans l'autre ordre: " <<  endl; 
	test_addition(v2, v1);
	cout << endl;
	test_addition(v1, v3);
	cout << "Et dans l'autre ordre: " << endl;
	test_addition(v3, v1);
	cout << endl;
	test_soustraction(v1, v2);
	cout << endl;
	test_combine(v1, v2);
	cout << endl;
	test_mult(v1, x);
	cout << endl;
	test_prod_scal(v1, v2); test_prod_scal(v2,v1);
	cout << endl;
	test_prod_vect(v1, v2);
	cout << endl;
	test_normes(v1); test_normes(v2);
	cout << endl;
	test_unitaire(v1);
	
	return 0;
}
	
	
