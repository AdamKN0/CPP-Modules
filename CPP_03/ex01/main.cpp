/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 22:37:37 by kadam             #+#    #+#             */
/*   Updated: 2024/12/07 09:09:59 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ScavTrap defaultScav;
    defaultScav.attack("enemy");
    defaultScav.takeDamage(5);
    defaultScav.beRepaired(3);
    defaultScav.guardGate();

    ScavTrap scav("Scav");
    scav.attack("enemy");
    scav.takeDamage(5);
    scav.beRepaired(3);
    scav.guardGate();

    ScavTrap scav2 = scav;
    scav2.attack("enemy");
    scav2.takeDamage(5);
    scav2.beRepaired(3);
    scav2.guardGate();

    ScavTrap scav3;
    scav3 = scav;
    scav3.attack("enemy");
    scav3.takeDamage(5);
    scav3.beRepaired(3);
    scav3.guardGate();

    return 0;
}
