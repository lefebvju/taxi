#pragma once
#include <fstream>
#define SIZE 1000
#define MINSIZE 100

namespace Hash{
    void homogene(string* s){
    s->erase(remove( s->begin(),  s->end(), '-'), s->end());
    s->erase(remove( s->begin(),  s->end(), '_'), s->end());
    s->erase(remove( s->begin(),  s->end(), ' '), s->end());
    for (long unsigned int i=0; i<s->length(); ++i)
    {
    (*s)[i] = ::toupper((*s)[i]);
    }
    }

    int hachage(string chaine)
{
    homogene(&chaine);
    int i = 0, nombreHache = 0;

    for (i = 0 ; chaine[i] != '\0' ; i++)
    {
        nombreHache += chaine[i];
    }
    nombreHache %= SIZE;

    return nombreHache;
}

int hachage(string chaine,int size)
{
    homogene(&chaine);
    int i = 0, nombreHache = 0;

    for (i = 0 ; chaine[i] != '\0' ; i++)
    {
        nombreHache += chaine[i];
    }
    nombreHache %= size;

    return nombreHache;
}

string* split(string s, string del)
{
    string* tab=new string[30];
    int indice=0;
    int start = 0;
    int end = s.find(del);
    while (end != -1) {
        tab[indice]= s.substr(start, end - start) ;
        start = end + del.size();
        end = s.find(del, start);
        indice++;
    }
    tab[indice]=  s.substr(start, end - start);
    return tab;
}

template <typename T>
void lie(string fichier,T *tab[SIZE],int *nbelem,T* (*creation)(string*))
{  
    *nbelem=0;
    for (int i = 0; i < SIZE; i++)
    {
        tab[i]=nullptr;
    }
     ifstream f;
    f.open(fichier);
    if (f.good()){
        f>>*nbelem;
        string ligne;
        getline(f, ligne);
        while(getline(f, ligne)) 
        {
            string* elem=Hash::split(ligne,";");
            tab[stoi(elem[0])]=creation(elem);
        } 
    }
    f.close();
}


template <typename T>
void lie(string fichier,T ***tab,int *nbelem,T* (*creation)(string*))
{  
    *nbelem=0;
     ifstream f;
    f.open(fichier);
    if (f.good()){
        f>>*nbelem;
        string ligne;
        getline(f, ligne);
        while(getline(f, ligne)) 
        {
            string* elem=Hash::split(ligne,";");
            tab[stoi(elem[0])][stoi(elem[1])]=creation(elem);
        }
    }
    f.close();
}


template <typename T>
void enregistre(string fichier,int nbelem,T *tab[SIZE])
{
    ofstream  monFlux(fichier);

if(monFlux){
    monFlux<<nbelem<<endl;
    for (int i = 0; i < SIZE; i++)
    {
        if(tab[i]!=nullptr){
            monFlux<<i<<";"<<tab[i]->tostring(";")<<endl;
        }
    }          
    }
    monFlux.close();

}


template <typename T>
void enregistre(string fichier,int nbelem,T ***tab)
{
    ofstream  monFlux(fichier);
    if(monFlux){
        monFlux<<nbelem<<endl;
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < MINSIZE; j++)
            {
                if(tab[i][j]!=nullptr){
                    monFlux<<i<<";"<<j<<";"<<tab[i][j]->tostring(";")<<endl;
                }
            }
        }          
    }
    monFlux.close();

}
}
