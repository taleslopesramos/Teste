#ifndef _GUIBTN_H
#define _GUIBTN_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include "game.hpp"

struct Btn {
    SDL_Texture *texture;

    Btn(std::string tex, SDL_Rect _rect, TTF_Font *font, SDL_Color color, SDL_Renderer *ren);
    ~Btn();

    void render(SDL_Renderer *ren);

    bool isHover();
    bool clicked();

    void setPadding(int x, int y);
    void setShadowOffset(SDL_Rect offset);

    private:
        SDL_Rect tex_rect, btn_rect, shadow_rect;
        SDL_Rect shadow_offset{-3, 3, 0, 0};
        Uint16 padding_x = 40, padding_y = 4;
};

#endif