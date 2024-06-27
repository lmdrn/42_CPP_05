/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:07:09 by lmedrano          #+#    #+#             */
/*   Updated: 2024/06/27 10:23:06 by lmedrano         ###   ########.fr       */
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
		ShrubberyCreationForm shrubForm("Home");
		RobotomyRequestForm robotForm("Bob");
		PresidentialPardonForm presidentForm("Alice");

		// Display initial states
		std::cout << PURPLE << bob << RESET << std::endl;
		std::cout << PURPLE << alice << RESET << std::endl;
		std::cout << PURPLE << charlie << RESET << std::endl;
		std::cout << PURPLE << shrubForm << RESET << std::endl;
		std::cout << PURPLE << robotForm << RESET << std::endl;
		std::cout << PURPLE << presidentForm << RESET << std::endl;
		
		// Bob tries to sign RobotomyRequestForm (ok)
		// Alice tries to exec RobotomyRequestForm (ok)
		std::cout << " " << std::endl;
		bob.signForm(robotForm);
		alice.executeForm(robotForm);

		// Charlie tries to sign PresidentialPardonForm (should fail)
		// Alice tries to exec PresidentialPardonForm (can exec but should fail coz not signed)
		std::cout << " " << std::endl;
		charlie.signForm(presidentForm);
		alice.executeForm(presidentForm);

		// Alice tries to sign and execute PresidentialPardonForm (ok)
		std::cout << " " << std::endl;
		alice.signForm(presidentForm);
		alice.executeForm(presidentForm);

		// Bob tries to sign ShruberryCreationForm (ok) and executes (ok) 
		// Alice tries to executes ShruberryCreationForm
		std::cout << " " << std::endl;
		bob.signForm(shrubForm);
		bob.executeForm(shrubForm);
		std::cout << " " << std::endl;
		alice.executeForm(shrubForm);
	}
	catch (std::exception& e)
	{
		std::cerr << RED << "Error : " << e.what() << RESET << std::endl;
	}
	return (0);
}
