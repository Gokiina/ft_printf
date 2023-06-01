/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodr2 <anarodr2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:59:26 by anarodr2          #+#    #+#             */
/*   Updated: 2023/03/23 12:29:16 by anarodr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	defi(va_list arg, char const type, int *count)
{
	if (type == '%')
		*count = put_char('%', count);
	if (type == 'c')
		*count = put_char(va_arg(arg, int), count);
	if (type == 's')
		*count = put_str(va_arg(arg, char const *), count);
	if (type == 'd' || type == 'i')
		*count = neg_num(va_arg(arg, int), count);
	if (type == 'u')
		*count = put_num(va_arg(arg, unsigned int), count, 'u');
	if (type == 'x')
		*count = put_num(va_arg(arg, unsigned int), count, 'x');
	if (type == 'X')
		*count = put_num(va_arg(arg, unsigned int), count, 'X');
	if (type == 'p')
		*count = put_ptr(va_arg(arg, unsigned long), count);
	return (*count);
}

int	cheking(va_list arg, char const *rts, int *count)
{
	int	i;

	i = 0;
	while (rts[i])
	{
		if (rts[i] == '%')
		{
			if (defi(arg, rts[i + 1], count) == -1)
				return (-1);
			i++;
		}
		else
		{
			if (put_char(rts[i], count) == -1)
				return (-1);
		}
		i++;
	}
	return (*count);
}

int	ft_printf(char const *rts, ...)
{
	int		k;
	va_list	arg;

	k = 0;
	va_start(arg, rts);
	if (cheking(arg, rts, &k) == -1)
		return (-1);
	va_end(arg);
	return (k);
}

/*int	main(void)
{
	void *str=NULL;
	
	if (ft_printf("%p\n", str) == printf("%p\n", str))
	{
		printf("OK :D\n");
		printf("%d", ft_printf("%p", str));
	}
	else
	{
		printf("KO :C\n");
		printf("-->%d", ft_printf("%p", str));
	}
	printf("%d",ft_printf("%p", ""));
	return (0);
}*/
