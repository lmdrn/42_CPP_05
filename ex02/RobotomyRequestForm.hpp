/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:40:29 by lmedrano          #+#    #+#             */
/*   Updated: 2024/06/05 17:01:45 by lmedrano         ###   ########.fr       */
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
    		RobotomyRequestForm(const std::string& target);
    		virtual ~RobotomyRequestForm();
		void	execute(const Bureaucrat& executor) const;
};

#endif /* ROBOTOMYREQUESTFORM_HPP */
