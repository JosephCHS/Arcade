/*
** EPITECH PROJECT, 2019
** ISprite.hpp
** File description:
** ISprite class Interface
*/

#ifndef ARCADE_INTEFACE_ISPRITE_HPP
#define ARCADE_INTEFACE_ISPRITE_HPP

#include <string>
#include "IObject.hpp"

class ISprite : public IObject
{
public:
    virtual ~ISprite() = default;

    /*!
     *  \brief Set Sprite pos
     *
     *  Methode to set the Sprite pos on the window
     *
     *  \param Pos x and y in a Vector2<int>
     */
    virtual void setPosition(const Vector2<int> &pos) override = 0;
    /*!
     *  \brief Get Sprite pos
     *
     *  Methode to get the Sprite pos on the window
     *
     *  \return Pos x and y in a Vector2<int>
     */
    virtual const Vector2<int> &getPosition() const override = 0;
    /*!
     *  \brief Set Sprite color
     *
     *  Methode to color the Sprite on the window
     *
     *  \param Color of the Sprite
     */
    virtual void setColor(Color Sprite, Color back) override = 0;
    
    /*!
     *  \brief Reverse the sprite
     *
     *  Methode to reverse the sprite like in a mirror
     *
     */
    virtual void reverse() = 0;
    /*!
     *  \brief Set Sprite size
     *
     *  Methode to set the Sprite size
     *
     *  \param Vector<int> : width and height
     */
    virtual void setSize(const Vector2<int> &size) = 0;
    /*!
     *  \brief Get Sprite size
     *
     *  Methode to get the Sprite size
     *
     *  \return Width and Height with Vector2<int>
     */
    virtual const Vector2<int> &getSize() const = 0;
    /*!
     *  \brief Set Sprite rect
     *
     *  Methode to set the rect of the Sprite
     *
     *  \param Vector<int> : pos x and y, width and height
     */
    virtual void setRect(const Vector4<int> &) = 0;
    /*!
     *  \brief Get Sprite rect
     *
     *  Methode to get the Sprite rect
     *
     *  \return Width, Height and pos(x, y) in Vector4<int>
     */
    virtual const Vector4<int> &getRect() const = 0;
};


#endif //ARCADE_INTEFACE_ISPRITE_HPP
