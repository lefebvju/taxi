
#include <string>
class Adresse{
private:
        int num;
        std::string rue;
  int codePostal;
        std::string ville;
public:
        Adresse(){};
        Adresse(int num, std::string rue, int codePost,std::string ville):num(num), rue(rue), codePostal(codePost),ville(ville){};
        Adresse(std::string rue, int codePost,std::string ville):num(0),rue(rue), codePostal(codePost),ville(ville){};
};
