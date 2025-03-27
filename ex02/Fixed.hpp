/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:05:22 by ufo               #+#    #+#             */
/*   Updated: 2025/03/09 15:31:34 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <string>
# include <cmath>


class Fixed {
    private:
        int _fixedNum;
        static const int _fractBits = 8;
    
    public:
        //Consstructors:
        Fixed(void);
        Fixed(const int numInt);
        Fixed(const float numFloat);
        Fixed(const Fixed &other);             // Copy constructor
        Fixed &operator=(const Fixed &other);  // Assignment
        ~Fixed();

        //Methods
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        int toInt( void ) const;
        float toFloat( void ) const;

        static Fixed& min(Fixed &a, Fixed &b);
        static const Fixed& min(const Fixed &a, const Fixed &b);
        static Fixed& max(Fixed &a, Fixed &b);
        static const Fixed& max(const Fixed &a, const Fixed &b);

        //BOOL Operators overloades 
        bool operator<(const Fixed &other) const;
        bool operator>(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;
        bool operator<=(const Fixed &other) const;
        bool operator>=(const Fixed &other) const;

        // Airthmetical overloades
        Fixed operator+(const Fixed &other) const;
        Fixed operator-(const Fixed &other) const;
        Fixed operator*(const Fixed &other) const;
        Fixed operator/(const Fixed &other) const;

        // Incrementing overloades
        Fixed& operator++();    // Pre-increment (++x)
        Fixed operator++(int);  // Post-increment (x++)
        Fixed& operator--();    // Pre-decrement (--x)
        Fixed operator--(int);  // Post-decrement (x--)

};

std::ostream & operator<<(std::ostream & o, Fixed const & input);

#endif