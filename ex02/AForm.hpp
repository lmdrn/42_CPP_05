/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:24:01 by lmedrano          #+#    #+#             */
/*   Updated: 2024/06/05 16:21:26 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#define RESET "\x1b[0m"
#define GREEN "\x1b[32m"
#define ORANGE "\x1b[38;5;208m"
#define RED "\x1b[31m"
#define PURPLE "\x1b[35m"

#include <iostream>
#include "GradeTooLowException.hpp"
#include "GradeTooHighException.hpp"
#include "FormNotSignedException.hpp"

class Bureaucrat;

class AForm
{
	protected:
		virtual void		doSmth(void) const = 0;
	private:
		std::string const	_name;
		bool			_isSigned;
		int const		_gradeToSign;
		int const		_gradeToExec;

	public:
		//Constructor
		AForm(const std::string& name, int sign, int exec);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &copy);
    		// Destructor
    		virtual ~AForm();

		//Getters
		std::string	getName(void) const;
		bool		getSignature(void) const;
		int		getGradeSign(void) const;
		int		getGradeExec(void) const;

		//Methods
		bool		beSigned(Bureaucrat& b);
		virtual void	execute(Bureaucrat& executor) const = 0;
};

// Overload of the insertion operator
std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif /* AFORM_HPP */
