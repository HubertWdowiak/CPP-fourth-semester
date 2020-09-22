#pragma once
#include "Stan.h"
#include "StanyBazowe.h"
#include <iostream>
class MaszynaStanow
{
    friend std::ostream& operator <<(std::ostream& s, const MaszynaStanow& m);
    
private:
    // asd asd asd asd asd asd
    std::vector<Stan*> m_stany;
    
    int curr = 0;
    
public:
// asd ads ads asd das
    void start()
    {
        std::cout <<"Rozpoczynamy dzialanie maszyny stanow!\n";
    }
    // asd asd asd ads asd 
    void operator+=(Stan* x)
    {
        m_stany.emplace_back(x);
    }
    // asd asd asd dsafasd 
    Stan& operator()()
    {
        return *(m_stany[curr]);
    }
    //asdfasdfasdf
    ~MaszynaStanow()
    {
        
        for(unsigned int i=0; i<m_stany.size(); i++)
        {
            delete m_stany[i];
        }
        //if(ListaString::halas)
          //  std::cout << " (list-dtor)\n";
    }
    // asd ads asd das a
    void operator++() {curr++;}
    //as dad sas asd asd asd 
    void operator--() {curr--;}
};
// asdfasdf asdf asdf asdf asd asdf asd fasd
std::ostream& operator<< (std::ostream& s, const MaszynaStanow& m)
{
    int x=0;
    if( m.m_stany[m.curr]->nazwa() == std::string("DostepneSystemy")) {x = 1;}
    else if(m.m_stany[m.curr]->nazwa() == std::string("ZbieranieDanych")) {x =2;}
    else if(m.m_stany[m.curr]->nazwa() == std::string("Podsumowanie")) {x=3;}
    else if(m.m_stany[m.curr]->nazwa() == std::string("Instalacja")) {x=4;}
    
    if(x==1)
        s << ">DostepneSystemy< ZbieranieDanych Podsumowanie";
    else if(x==2)
        s <<"DostepneSystemy >ZbieranieDanych< Podsumowanie";
    else if(x == 3)
        s <<"DostepneSystemy ZbieranieDanych >Podsumowanie<";
    else if(x==4)
        s<<"DostepneSystemy ZbieranieDanych Podsumowanie >Instalacja<";
    return s;
}