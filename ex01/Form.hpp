/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:24:01 by lmedrano          #+#    #+#             */
/*   Updated: 2024/05/31 13:54:59 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#define RESET "\x1b[0m"
#define GREEN "\x1b[32m"
#define ORANGE "\x1b[38;5;208m"
#define RED "\x1b[31m"
#define PURPLE "\x1b[35m"

#include <iostream>
#include "GradeTooLowException.hpp"
#include "GradeTooHighException.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool			_isSigned;
		int const		_gradeToSign;
		int const		_gradeToExec;

	public:
    		// Constructor
    		Form();
    		Form(const std::string& name, int sign, int exec);

    		// Destructor
    		~Form();

    		// Copy Constructor
    		Form(const Form& copy);

    		// Copy Assignment Operator
    		Form& operator=(const Form& copy);

		//Getters
		std::string	getName(void) const;
		bool		getSignature(void) const;
		int		getGradeSign(void) const;
		int		getGradeExec(void) const;

		//Methods
		bool		beSigned(Bureaucrat& b);
};

// Overload of the insertion operator
std::ostream& operator<<(std::ostream& os, const Form& f);

#endif /* FORM_HPP */
