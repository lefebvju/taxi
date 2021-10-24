class Temps{
    private:
        int heures;
        int minutes;
    public:
        Temps(int h, int m):heures(h), minutes(m){
            if(minutes >= 60){
                heures = heures+minutes/60;
                minutes = minutes%60;
            }
        };
        int getheures() const { return heures; }
        int getminutes() const { return minutes; }
};