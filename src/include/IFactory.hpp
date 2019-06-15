/*
** EPITECH PROJECT, 2018
** IFactory.hpp
** File description:
** Factory Interface
*/

#ifndef IFACTORY_
#define IFACTORY_

#include <memory>

#include "IWindow.hpp"
#include "IText.hpp"
#include "ISprite.hpp"
#include "IMusic.hpp"
#include "IClock.hpp"

typedef std::shared_ptr<IWindow> SPIWindow;
typedef std::unique_ptr<IText> UPIText;
typedef std::unique_ptr<ISprite> UPISprite;
typedef std::unique_ptr<IMusic> UPIMusic;
typedef std::unique_ptr<IClock> UPIClock;

/*
 * \class IFactory
 * 
 * \brief Interface has to be iniherited by all the factory to create any kind of graphical object
 * 
 */
class IFactory
{
public:
    virtual ~IFactory() = default;
/*
 * \method createWindow
 * 
 * \brief create a window
 * 
 * \param  const Vector2<int> &size: value size x (width) and y (height) of the window
 *          const std::string &name: name of the window
 * 
 * \return SPIWindow, shared ptr
 * 
 */
    virtual SPIWindow    createWindow(const Vector2<int> &size, const std::string &name) = 0;
/*
 * \method createText
 * 
 * \brief create a text
 * 
 * \param   const std::string &: string to be displayed
 *          const Vector2<int> &: vector with the position of the text (x, y)
 *          const std::string &: path to the font of the text
 *          IWindow &window: window, need to be used to display the text
 * 
 *  \return UPIText, unique ptr
 * 
 */
    virtual UPIText      createText(const std::string &, const Vector2<int> &, const std::string &, IWindow &window) = 0;
/*
 * \method createSprite
 * 
 * \brief create a sprite
 * 
 * \param   const std::string &: path to the sprite
 *          const Vector2<int> &: vector with the position of the sprite (x, y)
 *          const std::string &: text to be displayed instead of the sprite for the terminal graphic lib
 *          IWindow &window: window, need to be used to display the text
 * 
 *  \return UPISprite, unique ptr
 * 
 */
    virtual UPISprite    createSprite(const std::string &, const Vector2<int> &, const std::string &, IWindow &window) = 0;
/*
 * \method createMusic
 * 
 * \brief create a music
 * 
 * \param   const std::string &: path to the music
 * 
 *  \return UPISprite, unique ptr
 * 
 */
    virtual UPIMusic     createMusic(const std::string &) = 0;
/*
 * \method createClock
 * 
 * \brief create a clock
 * 
 *  \return UPIClock, unique ptr
 * 
 */
    virtual UPIClock     createClock() = 0;
};

typedef std::shared_ptr<IFactory> SPIFactory;

#endif // IFACTORY_
