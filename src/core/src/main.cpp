/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
** main of arcade
*/

#include <iostream>
#include "Arcade/Arcade.hpp"

int usage(char *binary)
{
    std::cout << "Usage : " << binary << " [graphical lib]" << std::endl << std::endl;
    std::cout << "\tExemple : " << binary << " ./lib/lib_arcade_sfml.so" << std::endl;
    std::cout << std::endl;
    std::cout << "The program will search for a \"games\" and a \"lib\" directory."; 
    std::cout << " Be sure to have both." << std::endl;
    return 84;
}

int main(int ac, char **av)
{
    if (ac != 2 || !std::filesystem::exists("./games") || !std::filesystem::exists("./lib"))
	return usage(av[0]);
    try {
	Arcade sys(av[1]);
	sys.start();
    } catch (std::exception &e) {
	std::cerr << e.what() << std::endl;
	return usage(av[0]);
    }
    return 0;
}
