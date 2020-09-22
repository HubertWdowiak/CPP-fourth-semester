#pragma once
#include <iostream>

//basic class inherited by text-containing classes
class MyPrintable
{
public:
    virtual std::string rawString() const = 0;
    virtual int getLength() const = 0;
};
