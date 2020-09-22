#pragma once

#include "ListaString.h"
#include "Stan.h"
#include <iostream>
#include <string>
#include <vector>

STATE_TYPE( DostepneSystemy ) {
public:
	DostepneSystemy(ListaString systems)
		: m_systList(std::move(systems))
		, m_selected(0)
	{
		
	}
	
	virtual void operator()() {
		std::cout << "Program mozna uruchomic na nastepujacych systemach: " << std::endl;
		std::cout << m_systList;
		
		//std::cin >> m_selected; 
		m_selected = 1; // <- udajemy wczytywanie danych
		Stan::curr_sys = m_systList[m_selected];
		std::cout << "wybrano \'" << m_systList[m_selected] << "\'" << std::endl;
	}
	
	virtual const char* nazwa() const { 
		return "DostepneSystemy";
	}
	
	virtual void podsumowanie() const {
		std::cout << " * Wybrano system: \'" << m_systList[m_selected] << "\'" << std::endl;;
	}
	
private:
	ListaString  m_systList;
	unsigned int m_selected;
};

STATE_TYPE( ZbieranieDanych ) {
    friend class MaszynaStanow;
public:
    
    ZbieranieDanych(std::string email){}
    virtual void operator()()
    {
            std::cout <<"Prosze podac dana: Adres email = ?, ";
            Stan::email = "Nowak@mail.com";
            std::cout << "podano '" <<Stan::email <<"'\n";
    }
    virtual const char* nazwa() const{return "ZbieranieDanych"; }
    virtual void podsumowanie() const{return; }
};
STATE_TYPE( Podsumowanie )
{
public:
    virtual void operator()()
    {
        std::cout<<"Podsumowanie:\n" << " * Wybrano system: '" << Stan::curr_sys << "'\n"
        << " * Adres email = " << Stan::email << "\n";
    }
    virtual const char* nazwa() const{return "Podsumowanie"; }
    virtual void podsumowanie() const{return;}
};

STATE_TYPE( Instalacja ) {
public:
	virtual void operator()() {
		std::cout << "Instalacja w toku... " << std::endl;
		std::cout << "OK!" << std::endl;
	}
	
	virtual const char* nazwa() const { 
		return "Instalacja";
	}
	
	virtual void podsumowanie() const {
		return;
	};
};