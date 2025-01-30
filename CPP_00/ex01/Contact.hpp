/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:39:08 by kadam             #+#    #+#             */
/*   Updated: 2024/09/09 11:45:00 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cstdlib>

class Contact
{
private:
    std::string _fn;
    std::string _ln;
    std::string _nn;
    std::string _pn;
    std::string _ds;

public:
    void set_all();
    std::string get_all(int i);
};
void ffstrtim(std::string &str);

#endif