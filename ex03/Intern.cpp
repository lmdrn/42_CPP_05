/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:42:05 by lmedrano          #+#    #+#             */
/*   Updated: 2024/06/08 18:09:01 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

// Constructor
Intern::Intern()
{
	std::cout << "Intern initialized" << std::endl;
}

// Destructor
Intern::~Intern()
{
	std::cout << "Intern destroyed" << std::endl;
}

// Copy Constructor
Intern::Intern(const Intern& copy)
{
	*this = copy;	
}

// Copy Assignment Operator
Intern& Intern::operator=(const Intern& copy)
{
	if (this != &copy)
	{}
	return (*this);
}

//Methods

AForm* Intern::createShrubberyCreationForm(const std::string& targetName)
{
	return (new ShrubberyCreationForm(targetName));
}

AForm* Intern::createPresidentialPardonForm(const std::string& targetName)
{
	return (new PresidentialPardonForm(targetName));
}

AForm* Intern::createRobotomyRequestForm(const std::string& targetName)
{
	return (new RobotomyRequestForm(targetName));
}

AForm*	Intern::makeForm(const std::string& formName, const std::string& targetName)
{
	for (int i = 0; i < formNumbers; i++)
	{
		if (form[i]._name == formName)
		{
			std::cout << PURPLE << "Intern created " << formName << RESET << std::endl;
			return ((this->*form[i].creationFunction)(targetName));
		}
	}
	throw UnknownFormException();
	return (NULL);
}

const Intern::FormType Intern::form[] =
{
	{"Shrubbery Creation", &Intern::createShrubberyCreationForm},
	{"Robotomy Request", &Intern::createRobotomyRequestForm},
	{"Presidential Pardon", &Intern::createPresidentialPardonForm}
};

const int Intern::formNumbers = sizeof(form) / sizeof(form[0]);
