/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:26:47 by coder             #+#    #+#             */
/*   Updated: 2021/12/12 21:32:46 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int res = ft_printf("%i - %s - %p %d - %c - %u - %x %X %%", 20, "", (void *)-1, '\0', -20, -1, -1, 200000000);
	ft_printf("\n%d", res);
}