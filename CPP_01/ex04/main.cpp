/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:58:12 by kadam             #+#    #+#             */
/*   Updated: 2024/10/26 13:32:38 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    if (ac != 4)
        return (std::cout << "Invalid number of arguments" << std::endl, 1);
    std::string file_name = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    if (s1.length() == 0)
        return (std::cout << "s1 cannot be an empty string" << std::endl, 1);
    std::ifstream file(file_name.c_str());
    if (!file.is_open())
        return (std::cout << "File not found" << std::endl, 1);
    std::ofstream new_file((file_name + ".replace").c_str());
    if (!new_file.is_open())
        return (std::cout << "Error creating the new file" << std::endl, 1);
    std::string line;
    while (getline(file, line))
    {
        std::size_t position = 0;
        while ((position = line.find(s1, position)) != std::string::npos)
        {
            new_file << line.substr(0, position) << s2;
            position += s1.length();
            line = line.substr(position);
            position = 0;
        }
        new_file << line << std::endl;
    }
    file.close();
    new_file.close();
    return 0;
}
