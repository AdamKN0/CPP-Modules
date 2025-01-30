/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:48:50 by kadam             #+#    #+#             */
/*   Updated: 2024/09/15 19:47:53 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::add()
{
    _contact[index].set_all();
    if (index < 7)
        index++;
    else
        index = 0;
    if (count < 8)
        count++;
}

static void print_header()
{
    std::cout << std::setw(10) << "index" << "|";
    std::cout << std::setw(10) << "first name" << "|";
    std::cout << std::setw(10) << "last name" << "|";
    std::cout << std::setw(10) << "nickname" << std::endl;
}

static std::string subster_it(std::string str)
{
    if (str.length() >= 10)
        return str.substr(0, 9) + ".";
    return str;
}

static int check_is_number(std::string str)
{
    int r = 0;
    int i = 0;
    if (str.empty())
        return -1;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i + 1] && str[i + 1] >= '0' && str[i + 1] <= '9')
            i++;
        else
            return -1;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        r = r * 10 + (str[i] - '0');
        i++;
    }
    if (str[i] == '\0')
        return r;
    return -1;
}

void PhoneBook::search()
{
    if (count == 0)
    {
        std::cout << "No contacts available" << std::endl;
        return;
    }
    print_header();
    for (int i = 0; i < count; i++)
    {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << subster_it(_contact[i].get_all(0)) << "|";
        std::cout << std::setw(10) << subster_it(_contact[i].get_all(1)) << "|";
        std::cout << std::setw(10) << subster_it(_contact[i].get_all(2)) << std::endl;
    }
    std::string input;
    std::cout << "Enter index of the contact: ";
    std::getline(std::cin, input);
    if (std::cin.eof())
    {
        std::cout << std::endl << "Unexpected EOF, exiting..." << std::endl;
        exit(1);
    }
    int ind = check_is_number(input);
    if (ind >= 0 && ind < count)
    {
        std::cout << "First name: " << _contact[ind].get_all(0) << std::endl;
        std::cout << "Last name: " << _contact[ind].get_all(1) << std::endl;
        std::cout << "Nickname: " << _contact[ind].get_all(2) << std::endl;
        std::cout << "Phone number: " << _contact[ind].get_all(3) << std::endl;
        std::cout << "Darkest secret: " << _contact[ind].get_all(4) << std::endl;
    }
    else
        std::cout << "Invalid index" << std::endl;
}
