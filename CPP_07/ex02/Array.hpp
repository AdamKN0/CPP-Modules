/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:29:36 by kadam             #+#    #+#             */
/*   Updated: 2025/01/20 12:32:43 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>

class Array
{
private:
    T *elements;
    unsigned int size;

public:
    Array() : elements(NULL), size(0)
    {
        std::cout << "Array Default Constructor" << std::endl;
    }

    Array(unsigned int n) : size(n)
    {
        elements = new T[n]();
        std::cout << "Array Parameterized Constructor" << std::endl;
    }

    ~Array()
    {
        delete[] elements;
        std::cout << "Array Destructor" << std::endl;
    }

    Array(const Array &other) : size(other.size)
    {
        elements = new T[other.size];
        for (unsigned int i = 0; i < size; i++)
            elements[i] = other.elements[i];
        std::cout << "Array Copy Constructor" << std::endl;
    }

    Array &operator=(const Array &other)
    {
        std::cout << "Array Assignment Operator" << std::endl;
        if (this == &other)
            return *this;
        delete[] elements;
        size = other.size;
        elements = new T[other.size];
        for (unsigned int i = 0; i < size; i++)
            elements[i] = other.elements[i];
        return *this;
    }

    T &operator[](unsigned int index)
    {
        if (index >= size)
            throw "Index out of bounds";
        return elements[index];
    }

    const T &operator[](unsigned int index) const
    {
        if (index >= size)
            throw "Index out of bounds";
        return elements[index];
    }

    unsigned int length() const
    {
        return size;
    }
};
