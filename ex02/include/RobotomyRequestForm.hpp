/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:08:42 by sergio            #+#    #+#             */
/*   Updated: 2025/10/17 12:48:09 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "../include/AForm.hpp"
# include <string>
# include <cstdlib>   // rand, srand
# include <ctime>     // time
# include <iostream>  // std::cout
# include <unistd.h>

class RobotomyRequestForm : public AForm
{
private:
    const std::string _target;

public:
    // OCF
    explicit RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();

    // Acción concreta
    void execute(Bureaucrat const& executor) const;
};

#endif // ROBOTOMYREQUESTFORM_HPP
