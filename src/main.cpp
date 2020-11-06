#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "globprops.hpp"
#include "game.hpp"
#include "player.hpp"
#include "start_scenario.hpp"
#include "gui_btn.hpp"
#include "arc.h"

int main( int argc, char* args[] )
{
	if(!initSubsystems())
        return 0;

	SDL_Window *window = createWindow("Fase de Teste");	
    SDL_Renderer *ren = createRenderer(window);

    std::string fontPath = resPath +"fonts/LatoRegular.ttf"; 
    TTF_Font *pFont = TTF_OpenFont(fontPath.c_str(), 30);

    std::string teste = "TEEEESTE";
    Btn button = Btn(teste, {10, 10}, pFont, {200,50,50}, ren);
    button.setPadding(30, 5);
    StartScenario startScenario(ren);
    Player player(resPath + "image.bmp", ren, 10, 10);
    startScenario.gameObjects.push_back(player);

    SDL_Event e;
    bool quit_game = false;
    // SDL_SetRenderDrawBlendMode(ren, SDL_BLENDMODE_BLEND);

    Arc arco = Arc({90, 90} , 40);
    Uint8 r,g,b,a; 

    while(!quit_game){
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 ){
            if(e.type == SDL_QUIT){
                quit_game = true;
                break;
            }
            else{
                startScenario.handleEvent(e);
            }
        }

        SDL_RenderClear(ren);
        // startScenario.render();
        // button.render(ren);
        SDL_GetRenderDrawColor(ren, &r, &g, &b, &a);

        SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
        arco.render(ren);
        SDL_SetRenderDrawColor(ren, r, g, b, a);

        SDL_RenderPresent(ren);
    }

	// Cleanup
    TTF_CloseFont(pFont);
    cleanupSDL(ren, window);
	return 0;
}