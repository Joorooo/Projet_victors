#pragma once
#include "Vecteur.h"

namespace Constantes {

inline const Vecteur g(0.0, 0.0, -9.81);
inline const double pi = 3.14159265358979323846;
inline const double G(6.6743015E-11); //constante universelle de gravitation en m^3*kg^-1*s^-2
inline const double  m_terre(5.972E24); //masse de la Terre en kg
inline const double m_mars(6.39E23); //masse de Mars en kg
inline const double m_soleil(1.989E30); //masse du Soleil en kg
inline const double r_terre(6.371E6); //rayon de la Terre en m
inline const double  ua(1.496E11); //distance moyenne entre Terre et Soleil (Unité Astronomique) en m
inline const double d_MS(1.52*ua); //distance moyenne entre Mars et Soleil en m

}
