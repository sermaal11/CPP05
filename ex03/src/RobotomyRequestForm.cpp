/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:08:43 by sergio            #+#    #+#             */
/*   Updated: 2025/10/17 12:51:25 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"

// --- OCF ---
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm(other), _target(other._target)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    (void)other; // _target es const; AForm maneja el resto; nada que reasignar
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

// --- execute ---
// Reglas: form firmado y executor.grade <= getGradeToExecute().
// Efecto: imprime ruidos y resultado 50% éxito / 50% fracaso.
void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    if (!getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << "* BZZZZT... BRRRR... DRILLING NOISES *" << std::endl;

    // Semilla básica (idempotente entre ejecuciones rápidas; suficiente para el ejercicio)
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    int r = std::rand();
	
	// ! std::cout << "Número Random: " << r <<std::endl; 

    if (r % 2 == 0)
        std::cout << GREEN << _target << " has been robotomized successfully." << RESET << std::endl;
    else
        std::cout << RED << "Robotomy failed on " << _target << "." << RESET << std::endl;
}