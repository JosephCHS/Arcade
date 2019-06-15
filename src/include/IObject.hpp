/*
** EPITECH PROJECT, 2019
** IObject.hpp
** File description:
** IObject class Interface
*/

#ifndef ARCADE_INTEFACE_IOBJECT_HPP
#define ARCADE_INTEFACE_IOBJECT_HPP


#include <utility>
#include "Vector.hpp"
#include "Color.hpp"

class IObject
{
public:
    /*!
     *  \brief Set Obj pos
     *
     *  Methode to set the obj pos on the window
     *
     *  \param Pos x and y in a Vector2<int>
     */
    virtual void setPosition(const Vector2<int> &pos) = 0;
     /*!
     *  \brief Get Obj pos
     *
     *  Methode to get the obj pos on the window
     *
     *  \return Pos x and y in a Vector2<int>
     */
    virtual const Vector2<int> &getPosition() const = 0;
    /*!
     *  \brief Set Obj color
     *
     *  Methode to color the obj on the window
     *
     *  \return Color of obj, color of back of obj
     */
    virtual void setColor(Color text, Color back) = 0;
};


#endif //ARCADE_INTEFACE_IOBJECT_HPP
