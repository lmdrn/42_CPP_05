/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:57:52 by lmedrano          #+#    #+#             */
/*   Updated: 2024/06/06 12:15:40 by lmedrano         ###   ########.fr       */
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
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	private:
		std::string	_target;

	public:
		//Constructor
    		ShrubberyCreationForm(const std::string& target);
		//Operator
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
		//Copy
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		//Destructor
    		~ShrubberyCreationForm();
		//Getters
		std::string	getTarget(void) const;
		//Methods
		void		execute(const Bureaucrat& executor) const;
};

// Overload of the insertion operator
std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& f);

#endif /* SHRUBBERYCREATIONFORM_HPP */
