#include "TCP.hpp"
#include "Adresse.hpp"
#include <regex>
string findjson(string json,string delimiteur1,string delimiteur2){
    string result= json.substr(json.find(delimiteur1+": ")+(delimiteur1+": ").size(),json.size());
    result= result.substr(0,result.find(delimiteur2));
    charInutile(&result);
    cout<<result<<endl;
    return result;
}

void Replace(string * str, const string& sub, const string& mod) {
    while(str->find(sub)!=string::npos){
        str->replace(str->find(sub), sub.length(), mod);
    }
}

void charInutile(string* s){
    s->erase(remove( s->begin(),  s->end(), '"'), s->end());
    s->erase(remove( s->begin(),  s->end(), '{'), s->end());
    s->erase(remove( s->begin(),  s->end(), '}'), s->end());
    s->erase(remove( s->begin(),  s->end(), '['), s->end());
    s->erase(remove( s->begin(),  s->end(), ']'), s->end());
    s->erase(remove( s->begin(),  s->end(), ':'), s->end());
    Replace(s,"\\u00c0","A");
 	Replace(s,"\\u00c1","A");
 	Replace(s,"\\u00e0","a");
 	Replace(s,"\\u00e1","a");
 	Replace(s,"\\u00c2","A");
 	Replace(s,"\\u00e2","a");
 	Replace(s,"\\u00c3","A");
 	Replace(s,"\\u00e3","a");
 	Replace(s,"\\u00c4","A");
 	Replace(s,"\\u00e4","a");
 	Replace(s,"\\u00c5","A");
 	Replace(s,"\\u00e5","a");
 	Replace(s,"\\u00c6","E");
 	Replace(s,"\\u00e6","e");
 	Replace(s,"\\u00c7","C");
 	Replace(s,"\\u00e7","c");
 	Replace(s,"\\u00d0","D");
 	Replace(s,"\\u00f0","d");
 	Replace(s,"\\u00c8","E");
 	Replace(s,"\\u00e8","e");
 	Replace(s,"\\u00c9","E");
 	Replace(s,"\\u00ca","E");
 	Replace(s,"\\u00ea","e");
 	Replace(s,"\\u00cb","E");
 	Replace(s,"\\u00eb","e");
 	Replace(s,"\\u00cc","I");
 	Replace(s,"\\u00ec","i");
 	Replace(s,"\\u00cd","I");
 	Replace(s,"\\u00ed","i");
 	Replace(s,"\\u00ce","I");
 	Replace(s,"\\u00ee","i");
 	Replace(s,"\\u00cf","I");
 	Replace(s,"\\u00ef","i");
 	Replace(s,"\\u00d1","N");
 	Replace(s,"\\u00f1","n");
 	Replace(s,"\\u00d2","O");
 	Replace(s,"\\u00f2","o");
 	Replace(s,"\\u00d3","O");
 	Replace(s,"\\u00f3","o");
 	Replace(s,"\\u00d4","O");
 	Replace(s,"\\u00f4","o");
 	Replace(s,"\\u00d5","O");
 	Replace(s,"\\u00f5","o");
 	Replace(s,"\\u00d6","O");
 	Replace(s,"\\u00f6","o");
 	Replace(s,"\\u0153","E");
 	Replace(s,"\\u0152","E");
 	Replace(s,"\\u00d8","O");
 	Replace(s,"\\u00f8","o");
 	Replace(s,"\\u00df","P");
 	Replace(s,"\\u00d9","U");
 	Replace(s,"\\u00f9","u");
 	Replace(s,"\\u00da","U");
 	Replace(s,"\\u00fa","u");
 	Replace(s,"\\u00db","U");
 	Replace(s,"\\u00fb","u");
 	Replace(s,"\\u00dc","U");
 	Replace(s,"\\u00fc","u");
 	Replace(s,"\\u00dd","Y");
 	Replace(s,"\\u00fd","y");
 	Replace(s,"\\u00de","P");
 	Replace(s,"\\u00fe","P");
 	Replace(s,"\\u0178","Y");
 	Replace(s,"\\u00ff","y");
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
    }else{
        this->num=-1;
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


