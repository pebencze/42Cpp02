/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:03:39 by pbencze           #+#    #+#             */
/*   Updated: 2024/10/17 15:14:52 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed {
    public:
        Fixed( void ); //default constructor
        Fixed( Fixed const & src); //copy constructor
        ~Fixed( void ); //destructor

        Fixed & operator=( Fixed const & rhs); //copy assignment operator

        int getRawBits( void ) const;
        void setRawBits( int const raw );

    private:
        int _fixed;
        static const int _fraction;
};

#endif
