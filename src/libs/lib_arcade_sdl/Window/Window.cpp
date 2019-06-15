/*
** EPITECH PROJECT, 2019
** Window.cpp
** File description:
** Window class implementation
*/

#include <iostream>
#include "Window.hpp"

Window::Window(Vector2<int> size, const std::string &title)
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    Mix_Init(MIX_INIT_FLAC | MIX_INIT_MP3 | MIX_INIT_OGG);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
    TTF_Init();
    _EventMap[SDLK_a] = A_CASE;
    _EventMap[SDLK_b] = B_CASE;
    _EventMap[SDLK_c] = C_CASE;
    _EventMap[SDLK_d] = D_CASE;
    _EventMap[SDLK_e] = E_CASE;
    _EventMap[SDLK_f] = F_CASE;
    _EventMap[SDLK_g] = G_CASE;
    _EventMap[SDLK_h] = H_CASE;
    _EventMap[SDLK_i] = I_CASE;
    _EventMap[SDLK_j] = J_CASE;
    _EventMap[SDLK_k] = K_CASE;
    _EventMap[SDLK_l] = L_CASE;
    _EventMap[SDLK_m] = M_CASE;
    _EventMap[SDLK_n] = N_CASE;
    _EventMap[SDLK_o] = O_CASE;
    _EventMap[SDLK_p] = P_CASE;
    _EventMap[SDLK_q] = Q_CASE;
    _EventMap[SDLK_r] = R_CASE;
    _EventMap[SDLK_s] = S_CASE;
    _EventMap[SDLK_t] = T_CASE;
    _EventMap[SDLK_u] = U_CASE;
    _EventMap[SDLK_v] = V_CASE;
    _EventMap[SDLK_w] = W_CASE;
    _EventMap[SDLK_x] = X_CASE;
    _EventMap[SDLK_y] = Y_CASE;
    _EventMap[SDLK_z] = Z_CASE;
    _EventMap[SDLK_ESCAPE] = ECHAP_CASE;
    _EventMap[SDLK_TAB] = TAB_CASE;
    _EventMap[SDLK_BACKSPACE] = BACK_CASE;
    _EventMap[SDLK_RETURN] = RETURN_CASE;
    _EventMap[SDLK_SPACE] = SPACE_CASE;
    _EventMap[SDLK_RIGHT] = ARIGHT_CASE;
    _EventMap[SDLK_UP] = AUP_CASE;
    _EventMap[SDLK_DOWN] = ADOWN_CASE;
    _EventMap[SDLK_LEFT] = ALEFT_CASE;
    _EventMap[SDLK_F1] = F1_CASE;
    _EventMap[SDLK_F2] = F2_CASE;
    _EventMap[SDLK_PAGEDOWN] = PAGE_DOWN;
    _EventMap[SDLK_PAGEUP] = PAGE_UP;
    this->_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
     size.x, size.y, SDL_WINDOW_SHOWN);
    this->_renderer = SDL_CreateRenderer(this->_window, -1, 0);
}

Window::~Window()
{
    SDL_DestroyRenderer(this->_renderer);
    SDL_DestroyWindow(this->_window);
    Mix_Quit();
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}

const Vector2<int> &Window::getSize(void) const
{
    SDL_GetWindowSize(_window, &_window_size->x, &_window_size->y);
    return (*_window_size);
}

EventCase Window::getLastEvent(void)
{
    while (SDL_PollEvent(&this->_EventCase)) {
        if (this->_EventCase.type == SDL_QUIT)
            return WINDOW_CLOSE;
	if (this->_EventCase.type == SDL_KEYDOWN)
	    return this->_EventMap[this->_EventCase.key.keysym.sym];
    }
    return NO_EVENT;
}

void Window::close(void)
{
    SDL_DestroyWindow(this->_window);
}

void Window::clear(const Vector4<int> &color)
{
    SDL_SetRenderDrawColor(this->_renderer, static_cast<Uint8>(color.x), static_cast<Uint8>(color.y), 
    static_cast<Uint8>(color.w), static_cast<Uint8>(color.h));
    SDL_RenderClear(this->_renderer);
}

void Window::display(void)
{
    SDL_RenderPresent(this->_renderer);
}

void Window::correctFrameRate(void)
{
    Uint32 delay = 1000 / 60;
    static Uint32 time = 0;
    Uint32 elapsed_time = SDL_GetTicks() - time;

    if (delay > elapsed_time) {
        SDL_Delay(delay - elapsed_time);
    }
    time = SDL_GetTicks();
}

SDL_Renderer &Window::getRenderer(void)
{
    return (*this->_renderer);
}

void Window::show(ISprite &object)
{
    int x = 0;
    int y = 0;
    SDL_GetWindowSize(_window, &x, &y);
    Sprite *real = static_cast<Sprite *>(&object);
    Vector4<int> rect = real->getRect();
    Vector2<int> size = real->getSize();
    Vector2<int> pos = real->getPosition();
    SDL_Rect dstrect;
    dstrect.h = rect.h;
    dstrect.w = rect.w;
    dstrect.x = rect.x;
    dstrect.y = rect.y;
    SDL_Rect srcrect;
    if (rect.w != 0 && rect.h != 0) {
        srcrect.h = rect.h;
        srcrect.w = rect.w;
    } else {
        srcrect.h = size.y;
        srcrect.w = size.x;
    }
    srcrect.x = pos.x;
    srcrect.y = pos.y;
    if (rect.h == 0 && rect.w == 0) {
        SDL_RenderCopy(this->_renderer, &real->getSprite(), NULL, &srcrect);
    } else {
        SDL_RenderCopy(this->_renderer, &real->getSprite(), &dstrect, &srcrect);
    }
}

void Window::show(IText &object)
{
    Text *real = static_cast<Text *>(&object);
    Vector2<int> pos = real->getPosition();
    Vector2<int> size = real->get_Size();
    SDL_Rect srcrect;
    srcrect.h = real->getSize();
    srcrect.w = size.x;
    srcrect.x = pos.x;
    srcrect.y = pos.y;

    SDL_RenderCopy(this->_renderer, &real->getTextObject(), NULL, &srcrect);
}
