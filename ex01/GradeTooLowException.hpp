/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:52:30 by lmedrano          #+#    #+#             */
/*   Updated: 2024/05/31 10:54:07 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADETOOLOWEXCEPTION_HPP
# define GRADETOOLOWEXCEPTION_HPP

#include <iostream>
#include <exception>

class GradeTooLowException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Grade is too low !");
		}
};

#endif /* GRADETOOLOWEXCEPTION_HPP */
