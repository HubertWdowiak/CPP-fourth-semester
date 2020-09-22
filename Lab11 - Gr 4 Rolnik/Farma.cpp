#include "Farma.h"

void Farma::dodaj(std::unique_ptr<Zwierz> new_ptr)
{
    zwierzeta.push_back(std::move(new_ptr));
}

void Farma::wypisz(std::string tekst) const
{
    std::cout << "-- " << tekst << " --" << std::endl;
    for(const auto &z : zwierzeta)
    {
        z->opisz();
    }
}

int Farma::zliczImie(std::string imie) const
{
    int ilosc = 0;
    for(const auto &z: zwierzeta)
    {
        if(z->imie() == imie)
            ilosc++;
    }
    return ilosc;
}

void Farma::statystykaImion() const
{
    std::vector< std::string > unique;
    for(auto &z: zwierzeta)
    {
        auto found = std::find(unique.begin(), unique.end(), z->imie());
        if(found == unique.end())
            unique.push_back(z->imie());
    
    }
    std::sort(unique.begin(), unique.end());
    for(auto &name: unique)
    {
        std::cout << name << ": " << zliczImie(name) << std::endl;
    }
}

std::vector<Owca*> Farma::wyprowadzOwce() const
{
    std::vector<Owca*> stado;
    for(auto &z: zwierzeta)
    {
        if(typeid(*z).name() == typeid(Owca).name())
        {
            Owca* nowa_owca = dynamic_cast< Owca* >(z.get());
            stado.push_back(nowa_owca);
        }
    }
    return stado;
}