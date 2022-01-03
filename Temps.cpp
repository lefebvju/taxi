#include "Temps.hpp"

Temps::Temps(int h, int m):heures(h), minutes(m){
    if(minutes >= 60){
        heures = heures+minutes/60;
        minutes = minutes%60;
    }
}

Temps::Temps(){
    heures=0;
    minutes=0;
}

bool Temps::operator<(const Temps& t){
    if (this->getheures()==t.getheures())
    {
        return this->getminutes()<t.getminutes();
    }
    return this->getheures()<t.getheures();
}

bool Temps::operator>(const Temps& t){
    if (this->getheures()==t.getheures())
    {
        return this->getminutes()>t.getminutes();
    }
    return this->getheures()>t.getheures();
}

bool Temps::operator<=(const Temps& t){
    if (this->getheures()==t.getheures())
    {
        return this->getminutes()<=t.getminutes();
    }
    return this->getheures()<=t.getheures();
}

bool Temps::operator>=(const Temps& t){
    if (this->getheures()==t.getheures())
    {
        return this->getminutes()>=t.getminutes();
    }
    return this->getheures()>=t.getheures();
}

bool Temps::operator!=(const Temps& t){
    if (this->getheures()==t.getheures())
    {
        return this->getminutes()!=t.getminutes();
    }
    return this->getheures()!=t.getheures();
}

bool Temps::operator==(const Temps& t){
    if (this->getheures()==t.getheures())
    {
        return this->getminutes()==t.getminutes();
    }
    return this->getheures()==t.getheures();
}