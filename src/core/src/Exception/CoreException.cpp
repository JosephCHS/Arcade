/*
** EPITECH PROJECT, 2019
** CoreException.cpp
** File description:
** CoreException class implementation
*/

#include "CoreException.hpp"

CoreException::CoreException(const std::string &_msg) : _error(_msg)
{
}

const char *CoreException::what() const noexcept
{
    std::cout << "Core error : ";
    return _error.c_str();
}
