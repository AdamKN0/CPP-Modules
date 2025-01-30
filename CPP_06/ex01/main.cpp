/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:55:41 by kadam             #+#    #+#             */
/*   Updated: 2025/01/17 11:24:59 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data data = {'a', 42, 3.14f};

    uintptr_t raw = Serializer::serialize(&data);
    Data *ptr = Serializer::deserialize(raw);

    if (ptr == &data)
        std::cout << "Deserialized pointer is the same as the original pointer" << std::endl;
    else
        std::cout << "Deserialized pointer is different from the original pointer" << std::endl;
    return 0;
}