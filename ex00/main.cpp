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

int main(void)
{
	// will throw error before constructor initialization
	try
	{
		Bureaucrat bureaucrat("John Doe", 151); // This will throw an exception
		std::cout << bureaucrat << std::endl;
	} 
	catch (const GradeTooLowException& error)
	{
		std::cerr << RED << "Exception: " << error.what() << RESET << std::endl;
	}

	//will throw error when incrementing and destroy bureaucrat before throwing exception to avoid mem leaks
	try
	{
		Bureaucrat bureaucrat("Jane Doe", 1);
		std::cout << bureaucrat << std::endl;

		bureaucrat.incrementGrade(); // This will throw an exception
	}
	catch (const GradeTooHighException& error)
	{
		std::cerr << RED << "Exception: " << error.what() << RESET << std::endl;
	}

    return (0);
}
