/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:07:09 by lmedrano          #+#    #+#             */
/*   Updated: 2024/05/31 11:18:07 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		// Creating Bureaucrat objects
		Bureaucrat bob("Bob", 2);
		Bureaucrat alice("Alice", 4);

		// Creating Form objects
		Form taxForm("Tax Form", 3, 5);

		// Display initial states
		std::cout << PURPLE << bob << RESET << std::endl;
		std::cout << PURPLE << alice << RESET << std::endl;
		std::cout << PURPLE << taxForm << RESET << std::endl;

		// Bob tries to sign the form and succeeds
		bob.signForm(taxForm);
		std::cout << taxForm << std::endl;

		// Alice tries to sign the form and fails
		alice.signForm(taxForm);
		std::cout << taxForm << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Test grade exceptions with Form objects
	try 
	{
	Form invalidForm("Invalid Form", 0, 5); // Should throw GradeTooHighException
	}
	catch (std::exception& e)
	{
		std::cerr << RED << "Invalid Form: " << e.what() << RESET << std::endl;
	}

	try 
	{
		Form invalidForm2("Invalid Form 2", 5, 151); // Should throw GradeTooLowException
	}
	catch (std::exception& e)
	{
		std::cerr << RED << "Invalid Form: " << e.what() << RESET << std::endl;
	}

	return (0);
}
