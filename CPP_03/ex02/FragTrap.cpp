/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 03:09:13 by kadam             #+#    #+#             */
/*   Updated: 2024/11/24 03:18:49 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    _name = "FragTrap_Default";
    _hitpoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap default " << _name << " is created." << std::endl;
}

FragTrap::FragTrap(const std::string &name)
{
    _name = name;
    _hitpoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " is created." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
{
    _name = other._name;
    _hitpoints = other._hitpoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    std::cout << "FragTrap " << _name << " is copied." << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << _name << " is destroyed." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    _name = other._name;
    _hitpoints = other._hitpoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    std::cout << "FragTrap " << _name << " is assigned." << std::endl;
    return *this;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << _name << " is requesting a high five!" << std::endl;
}
