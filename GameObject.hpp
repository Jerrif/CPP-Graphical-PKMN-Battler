#pragma once

#include <SDL2/SDL.h>

#include <cassert>

class GameObject {
public:
    // GameObject();
    // virtual ~GameObject();

    void attachRenderer(SDL_Renderer* r);

protected:
    static SDL_Renderer* renderer;
};