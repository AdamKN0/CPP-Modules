/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:58:43 by kadam             #+#    #+#             */
/*   Updated: 2025/01/16 20:24:33 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    static_cast<void>(other);
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    static_cast<void>(other);
    return (*this);
}
ScalarConverter::~ScalarConverter()
{
}

int one_char(const std::string &str)
{
    if (str.empty())
        return (std::cout << "Error : Empty string" << std::endl, 0);
    if (str.length() == 1 && !isdigit(str[0]))
    {
        if (isprint(str[0]))
            std::cout << "char : " << static_cast<char>(str[0]) << std::endl;
        else
            std::cout << "char : Non Displayable" << std::endl;
        std::cout << "int : " << static_cast<int>(str[0]) << std::endl;
        std::cout << "float : " << static_cast<float>(str[0]) << ".0f" << std::endl;
        std::cout << "double : " << static_cast<double>(str[0]) << ".0" << std::endl;
        return 0;
    }
    return 1;
}

int handle_inf_nan(const std::string &str)
{
    if (str == "nan" || str == "+nan" || str == "-nan")
    {
        std::cout << "char : impossible" << std::endl;
        std::cout << "int : impossible" << std::endl;
        if (str == "+nan" || str == "nan")
        {
            std::cout << "float : nanf" << std::endl;
            std::cout << "double : nan" << std::endl;
        }
        else
        {
            std::cout << "float : -nanf" << std::endl;
            std::cout << "double : -nan" << std::endl;
        }
        return 0;
    }
    else if (str == "inf" || str == "+inf" || str == "-inf")
    {
        std::cout << "char : impossible" << std::endl;
        std::cout << "int : impossible" << std::endl;
        if (str == "+inf" || str == "inf")
        {
            std::cout << "float : inff" << std::endl;
            std::cout << "double : inf" << std::endl;
        }
        else
        {
            std::cout << "float : -inff" << std::endl;
            std::cout << "double : -inf" << std::endl;
        }
        return 0;
    }
    return 1;
}

bool check_str(const std::string &str)
{
    int arr[3] = {0, 0, 0};
    for (size_t i = 0; str[i]; i++)
    {
        if (str[i] == '.' || str[i] == 'f' || str[i] == '-' || str[i] == '+')
        {
            if (str[i] == '.')
            {
                if (i == str.length() - 1 || i == 0)
                    return false;
                arr[0]++;
                if (arr[0] > 1)
                    return false;
            }
            else if (str[i] == 'f')
            {
                if (i == str.length() - 1)
                    arr[1]++;
                else
                    return false;
                if (arr[1] > 1)
                    return false;
            }
            else if (str[i] == '-' || str[i] == '+')
            {
                if (i == 0)
                    arr[2]++;
                else
                    return false;
                if (arr[2] > 1)
                    return false;
            }
        }
        else if (!isdigit(str[i]))
            return false;
    }
    return true;
}

void float_double(double value)
{
    std::ostringstream oss;
    oss << value;
    std::string str = oss.str();
    int dot = 0;
    for (unsigned long i = 0; str[i]; i++)
    {
        if (str[i] == '.')
            dot++;
    }
    if (dot == 0)
    {
        std::cout << "float : " << static_cast<float>(value) << ".0f" << std::endl;
        std::cout << "double : " << static_cast<double>(value) << ".0" << std::endl;
    }
    else
    {
        std::cout << "float : " << static_cast<float>(value) << "f" << std::endl;
        std::cout << "double : " << static_cast<double>(value) << std::endl;
    }
}

void ScalarConverter::convert(const std::string &str)
{
    if (one_char(str) == 0 || handle_inf_nan(str) == 0)
        return;
    if (!check_str(str))
    {
        std::cout << "Error : Invalid string" << std::endl;
        return;
    }
    try
    {
        double num = atof(str.c_str());
        if (num == 0)
            std::cout << "char: Non displayable" << std::endl;
        else
        {
            if (num > 127 || num < -128)
                std::cout << "char : impossible" << std::endl;
            else if (isprint(static_cast<char>(num)))
                std::cout << "char : " << static_cast<char>(num) << std::endl;
            else
                std::cout << "char : Non displayable" << std::endl;
        }
        if (num > 2147483647 || num < -2147483648)
            std::cout << "int : impossible" << std::endl;
        else
            std::cout << "int : " << static_cast<int>(num) << std::endl;
        float_double(num);
    }
    catch (const std::exception &exp)
    {
        std::cout << "Error: " << exp.what() << std::endl;
    }
}
