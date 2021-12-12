/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:19:11 by coder             #+#    #+#             */
/*   Updated: 2021/12/12 21:27:33 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h> //n se esquece de apagar essa linha antes de entrega pfvr

# if __APPLE__
#  define IS_MACOS 1
# else
#  define IS_MACOS 0
# endif

int		ft_putchar(char c);
size_t	ft_strlen(const char *s);
int		ft_putstr(char *s);
int		ft_printf(const char *src, ...);

int		checkbase(char *base);
int 	ft_check_hex(unsigned long int nbr, char *base, char flag);
int		ft_putnbr_base(unsigned long int nbr, char *base, char flag);

#endif