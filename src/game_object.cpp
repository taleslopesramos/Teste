#include "game_object.hpp"

GameObject::GameObject(std::string imagePath, SDL_Renderer *render, int x, int y) {
    texture = loadTexture(imagePath, render);
    dst.x = x;
    dst.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
}

GameObject::GameObject(std::string imagePath, SDL_Renderer *render, SDL_Rect newPos) {
    texture = loadTexture(imagePath, render);
    dst.x = newPos.x;
    dst.y = newPos.y;
    SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);    
}

GameObject::~GameObject() {
    SDL_DestroyTexture(texture);
}

bool GameObject::render(SDL_Renderer *render) {
    return SDL_RenderCopy(render, texture, NULL, &dst);
}