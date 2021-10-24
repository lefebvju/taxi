#include "Client.hpp"
#include "Adresse.hpp"
#include "Temps.hpp"
#include "Chauffeur.hpp"
#include "RDV.hpp"


struct Course{
    Chauffeur chauffeur;
    int nbVoyageur;
    Adresse depart;
    RDV rdv;
    Temps tempsTrajet;

    //Course(Chauffeur ch, Client cl, int nbV, Adresse depart,Adresse arriver, Temps tempsTrajet):chauffeur(ch),rdvclient(cl),nbVoyageur(nbV),depart(depart),rdv.arriver(arriver),tempsTrajet(tempsTrajet){};
};