/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:09:43 by sergio            #+#    #+#             */
/*   Updated: 2025/10/17 11:19:06 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define RED "\033[31m"
# define CYAN "\033[36m"
# define MAGENTA "\033[35m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define RESET "\033[0m"

# include <iostream>
# include <string>
# include <exception>

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int 				_grade;

	private:
		static void _assertLevelInRange(int grade);
	
	public:
	// OCF
		Bureaucrat(const std::string _name, int _grade);	//ctor x defecto
		Bureaucrat(const Bureaucrat& other);				//ctor x copia
		Bureaucrat& operator=(const Bureaucrat& other);		//operador de asig
		~Bureaucrat();										//dtor x defecto
		
	// Getters
		const std::string &getName() const;
		int getGrade() const;
	
	// Grade management, sign forms and execute forms
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm& form);
		void executeForm(AForm const& form);
		

	// Nested exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif // BUREAUCRAT_HPP
