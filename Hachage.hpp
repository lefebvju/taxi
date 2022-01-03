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
