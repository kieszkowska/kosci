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
        std::cout << "Błąd fonta";
    }
    this->surf = TTF_RenderUTF8_Blended(this->font, text.c_str(), this->color);
    this->tex = SDL_CreateTextureFromSurface(ren, this->surf);
    SDL_QueryTexture(tex, NULL, NULL, &rect.w, &rect.h);
    rect.x = pos.x;
    rect.y = pos.y;
    SDL_RenderCopy(this->ren, this->tex, NULL, &rect);
    return rect;
}

SDL_Rect WriteText::writeSecondary(std::string text, SDL_Point pos)
{
    SDL_Rect rect;
    if (font == nullptr) {
        std::cout << "Błąd fonta";
    }
    this->surf = TTF_RenderUTF8_Blended(this->font, text.c_str(), this->colorSecondary);
    this->tex = SDL_CreateTextureFromSurface(ren, this->surf);
    SDL_QueryTexture(tex, NULL, NULL, &rect.w, &rect.h);
    rect.x = pos.x;
    rect.y = pos.y;
    SDL_RenderCopy(this->ren, this->tex, NULL, &rect);
    return rect;
}
