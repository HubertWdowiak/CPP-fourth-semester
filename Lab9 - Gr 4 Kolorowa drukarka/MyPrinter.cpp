#include "MyPrinter.h"
#include <iostream>

MyPrinter::MyPrinter(unsigned int width)
	: m_width(width) 
{

}

////////////////////////////////////////////////////////////////////////
//  Jedyna metoda klasy MyPrinter ktora powinni Panstwo modyfikowac.  //
////////////////////////////////////////////////////////////////////////
void MyPrinter::print( const MyPrintable & obj ) const
{
	int shift = (m_width - obj.getLength()) / 2;
	std::string shift_str = std::string(shift, ' ');
    MyPrintable* obj_non_const = const_cast<MyPrintable*>(&obj);
    
    AttFormat* obj_format = dynamic_cast<AttFormat*>(obj_non_const);
	if(obj_format)
	    std::cout << controlSeq(obj_format->getFormat());
	
	AttColor* obj_color = dynamic_cast<AttColor*>(obj_non_const);
	if(obj_color)
	    std::cout << controlSeq(obj_color->getColor());
	    
	 std::cout << shift_str << obj.rawString() << resetSeq() << shift_str << std::endl;
}

////////////////////////////////////////////////////////////////////////
///                                                                  ///
///          ANSI/VT100 TERMINAL OUTPUT CONTROL SEQUENCES            ///
///                                                                  ///
////////////////////////////////////////////////////////////////////////

const char * MyPrinter::resetSeq()
{
	return "\x1B[0m";
}

// formats: BOLD, DIM, UNDERLINED, NORMAL
const char * MyPrinter::controlSeq( AttFormat::Attribute opt )
{
	switch(opt)
	{
		case AttFormat::BOLD :
			return "\x1B[1m";
		case AttFormat::DIM :
			return "\x1B[2m";
		case AttFormat::UNDERLINED :
			return "\x1B[4m";
		default:
			return MyPrinter::resetSeq();
	}
}

// colors: BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, GRAY, WHITE, DEFAULT
const char * MyPrinter::controlSeq( AttColor::Attribute opt )
{
	switch(opt)
	{
		case AttColor::BLACK :
			return "\x1B[30m";
		case AttColor::RED :
			return "\x1B[31m";
		case AttColor::GREEN :
			return "\x1B[32m";
		case AttColor::YELLOW :
			return "\x1B[33m";
		case AttColor::BLUE :
			return "\x1B[34m";
		case AttColor::MAGENTA :
			return "\x1B[35m";
		case AttColor::CYAN :
			return "\x1B[36m";
		case AttColor::GRAY :
			return "\x1B[90m";
		case AttColor::WHITE  :
			return "\x1B[97m";
		default:
			return MyPrinter::resetSeq();
	}
}
