/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:52:34 by sergio            #+#    #+#             */
/*   Updated: 2025/10/17 12:55:00 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"


// --- OCF ---
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm("PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
: AForm(other), _target(other._target)
{}

PresidentialPardonForm&
PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    (void)other;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

// --- execute ---
// Reglas: debe estar firmado y executor.grade <= grade_to_execute.
// Efecto: imprime el perdón presidencial.
void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    if (!getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
