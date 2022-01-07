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
    return new Client(elem[1],elem[2],stoi(elem[3]),r.adresse(elem[4]));
}

class Clients
{
private:
    Client* tab[SIZE];
    int nbelem;
    void creation(string *elem);
public:
    Clients(Adresses *r);
    ~Clients();
    Client client(string nom, string prenom, int tel,Adresse adresse);
};

Clients::Clients(Adresses *r)
{
    Hash::lie<Client>(FICHIERC,tab,&nbelem,creationC);   
}

Clients::~Clients()
{
    Hash::enregistre<Client>(FICHIERC,nbelem,tab);
}

Client Clients::client(string nom, string prenom, int tel=0,Adresse adresse=Adresse()){
    string s=nom+prenom+to_string(tel);
    int indice=Hash::hachage(s);
    if (tab[indice]==nullptr){
        Client* a=new Client(nom,prenom,tel,adresse);
        tab[indice]=a;
        nbelem++;
        return *a;
    }
        return *(tab[indice]);
}

void Clients::creation(string *elem){

}
