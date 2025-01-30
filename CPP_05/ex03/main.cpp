/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:53:02 by kadam             #+#    #+#             */
/*   Updated: 2025/01/14 16:57:34 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        Intern intern;
        
        AForm *shrubbery = intern.makeForm("shrubbery creation", "home");
        AForm *robotomy = intern.makeForm("robotomy request", "Bender");
        AForm *pardon = intern.makeForm("presidential pardon", "Ford Prefect");
        if (shrubbery)
        {
            shrubbery->beSigned(Bureaucrat("Bob", 1));
            shrubbery->execute(Bureaucrat("Bob", 1));
            delete shrubbery;
        }
        if (robotomy)
        {
            robotomy->beSigned(Bureaucrat("Bob", 1));
            robotomy->execute(Bureaucrat("Bob", 1));
            delete robotomy;
        }
        if (pardon)
        {
            pardon->beSigned(Bureaucrat("Bob", 1));
            pardon->execute(Bureaucrat("Bob", 1));
            delete pardon;
        }
        
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
