#pragma once
#include "Client.hpp"
#include "Adresse.hpp"
#include "Temps.hpp"
#include "Chauffeur.hpp"
#include "RDV.hpp"


struct Course{
    Chauffeur chauffeur;
    RDV rdv;
    int nbVoyageur; 
    Adresse depart;
    Temps tempsTrajet;

    Course(Chauffeur ch, RDV rdv, int nbV, Adresse depart, Temps tempsTrajet):chauffeur(ch),rdv(rdv),nbVoyageur(nbV),depart(depart),tempsTrajet(tempsTrajet){};
    Course(){};
    string tostring(string d){
        return chauffeur.tostring(d)+d+rdv.tostring(d)+d+to_string(nbVoyageur)+d+depart.info()+d+tempsTrajet.tostring(d);
    }

    friend ostream&  operator<<(ostream& os,const Course &structnoeud2)
    {
        os<<structnoeud2.rdv;
        os<<"Chauffeur: "<<structnoeud2.chauffeur;
        os<<"depart: "<<structnoeud2.depart;
        return os;
    };

};