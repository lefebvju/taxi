/*#include <iostream>
#include "Temps.hpp"
#include "Adresse.hpp"
#include "Chauffeur.hpp"
#include "Client.hpp"
#include "Course.hpp"
#include "calendrier.hpp"
using namespace std;
int main(){
    Chauffeur t1("Lefebvre","Nicolas","0666285939");
    Chauffeur t2("Stragiotti","Nicolas","0666666666");
    Chauffeur t3("Stragiotti","Alexandra","0666666666");
    Client c[100];
    for (int client = 0; client < 100; client++)
    {
        c[client]=Client(to_string(client),string("prénom"),123456789,Adresse(string("rue des potiers"),7800,string("la voulte")));
    }

    Calendrier cal;
    for (int i = 0; i < 100; i++)
    {
        cal.ajoute(Course(t1,RDV(c[i],Adresse(string(i+" rue des potiers"),7800,string(i+" la voulte")),Date(2021,12,11)),i,Adresse(string(i*10+" rue des potiers"),7800,string(i*10+" la voulte")),Temps(1,30)));
    }
    cal.affiche();

    return 0;
}
*/
// main.cpp

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>


int main(int argc, char** argv) {

}
