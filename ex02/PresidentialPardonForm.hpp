/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:52:10 by lmedrano          #+#    #+#             */
/*   Updated: 2024/06/05 16:59:28 by lmedrano         ###   ########.fr       */
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
    		// Destructor
    		virtual ~PresidentialPardonForm();
		void	execute(const Bureaucrat& executor) const;
};

#endif /* PRESIDENTIALPARDONFORM_HPP */
