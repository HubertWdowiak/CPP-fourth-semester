#pragma once

class FZlozona: public Fun
{
public:

    ~FZlozona()
    {
        delete fun1;
        delete fun2;
    }
    
    FZlozona() {};
    
    //kontruktor zapisuje funkcje x1 i x2 ktore beda nastepnie
    //mogly obliczyc wartosc jako fun1(fun2)
    FZlozona( Fun* x1, Fun* x2)
    {
        fun1 = x1->clone();
        fun2 = x2->clone();
    }
    
    //zwaraca wartosc zlozenia funkcji fun1 i fun2
    double wartosc( double x )
    {
        double val = fun2->wartosc( x );
        return fun1->wartosc( val );
    }
    
    Fun* clone()
    {
        Fun* x = new FZlozona( *this );
        return x;
    }
    
private:
    Fun* fun1;
    Fun* fun2;
};