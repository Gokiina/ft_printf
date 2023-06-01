/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodr2 <anarodr2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:18:47 by anarodr2          #+#    #+#             */
/*   Updated: 2023/04/03 11:45:11 by anarodr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(char const *rts, ...);
int	cheking(va_list arg, char const *rts, int *count);
int	defi(va_list arg, char const type, int *count);
int	put_ptr(unsigned long n, int *count);
int	put_num(unsigned int n, int *count, char type);
int	neg_num(int n, int *count);
int	put_str(char const *str, int *count);
int	put_char(int c, int *count);

#endif
