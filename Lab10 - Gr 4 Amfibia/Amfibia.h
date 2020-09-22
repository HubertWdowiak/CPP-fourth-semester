#pragma once
#include "Samochod.h"
#include "Motorowka.h"

class Amfibia: public Samochod, public Motorowka
{
public:

    Amfibia(std::string rej, PredkoscMaksymalna lad, PredkoscMaksymalna woda):Pojazd( rej ), Samochod( rej, lad ), Motorowka ( rej, woda ) {};
    
    //zwraca napis w formacie "Amfibia <REJESTRACJA>"
    std::string print() const
    { return "Amfibia " + Pojazd::print(); }
    
    //Zwracaja maksymalną prędkośc amfibii na lądzie
    const PredkoscMaksymalna& predkoscMaksymalna_Lad() const
    { return Samochod::predkosc; }
    
    //Zwracaja maksymalną prędkośc amfibii w wodzie
    const PredkoscMaksymalna& predkoscMaksymalna_Woda() const
    { return Motorowka::predkosc; }

};