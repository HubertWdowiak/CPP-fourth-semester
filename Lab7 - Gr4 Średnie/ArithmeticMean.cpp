#include "ArithmeticMean.h"

double ArithmeticMean::result() const
{
    if(get_amount() == 0)
        return 0;
    else
        return get_sum() / get_amount();
}

ArithmeticMean& ArithmeticMean::operator << (double a)
{
    add_to_sum(a);    
    return *this;
}

const ArithmeticMean ArithmeticMean::operator<< (double a) const
{
    std::cout << "ERROR: cannot add value " << a << " to const Arithmetic Mean\n";
    return *this;
}