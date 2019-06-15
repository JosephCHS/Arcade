/*
** EPITECH PROJECT, 2019
** Clock.hpp
** File description:
** Clock class Interface
*/

#ifndef ARCADE_INTEFACE_ICLOCK_HPP
#define ARCADE_INTEFACE_ICLOCK_HPP

#include <cstdint>
#include <ctime>


/*
 * \class IClock
 * 
 * \brief class to create and control a clock, the time is negative
 * 
 */
class IClock
{
public:
    virtual ~IClock() = default;
/*
 * \method resume
 * 
 * \brief resume the clock
 * 
 */
    virtual void resume() = 0;
/*
 * \method pause
 * 
 * \brief pause the clock
 * 
 */
    virtual void pause() = 0;
/*
 * \method getTime
 * 
 * \brief get the time (which is negative)
 * 
 */
    virtual clock_t getTime() = 0;
};


#endif //ARCADE_INTEFACE_ICLOCK_HPP
