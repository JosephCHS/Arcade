/*
** EPITECH PROJECT, 2019
** IText.hpp
** File description:
** IText class Interface
*/

#ifndef ARCADE_INTEFACE_ITEXT_HPP
#define ARCADE_INTEFACE_ITEXT_HPP

#include <string>
#include <utility>
#include "IObject.hpp"

class IText : public IObject
{
public:
    virtual ~IText() = default;

    /*!
     *  \brief Set Text pos
     *
     *  Methode to set the text pos on the window
     *
     *  \param Pos x and y in a Vector2<int>
     */
    virtual void setPosition(const Vector2<int> &) override = 0;
    /*!
     *  \brief Get Text pos
     *
     *  Methode to get the text pos on the window
     *
     *  \return Pos x and y in a Vector2<int>
     */
    virtual const Vector2<int> &getPosition(void) const override = 0;
    /*!
     *  \brief Set Text color
     *
     *  Methode to color the text on the window
     *
     *  \param Color of letters and color of back of the text
     */
    virtual void setColor(Color text, Color back) override = 0;
    /*!
     *  \brief Set text of Text Obj
     *
     *  Methode to set the text of Text OBJ
     *
     *  \param string to set to Text Obj
     */
    virtual void setText(const std::string &text) = 0;
    /*!
     *  \brief Get text of Text Obj
     *
     *  Methode to get the text of Text OBJ
     *
     *  \return String from Text obj
     */
    virtual const std::string &getText() const = 0;
    /*!
     *  \brief Set Text size
     *
     *  Methode to set the Text size
     *
     *  \param int : size to set
     */
    virtual void setSize(int size) = 0;
    /*!
     *  \brief Get Text size
     *
     *  Methode to get the Text size
     *
     *  \return int : size to get
     */
    virtual int getSize() const = 0;
};


#endif //ARCADE_INTEFACE_ITEXT_HPP
