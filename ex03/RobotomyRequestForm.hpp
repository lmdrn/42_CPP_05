/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:40:29 by lmedrano          #+#    #+#             */
/*   Updated: 2024/06/06 12:13:31 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#define RESET "\x1b[0m"
#define GREEN "\x1b[32m"
#define ORANGE "\x1b[38;5;208m"
#define RED "\x1b[31m"
#define PURPLE "\x1b[35m"

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
	    	// Private members
		std::string	_target;

	public:
		//Constructor
    		RobotomyRequestForm(const std::string& target);
		//Operator
		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
		//Copy
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		//Destructor
    		~RobotomyRequestForm();
		//Getters
		std::string	getTarget(void) const;
		//Methods
		void		execute(const Bureaucrat& executor) const;
};

// Overload of the insertion operator
std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& f);

#endif /* ROBOTOMYREQUESTFORM_HPP */
