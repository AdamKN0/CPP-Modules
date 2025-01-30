/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:39:58 by kadam             #+#    #+#             */
/*   Updated: 2025/01/20 12:11:26 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>

void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>

T min(T a, T b)
{
    return (a < b ? a : b);
}

template <typename T>
T max(T a, T b) {return (a > b ? a : b);}