#include <vector>
#include <memory>
#include "ObjetPhysique.h"
#include "ChampForces.h"
#include "Vide.h"
#include "Integrateur.h"
#include "Contraintes.h"

class Systeme {
	
	private:
	
	  double temps;
	  std::vector <std::unique_ptr<ObjetPhysique>> objets;   //collection hétérogène d'objet
	  std::vector <Contrainte*> contraintes; //collection hétérogène de contraintes
	  std::vector <ChampForces*> champsforces;//collection hétérogène de champs de forces
	  std::unique_ptr<Integrateur> integrateur;             //pointeur intelligent sur un integrateur
	  
	public:
	  
	  //constructeur
	  Systeme();
	  Systeme(double t, std::unique_ptr<Integrateur>&& integ);
	  
	  //manipulateurs
	  void ajouter_objet(std::unique_ptr<ObjetPhysique>&& objs);
	  void ajouter_contrainte(Contrainte* cont);
	  void ajouter_champ(ChampForces* champ);
	  void changer_integrateur(std::unique_ptr<Integrateur>&& integ);
	  void ajout_contrainte_objet(size_t indice_objet, size_t indice_contrainte);
	  void ajout_champs_objet(size_t indice_objet, size_t indice_champ);
	  
	  //methode publique
	  void evolue(double dt);
	  bool proche(size_t indice1, size_t indice2, double prec);
	  
	  
	  
	  //crée la sortie
	  std::ostream& affiche(std::ostream& sortie) const;
	  
	  //destructeur
	  virtual ~Systeme();


};

//surcharge de << pour un Systeme
std::ostream& operator<<(std::ostream& sortie, const Systeme& systeme);
