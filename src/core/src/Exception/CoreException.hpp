/*
** EPITECH PROJECT, 2019
** CoreException.hpp
** File description:
** CoreException class definition
*/

#ifndef COREEXCEPTION_HPP_
#define COREEXCEPTION_HPP_

#include <iostream>
#include <exception>

class CoreException : public std::exception
{
private:
    const std::string _error;
public:
    CoreException(const std::string &);

    const char *what() const noexcept override;
};

#endif
