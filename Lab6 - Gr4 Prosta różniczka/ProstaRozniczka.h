#include <iostream>
#pragma once
class ProstaRozniczka
{
public:
    ProstaRozniczka( double x )
    {
        m_step = x;
    }
    
    //zapisuje funkcje i obniza jej stopien, do zmiennej m_fun
    ProstaRozniczka* z( Fun* funkcja )
    {
        funkcja->set_c( funkcja->get_b() );
        funkcja->set_b( funkcja->get_a() );
        funkcja->set_a( 0 );
        m_fun = funkcja;
        return this;
    }

    //oblicze wartosc rozniczki przy kroku rownym m_step
    double w( double x ) 
    {
        return (m_fun->wartosc(x + m_step) - m_fun->wartosc(x - m_step)) / (2*m_step);
    }
    
private:
    
    Fun* m_fun;
    double m_step;
};