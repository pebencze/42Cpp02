/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:03:39 by pbencze           #+#    #+#             */
/*   Updated: 2024/08/07 13:30:16 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

class Fixed {
    public:
        Fixed( void );
        Fixed( const int num );
        Fixed( const float num );
        Fixed( Fixed const &src);
        ~Fixed( void );

        //=, >, <, >=, <=, ==, != +, -, *, /, ++, --
        bool operator<( Fixed const & rhs) const ;  
        bool operator>=( Fixed const & rhs) const ;  
        bool operator<=( Fixed const & rhs) const ;  
        bool operator==( Fixed const & rhs) const ;  
        bool operator!=( Fixed const & rhs) const ;  
        Fixed operator+( Fixed const & rhs) const ;  
        Fixed operator-( Fixed const & rhs) const ;  
        Fixed operator*( Fixed const & rhs) const ;  
        Fixed operator/( Fixed const & rhs) const ;  
        Fixed operator++( Fixed const & rhs );
        Fixed operator--( Fixed const & rhs ); 
        Fixed & operator++( Fixed const & rhs);  
        Fixed & operator--( Fixed const & rhs );
        
        static Fixed & min(Fixed & lhs, Fixed & rhs); 
        static Fixed const & min(Fixed const & lhs, Fixed const & rhs); 
        static Fixed & max(Fixed & lhs, Fixed & rhs); 
        static Fixed const & max(Fixed const & lhs, Fixed const & rhs); 

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        
    private:
        int _fixed;
        static const int _fraction;
        static const float _epsilon;
};

std::ostream &operator<<( std::ostream &o, Fixed const & rhs);
        
#endif