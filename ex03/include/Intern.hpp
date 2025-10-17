/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:26:44 by sergio            #+#    #+#             */
/*   Updated: 2025/10/17 13:37:08 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "../include/Bureaucrat.hpp"
# include "../include/AForm.hpp"
# include "../include/ShrubberyCreationForm.hpp"
# include "../include/RobotomyRequestForm.hpp"
# include "../include/PresidentialPardonForm.hpp"

# include <string>
# include <iostream>

class Intern
{
	private:
		static AForm* _createShrubbery(const std::string& target);
		static AForm* _createRobotomy(const std::string& target);
		static AForm* _createPresidential(const std::string& target);
	
	public:
	//OCF
    	Intern();
    	Intern(const Intern& other);
    	Intern& operator=(const Intern& other);
    	~Intern();	

    	AForm* makeForm(const std::string& formName, const std::string& target) const;

};

#endif // INTERN_HPP