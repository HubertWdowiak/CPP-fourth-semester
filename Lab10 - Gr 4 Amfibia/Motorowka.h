#pragma once
#include "PojazdWodny.h"

class Motorowka: public PojazdWodny
{
public:

    Motorowka(std::string rej, PredkoscMaksymalna x): Pojazd( rej ), predkosc( x ) {};
    
    PredkoscMaksymalna predkoscMaksymalna() const
    { return predkosc; }

    //zwraca napis w formacie "Motorowka <REJESTRACJA>"
    std::string print() const
    { return "Motorowka " + Pojazd::print(); }
    
protected:

    PredkoscMaksymalna predkosc;
};