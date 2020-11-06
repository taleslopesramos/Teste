#ifndef _SCENARIO_H
#define _SCENARIO_H

#include <vector>
#include <stack>
#include <SDL2/SDL.h>
#include "game_object.hpp"

struct Scenario
{
    SDL_Renderer *renderer;
    std::vector<GameObject> gameObjects;

    Scenario(SDL_Renderer *_renderer):renderer(_renderer) {}

    Scenario(SDL_Renderer *_renderer, std::vector<GameObject> objects): 
    renderer(_renderer), gameObjects(objects) {}

    virtual void render();
    virtual void update();

    virtual void handleEvent(SDL_Event &e);
};


#endif