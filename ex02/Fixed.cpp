/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:03:42 by pbencze           #+#    #+#             */
/*   Updated: 2024/08/07 14:07:48 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fraction = 8;
const float Fixed::_epsilon = (1 >> 8);

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

Fixed::Fixed( Fixed const & src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
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
    return (this->_fixed >> this->_fraction);
}

std::ostream &operator<<( std::ostream &o, Fixed const &rhs) {
    o << rhs.toFloat();
    return (o);
}

bool Fixed::operator>( Fixed const & rhs) const {
    return (this->_fixed > rhs._fixed);
} 

bool Fixed::operator<( Fixed const & rhs) const {
    return (this->_fixed < rhs._fixed);
}

bool Fixed::operator>=( Fixed const & rhs) const { 
    return (this->_fixed >= rhs._fixed);
}
 
bool Fixed::operator<=( Fixed const & rhs) const { 
    return (this->_fixed <= rhs._fixed);
} 

bool Fixed::operator==( Fixed const & rhs) const { 
    return (this->_fixed == rhs._fixed);
} 

bool Fixed::operator!=( Fixed const & rhs) const { 
    return (this->_fixed != rhs._fixed);
}

Fixed Fixed::operator+( Fixed const & rhs) const { 
    Fixed result;
    result._fixed = this->_fixed + rhs._fixed;
    return (result);
} 

Fixed Fixed::operator-( Fixed const & rhs) const { 
    Fixed result;
    result._fixed = this->_fixed - rhs._fixed;
    return (result);
} 

Fixed Fixed::operator*( Fixed const & rhs) const { 
    Fixed result;
    result._fixed = this->_fixed * rhs._fixed;
    return (result);
} 

Fixed Fixed::operator/( Fixed const & rhs) const { 
    Fixed result;
    result._fixed = this->_fixed / rhs._fixed;
    return (result);
} 

//postfix
Fixed Fixed::operator++(int) { 
    Fixed result = *this; //create snapshot
    this->_fixed += this->_epsilon; //update
    return (result); //return snapshot
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    this->_fixed -= this->_epsilon;
    return (temp);
} 

//prefix
Fixed & Fixed::operator++() {
    this->_fixed += this->_epsilon;
    return (*this);
} 

Fixed & Fixed::operator--() {
    this->_fixed -= this->_epsilon;
    return (*this)
} 

Fixed & Fixed::min(Fixed & lhs, Fixed & rhs) {
    if (lhs._fixed < rhs._fixed)
        return (lhs);
    else
        return (rhs);
}

Fixed const & Fixed::min(Fixed const & lhs, Fixed const & rhs) {
    if (lhs._fixed < rhs._fixed)
        return (lhs);
    else
        return (rhs);
}

Fixed & Fixed::max(Fixed & lhs, Fixed & rhs) {
    if (lhs._fixed > rhs._fixed)
        return (lhs);
    else
        return (rhs);
}

Fixed const & Fixed::max(Fixed const & lhs, Fixed const & rhs) {
    if (lhs._fixed > rhs._fixed)
        return (lhs);
    else
        return (rhs);
}