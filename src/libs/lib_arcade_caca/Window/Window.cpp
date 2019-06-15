/*
** EPITECH PROJECT, 2019
** Window.cpp
** File description:
** Window class implementation
*/

#include "./Window.hpp"

Window::Window(Vector2<int> size, [[maybe_unused]] const std::string &title)
{
    Vector2<int> size_tmp;

    size_tmp.x = (float)size.x / 1920.0 * 192.0;
    size_tmp.y = (float)size.y / 1080.0 * 48.0;
    _cv = caca_create_canvas((float)size.x / 1920.0 * 192.0, (float)size.y / 1080.0 * 48.0);
    _dp = caca_create_display(_cv);
    _size.x = caca_get_display_width(_dp) * 1920.0 / 192.0;
    _size.y = caca_get_display_height(_dp) * 1080.0 / 48.0;
    caca_set_display_time(_dp, 1000000.0 / 60.0);
    _EventMap[CACA_KEY_ESCAPE] = ECHAP_CASE;
    _EventMap[CACA_KEY_TAB] = TAB_CASE;
    _EventMap[CACA_KEY_BACKSPACE] = BACK_CASE;
    _EventMap[CACA_KEY_RETURN] = RETURN_CASE;
    _EventMap[CACA_KEY_RIGHT] = ARIGHT_CASE;
    _EventMap[CACA_KEY_UP] = AUP_CASE;
    _EventMap[CACA_KEY_DOWN] = ADOWN_CASE;
    _EventMap[CACA_KEY_LEFT] = ALEFT_CASE;
    _EventMap[CACA_KEY_F1] = F1_CASE;
    _EventMap[CACA_KEY_F2] = F2_CASE;
    _EventMap[CACA_KEY_PAGEDOWN] = PAGE_DOWN;
    _EventMap[CACA_KEY_PAGEUP] = PAGE_UP;
}

Window::~Window()
{
}

const Vector2<int> &Window::getSize(void) const
{
    return _size;
}

EventCase Window::getLastEvent(void)
{
    while (caca_get_event(_dp, CACA_EVENT_ANY, &_event, 0)) {
        if ((caca_get_event_type(&_event) & CACA_EVENT_QUIT)) {
            return WINDOW_CLOSE;
        }
        auto iter = _EventMap.find((caca_key)_event.data.key.ch);
        if ((caca_get_event_type(&_event) & CACA_EVENT_KEY_PRESS)) {
            if (iter != _EventMap.end()) {
                return _EventMap[(caca_key)_event.data.key.ch];
            } else {
                return (EventCase)_event.data.key.ch;
            }
        }
    }
    return NO_EVENT;
}

void Window::close(void)
{
    caca_free_display(_dp);
}

void Window::clear([[maybe_unused]] const Vector4<int> &color)
{
    caca_clear_canvas(_cv);
}

void Window::display(void)
{
    caca_refresh_display(_dp);
}

void Window::correctFrameRate(void)
{
}

void Window::show(ISprite &object)
{
    Sprite *real_spr = static_cast<Sprite *>(&object);
    Vector2<int> pos2 = real_spr->getPositionDraw();
    caca_blit(_cv, pos2.x, pos2.y, real_spr->getCanva(), NULL);
}

void Window::show(IText &object)
{
    Text *real_text = static_cast<Text *>(&object);
    Vector2<int> pos1 = real_text->getPositionDraw();
    caca_blit(_cv, pos1.x, pos1.y, real_text->getCanva(), NULL);
}

caca_canvas_t *Window::getCanva(void)
{
    return _cv;
}
