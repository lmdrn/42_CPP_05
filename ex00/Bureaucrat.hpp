/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:06:16 by lmedrano          #+#    #+#             */
/*   Updated: 2024/05/10 12:25:58 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

#include <iostream>

class Bureaucrat 
{
	private:
	    	// Private members
		const std::string	_name;
		int			grades[149];
	public:
    		// Constructor
    		Bureaucrat();

    		// Destructor
    		~Bureaucrat();

    		// Copy Constructor
    		Bureaucrat(const Bureaucrat& copy);

    		// Copy Assignment Operator
    		Bureaucrat& operator=(const Bureaucrat& copy);

		//Getters
		std::string	getName(void) const;
		std::string	getGrade(void) const;
};

#endif /* Bureaucrat_HPP */
