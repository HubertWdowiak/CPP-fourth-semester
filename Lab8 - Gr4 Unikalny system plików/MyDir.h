#pragma once
#include <vector>
#include "MyItem.h"
#include "MyUnique.h"
class MyDir: public MyItem
{
private:
    std::vector<MyItem*> files;
    
public:
    MyDir(): MyItem(""), files() {};
    MyDir(std::string name): MyItem(name), files() {};
    MyDir(const MyDir& copied): MyItem(copied), files(copied.files) {};
    ~MyDir();
    
    void ls(unsigned int op = 0) const {};
    
    MyDir* clone() const { return new MyDir(*this); }
    
    void operator /= (MyItem* new_item) { files.push_back(new_item); }
    void operator /= (MyUnique new_item) {};

};