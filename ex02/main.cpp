/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:07:09 by lmedrano          #+#    #+#             */
/*   Updated: 2024/06/06 11:50:13 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		// Creating Bureaucrat objects
		// Bob can sign ShrubberyCreationForm
		// Bob can exec ShruberryCreationForm
		// Bob can sign RobotomyRequestForm
		// Bob CANNOT exec RobotomyRequestForm
		// Bob CANNOT sign PresidentialPardonForm
		// Bob CANNOT exec PresidentialPardonForm
		Bureaucrat bob("Bob", 50);
		// Alice can sign and exec EVERYTHING
		Bureaucrat alice("Alice", 1);
		// Charlie CANNOT sign or exec anything
		Bureaucrat charlie("Charlie", 150);

		// Creating Form objects
		ShrubberyCreationForm treeForm("Home");
		RobotomyRequestForm robotForm("Bob");
		PresidentialPardonForm presidentForm("Alice");

		// Display initial states
		std::cout << PURPLE << bob << RESET << std::endl;
		std::cout << PURPLE << alice << RESET << std::endl;
		std::cout << PURPLE << charlie << RESET << std::endl;
		std::cout << PURPLE << treeForm << RESET << std::endl;
		std::cout << PURPLE << robotForm << RESET << std::endl;
		std::cout << PURPLE << presidentForm << RESET << std::endl;
		
		// Bob tries to sign RobotomyRequestForm (ok)
		// Alice tries to exec RobotomyRequestForm (ok)
		bob.signForm(robotForm);
		alice.executeForm(robotForm);

		// Charlie tries to sign PresidentialPardonForm (should fail)
		// Alice tries to exec PresidentialPardonForm (can exec but should fail coz not signed)
		charlie.signForm(presidentForm);
		alice.executeForm(presidentForm);

		// Alice tries to sign and execute PresidentialPardonForm (ok)
		alice.signForm(presidentForm);
		alice.executeForm(presidentForm);

		// Bob tries to sign and execute ShruberryCreationForm (ok) 
		bob.signForm(treeForm);
		bob.executeForm(treeForm);
	}
	catch (std::exception& e)
	{
		std::cerr << RED << "Error : " << e.what() << RESET << std::endl;
	}
	return (0);
}
