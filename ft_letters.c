/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodr2 <anarodr2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:27:19 by anarodr2          #+#    #+#             */
/*   Updated: 2023/03/23 17:23:56 by anarodr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_char(int c, int *count)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	*count = (*count + 1);
	return (*count);
}

int	put_str(char const *str, int *count)
{
	int	i;

	if (!str)
		str = "(null)";
	i = 0;
	while (str[i])
	{
		if (put_char(str[i], count) == -1)
			return (-1);
		i++;
	}
	return (*count);
}
