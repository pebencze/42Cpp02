/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:03:46 by pbencze           #+#    #+#             */
/*   Updated: 2024/10/17 17:25:21 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

#include <iostream>
#include "Fixed.hpp"

int main() {
    Fixed a;
    Fixed b(10);
    Fixed c(42.42f);
    Fixed d(b);
	Fixed zero(0);

    // Test assignment operator
    a = Fixed(1234.4321f);

	//values
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "zero: " << zero << std::endl;

    // Test comparison operators
    std::cout << "b < c: " << (b < c) << std::endl;
    std::cout << "b > c: " << (b > c) << std::endl;
    std::cout << "b >= d: " << (b >= d) << std::endl;
    std::cout << "b <= d: " << (b <= d) << std::endl;
    std::cout << "b == d: " << (b == d) << std::endl;
    std::cout << "b != c: " << (b != c) << std::endl;

    // Test arithmetic operators
    Fixed e = b + c;
    Fixed f = c - b;
    Fixed g = b * c;
    Fixed h = c / b;
	Fixed l = b * zero;

    std::cout << "b + c: " << e << std::endl;
    std::cout << "c - b: " << f << std::endl;
    std::cout << "b * c: " << g << std::endl;
	std::cout << "b * 0: " << l << std::endl;
    std::cout << "c / b: " << h << std::endl;

    // Test increment and decrement operators
    Fixed i;
    std::cout << "i: " << i << std::endl;
	std::cout << "i++: " << i++ << std::endl;
	std::cout << "i: " << i << std::endl;
    std::cout << "++i: " << ++i << std::endl;
    std::cout << "i--: " << i-- << std::endl;
	std::cout << "i: " << i << std::endl;
    std::cout << "--i: " << --i << std::endl;

    // Test min and max functions
    std::cout << "min(b, c): " << Fixed::min(b, c) << std::endl;
    std::cout << "max(b, c): " << Fixed::max(b, c) << std::endl;

    return 0;
}
