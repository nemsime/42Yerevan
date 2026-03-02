/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtumanya <mtumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 12:14:08 by mtumanya          #+#    #+#             */
/*   Updated: 2025/07/11 12:14:09 by mtumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (n > 0 && *ss1 && (*ss1 == *ss2))
	{
		ss1++;
		ss2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*ss1 - *ss2);
}
