/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:11:59 by kadam             #+#    #+#             */
/*   Updated: 2025/03/09 20:56:39 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <climits>
#include <sstream>


bool check_is_correct(int ac, char **av);
void sort_vector(std::vector<int> &v);
void sort_deque(std::deque<int> &d);
int toInt(const std::string& str);
