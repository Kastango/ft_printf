/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:35:50 by coder             #+#    #+#             */
/*   Updated: 2021/12/13 03:16:12 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if (ft_strlen(s) == 0)
		return (0);
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_check_hex(unsigned long int nbr, char *base, char flag)
{
	int	lenght;

	lenght = 0;
	if (!IS_MACOS && nbr == 0)
		lenght += write(1, "(nil)", 5);
	else
	{
		lenght += write(1, "0x", 2);
		lenght += ft_putnbr_base(nbr, "0123456789abcdef", flag);
	}
	return (lenght);
}

int	ft_putnbr_base(unsigned long int nbr, char *base, char flag)
{	
	int	i;
	int	display[16];
	int	lenght;

	i = 0;
	lenght = 0;
	if ((long)nbr < 0 && flag != 'p')
	{
		nbr *= -1;
		lenght = ft_putchar('-');
	}
	while (nbr != 0)
	{
		display[i++] = nbr % ft_strlen(base);
		nbr = nbr / ft_strlen(base);
	}
	if (i == 0 && nbr == 0)
		lenght = ft_putchar('0');
	while (i-- > 0)
		lenght += ft_putchar(base[display[i]]);
	return (lenght);
}
