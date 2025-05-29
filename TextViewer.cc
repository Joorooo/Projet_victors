#include "TextViewer.h"
#include "PointMateriel.h"
#include "Systeme.h"
 
using namespace std;

void TextViewer::dessine(PointMateriel const& a_dessiner) {
	flot << a_dessiner.get_E() << " # parametre" << endl;
	flot << a_dessiner.get_E_prime() << " # vitesse" << endl;
	flot << a_dessiner.position() << " # position physique" << endl;
	flot << a_dessiner.vitesse() << " # vitesse physique" << endl;
}

void TextViewer::dessine(Systeme const& a_dessiner) {
    flot << "Dessin du Systeme à t = " << a_dessiner.get_temps() << " : " << endl;
    if (a_dessiner.taille_objets() > 0) {
		for (size_t i(0); i < a_dessiner.taille_objets(); ++i) {
			flot << "Objet no " << i+1 << " : " << endl;
			a_dessiner.get_objet(i)->dessine_sur(*this);
		}
		flot << endl;
	}
}
