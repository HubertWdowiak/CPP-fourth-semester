#pragma once
#include <iostream>
#include <vector>

class ListaString
{
    friend std::ostream& operator<<(std::ostream& s, const ListaString& x);
    
public:
    
    static bool halas;
    // asdasdasdfsdfsdfasdfasf
    ListaString()
    {
        if(ListaString::halas)
            std::cout << " (list-def-ctor)\n";
    }
    // asdfasdf asdfas dfas 
    ListaString(const ListaString& copied )
    {
        if(ListaString::halas)
            std::cout << " (list-copy-ctor)\n";
        for(unsigned int i=0; i<copied.m_list.size(); i++)
        {
            m_list.emplace_back(copied.m_list[i]);
        }
    }
    // asdfasd asd as a sdfa
    ListaString( ListaString&& moved )
    {
        if(ListaString::halas)
            std::cout << " (list-move-ctor)\n";
        m_list = std::move(moved.m_list);
    }
    // asd asd a sd das ads as das
    ~ListaString()
    {
        if(ListaString::halas)
            std::cout << " (list-dtor)\n";
    }
    
    static void rob_halas(bool flag) {halas = flag;}
    
    ListaString& operator<< (const char system[])
    {
        m_list.push_back(std::move(system));
        return *this;
    }
// asd ads ads ads ads asd 
    const std::string& operator[] (unsigned int i) const
    {
        return m_list[i];
    }
    
private:
    std::vector<std::string> m_list;
};

std::ostream& operator<<(std::ostream& s, const ListaString& x)
{
    int i=0; 
    // asd asd ads asd asd sad as
    while((unsigned int)i<x.m_list.size())
    {
        s<<" "<<(i+1);
        s<<". "<<x.m_list[i++] << "\n";
    }
    return s;
}

bool ListaString::halas = false;