/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:19:14 by sergio            #+#    #+#             */
/*   Updated: 2025/10/16 23:33:27 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"


int main()
{
    std::cout << MAGENTA << "\n--- CASO 1: Firma correcta ---" << RESET << std::endl;

    try
    {
        Bureaucrat sergio("Sergio", 40);         
        Form contrato("Contract", 50, 80);
        std::cout << contrato << std::endl;
        sergio.signForm(contrato);
        std::cout << contrato << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << RED << "Error inesperado: " << e.what() << RESET << std::endl;
    }

	std::cout << MAGENTA << "\n--- CASO 2: Firma fallida (rango insuficiente) ---" << RESET << std::endl;

    try
    {
        Bureaucrat juan("Juan", 120);
        Form contrato("HighLevelContract", 50, 80);

        std::cout << contrato << std::endl;
        juan.signForm(contrato);
        std::cout << contrato << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << RED << "Error inesperado: " << e.what() << RESET << std::endl;
    }

	std::cout << MAGENTA << "\n--- CASO 3: Intento de firmar un formulario ya firmado ---" << RESET << std::endl;

    try
    {
        Bureaucrat ana("Ana", 10);
        Form permiso("Permit", 30, 50);

        std::cout << permiso << std::endl;
        ana.signForm(permiso);
        std::cout << permiso << std::endl;

        std::cout << CYAN << "Segundo intento de firma" << RESET << std::endl;
        ana.signForm(permiso);
    }
    catch (const std::exception& e)
    {
        std::cout << RED << "Error inesperado: " << e.what() << RESET << std::endl;
    }
	
	    std::cout << MAGENTA << "\n--- CASO 4: Creación de formularios con rangos inválidos ---" << RESET << std::endl;

    // Caso 4A: Grade demasiado alto (menor que 1)
    try
    {
        std::cout << CYAN << "Intentando crear formulario con grade_to_sign = 0..." << RESET << std::endl;
        Form f1("InvalidHigh", 0, 10);
        std::cout << f1 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << RED << "Excepción capturada: " << e.what() << RESET << std::endl;
    }

    // Caso 4B: Grade demasiado bajo (mayor que 150)
    try
    {
        std::cout << CYAN << "Intentando crear formulario con grade_to_sign = 150..." << RESET << std::endl;
        Form f2("InvalidLow", 151, 10);
        std::cout << f2 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << RED << "Excepción capturada: " << e.what() << RESET << std::endl;
    }

	    std::cout << MAGENTA << "\n--- CASO 5: Creación de Bureaucrats con grades inválidos ---" << RESET << std::endl;

    // 5A: grade demasiado alto (menor que 1)
    try
    {
        std::cout << CYAN << "Intentando crear Bureaucrat con grade = 0..." << RESET << std::endl;
        Bureaucrat badHigh("BadHigh", 0);
        std::cout << badHigh << std::endl; // no debe llegar
    }
    catch (const std::exception& e)
    {
        std::cout << RED << "Excepción capturada: " << e.what() << RESET << std::endl;
    }

    // 5B: grade demasiado bajo (mayor que 150)
    try
    {
        std::cout << CYAN << "Intentando crear Bureaucrat con grade = 151..." << RESET << std::endl;
        Bureaucrat badLow("BadLow", 151);
        std::cout << badLow << std::endl; // no debe llegar
    }
    catch (const std::exception& e)
    {
        std::cout << RED << "Excepción capturada: " << e.what() << RESET << std::endl;
    }

	    std::cout << MAGENTA << "\n--- CASO 6: Incremento y decremento en los límites ---" << RESET << std::endl;

    // 6A: intentar subir por encima del grade 1
    try
    {
        std::cout << CYAN << "Intentando incrementar un Bureaucrat en grade 1..." << RESET << std::endl;
        Bureaucrat elite("Elite", 1);
        std::cout << elite << std::endl;
        elite.incrementGrade();  // debería lanzar GradeTooHighException
    }
    catch (const std::exception& e)
    {
        std::cout << RED << "Excepción capturada: " << e.what() << RESET << std::endl;
    }

    // 6B: intentar bajar por debajo del grade 150
    try
    {
        std::cout << CYAN << "Intentando decrementar un Bureaucrat en grade 150..." << RESET << std::endl;
        Bureaucrat intern("Intern", 150);
        std::cout << intern << std::endl;
        intern.decrementGrade(); // debería lanzar GradeTooLowException
    }
    catch (const std::exception& e)
    {
        std::cout << RED << "Excepción capturada: " << e.what() << RESET << std::endl;
    }

    // 6C: caso válido en el rango medio
    try
    {
        std::cout << CYAN << "Incrementando y luego decrementando un Bureaucrat intermedio..." << RESET << std::endl;
        Bureaucrat mid("Mid", 75);
        std::cout << mid << std::endl;

        mid.incrementGrade();
        std::cout << YELLOW << "Tras incrementar: " << RESET << mid << std::endl;

        mid.decrementGrade();
        std::cout << YELLOW << "Tras decrementar: " << RESET << mid << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << RED << "Excepción capturada: " << e.what() << RESET << std::endl;
    }

	    std::cout << MAGENTA << "\n--- CASO 7: Simulación completa ---" << RESET << std::endl;

    try
    {
        Bureaucrat ceo("CEO", 1);
        Bureaucrat manager("Manager", 30);
        Bureaucrat junior("Junior", 120);

        Form f_top("TopSecret", 5, 10);
        Form f_mid("ProjectPlan", 50, 80);
        Form f_low("Timesheet", 140, 140);

        std::cout << "\n[Estado inicial]\n";
        std::cout << f_top << "\n" << f_mid << "\n" << f_low << std::endl;

        std::cout << "\n[Intentos de firma Junior]\n";
        // Junior intenta firmar de todo (fallará en top y mid, firmará low)
        junior.signForm(f_top);
        junior.signForm(f_mid);
        junior.signForm(f_low);

		std::cout << "\n[Intentos de firma Manager]\n";
        // Manager firma el mid; reintenta low ya firmado
        manager.signForm(f_top);
        manager.signForm(f_mid);
        manager.signForm(f_low);

		std::cout << "\n[Intentos de firma Ceo]\n";
        // CEO firma el top y reintenta mid ya firmado
        ceo.signForm(f_top);
        ceo.signForm(f_mid);
        ceo.signForm(f_low);

        std::cout << "\n[Estado final]\n";
        std::cout << f_top << "\n" << f_mid << "\n" << f_low << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << RED << "Error inesperado: " << e.what() << RESET << std::endl;
    }

    return 0;
}