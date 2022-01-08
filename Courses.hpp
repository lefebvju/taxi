#pragma once
#include "Course.hpp"
#include "Hachage.hpp"
#include "Adresses.hpp"
#include "Client.hpp"
#include <fstream>
#include <vector>
#include <string>
#define FICHIERCO "./save/Course.txt"


Course* creationC(string *elem){
    Adresses r;
    return new Course();//elem[1],elem[2],elem[3],r.adresse(elem[4]));
}

class Courses
{
private:
    Course* tab[SIZE];
    int nbelem;
public:
    Courses();
    ~Courses();
    Course course(Chauffeur ch, RDV rdv, int nbV, Adresse depart, Temps tempsTrajet);
};

Courses::Courses()
{
    Hash::lie<Course>(FICHIERCO,tab,&nbelem,creationC);   
}

Courses::~Courses()
{
    Hash::enregistre<Course>(FICHIERCO,nbelem,tab);
}

Course Courses::course(Chauffeur ch, RDV rdv, int nbV, Adresse depart, Temps tempsTrajet){
    string s=ch.tostring("")+rdv.tostring("")+to_string(nbV)+depart.info()+tempsTrajet.tostring("");//TODO faire un trie par date (faire peut etre double tableau de hachage avec un trie sur la date dans la première dimension et un depot naïf sur la deuxième dimension)
    int indice=Hash::hachage(s);
    if (tab[indice]==nullptr){
        Course* a=new Course(ch,rdv,nbV,depart,tempsTrajet);
        tab[indice]=a;
        nbelem++;
    }
        Hash::enregistre(FICHIERCO,nbelem,tab);
        return *(tab[indice]);

}

