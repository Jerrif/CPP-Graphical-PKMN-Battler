#pragma once

#include <SDL2/SDL.h>

#include <cassert>

// forward declare LTexture ?
class LTexture;

class GameObject {
public:
    // GameObject();
    // virtual ~GameObject();

    void attachRenderer(SDL_Renderer* r);
    void render(int x, int y, SDL_Rect* sourceRenderQuad = NULL, bool stretchToViewport = false);

protected:
    static SDL_Renderer* renderer;
    LTexture* renderTexture = NULL;
};