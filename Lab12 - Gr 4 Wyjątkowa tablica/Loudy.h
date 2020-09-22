#pragma once
#include <iostream>

class Loudy
{
public:

    //Glosny konstruktor
    Loudy(const std::string& text): m_text(text)
    {
        std::cout << "Laudy " << m_text << " is waking up!" << std::endl;
    }
    
    //Glosny destruktor
    ~Loudy()
    {
        std::cout << "Laudy " << m_text << " is going to sleep..." << std::endl;
    }
    
    void skip()
    {
        throw this;
    }

private:
    //nazwa obiektu
    std::string m_text;
};

class LoudyArray
{
public:

    //Konstruktor tworzy tablice Loudy* o dlugosci m_size 
    //i ustala jej wartosci na nullptr
    LoudyArray(const int size): m_size(size), m_array(new Loudy*[size]) 
    {
        for(int i=0; i<m_size; i++)
        {
            m_array[i] = nullptr;
        }
    };
    
    //destruktor usuwa cala zawartosc tablicy m_array
    ~LoudyArray()
    {
        for(int i=0; i<m_size; i++)
        {
            delete m_array[i];
        }
        delete[] m_array;
    }
    
    //Funkcja sprawdza czy w m_array pod indeksem index, znajduje sie jakis wskaznik.
    //Jesli tak, to usuwa go i nadpisuje object'em.
    //Jesli nie, to od razu ustala jego wartosc na object.
    //Jesli podany index, wychodzi poza zakres m_array, rzucany jest wyjatek
    void set(const int index, Loudy* object)
    {
        if(index < m_size)
        {
            delete m_array[index];
            m_array[index] = object;      
        }
        else
        {
            delete object;
            throw *this;
        }
    }
    
private:

    //dlugosc tablicy m_array
    int m_size;
    //dynamiczna tablica to przechowywania obiektów typu Loudy*
    Loudy** m_array;
};