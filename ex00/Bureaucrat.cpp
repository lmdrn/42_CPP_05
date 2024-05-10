/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:24:13 by lmedrano          #+#    #+#             */
/*   Updated: 2024/05/10 13:46:38 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructor
Bureaucrat::Bureaucrat();

// Destructor
Bureaucrat::~Bureaucrat();

// Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat& copy);

// Copy Assignment Operator
Bureaucrat& Bureatcrat::operator=(const Bureaucrat& copy);

//Getters
std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

std::string	Bureaucrat::getGrade(void) const;
{
	return (this->_grade);
}
