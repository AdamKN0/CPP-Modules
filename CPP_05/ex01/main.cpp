/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:53:02 by kadam             #+#    #+#             */
/*   Updated: 2025/01/14 15:31:21 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat b("Alice", 50);
        Form f("Form1", 100, 50);
        std::cout << f << std::endl;
        b.signForm(f);
        std::cout << f << std::endl;
    }
    catch (std::exception &exp)
    {
        std::cout << exp.what() << std::endl;
    }

    try
    {
        Bureaucrat b("Bob", 150);
        Form f("Form2", 100, 50);
        std::cout << f << std::endl;
        b.signForm(f);
        std::cout << f << std::endl;
    }
    catch (std::exception &exp)
    {
        std::cout << exp.what() << std::endl;
    }

    return 0;
}
