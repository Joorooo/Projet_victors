#include "TextViewer.h"
#include "PointMateriel.h"
#include "Systeme.h"
 
using namespace std;

//définition des méthodes dessine sur un PointMateriel et un Systeme
void TextViewer::dessine(PointMateriel const& a_dessiner) {a_dessiner.affiche_primaire(flot);}

void TextViewer::dessine(Systeme const& a_dessiner) {
    flot << "Dessin du Systeme à t = " << a_dessiner.get_temps() << " : " << endl;
    if (a_dessiner.taille_objets() > 0) {
		for (size_t i(0); i < a_dessiner.taille_objets(); ++i) { //itère sur tous les objets de l'attribut objets de la classe Systeme
			flot << "Objet no " << i+1 << " : " << endl;
			a_dessiner.get_objet(i)->dessine_sur(*this);
		}
		flot << endl;
	}
}
