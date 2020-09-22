#pragma once
#include <iostream>

class LicznikPoziomow
{
    /*
    Klasa imitujaca licznik poziomu programu, poprzez zliczanie obecnie 
    istniejacych instancji obiektu. Aby licznik dzialal poprawnie, po wkroczeniu 
    do nowego poziomu, konieczne jest automatyczne wywolanie konstruktora klasy.
    */
    
public:

    //Konstruktor zwieksza wartosc licznika o 1
    //i wypisuje informacje o numerze zaktualizowanego poziomu
    LicznikPoziomow()
    {
        poziom++;
        std::cout << "Rozpoczynamy poziom numer " << poziom << "." << std::endl;
    }
    
    //Destruktor wypisuje informacje o numerze aktualnego poziomu,
    //a nastepnie zmniejsza wartosc licznika o 1.
    ~LicznikPoziomow()
    {
        std::cout << "Konczymy poziom numer " << poziom << "." << std::endl;
        poziom--;
    }
    
private:
    //liczba przechowujaca wartosc licznika
    static int poziom;
};

int LicznikPoziomow::poziom = 0;