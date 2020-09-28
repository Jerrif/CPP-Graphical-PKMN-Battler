#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>

class LTexture {
public:
    LTexture(SDL_Renderer* r);
    // LTexture();

    ~LTexture();

    // loads image at specified path
    bool loadFromFile(std::string path);

    // renders the texture to mRenderer
    // void render(SDL_Renderer* renderer, int x, int y);
    // void render(SDL_Renderer* renderer, int x, int y, SDL_Rect* sourceRenderQuad = NULL, bool stretchToViewport = false);
    void render(int x, int y, SDL_Rect* sourceRenderQuad = NULL, bool stretchToViewport = false);

    int getWidth();
    int getHeight();

    void free();

private:
    // the actual hardware texture
    SDL_Texture* mTexture;

    SDL_Renderer* renderer = NULL;

    // image dimensions
    int mWidth;
    int mHeight;
};