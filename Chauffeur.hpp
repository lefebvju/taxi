#pragma once
#include <string>
using namespace std;

struct Chauffeur{
    string nom;
    string prenom;
    string tel;

    Chauffeur(string nom,string prenom,string tel):nom(nom),prenom(prenom),tel(tel){};
    Chauffeur(){};
    string tostring(string d);
    friend ostream&  operator<<(ostream& os,const Chauffeur &structnoeud2){
        os<<structnoeud2.prenom<<" "<<structnoeud2.nom<<endl;
        return os;
    };
    
};

string Chauffeur::tostring(string d){
    return this->nom+d+this->prenom+d+this->tel;
}