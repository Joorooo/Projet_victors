#include "vecteur.h"

using namespace std;

void test_addition(const Vecteur& v1, const Vecteur& v2) {
	cout << v1 << "+" << v2 << "=" << v1+v2 << endl;
	cout << v2 << "+" << v1 << "=" << v2 + v1 << endl << endl;
	cout << "Testons l'addition d'un vecteur quelquonque au vecteur nul : " << endl;
	Vecteur v_nul(3);
	cout << v1 << "+" << v_nul << "=" << v1 + v_nul << endl;
}

void test_soustraction(const Vecteur& v1, const Vecteur& v2) {
	cout << v1 << "-" << v2 << "=" << v1-v2 << endl;
	cout << v2 << "-" << v1 << "=" << v2 - v1 << endl << endl;;
	cout << "Testons la soustration d'un vecteur quelquonque au vecteur nul : " << endl;
	Vecteur v_nul(3);
	cout << v1 << "-" << v_nul << "=" << v1 -v_nul << endl;
}
	
void test_mult(const Vecteur& v1, double x) {
	cout << x << "*" << v1 << "=" << x*v1 << endl;
	cout << v1 << "*" << x << "=" << v1*x << endl;
}

void test_normes(const Vecteur& v1) {
	cout << "||" << v1 << "||" << "=" << v1.norme() << endl;
	cout << "||" << v1 << "||^2" << "=" << v1.norme2() << endl;
}

void test_prod_scal(const Vecteur& v1, const Vecteur& v2) {
	cout << v1 << "*" << v2 << "=" << v1 * v2 << endl;
}


void test_prod_vect(const Vecteur& v1, const Vecteur& v2) {
		cout << v1 << "^" << v2 << "=" << (v1^v2) << endl;
}

void test_unitaire(const Vecteur& v1) {
        cout << v1 << " normalisé devient : " << ~v1 << endl;
        cout << "Nous avons bien : " << endl; 
        test_normes(~v1);
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

