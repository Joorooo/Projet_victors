#include "TextViewer.h"
#include "PointMateriel.h"
#include "Systeme.h"
 
using namespace std;

void TextViewer::dessine(PointMateriel const& a_dessiner) {
    flot << "Dessin du PointMateriel : " << a_dessiner << std::endl;
}

void TextViewer::dessine(Systeme const& a_dessiner) {
    flot << "Dessin du Systeme : " << a_dessiner << std::endl;
}

void TextViewer::dessine_sur(PointMateriel const& a_dessiner) {
	flot << a_dessiner.get_E() << " # position physique" << endl;
};

	
