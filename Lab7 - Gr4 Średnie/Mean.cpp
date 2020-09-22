#include "Mean.h"

std::ostream& operator<< (std::ostream& o, const Mean& obj)
{
    o << obj.get_type();
    return o;
}

void Mean::reset()
{
    sum = 0;
    amount = 0;
}

void Mean::add_to_sum( float a )
{
    sum += a;
    amount += 1;
}
    