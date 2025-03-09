/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:19:23 by ufo               #+#    #+#             */
/*   Updated: 2025/03/09 15:47:48 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// ================= CONSTRUCTORS =================

Fixed:: Fixed(void) {
    std::cout << "Default constructor called\n";
    this->_fixedNum = 0;
}

Fixed:: Fixed(const int numInt) {
    this->_fixedNum = numInt << this->_fractBits;
    std::cout << "Int constructor called\n";
}

Fixed:: Fixed(const float numFloat) {
    this->_fixedNum = roundf(numFloat * (1 << this->_fractBits));
    std::cout << "Float constructor called\n";
}

Fixed:: Fixed(const Fixed &other) : _fixedNum(other._fixedNum) {
    std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        this->_fixedNum = other._fixedNum;
    }
    std::cout << "Copy assignment operator called\n";
    return *this;
}

// ================= DESTRUCTOR =================

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

// ================= METHODS =================

int Fixed::getRawBits(void) const {
    return this->_fixedNum;
}

void Fixed::setRawBits(int const raw) {
    this->_fixedNum = raw;
}

int Fixed::toInt(void) const {
    return this->_fixedNum >> _fractBits;
}

float Fixed::toFloat(void) const {
    return (float)this->_fixedNum / (1 << _fractBits);
}

// ================= STREAM OPERATOR =================

std::ostream &operator<<(std::ostream &o, Fixed const &input) {
    o << input.toFloat();
    return o;
}
