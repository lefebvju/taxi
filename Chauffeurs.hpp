#pragma once
#include "Chauffeur.hpp"
#include "Hachage.hpp"
#include <fstream>
#include <string>
#define FICHIERT "./save/Chauffeur.txt"


Chauffeur* creationT(string *elem){
    return new Chauffeur(elem[1],elem[2],elem[3]);
}

class Chauffeurs
{
private:
    Chauffeur* tab[SIZE];
    int nbelem;
    void creation(string *elem);
public:
    Chauffeurs();
    ~Chauffeurs();
    Chauffeur chauffeur(string nom, string prenom, string tel);
};

Chauffeurs::Chauffeurs()
{
    Hash::lie<Chauffeur>(FICHIERT,tab,&nbelem,creationT);   
}

Chauffeurs::~Chauffeurs()
{
    Hash::enregistre<Chauffeur>(FICHIERT,nbelem,tab);
}

Chauffeur Chauffeurs::chauffeur(string nom, string prenom, string tel){
    string s=nom+prenom+tel;
    int indice=Hash::hachage(s);
    if (tab[indice]==nullptr){
        Chauffeur* a=new Chauffeur(nom,prenom,tel);
        tab[indice]=a;
        nbelem++;
        return *a;
    }
        return *(tab[indice]);
}


