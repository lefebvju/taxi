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
};