/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 22:37:37 by kadam             #+#    #+#             */
/*   Updated: 2024/12/07 09:10:20 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap defaultClap;
    defaultClap.attack("enemy");
    defaultClap.takeDamage(5);
    defaultClap.beRepaired(3);

    ClapTrap clap("Clap");
    clap.attack("enemy");
    clap.takeDamage(5);
    clap.beRepaired(3);

    ClapTrap clap2 = clap;
    clap2.attack("enemy");
    clap2.takeDamage(5);
    clap2.beRepaired(3);

    ClapTrap clap3;
    clap3 = clap;
    clap3.attack("enemy");
    clap3.takeDamage(5);
    clap3.beRepaired(3);

    return 0;
}
