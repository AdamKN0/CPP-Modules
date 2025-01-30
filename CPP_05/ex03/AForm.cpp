/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:20:02 by kadam             #+#    #+#             */
/*   Updated: 2025/01/13 13:49:51 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Form Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Form Grade too low";
}

AForm::AForm() : name("default"), is_signed(false), grade_to_sign(150), grade_to_execute(150), target("default")
{
    std::cout << "Form Default constructor called" << std::endl;
}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_execute , std::string target) : name(name), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute), target(target)
{
    if (grade_to_sign < 1 || grade_to_execute < 1)
        throw GradeTooHighException();
    else if (grade_to_sign > 150 || grade_to_execute > 150)
        throw GradeTooLowException();
    this->is_signed = false;
    std::cout << "Form Parametric constructor called" << std::endl;
}

AForm::~AForm()
{
    std::cout << "Form Destructor called" << std::endl;
}

AForm::AForm(const AForm &other) : name(other.name), is_signed(other.is_signed), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute)
{
    std::cout << "Form Copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
    std::cout << "Form Assignation operator called" << std::endl;
    if (this == &other)
        return *this;
    this->is_signed = other.is_signed;
    return *this;
}

std::string AForm::getName() const
{
    return this->name;
}

std::string AForm::getTarget() const
{
    return this->target;
}

bool AForm::getIsSigned() const
{
    return this->is_signed;
}

int AForm::getGradeToSign() const
{
    return this->grade_to_sign;
}

int AForm::getGradeToExecute() const
{
    return this->grade_to_execute;
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > this->grade_to_sign)
        throw GradeTooLowException();
    if (this->is_signed)
        return;
    this->is_signed = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
    out << "Form " << f.getName() << ", signed: " << (f.getIsSigned() ? "yes" : "no") << ", grade to sign: " << f.getGradeToSign() << ", grade to execute: " << f.getGradeToExecute();
    return out;
}
