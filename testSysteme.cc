#include "Systeme.h"
#include "Libre.h"
#include "ChampNewtonien.h"
#include "PointMateriel.h"
#include "IntegrateurEulerCromer.h"
#include "constantes.h"

using namespace std;

int main() {
    Vecteur nul(3);
    double m(Constantes::m_terre);

    // 1. Créer les objets d'abord
    unique_ptr<PointMateriel> Terre = make_unique<PointMateriel>(
        nul, nul, vector<shared_ptr<Contrainte>>{}, 
        vector<shared_ptr<ChampForces>>{}, m);
    
    Vecteur pos2(Constantes::r_terre, 0, 0);
    unique_ptr <PointMateriel> satellite = make_unique<PointMateriel>(
        pos2, nul, vector<shared_ptr<Contrainte>>{},
        vector<shared_ptr<ChampForces>>{}, 0.1);
        
    unique_ptr<Integrateur> integrateur = std::make_unique<IntegrateurEulerCromer>();
    
    Systeme systeme(0, {}, {}, {}, std::move(integrateur));
    
    // 2. Maintenant créer les champs en utilisant les objets du système
    double prec(0.1);
    shared_ptr<ChampNewtonien> champ_terre = make_shared<ChampNewtonien>(*Terre, prec);
    shared_ptr<ChampNewtonien> champ_satellite = make_shared<ChampNewtonien>(*satellite, prec);

    
    // 3. Ajouter les objets au système avant de créer les champs
    systeme.ajouter_objet(std::move(Terre));
    systeme.ajouter_objet(std::move(satellite));

    // 4. Ajouter la contrainte
    systeme.ajouter_contrainte(make_shared<Libre>());
    systeme.ajout_contrainte_objet(0, 0);
    systeme.ajout_contrainte_objet(1, 0);

    // 5. Ajouter les champs
    systeme.ajouter_ChampForces(champ_terre);
    systeme.ajouter_ChampForces(champ_satellite);

    cout << systeme << endl;
    return 0;
}
