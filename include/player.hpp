#ifndef _PLAYER_H
#define _PLAYER_H
#include "game_object.hpp"

struct Player: public GameObject{
    int life, mana, gold;

    Player(std::string imagePath, SDL_Renderer *render, int x, int y):
    GameObject(imagePath, render, x, y){};
    
    Player(std::string imagePath, SDL_Renderer *render, SDL_Rect newPos):
    GameObject(imagePath, render, newPos){};
};
#endif