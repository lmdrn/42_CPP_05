/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:06:16 by lmedrano          #+#    #+#             */
/*   Updated: 2024/05/10 12:06:37 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

#include <iostream>

class Bureaucrat {
	private:
	    	// Private members

	public:
    		// Constructor
    		Bureaucrat();

    		// Destructor
    		~Bureaucrat();

    		// Copy Constructor
    		Bureaucrat(const Bureaucrat& copy);

    		// Copy Assignment Operator
    		Bureaucrat& operator=(const Bureaucrat& copy);
};

#endif /* Bureaucrat_HPP */
