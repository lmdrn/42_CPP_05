/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormNotSignedException.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:49:35 by lmedrano          #+#    #+#             */
/*   Updated: 2024/06/05 15:51:51 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMNOTSIGNEDEXCEPTION_HPP
# define FORMNOTSIGNEDEXCEPTION_HPP

#include <iostream>
#include <exception>

class FormNotSignedException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Form is not signed !");
		}
};

#endif /* FORMNOTSIGNEDEXCEPTION_HPP */
