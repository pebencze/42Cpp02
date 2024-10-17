/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:03:39 by pbencze           #+#    #+#             */
/*   Updated: 2024/10/17 15:40:45 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

class Fixed {
    public:
        Fixed( void ); //Fixed const ( void ); would be wrong -> constructors do not have a return type, not even const
        Fixed( const int num );
        Fixed( const float num );
        Fixed( Fixed const &src);
        ~Fixed( void );

        Fixed & operator=( Fixed const & rhs);

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;

    private:
        int _fixed;
        static const int _fraction;
};

std::ostream &operator<<( std::ostream &o, Fixed const & rhs); //overload of the insertion operator

#endif
