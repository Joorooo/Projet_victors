#include <iostream>
#include "Contraintes.h"

//opérateur d'affichage externe
std::ostream& operator<<(std::ostream& sortie, const Contrainte &c) {
	return c.affiche(sortie);
}
