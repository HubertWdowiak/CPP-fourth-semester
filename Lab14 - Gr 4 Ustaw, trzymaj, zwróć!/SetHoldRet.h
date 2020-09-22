#pragma once

class SetHoldRet
{
public:

    //funkcja ustala wartosc bazowa dla danego typu T
    template<typename T> void base(T value)
    {
        set_base<T>(new T(value));
    }
    
    //Zwraca referncje do ustalonej wartosci bazowej, dla danego typu T
    template<typename T> T& product()
    {
        return *set_base<T>(nullptr);
    }
    
    //Funkcja ustawia wartosc bazowa dla danego typu T i zwraca wskaznik do zmiennej
    //przechowywujacej owa bazowa wartosc.
    template<typename T> T* set_base(T* value_ptr);

};

template<typename T> T* SetHoldRet::set_base(T* value_ptr)
{
     static T* base = nullptr;
     if(value_ptr)
     {
         if(base)
         {
             *base = *value_ptr;
             delete value_ptr;
         }
         else
         {
             base = value_ptr;
         }
     }
     return base;
}