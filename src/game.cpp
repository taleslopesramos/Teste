#include "game.hpp"
#include "globprops.hpp"

bool initSubsystems(){
    if( SDL_Init( SDL_INIT_VIDEO ) != 0 )
	{
	    logSDLError(std::cout, "SDL_Init");
        return false;
	}

    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG){
        logSDLError(std::cout, "IMG_Init");
        SDL_Quit();
        return false;
    }

    if( TTF_Init() == -1 ){
        logSDLError(std::cout, "TTF_Init");
        SDL_Quit();
        return false;
    }

    return true;
}

SDL_Renderer* createRenderer(SDL_Window *win){
    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (ren == nullptr){
        logSDLError(std::cout, "SDL_CreateRenderer");
    }

    return ren;
}

SDL_Texture* loadTexture(std::string imagePath, SDL_Renderer *ren){
    SDL_Texture *tex = IMG_LoadTexture(ren, imagePath.c_str());
    
    if (tex == nullptr){
        logSDLError(std::cout, "LoadTexture");
    }

    return tex;
}

void logSDLError(std::ostream &os, const std::string &msg){
	os << msg << " error: " << SDL_GetError() << std::endl;
}

void cleanupSDL(SDL_Renderer *ren, SDL_Window *window){
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(window);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

SDL_Window* createWindow(const char *title){
	SDL_Window *window = NULL;	

    window = SDL_CreateWindow(
        title, 
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN 
    );

    if (window == nullptr){
        logSDLError(std::cout, "SDL_CreateWindow");
    }

    return window;
}

SDL_Texture* loadTextTexture(std::string text, SDL_Color color, TTF_Font *font, SDL_Renderer *ren){
    SDL_Surface* textSurface = TTF_RenderText_Solid( font, text.c_str(), color);
    if( textSurface == NULL )
    {
        logSDLError(std::cout, "TTF_RenderText_Solid");
        SDL_Quit();
        return nullptr;
    }

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(ren, textSurface);

    if(textTexture == NULL){
        logSDLError(std::cout, "SDL_CreateTextureFromSurface");
        SDL_FreeSurface( textSurface );
        SDL_Quit();
        return nullptr;
    }

    return textTexture;
}