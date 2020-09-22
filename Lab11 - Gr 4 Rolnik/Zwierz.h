#pragma once
#include <iostream>

class Farma;

class Zwierz
{
//Klasa po ktorej dziedziczy kazdy gatunek zwierzecia
public:

    Zwierz(std::string imie): m_imie(imie) {};
    
    virtual ~Zwierz() {};
    
    virtual void opisz() const = 0;
    
    //getter imienia zwierzecia
    std::string imie() const
    {
        return m_imie;
    }
       
protected:
    //string przechowujacy imie zwierzecia
    std::string m_imie;
};
