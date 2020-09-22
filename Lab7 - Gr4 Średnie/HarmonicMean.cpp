#include "HarmonicMean.h"

double HarmonicMean::result() const
{
    if(get_sum() == 0)
        return 0;
    else
        return get_amount() / get_sum();
}

HarmonicMean& HarmonicMean::operator << (double a)
{
    add_to_sum(1.0/a);
    return *this;
}

const HarmonicMean HarmonicMean::operator<< (double a) const
{
    std::cout << "ERROR: cannot add value " << a << " to const Harmonic Mean\n";
    return *this;
} 