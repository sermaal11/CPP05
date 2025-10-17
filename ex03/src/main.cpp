/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:41:39 by sergio            #+#    #+#             */
/*   Updated: 2025/10/17 13:44:41 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"

int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL))); // por Robotomy

    Intern intern;
    Bureaucrat boss("Boss", 1); // suficiente para firmar/ejecutar cualquier form

    std::cout << MAGENTA << "\n--- TEST 1: Crear cada formulario válido ---" << RESET << std::endl;
    {
        AForm* f1 = intern.makeForm("shrubbery creation", "home");
        AForm* f2 = intern.makeForm("robotomy request",  "marvin");
        AForm* f3 = intern.makeForm("presidential pardon","arthur");

        if (f1) 
        { 
            boss.signForm(*f1); 
            boss.executeForm(*f1); 
            delete f1; 
        }
        if (f2) 
        { 
            boss.signForm(*f2); 
            boss.executeForm(*f2); 
            delete f2; 
        }
        if (f3) 
        { 
            boss.signForm(*f3); 
            boss.executeForm(*f3); 
            delete f3; 
        }
    }

    std::cout << MAGENTA << "\n--- TEST 2: Nombre inválido (debe informar y devolver NULL) ---" << RESET << std::endl;
    {
        AForm* bad = intern.makeForm("coffee request", "office");
        if (!bad)
            std::cout << YELLOW << "Intern returned NULL for unknown form." << RESET << std::endl;
        delete bad; // seguro aunque sea NULL
    }

    std::cout << MAGENTA << "\n--- TEST 3: Crear, mostrar estado, firmar y ejecutar (ciclo completo) ---" << RESET << std::endl;
    {
        AForm* f = intern.makeForm("robotomy request", "bender");
        if (f)
        {
            std::cout << CYAN << "Estado inicial: " << RESET << *f << std::endl;
            boss.signForm(*f);
            boss.executeForm(*f);
            std::cout << CYAN << "Estado final:   " << RESET << *f << std::endl;
        }
        delete f;
    }

    std::cout << GREEN << "\n--- FIN TESTS INTERN ---" << RESET << std::endl;
    return 0;
}

