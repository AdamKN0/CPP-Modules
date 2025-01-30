/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 01:34:45 by kadam             #+#    #+#             */
/*   Updated: 2024/12/01 02:15:21 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    _name = "ScavTrap_Default";
    _hitpoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap default " << _name << " is created." << std::endl;
}

ScavTrap::ScavTrap(const std::string &name)
{
    _name = name;
    _hitpoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " is created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
    _name = other._name;
    _hitpoints = other._hitpoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    std::cout << "ScavTrap " << _name << " is copied." << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " is destroyed." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    _name = other._name;
    _hitpoints = other._hitpoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    std::cout << "ScavTrap " << _name << " is assigned." << std::endl;
    return *this;
}

void ScavTrap::attack(const std::string &target)
{
    if (_energyPoints <= 0 || _hitpoints <= 0)
    {
        std::cout << "ScavTrap " << _name << " can't attack. No energy or hitpoints left." << std::endl;
        return;
    }
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
}

void ScavTrap::guardGate()
{
    if (_energyPoints <= 0 || _hitpoints <= 0)
    {
        std::cout << "ScavTrap " << _name << " can't guard gate. No energy or hitpoints left." << std::endl;
        return;
    }
    std::cout << "ScavTrap " << _name << " has entered Gatekeeper mode." << std::endl;
    _energyPoints--;
}
