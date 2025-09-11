/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtumanya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:39:11 by mtumanya          #+#    #+#             */
/*   Updated: 2025/03/09 15:19:16 by mtumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(size_t n, char *hex)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 16)
		count += ft_hex(n / 16, hex);
	c = hex[n % 16];
	count += ft_putchar(c);
	return (count);
}

int	ft_phex(size_t	n, char *hex)
{
	int		count;
	char	c;
	int		ncount;

	if (n == 0)
	{
		ncount = ft_putstr("(nil)");
		return (ncount);
	}
	count = ft_putstr("0x");
	if (n >= 16)
		count += ft_hex(n / 16, hex);
	c = hex[n % 16];
	count += ft_putchar(c);
	return (count);
}
