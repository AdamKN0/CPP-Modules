/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:09:00 by kadam             #+#    #+#             */
/*   Updated: 2025/01/20 12:31:58 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    try
    {
        Array<int> arr(5);
        std::cout << "Length of arr: " << arr.length() << std::endl;
        for (unsigned int i = 0; i < arr.length(); ++i)
            arr[i] = i * 2;
        std::cout << "Values in arr: ";
        for (unsigned int i = 0; i < arr.length(); ++i)
            std::cout << arr[i] << " ";
        std::cout << std::endl;
        
        arr[5] = 10;
    }
    catch (const char *e)
    {
        std::cerr << "Exception: " << e << std::endl;
    }

    return 0;
}
