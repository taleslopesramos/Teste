#include "gui_btn.hpp"

Btn::Btn(std::string tex, SDL_Rect _rect, TTF_Font *font, SDL_Color color, SDL_Renderer *ren): btn_rect(_rect), tex_rect(_rect) {
    texture = loadTextTexture(tex, color, font, ren);

    SDL_QueryTexture(texture, NULL, NULL, &tex_rect.w, &tex_rect.h);

    // ajusta o padding da box do botao
    btn_rect.w = tex_rect.w + 2 * padding_x;
    btn_rect.h = tex_rect.h + 2 * padding_y;

    // centraliza o texto
    tex_rect.x += padding_x;
    tex_rect.y += padding_y;

    // ajusta o offset da sombra
    shadow_rect.x = _rect.x + shadow_offset.x;
    shadow_rect.y = _rect.y + shadow_offset.y;
    shadow_rect.w = btn_rect.w + shadow_offset.w;
    shadow_rect.h = btn_rect.h + shadow_offset.h;
}

bool Btn::isHover(){

}

bool Btn::clicked(){

}

void Btn::setPadding(int x, int y){
    padding_x = x;
    padding_y = y;

    // ajusta o padding da box do botao
    btn_rect.w = tex_rect.w + 2 * padding_x;
    btn_rect.h = tex_rect.h + 2 * padding_y;

    // centraliza o texto
    tex_rect.x = btn_rect.x + padding_x;
    tex_rect.y = btn_rect.y + padding_y;

    // Reset Shadow
    setShadowOffset(shadow_offset);
}

void Btn::setShadowOffset(SDL_Rect offset){
    shadow_offset.x = offset.x;
    shadow_offset.y = offset.y;
    shadow_offset.w = offset.w;
    shadow_offset.h = offset.h;

    shadow_rect.x = btn_rect.x + shadow_offset.x;
    shadow_rect.y = btn_rect.y + shadow_offset.y;
    shadow_rect.w = btn_rect.w + shadow_offset.w;
    shadow_rect.h = btn_rect.h + shadow_offset.h;
}

void Btn::render(SDL_Renderer *ren){
    Uint8 r, g, b, a;
    SDL_GetRenderDrawColor(ren, &r, &g, &b, &a);
    
    SDL_SetRenderDrawColor(ren, 70, 70, 70, 180);
    SDL_RenderFillRect(ren, &shadow_rect);

    SDL_SetRenderDrawColor(ren, 202, 202, 202, 255);
    SDL_RenderFillRect(ren, &btn_rect);

    SDL_RenderCopy(ren, texture, NULL, &tex_rect);

    SDL_SetRenderDrawColor(ren, r, g, b, a);
}

Btn::~Btn(){
    SDL_DestroyTexture(texture);
}