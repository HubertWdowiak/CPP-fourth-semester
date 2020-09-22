#pragma once

//class contains options of color, which may be chosen to color text
class AttColor
{
public:
  enum Attribute
  {
    	BLACK = 0,
    	RED = 1,
        GREEN = 2,
        YELLOW = 3,
        BLUE = 4,
        MAGENTA = 5,
        CYAN = 6,
        GRAY = 7,
        WHITE = 8
    };

    AttColor(Attribute color): m_color(color) {};
    AttColor::Attribute getColor() const { return m_color; }
    void setColor(Attribute color) { m_color = color; }
  
    
protected:
    //chosen color
    AttColor::Attribute m_color;
};
