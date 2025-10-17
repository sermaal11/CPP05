/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:52:27 by sergio            #+#    #+#             */
/*   Updated: 2025/10/17 12:53:27 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "../include/AForm.hpp"
# include <string>
# include <iostream>  // std::cout

class PresidentialPardonForm : public AForm
{
private:
    const std::string _target;

public:
    // OCF
    explicit PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();

    // Acción concreta
    void execute(Bureaucrat const& executor) const;
};

#endif // PRESIDENTIALPARDONFORM_HPP
