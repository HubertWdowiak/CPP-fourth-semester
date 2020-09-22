#pragma once
#include "PojazdLadowy.h"

class Samochod: public PojazdLadowy
{
public:

    Samochod(std::string rej, PredkoscMaksymalna x): Pojazd( rej ), predkosc( x ) {};
    
    PredkoscMaksymalna predkoscMaksymalna() const
    { return predkosc; }

    //zwraca napis w formacie "Samochod <REJESTRACJA>"
    std::string print() const
    { return "Samochod " + Pojazd::print(); }
    
protected:
    
    PredkoscMaksymalna predkosc;
    
};