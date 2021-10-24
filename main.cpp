#include <iostream>
#include "Temps.h"
#include "Adresse.h"
using namespace std;

int main(){
    Temps t(2,125);
    Adresse adresse;
    cout<<t.getheures()<< endl;
    cout<<t.getminutes()<< endl;
    return 0;
}