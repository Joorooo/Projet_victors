#include <vector>
#include <memory>
#include "ObjetPhysique.h"
#include "ChampForces.h"
#include "Integrateur.h"
#include "Contraintes.h"

class Systeme {
	
	private:
	
	  double temps;
	  std::vector <std::unique_ptr<ObjetPhysique>> objet;   //collection hétérogène d'objet
	  std::vector <std::shared_ptr<Contrainte>> contrainte; //collection hétérogène de contrainte
	  std::vector <std::shared_ptr<ChampForces>> champforce;//collection hétérogène de champs de forces
	  std::unique_ptr<Integrateur> integrateur;             //pointeure intelligent sur un integrateur
	  
	public:
	  
	  //constructeur
	  Systeme();
	  Systeme(double t, 
	          std::vector<std::unique_ptr<ObjetPhysique>> obj,
	          std::vector<std::shared_ptr<Contrainte>> cont,
	          std::vector<std::shared_ptr<ChampForces>> champ, 
	          std::unique_ptr<Integrateur> integ);
	  
	  //manipulateur
	  void ajouter_objet(std::unique_ptr<ObjetPhysique> obj);
	  void ajouter_contrainte(std::shared_ptr<Contrainte> cont);
	  void ajouter_ChampForces(std::shared_ptr<ChampForces> champ);
	  void changer_integrateur(std::unique_ptr<Integrateur> integ);
	  void ajout_contrainte_objet(size_t indice_objet, size_t indice_contrainte);
	  void ajout_champs_objet(size_t indice_objet, size_t indice_contrainte);
	  
	  
	  //Crée la sortie
	  std::ostream& affiche(std::ostream& sortie) const;
	  
	  //Destructeur
	  ~Systeme() = default;


};

//surcharge de << pour un Systeme
std::ostream& operator<<(std::ostream& sortie, const Systeme& systeme);
