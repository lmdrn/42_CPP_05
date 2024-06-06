/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:56:51 by lmedrano          #+#    #+#             */
/*   Updated: 2024/06/06 12:14:38 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"


PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm("Presidential Pardon", 25, 5), _target(target)
{
	if (getGradeSign() < 1 || getGradeExec() < 1)
		throw GradeTooHighException();
	else if (getGradeSign() > 150 || getGradeExec() > 150)
		throw GradeTooLowException();
	else
		std::cout << GREEN << getName() << "initialized" << std::endl; 
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
: AForm(copy.getName(), copy.getGradeSign(), copy.getGradeExec()), _target(copy.getTarget())
{
	*this = copy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	if (this != &copy)
	{
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destroyed" << std::endl;
}

//getters
std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

//methods
void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (!getSignature())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeExec())
		throw GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& f) {
    os << "Presidential Pardon Form: Target = " << f.getTarget() << ", Grade to sign = " << f.getGradeSign() 
       << ", Grade to execute = " << f.getGradeExec();
    if (f.getSignature()) {
        os << " (Signed)";
    } else {
        os << " (Not signed)";
    }
    return os;
}
