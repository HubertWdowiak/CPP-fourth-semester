#pragma once
#include "InfoClass.h"
class InfoSmartPtr
{
public:

    InfoSmartPtr( InfoClass* x ): m_ptr{x} 
    {
        m_ptr->m_counter++;
    };

    //operator zwracajacy raw pointer
    InfoClass operator* () const
    {
        return *m_ptr;
    }

    //operator przypisania zmniejszajacy licznik referencji w nadpisanej strukturze
    //a zwiekszajacy licznik w nowo wskazywanej strukturze
    //jesli nic nie wskazuje na dawna InfoClass, struktura ta jest usuwana
    void operator= (InfoSmartPtr x)
    {
        m_ptr->m_counter--;
        if(m_ptr->m_counter <= 0)
            delete m_ptr;
        m_ptr = x.m_ptr;
        m_ptr->m_counter++;
    }

    InfoClass* operator-> () const
    {
        return m_ptr;
    }


private:

    InfoClass* m_ptr;
};

class InfoSuperClass : public InfoClass
{
public:

    InfoSuperClass(std::string a, int b): InfoClass{a}, m_num{b} {};

private:

    int m_num;

};