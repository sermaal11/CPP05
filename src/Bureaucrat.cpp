/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:48:15 by sergio            #+#    #+#             */
/*   Updated: 2025/10/16 12:52:02 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

// OCF

// Constructor x defecto
Bureaucrat::Bureaucrat(const std::string name, int grade)
	: _name(name), _grade(grade)
{
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

// Getters
const std::string& Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

// Grade management
void Bureaucrat::incrementGrade()
{
	_grade--;
	std::cout << _name << " has been promoted to level " << _grade << std::endl;
}

void Bureaucrat::decrementGrade()
{
	_grade++;
	std::cout << _name << " has been demoted to level " << _grade << std::endl;
}