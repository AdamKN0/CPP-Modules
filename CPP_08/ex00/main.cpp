/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:06:06 by kadam             #+#    #+#             */
/*   Updated: 2025/01/27 10:06:06 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    std::list<int> lst;
    for (int i = 0; i < 10; i++)
        lst.push_back(i);
    try
    {
        std::list<int>::iterator it = easyfind(lst, 5);
        std::cout << *it << std::endl;
        it = easyfind(lst, 11);
        std::cout << *it << std::endl;
    }
    catch(const char *exp)
    {
        std::cout << exp << std::endl;
    }

    return 0;
}