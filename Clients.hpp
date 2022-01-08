#pragma once
#include "Client.hpp"
#include "Hachage.hpp"
#include "Adresses.hpp"
#include <fstream>
#include <vector>
#include <string>
#define FICHIERC "./save/Client.txt"


Client* creationC(string *elem){
    Adresses r;
    return new Client(elem[1],elem[2],elem[3],r.adresse(elem[4]));
}

class Clients
{
private:
    Client* tab[SIZE];
    int nbelem;
public:
    Clients();
    ~Clients();
    Client client(string nom, string prenom, string tel,Adresse adresse);
};

Clients::Clients()
{
    Hash::lie<Client>(FICHIERC,tab,&nbelem,creationC);   
}

Clients::~Clients()
{
    Hash::enregistre<Client>(FICHIERC,nbelem,tab);
}

Client Clients::client(string nom, string prenom, string tel="",Adresse adresse=Adresse()){
    string s=nom+prenom+tel;
    int indice=Hash::hachage(s);
    if (tab[indice]==nullptr){
        Client* a=new Client(nom,prenom,tel,adresse);
        tab[indice]=a;
        nbelem++;
    }
        Hash::enregistre(FICHIERC,nbelem,tab);
        return *(tab[indice]);
}


