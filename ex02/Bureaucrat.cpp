/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:24:13 by lmedrano          #+#    #+#             */
/*   Updated: 2024/06/05 16:36:31 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Constructor
Bureaucrat::Bureaucrat()
: _name("John Doe"), _grade(150)
{
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
	else
		std::cout << GREEN << _name << RESET << " initialized by default with grade " << GREEN << _grade << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
: _name(name), _grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
	else
		std::cout << GREEN << _name << RESET << " initialized with grade " << GREEN << _grade << RESET << std::endl;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "Bureaucrat has been destroyed" << RESET << std::endl;
}

// Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat& copy)
: _name(copy.getName()), _grade(copy.getGrade())
{
	*this = copy;
}

// Copy Assignment Operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	if (this != &copy)
	{
		_grade = copy._grade;
	}
	return (*this);
}

//Getters
std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

//Methods
void	Bureaucrat::incrementGrade(void)
{
	if (_grade <= 1)
		throw GradeTooHighException();
	else
		_grade--;
	std::cout << PURPLE << "Level up! Grade is now: " << _grade << RESET << std::endl;
}

void	Bureaucrat::decrementGrade(void)
{
	if (_grade >= 150)
		throw GradeTooLowException();
	else
		_grade++;
	std::cout << PURPLE << "Ow Naaaaur, Level down! Grade is now: " << _grade << RESET << std::endl;
}

void	Bureaucrat::signForm(AForm& f)
{
	if (f.beSigned(*this) == true)
		std::cout << GREEN << _name << " signed " << f.getName() << RESET << std::endl;
	else
		std::cout << RED << _name << " could not sign " << f.getName() << RESET << std::endl;
}

// Definition of the overloaded insertion operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bt) {
    os << bt.getName() << ", bureaucrat grade " << bt.getGrade();
    return os;
}
