#pragma once
#include "Zwierz.h"
class Owca: public Zwierz
{
//Klasa reprezentujaca gatunek zwierzecia - owce
public:
    Owca(std::string imie): Zwierz(imie), ostrzyzona(false) {};
    
    ~Owca()
    {
        std::cout << "Owca " << m_imie << " wrocila do zagrody" << std::endl;
    }
    
    //funkcja wypisuje informacje o gatunku, imieniu i czy owca jest ostrzyzona czy nie
    void opisz() const
    {
        std::cout <<"Owca " << m_imie << " - ";
        if(ostrzyzona)
            std::cout << "ostrzyzona" << std::endl;
        else
            std::cout << "nieostrzyzona" << std::endl;
    }
    
    //funkcja imitujaca strzyzenie owcy
    void ostrzyz()
    {
        ostrzyzona = true;
    }
    
private:
    
    //zmienna informujaca czy owca byla strzyzona
    bool ostrzyzona;
};