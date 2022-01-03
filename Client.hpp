#pragma once
using namespace std;

struct Client{
    string nom;
    string prenom;
    int tel;
    Adresse adresse;

    Client(string nom, string prenom, int tel,Adresse adresse) :nom(nom), prenom(prenom), tel(tel), adresse(adresse){};
    Client(){};
    friend ostream&  operator<<(ostream& os,const Client &structnoeud2){
        os<<structnoeud2.prenom<<" "<<structnoeud2.nom<<endl;
        return os;
    };
};