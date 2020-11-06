#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include <SDL2/SDL.h>
#include <string>
#include "game.hpp"

struct GameObject {
    SDL_Texture *texture;
    SDL_Rect dst;

    GameObject(std::string imagePath, SDL_Renderer *render, int x, int y);

    GameObject(std::string imagePath, SDL_Renderer *render, SDL_Rect newPos);

    virtual ~GameObject();

    virtual bool render(SDL_Renderer *render);

    virtual void update(){};
};

#endif