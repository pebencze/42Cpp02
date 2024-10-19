/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:03:42 by pbencze           #+#    #+#             */
/*   Updated: 2024/10/19 13:55:12 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fraction = 8;

Fixed::Fixed( void ) : _fixed(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed ( const int num ) {
    std::cout << "Int constructor called" << std::endl;
    this->_fixed = (num << this->_fraction);
}

Fixed::Fixed ( const float num ) {
    std::cout << "Float constructor called" << std::endl;
    this->_fixed = static_cast<int>(roundf(num * (1 << this->_fraction)));
}

Fixed::~Fixed( void ) {
    std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=( Fixed const & rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs) { //why this check: can lead to self-assignment problems in more complex programs e.g. double deletion, memory corruption, or other unexpected behavior.
        this->_fixed = rhs.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits( void ) const {
    return (this->_fixed);
}

void Fixed::setRawBits( int const raw ) {
    this->_fixed = raw;
}

float Fixed::toFloat( void ) const {
    return (static_cast<float>(this->_fixed) / (1 << this->_fraction));
}

int Fixed::toInt( void ) const {
	// adding 0.5 in fixed-point representation before shifting for rounding purposes
    return ((this->_fixed + (1 << (this->_fraction - 1))) >> this->_fraction);
}

std::ostream &operator<<( std::ostream &o, Fixed const &rhs) {
    o << rhs.toFloat();
    return (o);
}
