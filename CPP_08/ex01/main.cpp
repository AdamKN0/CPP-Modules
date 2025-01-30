/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:14:53 by kadam             #+#    #+#             */
/*   Updated: 2025/01/27 10:14:53 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    try
    {
        Span sp(30);
        for (int i = 0; i < 10; i++)
            sp.addNumber(i);

        std::vector<int> tmp;
        for (int i = 10; i < 20; i++)
            tmp.push_back(i);
        sp.addNumber(tmp);
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    }
    catch (const char *exp)
    {
        std::cout << exp << std::endl;
    }
    return 0;
}