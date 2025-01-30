/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:59:09 by kadam             #+#    #+#             */
/*   Updated: 2024/11/23 06:11:34 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    value = 0;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    value = other.value;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Assignation operator called" << std::endl;
    value = other.value;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int value)
{
    std::cout << "Int constructor called:" << std::endl;
    this->value = value * 256;
}

Fixed::Fixed(float value)
{
    std::cout << "Float constructor called:" << std::endl;
    this->value = static_cast<int>(roundf(value * 256));
}

int Fixed::toInt() const
{
    std::cout << "toInt member function called:" << std::endl;
    return value / 256;
}

float Fixed::toFloat() const
{
    std::cout << "toFloat member function called:" << std::endl;
    return static_cast<float>(value) / 256;
}

bool Fixed::operator>(const Fixed &other) const
{
    return value > other.value;
}

bool Fixed::operator<(const Fixed &other) const
{
    return value < other.value;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return value >= other.value;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return value <= other.value;
}

bool Fixed::operator==(const Fixed &other) const
{
    return value == other.value;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return value != other.value;
}

float Fixed::operator+(const Fixed &other) const
{
    return this->toFloat() + other.toFloat();
}

float Fixed::operator-(const Fixed &other) const
{
    return this->toFloat() - other.toFloat();
}

float Fixed::operator*(const Fixed &other) const
{
    return this->toFloat() * other.toFloat();
}

float Fixed::operator/(const Fixed &other) const
{
    return this->toFloat() / other.toFloat();
}

Fixed &Fixed::operator++()
{
    value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    value++;
    return temp;
}

Fixed &Fixed::operator--()
{
    value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    value--;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a <= b)
        return a;
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a <= b)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a >= b)
        return a;
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a >= b)
        return a;
    return b;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}
