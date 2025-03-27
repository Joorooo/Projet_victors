#include "vecteur.h"

using namespace std;

void voir(const Vecteur& v){
		cout <<"("  << v << ")";
	}

void test_addition(const Vecteur& v1, const Vecteur& v2) {
	voir(v1); cout << "+"; voir(v2); cout << "="; voir(v1 +v2); cout << endl;
	voir(v2); cout << "+"; voir(v1); cout << "="; voir(v2 + v1); cout << endl;
	cout << "Testons l'addition d'un vecteur quelquonque au vecteur nul : " << endl;
	Vecteur v_nul(3);
	voir(v1); cout << "+"; voir(v_nul); cout << "="; voir(v1+v_nul); cout << endl;
}

void test_soustraction(const Vecteur& v1, const Vecteur& v2) {
	voir(v1); cout << "-"; voir(v2); cout << "="; voir(v1 - v2); cout << endl;
	voir(v2); cout << "-"; voir(v1); cout << "="; voir(v2 - v1); cout << endl;
	cout << "Testons la soustration d'un vecteur quelquonque au vecteur nul : " << endl;
	Vecteur v_nul(0);
	voir(v1); cout << "-"; voir(v_nul); cout << "="; voir(v1 - v_nul ); cout << endl;
}
	
void test_mult(const Vecteur& v1, double x) {
	cout << x << "*"; voir(v1); cout << "="; voir(v1 * x); cout << endl;
}

void test_normes(const Vecteur& v1) {
	cout << "||"; voir(v1); cout << "||" << "=" ; cout << v1.norme() << endl;
	cout << "||"; voir(v1); cout << "||^2" << "="; cout << v1.norme2() << endl;
}

void test_prod_scal(const Vecteur& v1, const Vecteur& v2) {
	voir(v1); cout << "*"; voir(v2); cout << "="; cout << v1*v2 << endl;
}

void test_prod_vect(const Vecteur& v1, const Vecteur& v2) {
    cout << "Test du produit vectoriel entre des vecteurs de dimension " 
         << v1.dim() << " et " << v2.dim() << endl;
    Vecteur prod = v1 ^ v2;
    voir(v1); cout << "^"; voir(v2); cout << "="; voir(prod); cout << endl;
}

void test_unitaire(const Vecteur& v1){
    cout << "Test de la normalisation du vecteur : ";
    voir(v1); cout << endl;
    Vecteur v_unit = ~v1;
    voir(v1); cout << " normalisé devient : "; voir(v_unit); cout << endl;
    cout << "Nous avons bien : " << endl; 
    test_normes(v_unit);
}

void grand_test(const Vecteur& v1, const Vecteur &v2, const Vecteur &v3) {
    vector <Vecteur> ens = {v1, v2, v3};
    for (size_t i(0); i < 2; i++) {
        cout << "\n=== Test d'addition ===\n";
        test_addition(ens[i], ens[i+1]);
        cout << "\n=== Test de soustraction ===\n";
        test_soustraction(ens[i], ens[i+1]);
        cout << "\n=== Test de multiplication scalaire ===\n";
        test_mult(ens[i], 3.0);
        test_mult(ens[i], 0);
        cout << "\n=== Test du produit scalaire ===\n";
        test_prod_scal(ens[i], ens[i+1]);
        cout << "\n=== Test du produit vectoriel ===\n";
        test_prod_vect(ens[i], ens[i+1]);
        cout << "\n=== Test des normes ===\n";
        test_normes(ens[i]);
        cout << "\n=== Test de la normalisation ===\n";
        test_unitaire(ens[i]);
        cout << endl;
    }
}

int main() {
	Vecteur v1(1.0,-2.0,-0.1);
	Vecteur v2(2.6,3.5,4.1);
	Vecteur v3(2); v3.set_coord(0,9.78); v3.set_coord(1,-7.4);
	
	grand_test(v1, v2, v3);	
	
	return 0;
}

