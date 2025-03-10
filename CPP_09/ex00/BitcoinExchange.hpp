/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 06:24:06 by kadam             #+#    #+#             */
/*   Updated: 2025/03/09 06:24:07 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>
#include <cstdlib>

std::map<std::string, float> read_data_file(std::string file_name);
int check_is_decimal(std::string str, int i);
void read_input_file(std::string file_name, std::map<std::string, float> data_map);