#ifndef _ARC_HPP
#define _ARC_HPP
#include "point.h"
#include <SDL2/SDL.h>

struct Arc {
    Point orig;
    unsigned radius;
    Arc(Point _orig, unsigned _radius): orig(_orig), radius(_radius) {}
    void render(SDL_Renderer * renderer);
};

#endif