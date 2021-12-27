#include "TCP.hpp"
#include "Adresse.hpp"

string findjson(string json,string delimiteur1,string delimiteur2){
    string result= json.substr(json.find(delimiteur1+": ")+(delimiteur1+": ").size(),json.size());
    result= result.substr(0,result.find(delimiteur2));
    charInutile(&result);
    cout<<result<<endl;
    return result;
}

void charInutile(string* s){
    s->erase(remove( s->begin(),  s->end(), '"'), s->end());
    s->erase(remove( s->begin(),  s->end(), '{'), s->end());
    s->erase(remove( s->begin(),  s->end(), '}'), s->end());
    s->erase(remove( s->begin(),  s->end(), '['), s->end());
    s->erase(remove( s->begin(),  s->end(), ']'), s->end());
    s->erase(remove( s->begin(),  s->end(), ':'), s->end());
}

float findlongi(string s){
    s=findjson(s,"\"coordinates\"");
return stof(s);
}

float findlat(string s){
    s=findjson(s,"\"coordinates\"","]},");
    s=s.substr(s.find(", ")+string(", ").size(),s.size());    
return stof(s);
}

Adresse::Adresse(string label){
    replace( label.begin(), label.end(), ' ', '+');
    string request="GET /search/?q="+label+" HTTP/1.0\r\nHost: "+API+"\r\n\r\n";
    TcpClient c;
    c.conn(API , PORT);
    c.send_data(request);
    string recieve=c.receive(1024);
    
    recieve = recieve.substr(recieve.find("{\"type\":"),recieve.size() );
    recieve = recieve.substr(0,recieve.find(", {\"type\":") );
    if(recieve.find("\"housenumber\"")!=string::npos){
        this->num=stoi(findjson(recieve,"\"housenumber\""));
    }
    if(recieve.find("\"street\"")!=string::npos){
        this->rue=findjson(recieve,"\"street\"");
    }
    if(recieve.find("\"postcode\"")!=string::npos){
        this->codePostal=findjson(recieve,"\"postcode\"");
    }
    if(recieve.find("\"city\"")!=string::npos){
        this->ville=findjson(recieve,"\"city\"");
        this->latitude=findlat(recieve);
        this->longitude=findlongi(recieve);
    }


}

Adresse::Adresse(int num, string rue, string codePost,string ville):num(num), rue(rue), codePostal(codePost),ville(ville){

}

Adresse::Adresse(string rue, string codePost,string ville):num(0),rue(rue), codePostal(codePost),ville(ville){

}