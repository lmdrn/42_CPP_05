/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:48:54 by lmedrano          #+#    #+#             */
/*   Updated: 2024/05/31 11:18:20 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADETOOHIGHEXCEPTION_HPP
# define GRADETOOHIGHEXCEPTION_HPP

#include <iostream>
#include <exception>

class GradeTooHighException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Grade is too high!");
		}
};

#endif /* GRADETOOHIGHEXCEPTION_HPP */
