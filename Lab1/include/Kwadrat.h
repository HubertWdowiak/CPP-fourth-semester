#pragma once
#include "Ksztalt.h"

class Kwadrat : Ksztalt
{
    public:
    Kwadrat(int a): bok(a) {};
    void Ksztalt :: Wypisz(std::ostream)
    {
        std::cout << "Kwadrat o boku: " << bok << "/n";
    }
    
    int polePow()
    {
        return bok * bok;
    }

    private:
    int bok;
};