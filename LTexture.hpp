#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>

class LTexture {
public:
    // LTexture(SDL_Renderer* r);
    LTexture();

    ~LTexture();

    // loads image at specified path
    bool loadFromFile(SDL_Renderer* renderer, std::string path);

    // creates image from font string
    bool loadFromRenderedText(SDL_Renderer* renderer, std::string textureText, SDL_Color textColor, TTF_Font* font);

    // renders the texture to mRenderer
    void render(SDL_Renderer* renderer, int x, int y);

    int getWidth();
    int getHeight();

    void free();

private:
    // the actual hardware texture
    SDL_Texture* mTexture;

    // SDL_Renderer* mRenderer;

    // image dimensions
    int mWidth;
    int mHeight;
};