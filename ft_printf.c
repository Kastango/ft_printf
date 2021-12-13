/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 02:50:36 by arbernar          #+#    #+#             */
/*   Updated: 2021/12/13 03:19:29 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_number_flag(va_list *argptr, char flag)
{
	int	lenght;

	lenght = 0;
	if (flag == 'p')
		lenght += ft_check_hex((unsigned long int)va_arg(*argptr, void *),
				"0123456789abcdef", flag);
	else if (flag == 'i' || flag == 'd')
		lenght += ft_putnbr_base(va_arg(*argptr, int), "0123456789", flag);
	else if (flag == 'u')
		lenght += ft_putnbr_base(va_arg(*argptr, unsigned int),
				"0123456789", flag);
	else if (flag == 'x')
		lenght += ft_putnbr_base(va_arg(*argptr, unsigned int),
				"0123456789abcdef", flag);
	else if (flag == 'X')
		lenght += ft_putnbr_base(va_arg(*argptr, unsigned int),
				"0123456789ABCDEF", flag);
	return (lenght);
}

static int	ft_capture_the_flag(va_list *argptr, char flag)
{
	int	lenght;

	lenght = 0;
	if (flag == 'c')
		lenght += ft_putchar(va_arg(*argptr, int));
	if (flag == 's')
		lenght += ft_putstr(va_arg(*argptr, char *));
	if (flag == 'p' || flag == 'd' || flag == 'i' || flag == 'u' || flag == 'x'
		|| flag == 'X')
		lenght = ft_print_number_flag(argptr, flag);
	if (flag == '%')
		lenght += ft_putchar('%');
	return (lenght);
}

int	ft_printf(const char *src, ...)
{
	va_list	argptr;
	int		i;
	int		lenght;

	i = 0;
	lenght = 0;
	va_start(argptr, src);
	while (src[i])
	{
		if (src[i] == '%')
			lenght += ft_capture_the_flag(&argptr, src[++i]);
		else
			lenght += ft_putchar(src[i]);
		i++;
	}
	va_end(argptr);
	return (lenght);
}
