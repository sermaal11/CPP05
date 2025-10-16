/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:19:12 by sergio            #+#    #+#             */
/*   Updated: 2025/10/16 23:15:14 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"


// Constructor
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	:	_name(name),
		_isSigned(false),
		_gradeToSign(gradeToSign),
		_gradeToExecute(gradeToExecute)
{
	_assertLevelInRange(_gradeToSign);
	_assertLevelInRange(_gradeToExecute);
	std::cout << GREEN << "Constructor called for " << _name << RESET << std::endl;
}

// Constructor x copia
Form::Form(const Form& other)
	:	_name(other._name),
		_isSigned(other._isSigned),
		_gradeToSign(other._gradeToSign),
		_gradeToExecute(other._gradeToExecute)
{
	std::cout << GREEN << "Copy constructor called for " << _name << RESET << std::endl;
}

// Operador de asigancion
Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return *this;
}

// Destructor x defecto
Form::~Form()
{
	std::cout << RED << "Destructor called for " << _name << RESET << std::endl;
}

// Validacion de nivel
void Form::_assertLevelInRange(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

// Getters

const std::string& Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

// Signed Form Function
void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (_isSigned)
    {
        std::cout << YELLOW << "Form " << _name << " is already signed." << RESET << std::endl;
        return;
    }
	
    if (bureaucrat.getGrade() <= _gradeToSign)
        _isSigned = true;
    else
        throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form: grade too high (must be >= 1)";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form: grade too low (must be <= 150 or insufficient to sign)";
}

// Sobrecarga operador <<
std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << "Form \"" << f.getName() << "\", signed: ";
	
	if (f.getIsSigned())
	{
		os << "yes";
	}
	else
	{
		os << "no";
	}
	os << ", grade to sign: " << f.getGradeToSign()
       << ", grade to execute: " << f.getGradeToExecute();

	return os;
}