/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:48:32 by pbencze           #+#    #+#             */
/*   Updated: 2024/08/07 15:23:05 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include <iostream>
# include "Fixed.hpp"

class Point {
    public:
        Point(void);
        Point(const float n1, const float n2);
        Point(Point const & src);
        ~Point(void);
        
        Point & operator=(Point const & rhs);
        Fixed const &getX(void) const;
        Fixed const &getY(void) const;

        static bool bsp( Point const a, Point const b, Point const c, Point const point);

    private:
        Fixed const x;
        Fixed const y;
    
};

#endif