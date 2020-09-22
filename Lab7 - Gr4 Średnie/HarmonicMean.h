#pragma once
#include "Mean.h"

class HarmonicMean: public Mean
{
public:

    std::string get_type() const { return "Harmonic"; }

    const HarmonicMean operator<< (double a) const;
    
    HarmonicMean& operator << (double a) override;
    
    double result() const;
};