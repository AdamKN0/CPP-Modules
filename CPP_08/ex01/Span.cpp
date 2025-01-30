/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:14:50 by kadam             #+#    #+#             */
/*   Updated: 2025/01/27 10:50:40 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : n(0) {}
Span::Span(unsigned int n) : n(n) {}
Span::Span(const Span &copy) : n(copy.n), vec(copy.vec) {}
Span &Span::operator=(const Span &copy)
{
    if (this == &copy)
        return *this;
    n = copy.n;
    vec = copy.vec;
    return *this;
}
Span::~Span() {}

void Span::addNumber(int n)
{
    if (vec.size() >= this->n)
        throw "The vector is full";
    vec.push_back(n);
}

void Span::addNumber(std::vector<int> &tmp)
{
    if (vec.size() + tmp.size() > this->n)
        throw "The vector is full";
    vec.insert(vec.end(), tmp.begin(), tmp.end());
}

int Span::longestSpan(void)
{
    if (vec.size() < 2)
        throw "The vector is too short";
    std::vector<int> tmp = vec;
    std::sort(tmp.begin(), tmp.end());
    return abs(tmp.back() - tmp.front());
}

int Span::shortestSpan(void)
{
    if (vec.size() < 2)
        throw "The vector is too short";
    std::vector<int> tmp = vec;
    std::sort(tmp.begin(), tmp.end());
    int shortest = tmp[1] - tmp[0];
    int tmp_short = 0;
    for (size_t i = 2; i < tmp.size(); i++)
    {
        tmp_short = tmp[i] - tmp[i - 1];
        if (tmp_short < shortest)
            shortest = tmp_short;
    }
    return abs(shortest);
}