/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:05:22 by ufo               #+#    #+#             */
/*   Updated: 2025/03/06 11:13:30 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <string>

class Fixed {
    private:
        int _fixedNum;
        static const int _fractBits = 8;
    
    public:
        //Consstructors:
        Fixed();
        Fixed(const Fixed &other);             // Copy constructor
        Fixed &operator=(const Fixed &other);  // Assignment
        ~Fixed();

        //Methods
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif