/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodr2 <anarodr2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:27:24 by anarodr2          #+#    #+#             */
/*   Updated: 2023/03/23 11:25:54 by anarodr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_num(unsigned int n, int *count, char type);

int	neg_num(int n, int *count)
{
	if (n == -2147483648)
	{
		if (put_str("-2147483648", count) == -1)
			return (-1);
	}
	else
	{
		if (n < 0)
		{
			if (put_char('-', count) == -1)
				return (-1);
			n = n * -1;
		}
		if (put_num(n, count, 'u') == -1)
			return (-1);
	}
	return (*count);
}

int	put_num(unsigned int n, int *count, char type)
{
	char			*base;
	unsigned int	b;

	if (type == 'u')
	{
		base = "0123456789";
		b = 10;
	}
	if (type == 'x' || type == 'X')
	{
		b = 16;
		if (type == 'x')
			base = "0123456789abcdef";
		if (type == 'X')
			base = "0123456789ABCDEF";
	}
	if (n >= b)
	{
		if (put_num(n / b, count, type) == -1)
			return (-1);
	}
	if (put_char(base[n % b], count) == -1)
		return (-1);
	return (*count);
}
