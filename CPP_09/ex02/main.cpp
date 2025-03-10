/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:14:10 by kadam             #+#    #+#             */
/*   Updated: 2025/03/09 20:57:08 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (!check_is_correct(ac, av))
        return (std::cerr << "Error" << std::endl, 1);
    std::vector<int> v;
    std::deque<int> d;
    for (int i = 1; i < ac; ++i)
    {
        v.push_back(toInt(av[i]));
        d.push_back(toInt(av[i]));
    }
    std::cout << "Before: ";
    for (int i = 1; i < ac; ++i)
        std::cout << av[i] << " ";
    std::cout << std::endl;
    clock_t start = clock();
    sort_vector(v);
    clock_t end = clock();
    double vector_duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
    std::cout << "After: ";
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    start = clock();
    sort_deque(d);
    end = clock();
    double deque_duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
    std::cout << "Time to process a range of " << v.size() << " elements with std::vector: " << vector_duration << " us" << std::endl;
    std::cout << "Time to process a range of " << d.size() << " elements with std::deque: " << deque_duration << " us" << std::endl;
    return 0;
}