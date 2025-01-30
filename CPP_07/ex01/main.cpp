/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:42:55 by kadam             #+#    #+#             */
/*   Updated: 2025/01/20 12:16:51 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};

    std::cout << "Int Array: " << std::endl;
    iter(intArray, 5, print<int>);

    std::cout << "Double Array: " << std::endl;
    iter(doubleArray, 5, print<double>);

    std::cout << "Char Array: " << std::endl;
    iter(charArray, 5, print<char>);

    return 0;
}