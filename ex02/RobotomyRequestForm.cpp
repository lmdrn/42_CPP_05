/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:40:27 by lmedrano          #+#    #+#             */
/*   Updated: 2024/06/05 17:01:32 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

// Constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("Shrubbery Creation", 145, 137), _target(target)
{
	std::cout << getName() << "is initialized" << std::endl;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destroyed" << std::endl;
}

//methods
void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
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
