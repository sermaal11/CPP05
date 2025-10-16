/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:48:12 by sergio            #+#    #+#             */
/*   Updated: 2025/10/16 12:56:19 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main()
{
	Bureaucrat b1("Sergio", 2);
	std::cout << "Bureocrat name: " << b1.getName() << std::endl;
	std::cout << "Bureocrat grade: " << b1.getGrade() << std::endl;
	
	std::cout << "Before increment: " << b1.getGrade() << std::endl;
	b1.incrementGrade();
	std::cout << "After increment: " << b1.getGrade() << std::endl;

	b1.decrementGrade();
	std::cout << "After decrement: " << b1.getGrade() << std::endl;

	
	return 0;
}
