/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:15:39 by kadam             #+#    #+#             */
/*   Updated: 2025/01/27 10:49:12 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
private:
    unsigned int n;
    std::vector<int> vec;

public:
    Span();
    Span(unsigned int n);
    Span(const Span &copy);
    Span &operator=(const Span &copy);
    ~Span();
    void addNumber(int n);
    void addNumber(std::vector<int> &tmp);
    int longestSpan(void);
    int shortestSpan(void);
};
