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
        void affiche();
        friend ostream&  operator<<(ostream& os,const Adresse &structnoeud2){
        if(structnoeud2.num!=-1)
                os<<structnoeud2.num<<" ";
        os<<structnoeud2.rue<<" "<<structnoeud2.codePostal<<" "<<structnoeud2.ville<<endl;
        return os;
        };
};
