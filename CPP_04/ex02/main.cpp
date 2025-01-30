/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:36:55 by kadam             #+#    #+#             */
/*   Updated: 2024/12/12 17:36:55 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const int numAnimals = 10;
    Animal *animals[numAnimals];

    for (int i = 0; i < numAnimals / 2; i++)
    {
        animals[i] = new Dog();
    }
    for (int i = numAnimals / 2; i < numAnimals; i++)
    {
        animals[i] = new Cat();
    }

    for (int i = 0; i < numAnimals; i++)
    {
        animals[i]->makeSound();
    }
    for (int i = 0; i < numAnimals; i++)
    {
        delete animals[i];
    }
    return 0;
}
