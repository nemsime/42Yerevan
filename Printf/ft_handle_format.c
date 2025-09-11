/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtumanya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:39:22 by mtumanya          #+#    #+#             */
/*   Updated: 2025/03/09 15:16:27 by mtumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_format(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (specifier == 'X')
		return (ft_hex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (specifier == 'x')
		return (ft_hex(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (specifier == 'u')
		return (ft_uputnbr(va_arg(args, unsigned int)));
	else if (specifier == 'p')
		return (ft_phex((size_t)va_arg(args, void *), "0123456789abcdef"));
	else if (specifier == '%')
		return (ft_putchar('%'));
	return (0);
}
