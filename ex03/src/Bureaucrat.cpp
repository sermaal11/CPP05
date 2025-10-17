/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:10:07 by sergio            #+#    #+#             */
/*   Updated: 2025/10/17 11:22:30 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"

// OCF

// Constructor
Bureaucrat::Bureaucrat(const std::string name, int grade)
: _name(name), _grade(grade)
{
	_assertLevelInRange(grade);
	std::cout << GREEN << "Constructor called for " << _name << RESET << std::endl;
}
// Constructor x copia
Bureaucrat::Bureaucrat(const Bureaucrat& other)
: _name(other._name), _grade(other._grade)
{
	std::cout << GREEN << "Copy constructor called for " << _name << RESET << std::endl;
}

//Operador de asigancion
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		_grade = other._grade;
	}
	std::cout << GREEN << "Assigment operator called for " << _name << RESET << std::endl;
	return *this;
}

// Destructor x defecto
Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "Destructor called for " << _name << RESET << std::endl;
}

// Validacion de nivel
void Bureaucrat::_assertLevelInRange(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

// Getters
const std::string& Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

// Grade management and sign forms
void Bureaucrat::incrementGrade()
{
	_assertLevelInRange(_grade - 1);
	_grade--;
	std::cout << _name << " has been promoted to level " << _grade << std::endl;
}

void Bureaucrat::decrementGrade()
{
	_assertLevelInRange(_grade + 1);
	_grade++;
	std::cout << _name << " has been demoted to level " << _grade << std::endl;
}

void Bureaucrat::signForm(AForm& form)
{
	try
	{
		bool wasSigned = form.getIsSigned();   // guardamos el estado anterior

		form.beSigned(*this);

		// Solo imprimimos si el formulario ha cambiado de estado
		if (!wasSigned && form.getIsSigned())
			std::cout << GREEN << _name << " signed " << form.getName() << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << _name << " couldn’t sign " << form.getName()
				  << " because " << e.what() << RESET << std::endl;
	}
}
void Bureaucrat::executeForm(AForm const& form)
{
    try
    {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << _name << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

// Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat: grade too high (level < 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat: grade too low (level > 150)";
}
// Sobrecarga operador <<
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}
