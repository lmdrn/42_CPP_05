/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:52:10 by lmedrano          #+#    #+#             */
/*   Updated: 2024/06/06 12:09:28 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
	    	// Private members
		std::string	_target;

	public:
    		// Constructor
    		PresidentialPardonForm(const std::string& target);
		//Operator
		PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
		//Copy
		PresidentialPardonForm(const PresidentialPardonForm &copy);
    		// Destructor
    		~PresidentialPardonForm();
		//Getters
		std::string	getTarget(void) const;
		//Methods
		void		execute(const Bureaucrat& executor) const;
};

// Overload of the insertion operator
std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& f);

#endif /* PRESIDENTIALPARDONFORM_HPP */
