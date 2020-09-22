#pragma once
#include <iostream>
#include "MyItem.h"

class MyFile: public MyItem
{
private:
    std::string text;
public:
    MyFile(): MyItem(""), text("") {};
    MyFile(std::string x): MyItem(x), text("") {};
    MyFile(const MyFile& copied): MyItem(copied), text(copied.text) {};
    ~MyFile() = default;
    
    MyFile& operator<< ( std::string extra )
    {
        text += extra;
        text += "\n";
        return *this;
    }
    
    void cat() { std::cout << text; }
    void ls( unsigned int op ) const {MyItem::printName(); }
    MyFile* clone() const { return new MyFile(*this); }
    
};