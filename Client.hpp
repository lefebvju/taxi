#pragma once
using namespace std;
#include "Adresse.hpp"

struct Client{
    string nom;
    string prenom;
    string tel;
    Adresse adresse;

    Client(string nom, string prenom, string tel,Adresse adresse) :nom(nom), prenom(prenom), tel(tel), adresse(adresse){};
    Client(){};
    string tostring(string d);
    friend ostream&  operator<<(ostream& os,const Client &structnoeud2){
        os<<structnoeud2.prenom<<" "<<structnoeud2.nom<<endl;
        return os;
    };
};

string Client::tostring(string d){
        return this->nom+d+this->prenom+d+this->tel+d+this->adresse.info();
    };