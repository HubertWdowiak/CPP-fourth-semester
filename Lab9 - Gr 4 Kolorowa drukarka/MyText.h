#pragma once
#include <iostream>
#include "AttColor.h"
#include "AttFormat.h"
#include "MyPrintable.h"

//class allows to store string with chosen color and format
class MyText: public AttColor, public AttFormat, public MyPrintable
{
public:
    MyText(std::string text, AttFormat::Attribute format, AttColor::Attribute color): AttColor(color), AttFormat(format), m_text(text) {};
    
    void setText(std::string text) { m_text = text; }
    
    int getLength() const { return m_text.length(); }

    //returns colored text, formated in a proper way
    std::string rawString() const{ return m_text; }

private:
    std::string m_text;
};