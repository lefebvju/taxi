struct Client{
    std::string nom;
    std::string prenom;
    int tel;
    Adresse adresse;

    Client(std::string nom, std::string prenom, int tel,Adresse adresse) :nom(nom), prenom(prenom), tel(tel), adresse(adresse){};

};