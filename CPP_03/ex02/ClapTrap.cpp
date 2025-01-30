/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 22:47:26 by kadam             #+#    #+#             */
/*   Updated: 2024/11/24 03:16:24 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    _name = "ClapTrap_Default";
    _hitpoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
    std::cout << "ClapTrap default " << _name << " is created." << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
{
    _name = name;
    _hitpoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
    std::cout << "ClapTrap " << _name << " is created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    _name = other._name;
    _hitpoints = other._hitpoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    std::cout << "ClapTrap " << _name << " is copied." << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " is destroyed." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    _name = other._name;
    _hitpoints = other._hitpoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    std::cout << "ClapTrap " << _name << " is assigned." << std::endl;
    return *this;
}

void ClapTrap::attack(const std::string &target)
{
    if (_energyPoints <= 0 || _hitpoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " can't attack. No energy or hitpoints left." << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    _hitpoints -= amount;
    if (_hitpoints < 0)
        _hitpoints = 0;
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage. Remaining hitpoints: " << _hitpoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints <= 0 || _hitpoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " can't be repaired. No energy or hitpoints left." << std::endl;
        return;
    }
    _hitpoints += amount;
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " is repaired by " << amount << " points. New hitpoints: " << _hitpoints << std::endl;
}
