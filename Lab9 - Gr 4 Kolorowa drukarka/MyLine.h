#pragma once
#include <iostream>
#include "AttColor.h"

//class used to store line of the same character, with one selected color
class MyLine: public AttColor, public MyPrintable
{
public:

    void setLength(int length) { m_length = length; }

    void setChar(char sign) { m_sign = sign; }

    int getLength() const { return m_length; }
    
    //return string consisting of "m_sign" in quantity of "m_length"
    std::string rawString() const{ return std::string(m_length, m_sign); }

    MyLine(char sign, int length, AttColor::Attribute color): AttColor(color),  m_sign(sign), m_length(length){};

private:
    //character that the line consist of
    char m_sign;
    //quantity of characters stored in line
    int m_length;
};
