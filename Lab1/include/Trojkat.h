#pragma once
#include "Ksztalt.h"
#include <math.h>
class Trojkat : Ksztalt
{
    public:
    Trojkat(int a, int b, int c): bok1(a), bok2(b), bok3(c) {};
    void Ksztalt :: Wypisz( std::ostream )
    {
        std::cout << "Trojkat o bokach: " << bok1 << " " << bok2 << " " << bok3 << "\n";
    }

    int Ksztalt :: polePow()
    {
        int s = 1/2 * (bok1 + bok2 + bok3);
        return math::sqrt( s*(s-bok1)*(s-bok2)*(s-bok3) );
    }

    private:
    int bok1;
    int bok2;
    int bok3;
};