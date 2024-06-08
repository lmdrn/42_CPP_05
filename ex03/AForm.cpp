/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:56:05 by lmedrano          #+#    #+#             */
/*   Updated: 2024/06/08 18:11:46 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int sign, int exec)
: _name(name), _isSigned(false), _gradeToSign(sign), _gradeToExec(exec)
{
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExec > 150)
		throw GradeTooLowException();
	else
		std::cout << GREEN << "AForm initialized " << std::endl; 
}

AForm::AForm(const AForm &copy)
: _name(copy.getName()), _isSigned(getSignature()), _gradeToSign(getGradeSign()), _gradeToExec(getGradeExec())
{
	*this = copy;
}

AForm& AForm::operator=(const AForm &copy)
{
	if (this != &copy)
	{
		_isSigned = copy.getSignature();
	}
	return (*this);
}

// Destructor
AForm::~AForm()
{
	std::cout << RED << "AForm has been destroyed" << RESET << std::endl;
}	

//Getters
std::string	AForm::getName(void) const
{
	return (this->_name);
}

bool		AForm::getSignature(void) const
{
	return (this->_isSigned);
}

int		AForm::getGradeSign(void) const
{
	return (this->_gradeToSign);
}

int		AForm::getGradeExec(void) const
{
	return (this->_gradeToExec);
}

//Methods
bool		AForm::beSigned(Bureaucrat& b)
{
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExec > 150)
		throw GradeTooLowException();
	else if (b.getGrade() <= _gradeToSign)
	{
		return (_isSigned = true);
	}
	else
		return (_isSigned = false);
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form " << form.getName() << ", Signed: " << (form.getSignature())
       << ", Grade Required to Sign: " << form.getGradeSign()
       << ", Grade Required to Execute: " << form.getGradeExec();
    return os;
}
