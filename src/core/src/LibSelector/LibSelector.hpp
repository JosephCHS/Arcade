/*
** EPITECH PROJECT, 2019
** GameSelector.hpp
** File description:
** GameSelector class definition
*/

#ifndef LIBSELECTOR_HPP_
#define LIBSELECTOR_HPP_

#include <vector>
#include <dlfcn.h>
#include <filesystem>

#include "Exception/CoreException.hpp"
#include "IFactory.hpp"

class LibSelector
{
private:
    std::vector<std::string> _names;
    std::vector<std::string> _libs;
    void * _handle = nullptr;
    IFactory *(*_creator)(void) = nullptr;
    int _libs_nbr = 0;
    int _libs_idx = 0;
    UPISprite _next = nullptr;
    UPISprite _prev = nullptr;
    UPIText _title = nullptr;
    UPIText _name = nullptr;

    void loadLibs(const std::string &);
public:
    LibSelector(const std::string &);
    ~LibSelector();

    void init(SPIFactory &, SPIWindow &);
    IFactory *getLib(void);
    void draw(SPIWindow &);
    bool canNext();
    bool canPrev();
    void nextLib();
    void prevLib();
};

#endif /* LIBSELECTOR_HPP_ */
