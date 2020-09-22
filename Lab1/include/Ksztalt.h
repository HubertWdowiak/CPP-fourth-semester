#pragma once
#include <iostream>

class Ksztalt
{
    public:
    static void wypisz(const Ksztalt& a) 
    {
        a::wypisz(std::cout);
    };

    virtual void wypisz(std::ostream) const {};
    
    int polePow() 
    {
        return 0;
    }
};