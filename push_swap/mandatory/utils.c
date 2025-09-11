/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtumanya <mtumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 12:15:46 by mtumanya          #+#    #+#             */
/*   Updated: 2025/07/11 12:15:47 by mtumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *var1, int *var2)
{
	int	tmp;

	tmp = *var1;
	*var1 = *var2;
	*var2 = tmp;
}

int	is_sorted(t_stack *tmp)
{
	t_stack	*head;
	int		id;

	if (!tmp)
		return (0);
	id = 0;
	head = tmp;
	while (head)
	{
		if (head->index != id)
			return (0);
		id++;
		head = head->next;
	}
	return (1);
}
