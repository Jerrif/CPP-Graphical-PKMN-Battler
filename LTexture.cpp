#include "LTexture.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
// #include <SDL2/SDL_ttf.h>
#include <string>
#include <iostream>

LTexture::LTexture(SDL_Renderer* r) {
// LTexture::LTexture() {
    printf("Constructor:\tLTexture\n");
    renderer = r;
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
}

LTexture::~LTexture() {
    printf("Destructor:\tLTexture\n");
    free();
}

bool LTexture::loadFromFile(std::string path) {
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

// void LTexture::render(SDL_Renderer* renderer, int x, int y, SDL_Rect* sourceRenderQuad = NULL, SDL_Rect* destRenderQuad = NULL) {
void LTexture::render(int x, int y, SDL_Rect* sourceRenderQuad, bool stretchToViewport) {
    if (mTexture == NULL || renderer == NULL) {
        printf("mTexture or mRenderer was NULL when attempting to render a sprite to screen\n");
        return;
    }

    // sets the rendering space and render to screen
    // TODO: is this inefficient? is it remaking this every time? should these be references?
    SDL_Rect destRenderQuad = {x, y, mWidth, mHeight};
    SDL_Rect temp;

    // testing a way to make sprites move off the left/top edges of the screen
    // basically, it clips the sprite (using &sourceRenderQuad) by the amount that x/y is < 0
    // NOTE: this might come back to bite me when I do anything with sprite sheets / source clipping
    if (x < 0 || y < 0) {
        if (sourceRenderQuad == NULL) {
            temp = destRenderQuad;
            sourceRenderQuad = &temp;
        }
        sourceRenderQuad->x = std::abs(x);
        sourceRenderQuad->y = std::abs(y);
    }

    // this is if you want to render only a portion of the texture (like in a sprite sheet)
    // SDL_Rect sourceRenderQuad = {x, y, mWidth, mHeight};

    if (stretchToViewport) {
        SDL_RenderCopy(renderer, mTexture, sourceRenderQuad, NULL);
    } else {
        SDL_RenderCopy(renderer, mTexture, sourceRenderQuad, &destRenderQuad);
    }

}

int LTexture::getWidth() {
    return mWidth;
}

int LTexture::getHeight() {
    return mHeight;
}

void LTexture::free() {
    if (mTexture != NULL) {
        printf("Freeing LTexture\n");
        SDL_DestroyTexture(mTexture);
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}