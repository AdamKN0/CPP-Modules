/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 06:24:10 by kadam             #+#    #+#             */
/*   Updated: 2025/03/09 06:24:11 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (std::cout << "Error: could not open file." << std::endl, 1);
    std::map<std::string, float> data_map = read_data_file("data.csv");
    read_input_file(av[1], data_map);
    return 0;
}