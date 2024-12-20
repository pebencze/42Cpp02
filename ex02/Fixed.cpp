/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:03:42 by pbencze           #+#    #+#             */
/*   Updated: 2024/10/19 14:04:22 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fraction = 8;
const float Fixed::_epsilon = (1 >> 8);

Fixed::Fixed( void ) : _fixed(0) {
}

Fixed::Fixed ( const int num ) {
    this->_fixed = (num << this->_fraction);
}

Fixed::Fixed ( const float num ) {
    this->_fixed = static_cast<int>(roundf(num * (1 << this->_fraction)));
}

Fixed::Fixed( Fixed const & src) {
    *this = src;
}

Fixed::~Fixed( void ) {
}

Fixed & Fixed::operator=( Fixed const & rhs) {
    if (this != &rhs) {
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
    float result;
    result = this->toFloat() + rhs.toFloat();
    Fixed ret(result);
    return (ret);
}

Fixed Fixed::operator-( Fixed const & rhs) const {
    float result;
    result = this->toFloat() - rhs.toFloat();
    Fixed ret(result);
    return (ret);
}

Fixed Fixed::operator*( Fixed const & rhs) const {
    float result;
    result = this->toFloat() * rhs.toFloat();
    Fixed ret(result);
    return (ret);
}

Fixed Fixed::operator/( Fixed const & rhs) const {
    float result;
	if (rhs == 0)
		result = this->toInt() / rhs.toInt();
	else
    	result = this->toFloat() / rhs.toFloat(); //important to calculate with floats, not to lose fraction
    Fixed ret(result);
    return (ret);
}

//postfix
Fixed Fixed::operator++(int) {
    Fixed result = *this; //create snapshot
    this->_fixed++; //update
    return (result); //return snapshot
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    this->_fixed--;
    return (temp);
}

//prefix
Fixed & Fixed::operator++() {
    this->_fixed++;
    return (*this);
}

Fixed & Fixed::operator--() {
    this->_fixed--;
    return (*this);
}

Fixed & Fixed::min(Fixed & lhs, Fixed & rhs) {
    return ((lhs._fixed < rhs._fixed) ? lhs : rhs);
}

Fixed const & Fixed::min(Fixed const & lhs, Fixed const & rhs) {
    return ((lhs._fixed < rhs._fixed) ? lhs : rhs);
}

Fixed & Fixed::max(Fixed & lhs, Fixed & rhs) {
    return ((lhs._fixed > rhs._fixed) ? lhs : rhs);
}

Fixed const & Fixed::max(Fixed const & lhs, Fixed const & rhs) {
	return ((lhs._fixed > rhs._fixed) ? lhs : rhs);
}
