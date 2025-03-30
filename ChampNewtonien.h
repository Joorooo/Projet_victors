#include "ForceCentrale.h"

class ChampNewtonien : public ForceCentrale {
	public:
	
	virtual Vecteur force(const ObjetPhysique &p, double t = 0) const;
};
