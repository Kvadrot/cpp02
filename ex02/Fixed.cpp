/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:19:23 by ufo               #+#    #+#             */
/*   Updated: 2025/03/27 15:49:11 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// ================= CONSTRUCTORS =================

Fixed::Fixed(void) {
    std::cout << "Default constructor called\n";
    this->_fixedNum = 0;
}

Fixed::Fixed(const int numInt) {
    this->_fixedNum = numInt << this->_fractBits;
    std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float numFloat) {
    this->_fixedNum = (int)roundf(numFloat * (1 << this->_fractBits));
    std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed &other) {
    this->_fixedNum = other._fixedNum;
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

// ================= MIN & MAX FUNCTIONS =================

// Min Function (Non-const)
Fixed& Fixed::min(Fixed &a, Fixed &b) {
    if (a < b) {
        return a;
    }
    return b;
}

// Min Function (Const)
const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    if (a < b) {
        return a;
    }
    return b;
}

// Max Function (Non-const)
Fixed& Fixed::max(Fixed &a, Fixed &b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Max Function (Const)
const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    if (a > b) {
        return a;
    }
    return b;
}

// ================= OPERATORS OVERLOADING =================

// Comparison Operators
bool Fixed::operator>(const Fixed &other) const {
    return this->_fixedNum > other._fixedNum;
}

bool Fixed::operator<(const Fixed &other) const {
    return this->_fixedNum < other._fixedNum;
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->_fixedNum >= other._fixedNum;
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->_fixedNum <= other._fixedNum;
}

bool Fixed::operator==(const Fixed &other) const {
    return this->_fixedNum == other._fixedNum;
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->_fixedNum != other._fixedNum;
}

// Arithmetic Operators
Fixed Fixed::operator+(const Fixed &other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
    return Fixed((this->_fixedNum * other._fixedNum) >> _fractBits);
}

Fixed Fixed::operator/(const Fixed &other) const {
    if (other._fixedNum == 0) {
        throw std::runtime_error("Division by zero\n");
    }
    return Fixed((this->_fixedNum << _fractBits) / other._fixedNum);
}

// ================= INCREMENT & DECREMENT =================

// Pre-increment (++x)
Fixed& Fixed::operator++() {
    this->_fixedNum += 1;
    return *this;
}

// Post-increment (x++)
Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    this->_fixedNum += 1;
    return temp;
}

// Pre-decrement (--x)
Fixed& Fixed::operator--() {
    this->_fixedNum -= 1;
    return *this;
}

// Post-decrement (x--)
Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    this->_fixedNum -= 1;
    return temp;
}

// ================= STREAM OPERATOR =================

std::ostream &operator<<(std::ostream &o, Fixed const &input) {
    o << input.toFloat();
    return o;
}
