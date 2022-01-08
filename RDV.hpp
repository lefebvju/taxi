#pragma once
#include "Client.hpp"
#include "Adresse.hpp"
#include "Date.hpp"

struct RDV{
    Client client;
    Adresse adresse;
    Date date_RDV;
    Temps h_priseEnCharge;

    RDV(Client client,Adresse adresse,Date date_RDV): client(client), adresse(adresse), date_RDV(date_RDV){};
    RDV(){};
    string tostring(string d){
        return client.tostring(" ")+d+adresse.info()+d+date_RDV.tostring(" ")+d+h_priseEnCharge.tostring(" ");
    };
    
    friend ostream&  operator<<(ostream& os,const RDV &structnoeud2)
    {
        os<<"Date: "<<structnoeud2.date_RDV;
        os<<"client: "<<structnoeud2.client;
        os<<"Prise en charge: "<<structnoeud2.h_priseEnCharge;
        os<<"Arrivee: "<<structnoeud2.adresse;

        return os;
    };
};