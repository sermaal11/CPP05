/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:48:12 by sergio            #+#    #+#             */
/*   Updated: 2025/10/16 14:12:16 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main()
{
    std::cout << MAGENTA << "\nCreación válida" << RESET << std::endl;
    try {
        Bureaucrat b1("Sergio", 42);
        std::cout << b1 << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }

    std::cout << MAGENTA << "\nCreación inválida (grade 0)" << RESET << std::endl;
    try {
        Bureaucrat b1("Sergio", 0);
        std::cout << b1 << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << GREEN << "Excepción esperada: " << e.what() << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "Error inesperado: " << e.what() << RESET << std::endl;
    }

    std::cout << MAGENTA << "\nCreación inválida (grade 151)" << RESET << std::endl;
    try {
        Bureaucrat b1("Sergio", 151);
        std::cout << b1 << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << GREEN << "Excepción esperada: " << e.what() << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "Error inesperado: " << e.what() << RESET << std::endl;
    }

    std::cout << MAGENTA << "\nBorde superior: grade 1 -> increment" << RESET << std::endl;
    try {
        Bureaucrat b1("Sergio", 1);
        std::cout << b1 << std::endl;
        b1.incrementGrade(); // debe lanzar
        std::cout << RED << "ERROR: no lanzó" << RESET << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << GREEN << "Excepción esperada: " << e.what() << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "Error inesperado: " << e.what() << RESET << std::endl;
    }

    std::cout << MAGENTA << "\nBorde inferior: grade 150 -> decrement" << RESET << std::endl;
    try {
        Bureaucrat b1("Sergio", 150);
        std::cout << b1 << std::endl;
        b1.decrementGrade(); // debe lanzar
        std::cout << RED << "ERROR: no lanzó" << RESET << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << GREEN << "Excepción esperada: " << e.what() << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "Error inesperado: " << e.what() << RESET << std::endl;
    }

    std::cout << MAGENTA << "\nSecuencia válida: subir y bajar" << RESET << std::endl;
    try {
        Bureaucrat b1("Sergio", 42);
        std::cout << CYAN << "Inicial: " << b1 << RESET << std::endl;
        b1.incrementGrade();
        std::cout << CYAN << "Tras increment: " << b1 << RESET << std::endl;
        b1.decrementGrade();
        std::cout << CYAN << "Tras decrement: " << b1 << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }

    std::cout << MAGENTA << "\nOCF: copia y asignación" << RESET << std::endl;
    {
        Bureaucrat a("Alice", 10);
        Bureaucrat b(a);           // copy ctor
        Bureaucrat c("Carol", 150);
        c = a;                     // operator=
        std::cout << a << "\n" << b << "\n" << c << std::endl;
    }

    return 0;
}