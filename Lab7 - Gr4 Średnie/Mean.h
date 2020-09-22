#pragma once
#include <iostream>
class Mean
{
public:

    //Przeladowanie operatora << przekazuje na standardowe wyjscie
    //nazwe typu sredniej dla ktorej zostal wywolany operator.
    friend std::ostream& operator<< (std::ostream&, const Mean&);
    
    // przeladowanie operatora << dodaje do sumy objektu odpowiednia wartosc
    virtual Mean& operator << (double a)
    {
        add_to_sum( a );
        return * this;
    }
    
    //Zabezpiecza przed dodawaniem wartosci do stalego obiektu sredniej.
    const Mean& operator << (double a) const;
    
    //funkcja zwraca nazwe typu sredniej obiektu dla ktorego jest wywolana
    virtual std::string get_type() const { return ""; } 
    
    //funkcja zwraca obliczona wartosc sredniej
    virtual double result() const { return 0; }
    
    virtual ~Mean() {}
    
    Mean(): sum(0), amount(0) {}
    
    int get_amount() const { return amount; }
    
    float get_sum() const { return sum; }
    
    //dodaje liczbe do sumy i aktualizuje ilosc skladowych powiekszajac je o 1
    void add_to_sum( float );
    
    // funkcja przywraca wartosci startowe obiektu sredniej 
    void reset();
    
private:
    //suma potrzebna do wyliczenia sredniej
    float sum;
    //liczba skladowych sredniej
    int amount;
};
