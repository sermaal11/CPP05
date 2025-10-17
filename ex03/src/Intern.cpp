/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:27:36 by sergio            #+#    #+#             */
/*   Updated: 2025/10/17 13:37:58 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

// --- OCF ---
Intern::Intern() {}

Intern::Intern(const Intern& other) 
{ 
	(void)other; 
}

Intern& Intern::operator=(const Intern& other) 
{ 
	(void)other; 
	return *this; 
}

Intern::~Intern() {}

// --- Creadores auxiliares ---
AForm* Intern::_createShrubbery(const std::string& target) 
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::_createRobotomy(const std::string& target) 
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::_createPresidential(const std::string& target) 
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
    // Tabla de nombres que reconoce el Intern
    const std::string names[3] = 
	{
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    // Tabla paralela de punteros a funciones que crean los formularios
    AForm* (*creators[3])(const std::string& target) = 
	{
        &_createShrubbery,
        &_createRobotomy,
        &_createPresidential
    };

    // Búsqueda del nombre solicitado
    for (int i = 0; i < 3; ++i)
    {
        if (formName == names[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return creators[i](target);
        }
    }

    std::cout << "Intern couldn't find the form: " << formName << std::endl;
    return NULL;
}