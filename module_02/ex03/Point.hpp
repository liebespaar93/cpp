/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:10:34 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/17 15:27:33 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	/* data */
	const Fixed _x;
	const Fixed _y;
	
public:
	Point();
	~Point();
	Point(const float x, const float y);
	Point(Fixed x, Fixed y);
	Point(const Point& ret);
	
	Point& operator=(const Point& ref);
	
	Fixed	get_x() const;
	Fixed	get_y() const;
	void	set_x(float value);
	void	set_y(float value);
	int		get_x_sign() const;
	int		get_y_sign() const;
};

#endif
