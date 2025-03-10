/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 06:23:53 by kadam             #+#    #+#             */
/*   Updated: 2025/03/09 20:38:28 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int calculate_rpn(const std::string &args)
{
    std::string op = "+-*/";
    std::stack<int> stack;
    std::string token;
    std::istringstream ss(args);
    while (ss >> token)
    {
        if (op.find(token) != std::string::npos)
        {
            if (stack.size() < 2)
                return (std::cerr << "Error" << std::endl, 1);
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            if (token == "+")
                stack.push(b + a);
            else if (token == "-")
                stack.push(b - a);
            else if (token == "*")
                stack.push(b * a);
            else if (token == "/")
            {
                if (a == 0)
                    return (std::cerr << "Error" << std::endl, 1);
                stack.push(b / a);
            }
        }
        else
        {
            for (std::string::iterator it = token.begin(); it != token.end(); ++it)
            {
                if (!std::isdigit(*it))
                    return (std::cerr << "Error" << std::endl, 1);
            }
            std::stringstream ss(token);
            int num = 0;
            ss >> num;
            if (num >= 10)
                return (std::cerr << "Error" << std::endl, 1);
            stack.push(num);
        }
    }
    if (stack.size() != 1)
        return (std::cerr << "Error" << std::endl, 1);
    std::cout << stack.top() << std::endl;
    return 0;
}
