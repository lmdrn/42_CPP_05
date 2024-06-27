/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:35:52 by lmedrano          #+#    #+#             */
/*   Updated: 2024/06/27 10:41:43 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#define RESET "\x1b[0m"
#define GREEN "\x1b[32m"
#define ORANGE "\x1b[38;5;208m"
#define RED "\x1b[31m"
#define PURPLE "\x1b[35m"

#include <iostream>
#include "GradeTooLowException.hpp"
#include "GradeTooHighException.hpp"
#include "FormNotSignedException.hpp"
#include "UnknownFormException.hpp"
#include "AForm.hpp"

class Intern
{
	private:
		AForm* createShrubberyCreationForm(const std::string& targetName);
		AForm* createRobotomyRequestForm(const std::string& targetName);
		AForm* createPresidentialPardonForm(const std::string& targetName);

		typedef AForm* (Intern::*FormCreationFunction)(const std::string&);
		struct FormType
		{
			std::string	_name;
			FormCreationFunction creationFunction;
		};

		static const	FormType	form[];
		static const	int		formNumbers;
	public:
    		// Constructor
    		Intern();

    		// Destructor
    		~Intern();

    		// Copy Constructor
    		Intern(const Intern& copy);

    		// Copy Assignment Operator
    		Intern& operator=(const Intern& copy);

		//Methods
		AForm*	makeForm(const std::string& formName, const std::string& targetName);
};

#endif /* INTERN_HPP */
