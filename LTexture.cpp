#include "LTexture.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>

// LTexture::LTexture(SDL_Renderer* r) {
LTexture::LTexture() {
    printf("LTexture constructor!\n");
    // mRenderer = r;
    mWidth = 0;
    mHeight = 0;
}

LTexture::~LTexture() {
    printf("LTexture destructor!\n");
    // free();
}

bool LTexture::loadFromFile(SDL_Renderer* renderer, std::string path) {
    // get rid of preexisting texture
    free();

    // the final texture
    SDL_Texture *newTexture = NULL;

    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL) {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
        return false;
    }

    // create texture from surface pixels
    // newTexture = SDL_CreateTextureFromSurface(mRenderer, loadedSurface);
    newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (newTexture == NULL) {
        printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        return false;
    }

    mWidth = loadedSurface->w;
    mHeight = loadedSurface->h;

    // we no longer need the surface, so free it
    SDL_FreeSurface(loadedSurface);

    // assign our texture member variable to the texture
    mTexture = newTexture;
    return mTexture != NULL;
}

bool LTexture::loadFromRenderedText(SDL_Renderer* renderer, std::string textureText, SDL_Color textColor, TTF_Font* font) {
    // TODO
    return false;
}

void LTexture::render(SDL_Renderer* renderer, int x, int y) {
    if (mTexture == NULL || renderer == NULL) {
        printf("mTexture or mRenderer was NULL when attempting to render a sprite to screen");
        return;
    }

    // sets the rendering space and render to screen
    // TODO: is this inefficient? is it remaking this every time? should these be references?
    // this is if you want to render only a portion of the texture (like in a sprite sheet)
    // SDL_Rect renderQuad = {x, y, mWidth, mHeight};

    SDL_RenderCopy(renderer, mTexture, NULL, NULL);
    // SDL_RenderCopyEx(mRenderer, mTexture, NULL, NULL, NULL, NULL, NULL);
}

int LTexture::getWidth() {
    return mWidth;
}

int LTexture::getHeight() {
    return mHeight;
}

void LTexture::free() {
    if (mTexture != NULL) {
        SDL_DestroyTexture(mTexture);
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}