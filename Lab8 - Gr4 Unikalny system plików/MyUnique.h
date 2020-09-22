#pragma once
#include "MyItem.h"

class MyUnique
{
private:
    MyItem* ptr;
public:
    static std::vector<MyUnique*> uniques;
    static std::vector<MyItem*> already_pointed;
    MyUnique(): ptr(nullptr) {MyUnique::uniques.push_back(this);}
    MyUnique ( MyUnique&& moved )
    {
        MyUnique::uniques.push_back(this);
        ptr = std::move(moved.ptr);
        moved.ptr = nullptr;
    }
    MyUnique(MyItem* item)
    {
        bool in = false;
        
        for( unsigned int i =0; i<MyUnique::already_pointed.size(); i++)
        {
            if( already_pointed[i] == item )
                in = true;
        }
        
        if(!in)
        { 
            ptr = item;
            already_pointed.push_back(item);
        }
        else 
            ptr = nullptr;
    
        MyUnique::uniques.push_back(this);
    }
    
    void operator=(MyUnique&& moved)
    {
        MyItem* temp = moved.ptr;
        for( unsigned int i = 0; i<MyUnique::uniques.size(); i++)
        {
            if(MyUnique::uniques[i]->get() == temp)
                MyUnique::uniques[i]->ptr = nullptr;
        }
        ptr = temp;
    }
    
    MyItem* operator->() { return ptr; }
    MyItem* get() { return ptr; }
};

std::vector<MyItem*> MyUnique::already_pointed {};
std::vector<MyUnique*> MyUnique::uniques {};