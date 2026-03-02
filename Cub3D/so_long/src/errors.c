/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtumanya <mtumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:34:12 by mtumanya          #+#    #+#             */
/*   Updated: 2025/07/11 13:30:43 by mtumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_error(int fd, char *str)
{
	write(2, str, ft_strlen(str));
	if (fd)
		close(fd);
	exit(EXIT_FAILURE);
}
