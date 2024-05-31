/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:06:16 by lmedrano          #+#    #+#             */
/*   Updated: 2024/05/31 11:12:53 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

#define RESET "\x1b[0m"
#define GREEN "\x1b[32m"
#define ORANGE "\x1b[38;5;208m"
#define RED "\x1b[31m"
#define PURPLE "\x1b[35m"

#include <iostream>
#include "GradeTooLowException.hpp"
#include "GradeTooHighException.hpp"

class Bureaucrat 
{
	private:
	    	// Private members
		const std::string	_name;
		int			_grade;
	public:
    		// Constructor
    		Bureaucrat();
		Bureaucrat(const std::string name, int grade);

    		// Destructor
    		~Bureaucrat();

    		// Copy Constructor
    		Bureaucrat(const Bureaucrat& copy);

    		// Copy Assignment Operator
    		Bureaucrat& operator=(const Bureaucrat& copy);

		//Getters
		std::string	getName(void) const;
		int 		getGrade(void) const;

		//Methods
		void		incrementGrade(void);
		void 		decrementGrade(void);
};

// Overload of the insertion operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bt);

#endif /* Bureaucrat_HPP */
