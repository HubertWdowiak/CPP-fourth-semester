#pragma once
#include <iostream>

//Klasa przechowująca maksymalną wartośc prędkości np. Pojazdu
class PredkoscMaksymalna 
{
    //operator << pozwala wypisac przechowywaną prędkość wraz z jednostką
    friend std::ostream& operator<< (std::ostream& s, const PredkoscMaksymalna& x);

public:

    PredkoscMaksymalna(int i): predkosc_max{i} {};
    
private:

    int predkosc_max;
};

std::ostream& operator<< (std::ostream& s, const PredkoscMaksymalna& x)
{
    return s << x.predkosc_max << " km/h";
}