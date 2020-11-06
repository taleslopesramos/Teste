#ifndef __GAME_H
#define __GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

bool initSubsystems();

SDL_Renderer* createRenderer(SDL_Window *win);

SDL_Texture* loadTexture(std::string imagePath, SDL_Renderer *ren);

/**
* Log an SDL error with some error message to the output stream of our choice
* @param os The output stream to write the message to
* @param msg The error message to write, format will be msg error: SDL_GetError()
*/
void logSDLError(std::ostream &os, const std::string &msg);

/**
 * Free and clean SDL Stuff
*/
void cleanupSDL(SDL_Renderer *ren, SDL_Window *window);

/**
 * Create an SDL_window
*/
SDL_Window* createWindow(const char *title);

SDL_Texture* loadTextTexture(std::string text, SDL_Color color, TTF_Font *font, SDL_Renderer *ren);

#endif