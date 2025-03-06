/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:19:23 by ufo               #+#    #+#             */
/*   Updated: 2025/03/06 11:14:10 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

//CONSTRUCTORS
Fixed:: Fixed() {
    this->_fixedNum = 0;
    std::cout << "Default contructor called\n";
}

Fixed:: Fixed(const Fixed &other) {
    *this = other;
    std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        this->_fixedNum = other._fixedNum;
    }
    std::cout << "Copy assignment operator called\n";
    return *this;
}

//deconstructed
Fixed:: ~Fixed() {
    std::cout << "Destructor called\n";
}

//METHODS
int Fixed:: getRawBits( void ) const {
    std::cout << "getRawBits member function called\n";
    return (this->_fixedNum);
    
}

 void Fixed:: setRawBits( int const raw ) {
    this->_fixedNum = raw;
    std::cout << "getRawBits member function called\n";
 }
