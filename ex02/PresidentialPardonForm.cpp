/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:56:51 by lmedrano          #+#    #+#             */
/*   Updated: 2024/06/05 17:01:31 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"


PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm("Presidential Pardon", 25, 5), _target(target)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destroyed" << std::endl;
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
