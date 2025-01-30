/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:03:59 by kadam             #+#    #+#             */
/*   Updated: 2024/10/26 14:47:21 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (std::cout << "Invalid number of arguments" << std::endl, 1);
    Harl harl;
    harl.complain(av[1]);
    return 0;
}
