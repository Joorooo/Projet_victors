#include <iostream>
#include "Contraintes.h"

//destructeur
Contrainte::~Contrainte() {}

//opérateur d'affichage externe
std::ostream& operator<<(std::ostream& sortie, const Contrainte &c) {
	return c.affiche(sortie);
}
