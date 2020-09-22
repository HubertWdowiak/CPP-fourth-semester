#pragma once
#include "Zwierz.h"

class Kon: public Zwierz
{
//Klasa reprezentujaca gatunek zwierzecia - konia
public:
    
    Kon(std::string imie): Zwierz(imie) {};
    
    ~Kon()
    {
        std::cout << "Kon " << m_imie << "wrocil do stajni" << std::endl;
    }
    
    //funkcja wypisujaca informacje o gatunku i imieniu
    void opisz() const
    {
        std::cout <<"Kon " << m_imie << std::endl;
    }
};