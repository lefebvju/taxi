#pragma once
#include <iomanip>
struct Date{
    int annees;
    int mois;
    int jours;
    Date(int annees, int mois, int jours):annees(annees), mois(mois), jours(jours){};
    Date(){};
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