#pragma once
#include <algorithm>
#include <string>
#define API "api-adresse.data.gouv.fr"
#define PORT 80

using namespace std;

string findjson(string json,string delimiteur1,string delimiteur2=",");
void charInutile(string* s);

class Adresse{
private:
        int num;
        string rue;
        string codePostal;
        string ville;
        float latitude;
        float longitude;
public:
        Adresse(){};
        Adresse(int num, string rue, string codePost,string ville);
        Adresse(string rue, string codePost,string ville);
        Adresse(string label);
        
};
