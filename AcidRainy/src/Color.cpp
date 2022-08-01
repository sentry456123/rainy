#include "Color.h"

Color::Color(int r, int g, int b) :
	r(r), g(g), b(b), a(0xff)
{}

Color::Color(int r, int g, int b, int a) :
	r(r), g(g), b(b), a(a)
{}