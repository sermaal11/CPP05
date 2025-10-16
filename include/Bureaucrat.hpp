/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:48:19 by sergio            #+#    #+#             */
/*   Updated: 2025/10/16 12:44:45 by sergio           ###   ########.fr       */
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

class Bureaucrat
{
	private:
		const std::string	_name;
		int 				_grade;
	
	public:
	// OCF
		Bureaucrat(const std::string _name, int _grade);	//ctor x defecto
		Bureaucrat(const Bureaucrat& other);				//ctor x copia
		Bureaucrat& operator=(const Bureaucrat& other);		//operador de asig
		~Bureaucrat();										//dtor x defecto
		
	// Getters
		const std::string &getName() const;
		int getGrade() const;
	
	// Grade management
		void incrementGrade();
		void decrementGrade();
};

#endif // BUREAUCRAT_HPP
