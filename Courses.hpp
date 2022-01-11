#pragma once
#include "Course.hpp"
#include "Hachage.hpp"
#include "Adresses.hpp"
#include "Clients.hpp"
#include <fstream>
#include <vector>
#include <string>
#define FICHIERCO "./save/Course.txt"


Course* creationCo(string *elem){
    Adresses r;
    Chauffeurs ch;
    Clients c;
    return new Course(ch.chauffeur(elem[2],elem[3],elem[4]),RDV(c.client(elem[5],elem[6],elem[7],r.adresse(elem[8])),r.adresse(elem[9]),Date(stoi(elem[10]),stoi(elem[11]),stoi(elem[12])),Temps(stoi(elem[13]),stoi(elem[14]))),stoi(elem[15]),r.adresse(elem[16]),Temps(stoi(elem[17]),stoi(elem[18])));
}

class Courses
{
private:
    Course*** tab;
    int nbelem;
public:
    Courses();
    ~Courses();
    Course course(Chauffeur ch, RDV rdv, int nbV, Adresse depart, Temps tempsTrajet);
    Course course(Chauffeur ch, Client client, string Aarrivee, Date date_RDV, int h_priseEnCharge,int m_priseEnCharge, int nbV, string Adepart, int heureTrajet,int minutesTrajet);
};

Courses::Courses()
{
    tab= new Course**[SIZE]; 
    // Pour chaque pointeur triple du tableau  
    for(int vIndexGrille = 0; vIndexGrille  < SIZE; vIndexGrille ++) 
    {
        // Créer un tableau de pointeurs doubles dans vTableau[vIndexGrille].
        tab[vIndexGrille] = new Course* [MINSIZE]; 
		
        // Pour chaque pointeur double du tableau vTableau[vIndexGrille].
        for(int vIndexLigne = 0; vIndexLigne < MINSIZE; vIndexLigne++) 
        {
            // Créer un tableau de pointeurs dans vTableau[vIndexGrille][vIndexLigne].
            //tab[vIndexGrille][vIndexLigne] = new Course ;
            tab[vIndexGrille][vIndexLigne] = nullptr ;
        }
    }
    
    Hash::lie<Course>(FICHIERCO,tab,&nbelem,creationCo);   
}

Courses::~Courses()
{
    Hash::enregistre<Course>(FICHIERCO,nbelem,tab);
}

Course Courses::course(Chauffeur ch, RDV rdv, int nbV, Adresse depart, Temps tempsTrajet){
    string s=rdv.tostring("")+to_string(nbV)+depart.info()+tempsTrajet.tostring("");//TODO faire un trie par date (faire peut etre double tableau de hachage avec un trie sur la date dans la première dimension et un depot naïf sur la deuxième dimension)
    int indice=Hash::hachage(s,MINSIZE);
    if (tab[rdv.date_RDV.nbofday()][indice]==nullptr){
         Course* a=new Course(ch,rdv,nbV,depart,tempsTrajet);
         tab[rdv.date_RDV.nbofday()][indice]=a;
         nbelem++;
    }
        Hash::enregistre(FICHIERCO,nbelem,tab);
        return *(tab[rdv.date_RDV.nbofday()][indice]);

}

/*
Course Courses::course(Chauffeur ch, Client client, string Aarrivee, Date date_RDV, int h_priseEnCharge,int m_priseEnCharge, int nbV, string Adepart, int heureTrajet,int minutesTrajet){
    string s=ch.tostring("")+";"+client.tostring("")+";"+Aarrivee+";"+date_RDV.tostring("")+";"+to_string(h_priseEnCharge)+";"+to_string(m_priseEnCharge)+";"+to_string(nbV)+";"+Adepart+";"+to_string(heureTrajet)+";"+to_string(minutesTrajet);
    int indice=Hash::hachage(s);
    if (tab[indice]==nullptr){
        Course* a=new Course(ch,rdv,nbV,depart,tempsTrajet);
        tab[indice]=a;
        nbelem++;
    }
        Hash::enregistre(FICHIERCO,nbelem,tab);
        return *(tab[indice]);

}*/
