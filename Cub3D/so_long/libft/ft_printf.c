/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtumanya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:39:37 by mtumanya          #+#    #+#             */
/*   Updated: 2025/03/09 15:27:53 by mtumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	args;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count = count + ft_handle_format(format[i + 1], args);
			i++;
		}
		else
			count = count + ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
