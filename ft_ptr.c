/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodr2 <anarodr2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:44:06 by anarodr2          #+#    #+#             */
/*   Updated: 2023/03/23 17:18:10 by anarodr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	aux_ptr(unsigned long n, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
	{
		if (aux_ptr(n / 16, count) == -1)
			return (-1);
	}
	if (put_char(base[n % 16], count) == -1)
		return (-1);
	return (*count);
}

int	put_ptr(unsigned long n, int *count)
{
	if (put_str("0x", count) == -1)
		return (-1);
	if (aux_ptr(n, count) == -1)
		return (-1);
	return (*count);
}
