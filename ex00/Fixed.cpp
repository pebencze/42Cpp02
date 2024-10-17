/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:03:42 by pbencze           #+#    #+#             */
/*   Updated: 2024/10/17 15:37:17 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

const int Fixed::_fraction = 8; //initializing a static member

Fixed::Fixed( void ) : _fixed(0) { //member initializer list
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src; //!!!
}

Fixed::~Fixed( void ) {
    std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=( Fixed const & rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->_fixed = rhs.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixed);
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
    this->_fixed = raw;
}
