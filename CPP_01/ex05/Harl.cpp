/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:05:48 by kadam             #+#    #+#             */
/*   Updated: 2024/10/26 13:37:02 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
    std::cout << "Harl constructor" << std::endl;
}

Harl::~Harl(void)
{
    std::cout << "Harl destructor" << std::endl;
}

void Harl::debug(void)
{
    std::cout << "DEBUG" << std::endl;
}
void Harl::info(void)
{
    std::cout << "INFO" << std::endl;
}
void Harl::warning(void)
{
    std::cout << "WARNING" << std::endl;
}
void Harl::error(void)
{
    std::cout << "ERROR" << std::endl;
}

void Harl::complain(std::string level)
{
    void (Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    for (; i < 4 && level != levels[i]; i++);
    if (i < 4)
    {
        (this->*f[i])();
        return;
    }
    std::cout << "Invalid level" << std::endl;
}
