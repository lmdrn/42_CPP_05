/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UnknownFormException.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:38:59 by lmedrano          #+#    #+#             */
/*   Updated: 2024/06/08 16:40:00 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNKNOWNFORMEXCEPTION_HPP
# define UNKNOWNFORMEXCEPTION_HPP

#include <iostream>
#include <exception>

class UnknownFormException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("This form does not exist !");
		}
};

#endif /* UNKNOWNFORMEXCEPTION_HPP */
