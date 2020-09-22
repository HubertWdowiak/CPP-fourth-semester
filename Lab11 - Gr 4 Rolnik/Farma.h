#pragma once
#include <memory>
#include <vector>
#include <numeric>
#include <algorithm>
#include <typeinfo>
#include "Owca.h"
#include "Krowa.h"
#include "Kon.h"

class Farma
{
public:
    ~Farma();
    
    //funkcja dodaje uniqe_ptr na zwierze do vectora zwierzeta
    void dodaj(std::unique_ptr<Zwierz> new_ptr);
    
    //funkcja wypisuje informacje o kazdym zwierzeciu w farmie w formacie:
    //[GATUNEK] [IMIE] [INFORMACJA O STRZYZENIU JESLI ZWIERZE TO OWCA]
    void wypisz(std::string tekst) const;
    
    //funkcja zwraca informacje ile zwierzat w farmie nosi podane imie
    int zliczImie(std::string imie) const;
    
    //wyswietla imiona w kolejnosci alfabetycznej (bez powtarzania), wraz z liczba ich wystapien
    void statystykaImion() const;
    
    //zwraca wektor wskaznikow na owce, w którym znajduja sie wszystkie owce z farmy
    std::vector<Owca*> wyprowadzOwce() const;
    
private:
    //wektor przechowujacy unique_ptr na kazde ze zwierzat w farmie
    std::vector< std::unique_ptr<Zwierz> > zwierzeta;
};