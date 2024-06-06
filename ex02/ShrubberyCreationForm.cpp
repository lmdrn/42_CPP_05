/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:57:38 by lmedrano          #+#    #+#             */
/*   Updated: 2024/06/06 12:15:16 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("Robotomy Request", 72, 45), _target(target)
{
	if (getGradeSign() < 1 || getGradeExec() < 1)
		throw GradeTooHighException();
	else if (getGradeSign() > 150 || getGradeExec() > 150)
		throw GradeTooLowException();
	else
		std::cout << GREEN << getName() << "initialized" << std::endl; 
	std::srand(std::time(NULL));
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
: AForm(copy.getName(), copy.getGradeSign(), copy.getGradeExec()), _target(copy.getTarget())
{
	*this = copy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	if (this != &copy)
	{
	}
	return (*this);
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destroyed" << std::endl;
}

//Getters
std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

//methods
void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (!getSignature())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeExec())
		throw GradeTooLowException();
	std::cout << "Drilling noises..." << std::endl;
	if (std::rand() % 2)
	{
		std::cout << _target << " has been robotomized successfully." << std::endl;
	}
	else
	{
		std::cout << "The robotomy failed" << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& f) {
    os << "Shrubbery Creation Form: Target = " << f.getTarget() << ", Grade to sign = " << f.getGradeSign() 
       << ", Grade to execute = " << f.getGradeExec();
    if (f.getSignature()) {
        os << " (Signed)";
    } else {
        os << " (Not signed)";
    }
    return os;
}
