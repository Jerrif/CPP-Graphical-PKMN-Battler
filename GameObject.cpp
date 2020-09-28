#include "GameObject.hpp"

#include <iostream>

SDL_Renderer* GameObject::renderer = NULL;

void GameObject::attachRenderer(SDL_Renderer* r) {
    std::cout << "Test Renderer before: " << renderer << "\n" << std::endl;
    renderer = r;
    std::cout << "Test Renderer after: " << renderer << "\n" << std::endl;
}

// System::~System() {
// }