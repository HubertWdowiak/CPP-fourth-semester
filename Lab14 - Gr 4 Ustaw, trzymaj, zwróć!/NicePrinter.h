#pragma once
#include <iostream>
#include <iomanip>

class NicePrinter
{//Klasa imitujaca drukarke, sluzaca do wypisywania tekstow
public:

    //Glosny konstruktor, ktory ustawia pole szerokosci wyjscia w operacjach 
    //wypisywania, na wartosc "n".
    NicePrinter(const int n): m_num(n) 
    {
        std::cout << "NicePrinter: Set " << m_num << "-digits prefix" << std::endl;
    };
    
    //Wyswietla separator z liczba "n" na srodku
    void separator(const int n) const
    {
        std::cout << "=====-===== " << n << " =====-=====" << std::endl;
    }
    
    //Wyswietla napis w formacie "* [NAPIS] *", gdzie NAPIS jest stringiem
    //podanym w zmiennej text.
    void header(const std::string& text) const
    {
        std::cout << "* " << text << " *" << std::endl;
    }
    
    //Wyswietla informacje ile razy uzyto tej funkcji, a nastepnie podana wartosc,
    //w formacie "[numer wywolania funkcji]: [value]", przy czym zachowana jest
    //szerokosc pola wypisywania ustalona w zmiennej m_num.
    template<typename T> void operator()(T value) const
    {
        std::cout << counter() << ": " <<  std::setw(m_num) << value << std::endl;    
    }
    
    //Pomocnicza funkcja zliczajaca jej wywolania.
    //Zaczynajac od 1, dodaje 1 po kazdym jej uzyciu.
    int counter() const
    {
        static int counter = 1;
        return counter++;
    }
private:
    //Cmienna przechowujaca obecna szerokosc pola dla wypisywanych wartosci.
    int m_num;
};