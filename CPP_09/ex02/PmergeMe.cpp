/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:14:13 by kadam             #+#    #+#             */
/*   Updated: 2025/03/09 22:48:03 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int toInt(const std::string &str)
{
    std::stringstream ss(str);
    int value;
    ss >> value;
    return value;
}

bool check_is_correct(int ac, char **av)
{
    if (ac <= 1)
        return false;
    for (int i = 1; i < ac; ++i)
    {
        std::string str = av[i];
        if (str.empty())
            return false;
        for (std::string::iterator it = str.begin(); it != str.end(); ++it)
        {
            if (!std::isdigit(*it))
                return false;
        }
        if (toInt(str) > INT_MAX)
            return false;
    }
    return true;
}

void sa_vec(std::vector<int> &v)
{
    if (v.size() >= 2 && v[0] > v[1])
    {
        std::swap(v[0], v[1]);
    }
}

void sa_deq(std::deque<int> &d)
{
    if (d.size() >= 2 && d[0] > d[1])
    {
        std::swap(d[0], d[1]);
    }
}

void sort_vector(std::vector<int> &v)
{
    size_t jacobsthal[20] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};
    std::vector<int> Small_V;
    size_t size = v.size();
    if (size == 3)
    {
        Small_V.push_back(v[2]);
        v.erase(v.begin() + 2);
        sa_vec(v);
        size--;
    }
    else if (size <= 2)
    {
        sa_vec(v);
        return;
    }
    for (size_t i = 0; i < size - 1; i += 2)
    {
        if (v[i] > v[i + 1])
        {
            Small_V.push_back(v[i + 1]);
            v.erase(v.begin() + i + 1);
        }
        else
        {
            Small_V.push_back(v[i]);
            v.erase(v.begin() + i);
        }
        size--;
    }
    sort_vector(v);
    size_t size_Small = Small_V.size();
    for (size_t i = 0; i < 20; i++)
    {
        if (jacobsthal[i] < size_Small)
        {
            std::vector<int>::iterator low = std::lower_bound(v.begin(), v.end(), Small_V[jacobsthal[i]]);
            v.insert(low, Small_V[jacobsthal[i]]);
            Small_V[jacobsthal[i]] = -10;
        }
        else
            break;
    }
    for (std::vector<int>::iterator it = Small_V.begin(); it != Small_V.end(); ++it)
    {
        if (*it == -10)
            continue;
        std::vector<int>::iterator low = std::lower_bound(v.begin(), v.end(), *it);
        v.insert(low, *it);
    }
}

void sort_deque(std::deque<int> &d)
{
    std::deque<int> Small_D;
    size_t size = d.size();
    size_t jacobsthal[20] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};
    if (size == 3)
    {
        Small_D.push_back(d[2]);
        d.erase(d.begin() + 2);
        sa_deq(d);
        size--;
    }
    else if (size <= 2)
    {
        sa_deq(d);
        return;
    }
    for (size_t i = 0; i < size - 1; i += 2)
    {
        if (d[i] > d[i + 1])
        {
            Small_D.push_back(d[i + 1]);
            d.erase(d.begin() + i + 1);
        }
        else
        {
            Small_D.push_back(d[i]);
            d.erase(d.begin() + i);
        }
        size--;
    }
    sort_deque(d);
    size_t size_Small = Small_D.size();
    for (size_t i = 0; i < 20; i++)
    {
        if (jacobsthal[i] < size_Small)
        {
            std::deque<int>::iterator low = std::lower_bound(d.begin(), d.end(), Small_D[jacobsthal[i]]);
            d.insert(low, Small_D[jacobsthal[i]]);
            Small_D[jacobsthal[i]] = -10;
        }
        else
            break;
    }
    for (std::deque<int>::iterator it = Small_D.begin(); it != Small_D.end(); ++it)
    {
        if (*it == -10)
            continue;
        std::deque<int>::iterator low = std::lower_bound(d.begin(), d.end(), *it);
        d.insert(low, *it);
    }
}
