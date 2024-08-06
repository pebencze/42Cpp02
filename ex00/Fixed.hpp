/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:03:39 by pbencze           #+#    #+#             */
/*   Updated: 2024/08/06 17:24:18 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed {
    public:
        Fixed( void );
        Fixed( Fixed const & src);
        ~Fixed( void );

        Fixed & operator=( Fixed const & rhs);

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        
    private:
        int _fixed;
        static const int _fraction;
};

#endif