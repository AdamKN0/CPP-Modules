/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:26:22 by kadam             #+#    #+#             */
/*   Updated: 2025/01/14 16:53:11 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &copy)
{
    std::cout << "Intern copy constructor called" << std::endl;
    *this = copy;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &copy)
{
    std::cout << "Intern assignation operator called" << std::endl;
    if (this == &copy)
        return (*this);
    return (*this);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int i = 0;
    for (; i < 3; i++)
    {
        if (formName == formNames[i])
            break;
    }
    switch (i)
    {
    case 0:
        std::cout << "Intern creates " << formName << std::endl;
        return (new ShrubberyCreationForm(target));
    case 1:
        std::cout << "Intern creates " << formName << std::endl;
        return (new RobotomyRequestForm(target));
    case 2:
        std::cout << "Intern creates " << formName << std::endl;
        return (new PresidentialPardonForm(target));
    default:
        std::cout << "Intern cannot create " << formName << " form" << std::endl;
        return (NULL);
    }
    
}
    