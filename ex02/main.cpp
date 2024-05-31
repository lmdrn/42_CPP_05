/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:07:09 by lmedrano          #+#    #+#             */
/*   Updated: 2024/05/31 16:04:08 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main(void)
{
	try
	{
		// Creating Bureaucrat objects
		Bureaucrat bob("Bob", 2);
		Bureaucrat alice("Alice", 4);

		// Creating Form objects
		SchruberryCreationForm treeForm("Tax Form", 145, 137);
		RobotpmyRequestForm robotForm("Tax Form", 72, 45);
		PresidentialPardonForm presidentForm("Tax Form", 25, 5);

		// Display initial states
		std::cout << PURPLE << bob << RESET << std::endl;
		std::cout << PURPLE << alice << RESET << std::endl;
		std::cout << PURPLE << treeForm << RESET << std::endl;
		std::cout << PURPLE << robotForm << RESET << std::endl;
		std::cout << PURPLE << presidentForm << RESET << std::endl;

	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
