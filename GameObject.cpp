#include "GameObject.hpp"
#include "LTexture.hpp"

#include <iostream>
#include <cassert>

SDL_Renderer* GameObject::renderer = NULL;

// System::~System() {
// }

void GameObject::attachRenderer(SDL_Renderer* r) {
    std::cout << "Test Renderer before: " << renderer << "\n" << std::endl;
    renderer = r;
    std::cout << "Test Renderer after: " << renderer << "\n" << std::endl;
}

void GameObject::render(int x, int y, SDL_Rect* sourceRenderQuad, bool stretchToViewport) {
    // assert(renderTexture != NULL);
    renderTexture->render(x, y, sourceRenderQuad, stretchToViewport);
}