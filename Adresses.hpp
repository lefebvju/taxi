#pragma once
#include "Adresse.hpp"
#include "Hachage.hpp"
#include <fstream>
#include <string>
#define FICHIERA "./save/Adresse.txt"



Adresse* creationA(string *elem){
    
    return new Adresse(stof(elem[1]),stof(elem[2]),stoi(elem[3]),elem[4],elem[5],elem[6]);
}

class Adresses
{
private:
    
    int nbelem;
    
public:
    Adresse* tab[SIZE];
    Adresses();
    ~Adresses();
    Adresse adresse(string label);
    
};

Adresses::Adresses(/* args */)
{
    Hash::lie<Adresse>(string(FICHIERA),tab,&nbelem,&(creationA));
}

Adresses::~Adresses()
{

    Hash::enregistre<Adresse>(FICHIERA,nbelem,tab);

}

Adresse Adresses::adresse(string label){
    int indice=Hash::hachage(label);
    if (tab[indice]==nullptr){
        Adresse* a=new Adresse(label);
        int verif=Hash::hachage(a->info());
        if (tab[verif]==nullptr){
        tab[verif]=a;
        nbelem++;
        return *a;
        }else{
            return *(tab[verif]);
        }
    }
        return *(tab[indice]);
}



