#pragma once
#include "Client.hpp"
#include "Adresse.hpp"
#include "Date.hpp"

struct RDV{
    Client client;
    Adresse adresse;
    Date date_RDV;

    RDV(Client client,Adresse adresse,Date date_RDV): client(client), adresse(adresse), date_RDV(date_RDV){};
    RDV(){};

};