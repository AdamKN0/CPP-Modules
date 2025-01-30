/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:02:06 by kadam             #+#    #+#             */
/*   Updated: 2025/01/27 10:15:19 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <list>
#include <algorithm>

template <typename T>

typename T::iterator easyfind(T &container, int n)
{
    typename T::iterator it = find(container.begin(), container.end(), n);
    if (it == container.end())
        throw "Element not found";
    return it;
}