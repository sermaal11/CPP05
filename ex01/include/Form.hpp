/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:19:07 by sergio            #+#    #+#             */
/*   Updated: 2025/10/16 19:24:45 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# define RED "\033[31m"
# define CYAN "\033[36m"
# define MAGENTA "\033[35m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define RESET "\033[0m"

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;	// Forward declaration para evitar dependencias circulares

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	private:
		static void _assertLevelInRange(int grade);

	public:
		//OCF
		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		// Getters
		const std::string& getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		// Signed Form Function
		void beSigned(const Bureaucrat& bureaucrat);

		// Nested Execptions
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

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif // FORM_HPP
