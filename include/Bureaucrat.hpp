/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:48:19 by sergio            #+#    #+#             */
/*   Updated: 2025/10/16 12:07:32 by sergio           ###   ########.fr       */
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
		int 				_level;
	
	public:
	// OCF
		Bureaucrat(const std::string _name, int _level);	//ctor x defecto
		Bureaucrat(const Bureaucrat& other);				//ctor x copia
		Bureaucrat& operator=(const Bureaucrat& other);		//operador de asig
		~Bureaucrat();										//dtor x defecto
		
	
	
};

#endif // BUREAUCRAT_HPP
