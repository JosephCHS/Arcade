#ifndef IGAME_
#define IGAME_

#include <vector>

#include "IFactory.hpp"


/*! \class IGame
 * \brief interface used to create any kind of game in our Arcade Project
 *
 *  This interface has to be inherited from all the games
 */
class IGame
{
public:
   /*!
     *  \brief Destructor
     *
     *  Destructor of the CPlayer class
     */
    virtual ~IGame() = default;
    /*!
     *  \brief Real way to init the class
     * 
     *  \param  SPIFactory factory : shared ptr, to build every graphical component
     *          SPIWindow window : shared_ptr, to store the window object 
     * 
     *  \return void
     */
    virtual void init(SPIFactory factory, SPIWindow window) = 0;
    /*!
     *  \brief Run the Game
     * 
     *  All the game's private method are call here to let the core make a loop and use 
     *  it inside the core's loop
     * 
     *  \param  EventCase e: give the last event, the last key pressed
     * 
     *  \return int : return the score for the storage of the highscore
     */
    virtual int run(EventCase e) = 0;
    /*!
     *  \brief reset the game
     *
     * Use the key "r" to reset the game during your game
     *
     */
    virtual void reset() = 0;
    /*!
     *  \brief Return the state of the game
     * 
     *  Method used by the core to cancel and leave the game if the game is over
     * 
     *  \return bool : false => game over, true => continue the loop
     */
    virtual bool gameOver() const = 0;
};

typedef std::shared_ptr<IGame> SPIGame;

#endif // IGAME_
