#pragma once
#include "Pojazd.h"

class Rower: public PojazdLadowy
{
public:

    Rower(std::string rej): Pojazd( rej ) {};
    
    //funkcja zwraca napis w formacie "Rower <REJESTRACJA>"
    std::string print() const
    { return "Rower" + Pojazd::print(); }
};