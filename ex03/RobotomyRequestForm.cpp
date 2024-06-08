/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:40:27 by lmedrano          #+#    #+#             */
/*   Updated: 2024/06/08 18:09:46 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

// Constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("Robotomy Request", 145, 137), _target(target)
{
	if (getGradeSign() < 1 || getGradeExec() < 1)
		throw GradeTooHighException();
	else if (getGradeSign() > 150 || getGradeExec() > 150)
		throw GradeTooLowException();
	else
	std::cout << getName() << " is initialized" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
: AForm(copy.getName(), copy.getGradeSign(), copy.getGradeExec()), _target(copy.getTarget())
{
	*this = copy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (this != &copy)
	{
	}
	return (*this);
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destroyed" << std::endl;
}

//Getters
std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
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
		std::cout << PURPLE << _target << " has been robotomized successfully." << RESET << std::endl;
	}
	else
	{
		std::cout << PURPLE << "The robotomy failed" << RESET << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& f) {
    os << "Robotomy Request Form: Target = " << f.getTarget() << ", Grade to sign = " << f.getGradeSign() 
       << ", Grade to execute = " << f.getGradeExec();
    if (f.getSignature()) {
        os << " (Signed)";
    } else {
        os << " (Not signed)";
    }
    return os;
}
