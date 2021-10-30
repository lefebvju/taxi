#include <iostream>
#include <map>
#include "Date.hpp"
#include "Temps.hpp"
#include "Chauffeur.hpp"
#include "Course.hpp"

using namespace std;

struct PriseEnCharge{
    Date dt;
    Temps t;
    Chauffeur ch;
    PriseEnCharge(Date dt,Temps t,Chauffeur ch):dt(dt),t(t),ch(ch){};
};

struct Calendrier{
    std::map<PriseEnCharge,Course> cal;
};