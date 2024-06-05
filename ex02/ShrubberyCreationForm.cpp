/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:57:38 by lmedrano          #+#    #+#             */
/*   Updated: 2024/06/05 16:51:08 by lmedrano         ###   ########.fr       */
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
	std::srand(std::time(NULL));
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destroyed" << std::endl;
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
