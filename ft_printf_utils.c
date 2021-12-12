/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:35:50 by coder             #+#    #+#             */
/*   Updated: 2021/12/12 09:40:43 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
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

int	checkbase(char *base)
{
	int	j;
	int	i;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	j = 1;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

int ft_check_hex(unsigned long int nbr, char *base, char flag)
{
	int lenght;

	if(!IS_MACOS && nbr == 0)
		lenght += write(1, "(nil)", 5);
	else
	{
		lenght += write(1, "0x", 2);
		lenght += ft_putnbr_base(nbr,"0123456789abcdef", flag);
	}
	
	return (lenght);
}

int	ft_putnbr_base(unsigned long int nbr, char *base, char flag)
{	
	int	size;
	int	lenght;

	lenght = 0;
	size = ft_strlen(base);
	if (!checkbase(base))
		return (0);
	if ((long)nbr < 0 && flag != 'p')
	{
		lenght += ft_putchar('-');
		lenght += ft_putnbr_base(-nbr, base, flag);
		return (lenght);
	}
	if (nbr >= size)
	{
		lenght += ft_putnbr_base(nbr / size, base, flag);
		lenght += ft_putnbr_base(nbr % size, base, flag);
	}
	else
	{
		lenght += ft_putchar(base[nbr]);
	}
	return (lenght);
}