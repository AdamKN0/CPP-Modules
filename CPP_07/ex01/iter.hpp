/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:05:11 by kadam             #+#    #+#             */
/*   Updated: 2025/01/20 12:15:27 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T,typename F>

void iter(T *array, int length, F func)
{
    for (int i = 0; i < length; i++)
        func(array[i]);
}

template <typename T>

void print(T n)
{
    std::cout << n << std::endl;
}
