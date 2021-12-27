#pragma once
#include <iostream>
#include <map>
#include "Date.hpp"
#include "Temps.hpp"
#include "Chauffeur.hpp"
#include "Course.hpp"



using namespace std;

struct PriseEnCharge{
    Date dt;
    Temps h;
    Chauffeur ch;
    PriseEnCharge(Date dt,Temps h,Chauffeur ch):dt(dt),h(h),ch(ch){};
    bool operator <(const PriseEnCharge &pec) const{
        return this->dt < pec.dt;
    };
};

typedef map<PriseEnCharge,Course> Map;

struct Calendrier{
    Map cal;

    void ajoute(Course c){
        cal.insert(pair<PriseEnCharge,Course>(PriseEnCharge(c.rdv.date_RDV,c.tempsTrajet,c.chauffeur),c));
    }

    void affiche(){
        Map::const_iterator iter;
        for ( iter = this->cal.begin(); iter != this->cal.end(); iter++)
        {
            cout<<iter->first.h.getheures();
        }
        
    };
};