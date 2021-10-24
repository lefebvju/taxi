#include "Client.h"
#include "Adresse.h"
#include "Date.h"

struct RDV{
    Client client;
    Adresse adresse;
    Date date_RDV;

    RDV(Client client,Adresse adresse,Date date_RDV): client(client), adresse(adresse), date_RDV(date_RDV){};
};