#pragma once

//class contains options of format, which may be chosen to format text
class AttFormat
{
public:

    enum Attribute
    {
        BOLD = 0,
    	DIM = 1,
    	UNDERLINED = 2,
    	NORMAL = 3
    };
    
    AttFormat(Attribute format): m_format(format) {};
    AttFormat::Attribute getFormat() const{ return m_format; }
    void setFormat(AttFormat::Attribute format) { m_format = format; }

protected:
    //chosen format type
    AttFormat::Attribute m_format;
};
