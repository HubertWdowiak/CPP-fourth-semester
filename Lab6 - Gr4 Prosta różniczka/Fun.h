#pragma once

class Fun
{
private:

    double m_a = 0;
    double m_b = 0;
    double m_c = 0;

public:
    
    //Funkcja zwracajaca wartosc w zaleznosci jakiego stopnia jest wielomian
    virtual double wartosc(double x) {return 0;}
    virtual ~Fun(){};
    
    //***********************************************
    //Setterry zwracajace wskaznik do obiektu
    Fun* c(double x)
    {
        m_c = x;
        return this;
    }
    
    Fun* a(double x) 
    { 
        m_a = x; 
        return this;
    }
    
    Fun* b(double x) 
    {
        m_b = x;
        return this;
    }
    //************************************************
    //wirtualna funkcja kopiujaca 
    virtual Fun* clone() = 0;
    
    //************************************************
    //Zwykle settery i gettery
    double get_a()
    {
        return m_a;
    }
    
    double get_b()
    {
        return m_b;
    }
    
    void set_a(double x)
    {
        m_a = x;
    }
    
    void set_b(double x)
    {
        m_b = x;
    }
    
    double get_c()
    {
        return m_c;
    }
    
    void set_c(double x)
    {
        m_c = x;
    }
};