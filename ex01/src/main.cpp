/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:19:14 by sergio            #+#    #+#             */
/*   Updated: 2025/10/16 19:51:43 by sergio           ###   ########.fr       */
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

        std::cout << CYAN << "Intentando firmar formulario válido..." << RESET << std::endl;
        sergio.signForm(contrato);

        std::cout << YELLOW << "Estado del formulario tras la firma:" << RESET << std::endl;
        std::cout << contrato << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << RED << "Error inesperado: " << e.what() << RESET << std::endl;
    }

	

    return 0;
}