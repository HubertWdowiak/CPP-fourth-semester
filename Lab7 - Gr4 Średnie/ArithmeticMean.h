#pragma once
#include "Mean.h"

class ArithmeticMean: public Mean
{
public:

    std::string get_type() const { return "Arithmetic"; }
    
    const ArithmeticMean operator<< (double a) const;
    
    ArithmeticMean& operator << (double) override;
    
    double result() const;
};