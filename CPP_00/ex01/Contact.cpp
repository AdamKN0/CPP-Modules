/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:41:56 by kadam             #+#    #+#             */
/*   Updated: 2024/09/13 10:36:48 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void ffstrtim(std::string &str)
{
    if (str.empty())
        return;
    size_t start = 0;
    size_t end = str.length();
    while (str[start] == ' ' || (str[start] >= 9 && str[start] <= 13))
        start++;
    while (str[end] == ' ' || (str[end] >= 9 && str[end] <= 13))
        end--;
    str = str.substr(start, end - start);
}

static int is_space(std::string str)
{
    int i = 0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '\0')
        return 1;
    return 0;
}

static void check_is_valid(std::string &str)
{
    while (str.empty() || is_space(str))
    {
        std::cout << "Invalid input, please enter again: ";
        getline(std::cin, str);
        if (std::cin.eof())
        {
            std::cout << std::endl << "Unexpected EOF, exiting..." << std::endl;
            exit(1);
        }
    }
    ffstrtim(str);
}

void Contact::set_all()
{
    std::cout << "Enter first name: ";
    getline(std::cin, _fn);
    if (std::cin.eof())
    {
        std::cout << std::endl<< "Unexpected EOF, exiting..." << std::endl;
        exit(1);
    }
    check_is_valid(_fn);
    std::cout << "Enter last name: ";
    getline(std::cin, _ln);
    if (std::cin.eof())
    {
        std::cout << std::endl << "Unexpected EOF, exiting..." << std::endl;
        exit(1);
    }
    check_is_valid(_ln);
    std::cout << "Enter nickname: ";
    getline(std::cin, _nn);
    if (std::cin.eof())
    {
        std::cout << std::endl << "Unexpected EOF, exiting..." << std::endl;
        exit(1);
    }
    check_is_valid(_nn);
    std::cout << "Enter phone number: ";
    getline(std::cin, _pn);
    if (std::cin.eof())
    {
        std::cout << std::endl << "Unexpected EOF, exiting..." << std::endl;
        exit(1);
    }
    check_is_valid(_pn);
    std::cout << "Enter darkest secret: ";
    getline(std::cin, _ds);
    if (std::cin.eof())
    {
        std::cout << std::endl << "Unexpected EOF, exiting..." << std::endl;
        exit(1);
    }
    check_is_valid(_ds);
}

std::string Contact::get_all(int i)
{
    if (i == 0)
        return _fn;
    else if (i == 1)
        return _ln;
    else if (i == 2)
        return _nn;
    else if (i == 3)
        return _pn;
    else
        return _ds;
}
