#pragma once
using namespace std;
#include "Adresse.hpp"

struct Client{
    string nom;
    string prenom;
    int tel;
    Adresse adresse;

    Client(string nom, string prenom, int tel,Adresse adresse) :nom(nom), prenom(prenom), tel(tel), adresse(adresse){};
    Client(){};
    string tostring(string d){
        return this->nom+d+this->prenom+d+to_string(this->tel)+d+this->adresse.info();
    };
    friend ostream&  operator<<(ostream& os,const Client &structnoeud2){
        os<<structnoeud2.prenom<<" "<<structnoeud2.nom<<endl;
        return os;
    };
};