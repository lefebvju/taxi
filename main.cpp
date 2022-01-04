#include <iostream>
#include "Temps.hpp"
#include "Adresse.hpp"
#include "Chauffeur.hpp"
#include "Client.hpp"
#include "Course.hpp"
#include "Hachage.hpp"
#include "calendrier.hpp"
using namespace std;

int main(){
    Chauffeur t1("Lefebvre","Nicolas","0666285939");
    Chauffeur t2("Stragiotti","Nicolas","0666666666");
    Chauffeur t3("Stragiotti","Alexandra","0666666666");
    Registre r; 
    Client c;
    //for (int client = 0; client < 10; client++)
    //{
        c=Client("to_string(client)",string("prénom"),123456789,r.adresse(string("07800 la voulte")));
    

    Course cal;//[11];
    //for (int i = 0; i < 10; i++)
    //{
        cal=Course(t1,RDV(c,r.adresse(string("07800 la voulte")),Date(2021,2,1)),1,r.adresse(string(" 07800 saint laurent du pape")),Temps(1,30));
    //}
    /*for (int i = 0; i < 10; i++)
    {
        cal[1].affiche();
    }*/
    cout<<cal<<endl;
    



    return 0;
}

