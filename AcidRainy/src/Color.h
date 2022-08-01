#ifndef COLOR_H
#define COLOR_H


class Color
{
public:
	int r, g, b, a;
public:
	Color(int r, int g, int b);
	Color(int r, int g, int b, int a);
};

#define COLOR_WHITE Color(0xff, 0xff, 0xff)
#define COLOR_BLACK Color(0x00, 0x00, 0x00)
#define COLOR_RED Color(0xff, 0x00, 0x00)
#define COLOR_BLUE Color(0x00, 0x00, 0xff)
#define COLOR_YELLOW Color(0x00, 0xff, 0x00)
#define COLOR_GREEN Color(0x00, 0xff, 0x00)
#define COLOR_LIGHT_GRAY Color(0xd3, 0xd3, 0xd3)
#define COLOR_GRAY Color(0x80, 0x80, 0x80)
#define COLOR_DARK_GRAY Color(0x40, 0x40, 0x40)

#endif
