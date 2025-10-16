/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:48:12 by sergio            #+#    #+#             */
/*   Updated: 2025/10/16 12:18:00 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main()
{
	std::cout << "--- Creating b1 ---" << std::endl;
	Bureaucrat b1("Sergio", 1);
	
	std::cout << "\n--- Copy constructing b2 from b1 ---" << std::endl;
	Bureaucrat b2(b1);

	std::cout << "\n--- Assigning b1 = b2 ---" << std::endl;
	b1 = b2;

	std::cout << "\n--- End of main ---" << std::endl;
	return 0;
}
