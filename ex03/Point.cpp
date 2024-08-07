/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:48:36 by pbencze           #+#    #+#             */
/*   Updated: 2024/08/07 15:22:47 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0) {
    
}

Point::Point(const float n1, const float n2) : x(n1), y(n2) {
    
}

Point::Point(Point const & src) {
    *this = src;
}

Point::~Point(void) {
    
}

Point & Point::operator=(Point const & rhs) {
    if (this != &rhs)
    {
        this->x = rhs.getX();
        this->y = rhs.getY();
    }
    return (*this);
}

Fixed const &Point::getX(void) const {
    return (this->x);
}

Fixed const &Point::getY(void) const {
    return (this->y);
}

bool Point::bsp( Point const a, Point const b, Point const c, Point const point);