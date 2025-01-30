/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 22:37:37 by kadam             #+#    #+#             */
/*   Updated: 2024/12/07 09:12:10 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    FragTrap defaultFrag;
    defaultFrag.attack("enemy");
    defaultFrag.takeDamage(5);
    defaultFrag.beRepaired(3);
    defaultFrag.highFivesGuys();

    FragTrap frag("Frag");
    frag.attack("enemy");
    defaultFrag.takeDamage(5);
    defaultFrag.beRepaired(3);
    defaultFrag.highFivesGuys();

    FragTrap frag2 = frag;
    frag2.attack("enemy");
    defaultFrag.takeDamage(5);
    defaultFrag.beRepaired(3);
    defaultFrag.highFivesGuys();

    FragTrap frag3;
    frag3 = frag;
    frag3.attack("enemy");
    defaultFrag.takeDamage(5);
    defaultFrag.beRepaired(3);
    defaultFrag.highFivesGuys();

    return 0;
}