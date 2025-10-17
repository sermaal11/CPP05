/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:42:52 by sergio            #+#    #+#             */
/*   Updated: 2025/10/17 11:04:33 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat; // Forward declaration

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	
	private:
		static void _assertGradeInRange(int grade); // 1..150

	public:
		//OCF
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		//Getters
		const std::string&	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		//Firma
		void beSigned(const Bureaucrat& bureaucrat);

		//Ejecucion
		virtual void execute(Bureaucrat const& executor) const = 0;

		//Execpciones
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
		class FormNotSignedException : public std::exception
		{
			public:
				const char* what() const throw();	
		};
};

//Operador de salida
std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif // AFORM_HPP
