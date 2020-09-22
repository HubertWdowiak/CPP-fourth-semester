#pragma once
#define STATE_TYPE(X) class X:public Stan
#include <iostream>

class Stan{
public:
    virtual void operator()() = 0;
    virtual const char* nazwa() const = 0;
    virtual void podsumowanie() const = 0;
    virtual ~Stan() = default;
    static std::string curr_sys;
    static std::string email;
};

std::string Stan::curr_sys = "";
std::string Stan::email = "";