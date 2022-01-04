#include "Adresse.hpp"
int hachage(string chaine)
{
    int i = 0, nombreHache = 0;

    for (i = 0 ; chaine[i] != '\0' ; i++)
    {
        nombreHache += chaine[i];
    }
    nombreHache %= 1000;

    return nombreHache;
}


class Registre
{
private:
    Adresse* tab[1000];
public:
    Registre();
    ~Registre();
    Adresse adresse(string label);
};

Registre::Registre(/* args */)
{
    for (int i = 0; i < 1000; i++)
    {
        tab[i]=nullptr;
    }
    
}

Registre::~Registre()
{
}

Adresse Registre::adresse(string label){
    string s=label;
    s.erase(remove( s.begin(),  s.end(), ' '), s.end());
    int indice=hachage(label);
    if (tab[indice]==nullptr){
        Adresse* a=new Adresse(label);
        tab[indice]=a;
        return *a;
    }
        return *(tab[indice]);
}
