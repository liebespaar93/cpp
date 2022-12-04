/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:46:31 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/05 06:36:38 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	check_left_side(Point const point, Point const p_center, Point const p_next)
{
	Point	point_len(point.get_x() - p_center.get_x(), point.get_y() - p_center.get_y());
	Point	next_len(p_next.get_x() - p_center.get_x(), p_next.get_y() - p_center.get_y());
	Fixed	point_angle(point_len.get_y() / point_len.get_x());
	Fixed	next_angle(next_len.get_y() / next_len.get_x());
	
	if (0x7fffff80u == next_angle.getRawBits() || 0x7fffff80u == point_angle.getRawBits())
		return (0);
	if (next_len.get_x_sign() == point_len.get_x_sign() \
		 && (next_len.get_y_sign() == point_len.get_y_sign()))
	{
		if (point_angle >= next_angle)
			return (1);
		else
			return (0);
	}
	else if (next_len.get_x_sign() != point_len.get_x_sign() \
		 && (next_len.get_y_sign() != point_len.get_y_sign()))
	{
		if (point_angle <= next_angle)
			return (1);
		else
			return (0);
	}
	else if ((!next_len.get_x_sign() && !next_len.get_y_sign()) \
		|| (next_len.get_x_sign() && !next_len.get_y_sign()))
	{
		if (point_len.get_x_sign())
			return (1);
		else
			return (0);
	}
	else if ((next_len.get_x_sign() && next_len.get_y_sign()) \
		|| (!next_len.get_x_sign() && next_len.get_y_sign()))
	{
		if (!point_len.get_x_sign())
			return (1);
		else
			return (0);
	}
	return (0);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{	
	int count = 0;

	if (check_left_side(c, a, b))
		count += check_left_side(point, a, b);
	else
		count += check_left_side(point, b, a);
	if (check_left_side(a, b, c))
		count += check_left_side(point, b, c);
	else
		count += check_left_side(point, c, b);
	if (check_left_side(b, c, a))
		count += check_left_side(point, c, a);
	else
		count += check_left_side(point, a, c);
	return (count == 3);
}
