#pragma once
#include <iomanip>
#include <iostream>
#include <ctime>

struct Date{
    int annees;
    int mois;
    int jours;
    Date(int annees, int mois, int jours):annees(annees), mois(mois), jours(jours){};
    //Date(int uniquenb):annees(uniquenb/(13*32)), mois((uniquenb/(32))%13), jours(jours){};
    Date(){};
    int nbofday(){
        return this->uniqueNb()-this->uniqueNow();
    }
    int uniqueNb(){
        return (annees)*(32*13)+mois*32+jours;
    };
    int uniqueNow(){
        time_t t = time(0);
        struct tm *st = localtime(&t);
        int a=1900+st->tm_year;
        int m=1+st->tm_mon;
        int j=st->tm_mday;
        return a*(32*13)+m*32+j;
    }
    string tostring(string d){
            return to_string(jours)+d+to_string(mois)+d+to_string(annees);
        }
    bool operator<(const Date &dt)const{
        if (this->annees!=dt.annees){
            return this->annees<dt.annees;
        }
        else if(this->mois!=dt.mois){
            return this->mois<dt.mois;
        }
        else{
            return this->jours< dt.jours;
        }
            
            
    };
    friend ostream&  operator<<(ostream& os,const Date &structnoeud2){
        os<<setw(2)<< setfill('0') <<structnoeud2.jours<<"/"<<setw(2)<< setfill('0') <<structnoeud2.mois<<"/"<<setw(4)<< setfill('0') <<structnoeud2.annees<<endl;;
        return os;
    };
};