#pragma once
#include <cmath>
#include <iostream>

class Liniowa: public Fun
{
public:
    
    ~Liniowa() = default;

    static Liniowa* utworz();

    //funkcja zwraca wartosc wielomianu ax+b    
    double wartosc( double x )
    {
        return get_a() * x + get_b();
    }
        
    //funkcja dziala jak konstruktor kopiujacy
    Fun* clone()
    {
        Fun* x = Liniowa::utworz();
        x->set_a( this->get_a() );
        x->set_b( this->get_b() );
        x->set_c( this->get_c() );
        return x;
    }

};

Liniowa* Liniowa::utworz()
{
    Liniowa* x = new Liniowa();
    return x;
}

class Kwadratowa: public Fun
{
public:

    ~Kwadratowa() = default;

    static Kwadratowa* utworz();

    //zwraca wartosc wielomianu ax^2 + bx + c
    double wartosc( double x )
    {
        return  get_a() * x * x + get_b() * x + get_c();
    }
    
    Fun* clone()
    {
        Fun* x = Kwadratowa::utworz();
        x->set_a(this->get_a());
        x->set_b(this->get_b());
        x->set_c(this->get_c());
        return x;
    }
};

Kwadratowa* Kwadratowa::utworz()
{
  Kwadratowa* x = new Kwadratowa();
  return x;
}

class Sinus: public Fun
{
public:

    ~Sinus() = default;
    
    double wartosc(double x)
    {
        return sin(x);
    }
    
    Fun* clone()
    {
        Fun* x = new Sinus(*this);
        return x;
    }
};