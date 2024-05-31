/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:57:52 by lmedrano          #+#    #+#             */
/*   Updated: 2024/05/31 16:08:26 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#define RESET "\x1b[0m"
#define GREEN "\x1b[32m"
#define ORANGE "\x1b[38;5;208m"
#define RED "\x1b[31m"
#define PURPLE "\x1b[35m"

#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	private:
		std::string	_target;
		void		doSmth() const;

	public:
    		// Constructor
    		ShrubberyCreationForm(const std::string& target);

    		// Destructor
    		~ShrubberyCreationForm();

    		// Copy Constructor
    		ShrubberyCreationForm(const ShrubberyCreationForm& copy);

    		// Copy Assignment Operator
    		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
		
		//methods
		void	execute(const Bureaucrat& executor) const;
};

#endif /* SHRUBBERYCREATIONFORM_HPP */
