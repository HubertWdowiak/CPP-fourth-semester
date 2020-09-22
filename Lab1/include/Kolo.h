#pragma once 
#include "Ksztalt.h"

class Kolo : public Ksztalt
{
    public:
    Kolo(int a): promien(a) {};
    void Ksztalt :: wypisz(std::ostream)
    {
        std::cout << "Kolo o promieniu: " << promien <<"\n";
    }

    private:
    int promien;
};