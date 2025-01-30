/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:11:04 by kadam             #+#    #+#             */
/*   Updated: 2025/01/17 11:13:03 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identify.hpp"

Base *generate(void)
{
    std::srand(std::time(0));
    int random = std::rand() % 3;
    if (random == 0)
        return new A;
    else if (random == 1)
        return new B;
    else
        return new C;
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

void identify(Base &p)
{
    try
    {
        static_cast<void>(dynamic_cast<A &>(p));
        std::cout << "A" << std::endl;
    }
    catch (const std::exception &e)
    {
        try
        {
            static_cast<void>(dynamic_cast<B &>(p));
            std::cout << "B" << std::endl;
        }
        catch (const std::exception &e)
        {
            try
            {
                static_cast<void>(dynamic_cast<C &>(p));
                std::cout << "C" << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cout << "Unknown" << std::endl;
            }
        }
    }
}
