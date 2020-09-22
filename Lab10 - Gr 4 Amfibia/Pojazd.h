#pragma once
#include <iostream>

//Klasa bazowa dla wszystkich pojazdów
class Pojazd
{   
    //operator << umożliwia klasom pochodnym wypisanie typu pojazdu wraz z jego rejestracją
    //w formacie [TYP] <REJESTRACJA>
    friend std::ostream& operator<< (std::ostream& s, const Pojazd& x);

public:

    Pojazd() = default;
    
    Pojazd(std::string rej): rejestracja( rej ) {};
    
    virtual ~Pojazd() {};
    
    //funkcja zwraca rejestrację w klamerkach <>
    virtual std::string print() const
    { return "<" + rejestracja + ">"; }
        
protected:

    std::string rejestracja;
};

std::ostream& operator<< (std::ostream& s, const Pojazd& x)
{
    return s << x.print();
}
