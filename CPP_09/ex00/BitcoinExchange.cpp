/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 06:24:02 by kadam             #+#    #+#             */
/*   Updated: 2025/03/10 03:54:44 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<std::string, float> read_data_file(std::string file_name)
{
    std::map<std::string, float> data_map;
    std::string line;
    std::ifstream file(file_name.c_str());
    if (file.is_open())
    {
        std::getline(file, line);
        while (std::getline(file, line))
        {
            std::string date;
            float price;
            std::stringstream ss(line);
            std::getline(ss, date, ',');
            ss >> price;
            data_map[date] = price;
        }
        file.close();
    }
    else
    {
        std::cout << "Error: could not open file." << std::endl;
        exit(1);
    }
    return data_map;
}

int check_is_decimal(std::string str, int i)
{
    if (i == 0)
    {
        int dot = 0;
        if (str[0] == '.' || str[str.size() - 1] == '.')
            return 0;
        for (std::string::iterator it = str.begin(); it != str.end(); ++it)
        {
            if (!std::isdigit(*it) && *it != '.')
                return 0;
            if (*it == '.')
                dot++;
        }
        if (dot > 1)
            return 0;
        if (std::atof(str.c_str()) < 0 || std::atof(str.c_str()) > 1000)
            return 0;
        return 1;
    }
    for (std::string::iterator it = str.begin(); it != str.end(); ++it)
    {
        if (!std::isdigit(*it))
            return 0;
    }
    if (i == 1)
    {
        if (std::atol(str.c_str()) < 1 || std::atol(str.c_str()) > 12)
            return 0;
    }
    else if (i == 2)
    {
        if (std::atol(str.c_str()) < 1 || std::atol(str.c_str()) > 31)
            return 0;
    }
    else if (i == -1)
    {
        if (std::atol(str.c_str()) < 1999 || std::atol(str.c_str()) > 2030)
            return 0;
    }
    return 1;
}

void read_input_file(std::string file_name, std::map<std::string, float> data_map)
{
    std::string line;
    std::ifstream file(file_name.c_str());
    if (file.is_open())
    {
        std::getline(file, line);
        if (line != "DATE | VALUE")
        {
            std::cout << "Error: The first line of the file is not 'DATE | VALUE'" << std::endl;
            exit(1);
        }
        while (std::getline(file, line))
        {
            std::string date;
            std::string price;
            std::stringstream ss(line);
            std::getline(ss, date, '|');
            ss >> price;
            date.erase(std::remove_if(date.begin(), date.end(), ::isspace), date.end());
            if (!ss.eof())
            {
                std::cout << "Error: The line has more than one '|' character" << std::endl;
                continue;    
            }            
            if (date.empty() || price.empty())
            {
                std::cout << "Error: YOU HAVE AN EMPTY DATE OR PRICE" << std::endl;
                continue;
            }
            if (!check_is_decimal(price, 0))
            {
                std::cout << "Error: The price is not a number" << std::endl;
                continue;
            }
            std::string year;
            std::string month;
            std::string day;
            std::stringstream ss_date(date);
            std::getline(ss_date, year, '-');
            std::getline(ss_date, month, '-');
            ss_date >> day;
            if (year.empty() || month.empty() || day.empty())
            {
                std::cout << "Error: YOU HAVE AN EMPTY YEAR OR MONTH OR DAY" << std::endl;
                continue;
            }
            if (!check_is_decimal(year, -1) || !check_is_decimal(month, 1) || !check_is_decimal(day, 2))
            {
                std::cout << "Error: in the date" << std::endl;
                continue;
            }
            if (std::atol(month.c_str()) == 2 && std::atol(day.c_str()) > 28)
            {
                std::cout << "Error: February has only 28 days" << std::endl;
                continue;
            }
            std::map<std::string, float>::iterator it = data_map.lower_bound(date);
            if (it == data_map.end() || it->first != date)
            {
                if (it == data_map.begin())
                {
                    std::cout << "Error: No previous date available for " << date << std::endl;
                    continue;
                }
                --it;
            }
            float pricee = it->second * std::atof(price.c_str());
            std::cout << date << " ==> " << price << " = " << pricee << std::endl;
        }
        file.close();
    }
    else
    {
        std::cout << "Error: Could not open file" << std::endl;
        exit(1);
    }
}