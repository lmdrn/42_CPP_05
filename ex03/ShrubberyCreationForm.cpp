/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:57:38 by lmedrano          #+#    #+#             */
/*   Updated: 2024/06/27 10:28:21 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("Shrubbery Creation", 145, 137), _target(target)
{
	if (getGradeSign() < 1 || getGradeExec() < 1)
		throw GradeTooHighException();
	else if (getGradeSign() > 150 || getGradeExec() > 150)
		throw GradeTooLowException();
	else
		std::cout << GREEN << getName() << " initialized" << std::endl; 
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
	std::ofstream ofs(getTarget() + "_shrubbery");
	if (ofs.is_open()) {
		ofs << "       _-_ " << std::endl;
		ofs << "    /~~   ~~\\ " << std::endl;
		ofs << " /~~         ~~\\ " << std::endl;
		ofs << "{               }" << std::endl;
		ofs << " \\  _-     -_  /" << std::endl;
		ofs << "   ~  \\\\ //  ~" << std::endl;
		ofs << "_- -   | | _- _" << std::endl;
		ofs << "  _ -  | |   -_" << std::endl;
		ofs << "      // \\\\" << std::endl;
		ofs.close();
	} 
	else 
	{
		std::cerr << "Could not create file" << std::endl;
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
