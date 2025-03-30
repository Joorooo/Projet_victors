#include <iostream>
#include "ChampNewtonien.h"
#include "constantes.h"

using namespace std;

Vecteur ChampNewtonien::force(const ObjetPhysique &p, double t) const {
	return Constantes::m_terre * Constantes::G * p.get_m()*quadratique_inverse(p);
}
