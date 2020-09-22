#pragma once
#include <iostream>

class Calc_error: public std::runtime_error
{
    /*
    Klasa pozwalajaca utworzyc liste wyjatkow (wraz ze szczegolowymi informacjami),
    w kolejnosci poziomow ich wystapienia, a takze umozliwiajaca ich obsluge.
    */
    
public:   
    
    //Konstruktor 
    Calc_error(std::runtime_error* err, const std::string& text, const std::string& file, const int line): 
    std::runtime_error(text + ", [plik = " + file + ", linia = " + std::to_string(line) + "]"), m_err(err) {};
    
    //Funkcja umozliwiajaca obsluge wyjatkow, poprzez wypisanie 
    //(w rosnacej kolejnosci poziomow ich wystapien) ich tresci, pliku a takze 
    //linii, w których zostal wylapany poszczegolny wyjatek
    static void handler();
    
private:
    
    //Wskaznik na blad, ktory wystapil poziom wyzej
    //np. dla bledu z poziomu 1, m_err jest wskaznikiem na blad z poziomu 2
    std::runtime_error* m_err;
};

void Calc_error::handler()
{
    try
    {
        throw;
    }
    catch(std::runtime_error* err)
    {
        std::cout << "Zlapano wyjatek:" << std::endl;
        bool loop = true;
        while(loop)
        {
            std::cout << "-- z powodu: " << err->what() << std::endl;
            Calc_error* check_ptr = dynamic_cast<Calc_error*>(err);
            if(check_ptr)
            {
                err = check_ptr->m_err;
                delete check_ptr;
            }
            else
            {
                delete err;
                loop = false;
            }
        }
    }
}