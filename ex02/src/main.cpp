/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:41:39 by sergio            #+#    #+#             */
/*   Updated: 2025/10/17 13:06:29 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main()
{
    // Semilla global para robotomy
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    std::cout << MAGENTA << "\n--- CASO 1: ShrubberyCreationForm (firma y ejecución OK) ---" << RESET << std::endl;
    try {
        Bureaucrat gardener("Gardener", 130);          // <=145 para firmar, <=137 para ejecutar
        ShrubberyCreationForm tree("backyard");

        std::cout << CYAN << "Estado inicial: " << RESET << tree << std::endl;
        gardener.signForm(tree);                        // OK
        gardener.executeForm(tree);                     // OK -> crea "backyard_shrubbery"
        std::cout << CYAN << "Estado final:   " << RESET << tree << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "Excepción: " << e.what() << RESET << std::endl;
    }

    std::cout << MAGENTA << "\n--- CASO 2: RobotomyRequestForm (firma OK, dos ejecuciones) ---" << RESET << std::endl;
    try {
        Bureaucrat tech("Tech", 40);                    // <=72 firmar, <=45 ejecutar
        RobotomyRequestForm r("Subject_X");

        std::cout << CYAN << "Estado inicial: " << RESET << r << std::endl;
        tech.signForm(r);                                // OK
        tech.executeForm(r);                             // éxito/fracaso
        sleep(1);
		tech.executeForm(r);                             // éxito/fracaso(Pueden coincidir)
        std::cout << CYAN << "Estado final:   " << RESET << r << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "Excepción: " << e.what() << RESET << std::endl;
    }

    std::cout << MAGENTA << "\n--- CASO 3: PresidentialPardonForm (firma y ejecución OK) ---" << RESET << std::endl;
    try {
        Bureaucrat chief("Chief", 3);                   // <=25 firmar, <=5 ejecutar
        PresidentialPardonForm p("Arthur Dent");

        std::cout << CYAN << "Estado inicial: " << RESET << p << std::endl;
        chief.signForm(p);                               // OK
        chief.executeForm(p);                            // OK
        std::cout << CYAN << "Estado final:   " << RESET << p << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "Excepción: " << e.what() << RESET << std::endl;
    }

    std::cout << MAGENTA << "\n--- CASO 4: Errores (no firmado y rango insuficiente) ---" << RESET << std::endl;

    // 4A: Ejecutar sin firmar
    try {
        Bureaucrat exec("Exec", 1);
        ShrubberyCreationForm s("unsigndemo");
        std::cout << YELLOW << "[4A] Intentando ejecutar sin firmar..." << RESET << std::endl;
        exec.executeForm(s);                             // Debe fallar: FormNotSignedException
    } catch (const std::exception& e) {
        std::cout << RED << "Excepción: " << e.what() << RESET << std::endl;
    }

    // 4B: Firmar OK pero ejecutar con rango insuficiente
    try {
        Bureaucrat lowExec("LowExec", 140);              // puede firmar shrubbery (<=145) pero NO ejecutar (necesita <=137)
        ShrubberyCreationForm s2("lowexecdemo");
        std::cout << YELLOW << "[4B] Firmar con LowExec..." << RESET << std::endl;
        lowExec.signForm(s2);                            // OK
        std::cout << YELLOW << "[4B] Ejecutar con LowExec (debería fallar)..." << RESET << std::endl;
        lowExec.executeForm(s2);                         // Debe fallar: GradeTooLowException para execute
    } catch (const std::exception& e) {
        std::cout << RED << "Excepción: " << e.what() << RESET << std::endl;
    }

    // 4C: Intentar firmar con rango insuficiente
    try {
        Bureaucrat intern("Intern", 150);
        PresidentialPardonForm px("Trillian");
        std::cout << YELLOW << "[4C] Intern intenta firmar Presidential (debe fallar)..." << RESET << std::endl;
        intern.signForm(px);                             // Debe fallar: GradeTooLowException para sign
    } catch (const std::exception& e) {
        std::cout << RED << "Excepción: " << e.what() << RESET << std::endl;
    }

    std::cout << GREEN << "\n--- FIN DE TESTS ex02 ---" << RESET << std::endl;
    return 0;
}

