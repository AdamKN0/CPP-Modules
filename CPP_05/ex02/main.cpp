/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:53:02 by kadam             #+#    #+#             */
/*   Updated: 2025/01/14 16:54:44 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    try
    {
        Bureaucrat bob("Bob", 1);
        Bureaucrat alice("Alice", 150);

        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Ford Prefect");

        bob.signForm(shrubbery);
        bob.signForm(robotomy);
        bob.signForm(pardon);

        bob.executeForm(shrubbery);
        bob.executeForm(robotomy);
        bob.executeForm(pardon);

        alice.signForm(shrubbery);
        alice.executeForm(shrubbery);
    }
    catch (std::exception &exp)
    {
        std::cerr << "Exception: " << exp.what() << std::endl;
    }
    catch (const char *msg)
    {
        std::cout << msg << std::endl;
    }

    return 0;
}
