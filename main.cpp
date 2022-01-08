#include <iostream>
#include "Temps.hpp"
#include "Adresse.hpp"
#include "Chauffeurs.hpp"
#include "Client.hpp"
#include "Course.hpp"
#include "Hachage.hpp"
#include "calendrier.hpp"
#include "Clients.hpp"
using namespace std;

int main(){
    Chauffeurs t;
    Adresses r;
    
    Clients c;
    //for (int client = 0; client < 10; client++)
    //{
       c.client("to_string(client)",string("prénom"),"123456789",r.adresse(string("07800 la voulte")));
    

    Course cal;//[11];
    //for (int i = 0; i < 10; i++)
    //{
        cal=Course(t.chauffeur("Stragiotti","Alexandra","0666666666"),RDV(c.client("to_string(client)",string("prénom"),"123456789",r.adresse(string("07800 la voulte sur rhone"))),r.adresse(string("07800 la voulte sur rhone")),Date(2021,2,1)),1,r.adresse(string(" 07800 saint laurent du pape")),Temps(1,30));
    //}
    //for (int i = 0; i < 10; i++)
    //{
     //   cal[1].affiche();
    //}
    cout<<cal<<endl;

    



    return 0;
}

