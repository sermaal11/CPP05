/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:48:15 by sergio            #+#    #+#             */
/*   Updated: 2025/10/16 12:15:37 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

// OCF

// Constructor x defecto
Bureaucrat::Bureaucrat(const std::string name, int level)
	: _name(name), _level(level)
{
	std::cout << GREEN << "Constructor called for " << _name << RESET << std::endl;
}
// Constructor x copia
Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name), _level(other._level)
{
	std::cout << GREEN << "Copy constructor called for " << _name << RESET << std::endl;
}

//Operador de asigancion
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		_level = other._level;
	}
	std::cout << GREEN << "Assigment operator called for " << _name << RESET << std::endl;
	return *this;
}

// Destructor x defecto
Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "Destructor called for " << _name << RESET << std::endl;
}
