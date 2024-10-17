/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:03:46 by pbencze           #+#    #+#             */
/*   Updated: 2024/10/17 15:36:17 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    Fixed a; //constructor called
    Fixed b( a ); //copy constructor called
    Fixed c;

    c = b; //copy assignment operator called

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
	c.setRawBits(9);
	std::cout << c.getRawBits() << std::endl;

    return 0;
}
