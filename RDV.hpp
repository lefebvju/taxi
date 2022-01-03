#pragma once
#include "Client.hpp"
#include "Adresse.hpp"
#include "Date.hpp"

struct RDV{
    Client client;
    Adresse adresse;
    Date date_RDV;
    Temps priseEnCharge;

    RDV(Client client,Adresse adresse,Date date_RDV): client(client), adresse(adresse), date_RDV(date_RDV){};
    RDV(){};
    
    friend ostream&  operator<<(ostream& os,const RDV &structnoeud2)
    {
        os<<"Date: "<<structnoeud2.date_RDV;
        os<<"client: "<<structnoeud2.client;
        os<<"Prise en charge: "<<structnoeud2.priseEnCharge;
        os<<"Arrivee: "<<structnoeud2.adresse;

        return os;
    };
};