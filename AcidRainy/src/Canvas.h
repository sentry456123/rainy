#ifndef CANVAS_H
#define CANVAS_H


#include "SDL.h"
#include "Color.h"
#include "SDL_ttf.h"
#include "SDL_image.h"

#define FONT_PLAIN "Montserrat-Regular.otf"

enum class TextPosMode
{
	TOP_LEFT,
	TOP_MIDDLE,
	TOP_RIGHT,
	MIDDLE_LEFT,
	CENTER,
	MIDDLE_RIGHT,
	BOTTOM_LEFT,
	BOTTOM_MIDDLE,
	BOTTOM_RIGHT,
};

class Canvas
{
private:
	SDL_Renderer** renderer;
	
public:
	Canvas(SDL_Renderer** renderer);
public:
	void Clear();
	void Present();
	void SetColor(int r, int g, int b);
	void SetColor(int r, int g, int b, int a);
	void SetColor(Color color);
	void DrawRect(int x, int y, int width, int height);
	void FillRect(int x, int y, int width, int height);
	void DrawText(const char* filePath, const char* text, int x, int y, int size, Color color, TextPosMode mode);
	void DrawImage(const char* filePath, int x, int y, int width, int height);
	void DrawImage(const char* filePath, int fx, int fy, int fwidth, int fheight, 
		int ix, int iy, int iwidth, int iheight);
};



#endif

