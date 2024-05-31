/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:45:11 by lmedrano          #+#    #+#             */
/*   Updated: 2024/05/31 13:58:52 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
: _name("John Doe"), _isSigned(false), _gradeToSign(1), _gradeToExec(1)
{
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExec > 150)
		throw GradeTooLowException();
	else
		std::cout << GREEN << _name << "default initialized" << std::endl; 
}

Form::Form(const std::string& name, const int sign, const int exec)
	: _name(name), _isSigned(false), _gradeToSign(sign), _gradeToExec(exec)
{
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExec > 150)
		throw GradeTooLowException();
	else
		std::cout << GREEN << _name << "initialized" << std::endl; 
}

// Destructor
Form::~Form()
{
	std::cout << RED << "Form has been destroyed" << RESET << std::endl;
}

// Copy Constructor
Form::Form(const Form& copy)
: _name(copy.getName()), _isSigned(getSignature()), _gradeToSign(getGradeSign()), _gradeToExec(getGradeExec())
{
	*this = copy;
}

// Copy Assignment Operator
Form& Form::operator=(const Form& copy)
{
	if (this != &copy)
	{
		_isSigned = copy.getSignature();
	}
	return (*this);
}

//Getters
std::string	Form::getName(void) const
{
	return (this->_name);
}

int	Form::getGradeSign(void) const
{
	return (this->_gradeToSign);
}

int	Form::getGradeExec(void) const
{
	return (this->_gradeToExec);
}

bool	Form::getSignature(void) const
{
	return (this->_isSigned);
}

bool	Form::beSigned(Bureaucrat& b)
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

// Overloaded insertion operator
std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form " << form.getName() << ", Signed: " << (form.getSignature())
       << ", Grade Required to Sign: " << form.getGradeSign()
       << ", Grade Required to Execute: " << form.getGradeExec();
    return os;
}
