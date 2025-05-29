#include "cmath"
#include "Spherique.h"
#include "ObjetPhysique.h"

using namespace std;

//constructeur
Spherique::Spherique(double r) : r(r) {}

//accesseurs des angles et dérivées angulaires
double Spherique::get_teta(const ObjetPhysique &p) const {return p.get_E().getcoord(0);}
double Spherique::get_phi(const ObjetPhysique &p) const {return p.get_E().getcoord(1);}
double Spherique::get_teta_prime(const ObjetPhysique &p) const {return p.get_E_prime().getcoord(0);}
double Spherique::get_phi_prime(const ObjetPhysique &p) const {return p.get_E_prime().getcoord(1);}
//méthodes publiques
Vecteur Spherique::applique_force(const ObjetPhysique &p, const Vecteur &force, double t) const {
	if (p.get_m() <= prec) {
		cerr << "La masse ne peut pas être nulle" << endl;
		return force;
	} else {
		double teta = get_teta(p);
		double phi = get_phi(p);
		double teta_prime = get_teta_prime(p);
		double phi_prime = get_phi_prime(p);
		
		Vecteur teta_carth({cos(teta)*cos(phi), cos(teta)*sin(phi), -sin(teta)}); //vecteur unitaire de teta dans les coordonnées carthésiennes
		Vecteur phi_carth({-sin(phi), cos(phi), 0}); //vecteur unitaire de phi dans les coordonnées carthésiennes
		
		double force_teta = -1*force*teta_carth;
		double force_phi = force*phi_carth;
		
		double teta_pprime = (1.0/(p.get_m()*r))*force_teta + sin(teta)*cos(teta)*phi_prime*phi_prime;
		double phi_pprime(0.0);
		if (fabs(teta) >= 1E-2) {
			phi_pprime = (1.0/(p.get_m()*r*sin(teta)))*force_phi - 2*(1.0/tan(teta))*teta_prime*phi_prime;
		}
		Vecteur acc({teta_pprime, phi_pprime});
		return acc;
	}
}
Vecteur Spherique::position(const ObjetPhysique &p) const {
	Vecteur pos({r*sin(get_teta(p))*cos(get_phi(p)), r*sin(get_teta(p))*sin(get_phi(p)), r*cos(get_teta(p))});
	return pos;
}
Vecteur Spherique::vitesse(const ObjetPhysique &p) const {
	double teta = get_teta(p);
	double phi = get_phi(p);
	double teta_prime = get_teta_prime(p);
	double phi_prime = get_phi_prime(p);
	Vecteur vit({teta_prime*cos(teta)*cos(phi)-phi_prime*sin(teta)*sin(phi), teta_prime*cos(teta)*sin(phi)+phi_prime*sin(teta)*cos(phi),
		        -teta_prime*sin(teta)});
	return r*vit;
}
ostream& Spherique::affiche(ostream& sortie) const {
	sortie << "contrainte sphérique";
	return sortie;
}


