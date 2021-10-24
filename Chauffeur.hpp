#include <string>


struct Chauffeur{
    std::string nom;
    std::string prenom;
    int tel;

    Chauffeur(std::string nom,std::string prenom,int tel):nom(nom),prenom(prenom),tel(tel){};
};