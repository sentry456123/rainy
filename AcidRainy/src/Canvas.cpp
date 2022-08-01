#include "Canvas.h"
#include <iostream>

Canvas::Canvas(SDL_Renderer** renderer) : renderer(renderer) {}

void Canvas::Clear()
{
	SDL_RenderClear(*renderer);
}

void Canvas::Present()
{
	SDL_RenderPresent(*renderer);
}

void Canvas::SetColor(int r, int g, int b)
{
	SDL_SetRenderDrawColor(*renderer, r, g, b, SDL_ALPHA_OPAQUE);
}

void Canvas::SetColor(int r, int g, int b, int a)
{
	SDL_SetRenderDrawColor(*renderer, r, g, b, a);
}

void Canvas::SetColor(Color color)
{
	SetColor(color.r, color.g, color.b, color.a);
}

void Canvas::DrawRect(int x, int y, int width, int height)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;
	SDL_RenderDrawRect(*renderer, &rect);
}

void Canvas::FillRect(int x, int y, int width, int height)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;
	SDL_RenderFillRect(*renderer, &rect);
}

void Canvas::DrawText(const char* filePath, const char* text, int x, int y, int size, Color color, TextPosMode mode)
{
	SDL_Color sdlColor = { color.r, color.g, color.b, color.a };
	TTF_Font* font = TTF_OpenFont(filePath, size);
	SDL_Surface* surface = TTF_RenderText_Blended(font, text, sdlColor);
	if (!surface)
	{
		std::cout << "Couldn't create surface from " << filePath << std::endl;
		return;
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(*renderer, surface);
	if (!texture)
	{
		std::cout << "Couldn't create texture" << std::endl;
		return;
	}
	SDL_Rect rect;
	switch (mode)
	{
	case TextPosMode::TOP_LEFT:      rect.x = x;                  rect.y = y;                  break;
	case TextPosMode::TOP_MIDDLE:    rect.x = x - surface->w / 2; rect.y = y;                  break;
	case TextPosMode::TOP_RIGHT:     rect.x = x - surface->w;     rect.y = y;                  break;
	case TextPosMode::MIDDLE_LEFT:   rect.x = x;                  rect.y = y - surface->h / 2; break;
	case TextPosMode::CENTER:        rect.x = x - surface->w / 2; rect.y = y - surface->h / 2; break;
	case TextPosMode::MIDDLE_RIGHT:  rect.x = x - surface->w;     rect.y = y - surface->h / 2; break;
	case TextPosMode::BOTTOM_LEFT:   rect.x = x;                  rect.y = y - surface->h;     break;
	case TextPosMode::BOTTOM_MIDDLE: rect.x = x - surface->w / 2; rect.y = y - surface->h;     break;
	case TextPosMode::BOTTOM_RIGHT:  rect.x = x - surface->w;     rect.y = y - surface->h;     break;
	}
	rect.w = surface->w;
	rect.h = surface->h;
	SDL_RenderCopy(*renderer, texture, nullptr, &rect);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
	TTF_CloseFont(font);
}

void Canvas::DrawImage(const char* filePath, int x, int y, int width, int height)
{
	SDL_Surface* surface = IMG_Load(filePath);
	if (!surface)
	{
		std::cout << "Couldn't create surface" << std::endl;
		return;
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(*renderer, surface);
	if (!texture)
	{
		std::cout << "Couldn't create texture" << std::endl;
		return;
	}

	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;

	SDL_RenderCopy(*renderer, texture, nullptr, &rect);

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

void Canvas::DrawImage(const char* filePath, int fx, int fy, int fwidth, int fheight, int ix, int iy, int iwidth, int iheight)
{
	SDL_Surface* surface = IMG_Load(filePath);
	if (!surface)
	{
		std::cout << "Couldn't create surface" << std::endl;
		return;
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(*renderer, surface);
	if (!texture)
	{
		std::cout << "Couldn't create texture" << std::endl;
		return;
	}

	SDL_Rect frameRect;
	frameRect.x = fx;
	frameRect.y = fy;
	frameRect.w = fwidth;
	frameRect.h = fheight;

	SDL_Rect imageRect;
	imageRect.x = ix;
	imageRect.y = iy;
	imageRect.w = iwidth;
	imageRect.h = iheight;

	SDL_RenderCopy(*renderer, texture, &frameRect, &imageRect);

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}