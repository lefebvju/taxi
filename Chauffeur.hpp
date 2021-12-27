#pragma once
#include <string>
using namespace std;

struct Chauffeur{
    string nom;
    string prenom;
    string tel;

    Chauffeur(string nom,string prenom,string tel):nom(nom),prenom(prenom),tel(tel){};
    Chauffeur(){};
};