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
        friend ostream&  operator<<(ostream& os,const Temps &structnoeud2)
    {
        os<<setw(2)<< setfill('0') <<structnoeud2.getheures()<<":"<<setw(2)<< setfill('0') <<structnoeud2.getminutes()<<endl;
        return os;
    };
};