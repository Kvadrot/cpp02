/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:19:23 by ufo               #+#    #+#             */
/*   Updated: 2025/03/06 17:51:04 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

//CONSTRUCTORS
Fixed:: Fixed(void) {
	std::cout << "default constructor called\n";
	this->_fixedNum = 0;
}

Fixed:: Fixed(const int numInt) {
    this->_fixedNum = numInt << this->_fractBits;
    std::cout << "Int contructor called\n";
}

Fixed:: Fixed(const float numFloat) {
    this->_fixedNum = (int)roundf(numFloat * (1 << this->_fractBits));
    std::cout << "Float contructor called\n";
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

std::ostream & operator<<(std::ostream & o, Fixed const & input)
{
	o << input.toFloat();
	return (o);
}

int Fixed:: toInt( void ) const {
    int convertedFractBeats = (1 << this->_fractBits); //shifts 00000001 n times to the left causing powering int 
    return (this->_fixedNum * convertedFractBeats);
}
float Fixed:: toFloat( void ) const {
    int convertedFractBeats = (1 << this->_fractBits); //shifts 00000001 n times to the left causing powering int 
    return float(this->_fixedNum / convertedFractBeats);
}
