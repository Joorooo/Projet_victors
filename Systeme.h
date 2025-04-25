#include <vector>
#include <memory>
#include "ObjetPhysique.h"
#include "ChampForces.h"
#include "Integrateur.h"
#include "Contraintes.h"

class Systeme {
	
	private:
	
	  double temps;
	  std::vector <std::unique_ptr<ObjetPhysique>> objets;   //collection hétérogène d'objet
	  std::vector <std::unique_ptr<Contrainte>> contraintes; //collection hétérogène de contrainte
	  std::vector <std::unique_ptr<ChampForces>> champsforces;//collection hétérogène de champs de forces
	  std::unique_ptr<Integrateur> integrateur;             //pointeur intelligent sur un integrateur
	  
	public:
	  
	  //constructeur
	  Systeme();
	  Systeme(double t, std::unique_ptr<Integrateur>&& integ);
	  
	  //manipulateur
	  void ajouter_objet(std::unique_ptr<ObjetPhysique>&& objs);
	  void ajouter_contrainte(const Contrainte &cont);
	  void ajouter_champ(const ChampForces &champ);
	  void changer_integrateur(std::unique_ptr<Integrateur>&& integ);
	  
	  //methode publique
	  void evolue(double dt);
	  bool proche(size_t indice1, size_t indice2, double prec);
	  
	  
	  
	  //Crée la sortie
	  std::ostream& affiche(std::ostream& sortie) const;
	  
	  //Destructeur
	  ~Systeme() = default;


};

//surcharge de << pour un Systeme
std::ostream& operator<<(std::ostream& sortie, const Systeme& systeme);
