/*
** EPITECH PROJECT, 2019
** Window.hpp
** File description:
** Window class Interface
*/

#ifndef ARCADE_INTEFACE_IWINDOW_HPP
#define ARCADE_INTEFACE_IWINDOW_HPP


#include "Event.hpp"
#include "Vector.hpp"
#include "IText.hpp"
#include "ISprite.hpp"

class IWindow
{
public:
    virtual ~IWindow() = default;

    /*!
     *  \brief Return window size
     *
     *  Methode to get the window height and width
     * in a Vector2
     *
     *  \return 2 int in a Vector2
     */
    virtual const Vector2<int> &getSize() const = 0;
    /*!
     *  \brief Get last event
     *
     *  Methode to get the last event catch
     *  in an enum EventCase
     *
     *  \return Last event or
     * NO_EVENT if nothing happened
     */
    virtual EventCase getLastEvent() = 0;
    /*!
     *  \brief Close Window
     *
     *  Methode to close the window
     * in instance
     */
    virtual void close() = 0;
    /*!
     *  \brief Clear window
     *
     *  Methode to clear the display of
     * the window
     *
     *  \param Vector4 with RGBA
     */
    virtual void clear(const Vector4<int> &) = 0;
    /*!
     *  \brief Display window
     *
     *  Methode to display on the window
     *
     */
    virtual void display() = 0;
    /*!
     *  \brief Set 60FPS
     *
     *  Methode to make the window
     * runs at 60 FPS (should be call at the start of the mainloop)
     *
     */
    virtual void correctFrameRate() = 0;

    /*!
     *  \brief Set Text
     *
     *  Methode to set a text in display()
     *
     *  \param Text to set
     */
    virtual void show(IText &object) = 0;
    /*!
     *  \brief Set Sprite
     *
     *  Methode to set a sprite in display()
     *
     *  \param Sprite to set
     */
    virtual void show(ISprite &object) = 0;
};


#endif //ARCADE_INTEFACE_IWINDOW_HPP
