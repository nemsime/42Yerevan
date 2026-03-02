/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtumanya <mtumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 12:13:37 by mtumanya          #+#    #+#             */
/*   Updated: 2025/07/11 12:13:38 by mtumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dup;

	len = ft_strlen (s1);
	dup = (char *) malloc (len + 1);
	if (dup == NULL)
		return (NULL);
	ft_memset (dup, 0, len + 1);
	ft_memcpy (dup, s1, len + 1);
	return (dup);
}
