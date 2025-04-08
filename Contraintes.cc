#include <iostream>
#include "Contraintes.h"

//Opérateure externe
std::ostream& operator<<(std::ostream& sortie, const Contrainte &c) {
	return c.affiche(sortie);
}
