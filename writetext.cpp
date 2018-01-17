#include "writetext.h"

WriteText::WriteText(std::string file, int size, SDL_Renderer* ren)
{
    this->font = TTF_OpenFont(file.c_str(), size);
    this->ren = ren;
}

WriteText::~WriteText()
{
    TTF_CloseFont(this->font);
}

SDL_Rect WriteText::write(std::string text, SDL_Point pos)
{
    SDL_Rect rect;
    if (font == nullptr) {
        std::cout << "Błąd fonta" << std::endl;
    }
    SDL_Surface* surf;
    SDL_Texture* tex;
    surf = TTF_RenderUTF8_Blended(this->font, text.c_str(), this->color);
    tex = SDL_CreateTextureFromSurface(ren, surf);
    SDL_QueryTexture(tex, NULL, NULL, &rect.w, &rect.h);
    rect.x = pos.x;
    rect.y = pos.y;
    SDL_RenderCopy(this->ren, tex, NULL, &rect);
    SDL_FreeSurface(surf);
    SDL_DestroyTexture(tex);
    return rect;
}

SDL_Rect WriteText::writeSecondary(std::string text, SDL_Point pos)
{
    SDL_Rect rect;
    if (font == nullptr) {
        std::cout << "Błąd fonta" << std::endl;
    }
    SDL_Surface* surf;
    SDL_Texture* tex;
    surf = TTF_RenderUTF8_Blended(this->font, text.c_str(), this->colorSecondary);
    tex = SDL_CreateTextureFromSurface(ren, surf);
    SDL_QueryTexture(tex, NULL, NULL, &rect.w, &rect.h);
    rect.x = pos.x;
    rect.y = pos.y;
    SDL_RenderCopy(this->ren, tex, NULL, &rect);
    SDL_FreeSurface(surf);
    SDL_DestroyTexture(tex);
    return rect;
}
