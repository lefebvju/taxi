#pragma once
#include <iomanip>
using namespace std;
class Temps{
    private:
        int heures;
        int minutes;
    public:
        Temps(int h, int m);
        Temps();
        int getheures() const { return heures; }
        int getminutes() const { return minutes; }
        bool operator< (const Temps& t);
        bool operator> (const Temps& t);
        bool operator<= (const Temps& t);
        bool operator>= (const Temps& t);
        bool operator!= (const Temps& t);
        bool operator== (const Temps& t);
        string tostring(string d){
            return to_string(heures)+d+to_string(minutes);
        }
        friend ostream&  operator<<(ostream& os,const Temps &structnoeud2)
    {
        os<<setw(2)<< setfill('0') <<structnoeud2.getheures()<<":"<<setw(2)<< setfill('0') <<structnoeud2.getminutes()<<endl;
        return os;
    };
};