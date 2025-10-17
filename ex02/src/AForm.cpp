/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:41:45 by sergio            #+#    #+#             */
/*   Updated: 2025/10/17 11:15:13 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"

//OCF
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
	:	_name(name),
		_isSigned(false),
		_gradeToSign(gradeToSign),
		_gradeToExecute(gradeToExecute)
{
	_assertGradeInRange(_gradeToSign);
	_assertGradeInRange(_gradeToExecute);
}

AForm::AForm(const AForm& other)
	:	_name(other._name),
		_isSigned(other._isSigned),
		_gradeToSign(other._gradeToSign),
		_gradeToExecute(other._gradeToExecute)
{}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return *this;
}

AForm::~AForm() {}

//Helper
void AForm::_assertGradeInRange(int grade)
{
	if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

//Getters
const std::string& AForm::getName() const
{
	return _name;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

//Firma
void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign)
	{
		_isSigned = true;
	}
	else
	{
		throw GradeTooLowException();
	}
}

//Excepciones
const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm: grade too high (must be >= 1)";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm: grade too low (must be <= 150 or insufficient privileges)";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "AForm: cannot execute because the form is not signed";
}

//Operador <<
std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << "AForm \"" << f.getName() << "\", signed: ";
    if (f.getIsSigned())
        os << "yes";
    else
        os << "no";

    os << ", grade to sign: " << f.getGradeToSign()
       << ", grade to execute: " << f.getGradeToExecute();

    return os;
}
