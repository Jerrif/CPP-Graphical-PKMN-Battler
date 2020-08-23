#include "LWindow.hpp"

#include <SDL2/SDL.h>
#include <string>

// constructor
LWindow::LWindow(const int screenWidth, const int screenHeight):mSCREEN_WIDTH(screenWidth), mSCREEN_HEIGHT(screenHeight) {
    mWindow = NULL;
    mMinimized = false;
    mRenderer = NULL;
    mWidth = 0;
    mHeight = 0;
    // I think the constructor should do the init stuff?
}

bool LWindow::init() {
    // I think this should just be in the constructor?
    mWindow = SDL_CreateWindow("Digimons", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mSCREEN_WIDTH, mSCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if(mWindow == NULL) {
        printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
        return false;
    }

    mWidth = mSCREEN_WIDTH;
    mHeight = mSCREEN_HEIGHT;

    // create renderer for window
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(mRenderer == NULL) {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(mWindow);
        mWindow = NULL;
        return false;
    }

    // init renderer color
    SDL_SetRenderDrawColor(mRenderer, 0xff, 0xff, 0xff, 0xff);

    // grab window identifier
    mWindowID = SDL_GetWindowID(mWindow);

    // flag as opened
    mShown = true;

    return mWindow != NULL && mRenderer != NULL;
}

SDL_Renderer* LWindow::getRenderer() {
    return mRenderer;
}

void LWindow::handleEvent(SDL_Event& e) {
    // TODO
}

void LWindow::free() {
    if( mWindow != NULL ) {
        SDL_DestroyWindow( mWindow );
    }

    mWidth = 0;
    mHeight = 0;
}

void LWindow::render() {
    if(!mMinimized) {
        // clear screen
        SDL_SetRenderDrawColor(mRenderer, 0xff, 0xff, 0xff, 0xff);
        SDL_RenderClear(mRenderer);

        // update screen
        SDL_RenderPresent(mRenderer);
    }
}

bool LWindow::isShown() {
    return mShown;
}

int LWindow::getWidth() {
    return mWidth;
}

int LWindow::getHeight() {
    return mHeight;
}

bool LWindow::isMinimized() {
    return mMinimized;
}