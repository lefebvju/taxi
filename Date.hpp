#pragma once
struct Date{
    int annees;
    int mois;
    int jours;
    Date(int annees, int mois, int jours):annees(annees), mois(mois), jours(jours){};
    Date(){};
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
};