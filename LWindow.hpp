#pragma once

#include <SDL2/SDL.h>

class LWindow {
    public:
    //constructor
    LWindow(const int screenWidth, const int screenHeight);

    // I think this should just be in the constructor?
    bool init();

    // this will handle winow events such as resize?
    void handleEvent(SDL_Event& e);

    // shows window contents
    void render();

    void free();

    int getWidth();
    int getHeight();

    // return the renderer associated with this window
    SDL_Renderer* getRenderer();

    bool isMinimized();
    bool isShown();

    private:
    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;
    Uint32 mWindowID;

    int mWidth;
    int mHeight;

    bool mMinimized;
    bool mShown;

    const int mSCREEN_WIDTH, mSCREEN_HEIGHT;
};