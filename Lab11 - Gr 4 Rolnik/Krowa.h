#pragma once
#include "Zwierz.h"

class Krowa: public Zwierz
{
//Klasa reprezentujaca gatunek zwierzecia - krowe
public:
    
    Krowa(std::string imie): Zwierz(imie) {};
    
    ~Krowa()
    {
        std::cout << "Krowa " << m_imie << " wrocila do obory" << std::endl;
    }
    
    //funkcja wypisujaca informacje o gatunku i imieniu
    void opisz() const
    {
        std::cout <<"Krowa " << m_imie << std::endl;
    }
};
