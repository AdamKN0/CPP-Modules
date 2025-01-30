/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:34:27 by kadam             #+#    #+#             */
/*   Updated: 2024/09/09 18:31:13 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    PhoneBook pb;
    while (1)
    {
        std::cout << "Enter a command: (ADD, SEARCH, EXIT): ";
        std::string cmd;
        std::getline(std::cin, cmd);
        ffstrtim(cmd);
        if (cmd == "ADD")
            pb.add();
        else if (cmd == "SEARCH")
            pb.search();
        else if (cmd == "EXIT" || std::cin.eof())
        {
            std::cout << std::endl << "Exiting..." << std::endl;
            break;
        }
        else
            std::cout << "Invalid command" << std::endl;
    }
}